---
title: mysql 数据库的主从同步
top: 0
date: 2020-07-04 15:09:21
categories: MySql
tags:
- mysql
- slave
---

大型网站为了软解大量的并发访问，除了在网站实现分布式负载均衡，远远不够.
到了数据业务层、数据访问层，如果还是传统的数据结构，
或者只是单单靠一台服务器来处理如此多的数据库连接操作，数据库必然会崩溃，特别是数据丢失的话，后果更是不堪设想.
利用主从数据库来实现读写分离，从而分担主数据库的压力.
在多个服务器上部署 mysql，将其中一台认为主数据库，而其他为从数据库，实现主从同步.
其中主数据库负责主动写的操作，而从数据库则只负责主动读的操作（slave 从数据库仍然会被动的进行写操作，为了保持数据一致性），
这样就可以很大程度上的避免数据丢失的问题，同时也可减少数据库的连接，减轻主数据库的负载.

主从同步复制有以下几种方式：
* 同步复制：master 的变化，必须等待 slave-1,slave-2,...,slave-n 完成后才能返回。
* 异步复制：master 只需要完成自己的数据库操作即可，至于 slaves 是否收到二进制日志，是否完成操作，不用关心。MYSQL 的默认设置。
* 半同步复制：master 只保证 slaves 中的一个操作成功，就返回，其他 slave 不管。这个功能，是由 google 为 MYSQL 引入的。

mysql 主从复制的思路：
*配置主服务器，即 msater，使之具备一下能力(主要接受用户的写操作，并且负责将二进制日志同步给从服务器)
    * 记录二进制日志
    * 为从服务提供一个用户(设置密码)，提高二进制日志同步得安全性

*配置从服务器，即 slave，使之具备一下能力(主要负责用户的读操作(分担主服务器的读写压力)，并且负责重放 master的 写操作，还能实现容灾能力，保证高可用)
    * 记录中继日志
    * 连接到 mysql 可以启动 slave 功能，并且设置 master 信息，通过配置信息，开启 IO_THREAD 和 SQL_THREAD 线程

<!--more-->

下面是在centos 7系统上，实现的 mysql5.7 数据库的主从同步配置，从而实现读写分离操作。

这里测试的两台服务器的IP地址分别为主服务器（192.168.2.19）和从服务器（192.168.2.169）
分别在这两个服务器上创建test数据库，以备后面测试。

##### master 主服务器的配置
* 配置文件my.cnf的修改
`vim /etc/my.cnf`
在`[mysqld]`中添加：
```
#备注：
#server-id 服务器唯一标识。
#log_bin 启动MySQL二进制日志，即数据同步语句，从数据库会一条一条的执行这些语句。
#binlog_do_db 指定记录二进制日志的数据库，即需要复制的数据库名，如果复制多个数据库，重复设置这个选项即可。
#binlog_ignore_db 指定不记录二进制日志的数据库，即不需要复制的数据库名，如果有多个数据库，重复设置这个选项即可。
#其中需要注意的是，binlog_do_db和binlog_ignore_db为互斥选项，一般只需要一个即可。

server-id=1
log_bin=master-bin
log_bin_index=master-bin.index
binlog_do_db=test

```
* 创建从服务器的用户和权限
进入主 mysql 数据库`mysql -uroot -p`
创建从数据库的 `masterbackup`用户和权限
```
#备注
#192.168.2.%通配符，表示0-255的IP都可访问主服务器，正式环境请配置指定从服务器IP
#若将 192.168.2.% 改为 %，则任何ip均可作为其从数据库来访问主服务器
grant replication slave on *.* to masterbackup@'192.168.2.%' identified by '12345678';
# 刷新权限信息
flush privileges; 
```
重启mysql服务`service mysqld restart`

* 查看主服务器状态
```
mysql> show master status;
+-------------------+----------+--------------+------------------+-------------------+
| File              | Position | Binlog_Do_DB | Binlog_Ignore_DB | Executed_Gtid_Set |
+-------------------+----------+--------------+------------------+-------------------+
| master-bin.000001 |      154 | test         |                  |                   |
+-------------------+----------+--------------+------------------+-------------------+
```

##### slave 从服务器的配置
* 配置文件my.cnf的修改
`vim /etc/my.cnf`
在`[mysqld]`中添加：
```
#备注：
#server-id 服务器唯一标识，如果有多个从服务器，每个服务器的server-id不能重复，跟IP一样是唯一标识，如果你没设置server-id或者设置为0，则从服务器不会连接到主服务器。
#relay-log 启动MySQL二进制日志，可以用来做数据备份和崩溃恢复，或主服务器挂掉了，将此从服务器作为其他从服务器的主服务器。
#replicate-do-db 指定同步的数据库，如果复制多个数据库，重复设置这个选项即可。若在master端不指定binlog-do-db，则在slave端可用replication-do-db来过滤。
#replicate-ignore-db 不需要同步的数据库，如果有多个数据库，重复设置这个选项即可。
#其中需要注意的是，replicate-do-db和replicate-ignore-db为互斥选项，一般只需要一个即可。

server-id=2
relay-log=slave-relay-bin
relay-log-index=slave-relay-bin.index
#replicate-do-db=test

```
退出保存重启

* 连接 master 主服务器
```
#备注：
#master_host对应主服务器的IP地址。
#master_port对应主服务器的端口。
#master_log_file对应 show master status 显示的File列：master-bin.000001。
#master_log_pos对应 show master status 显示的Position列：154。

mysql> change master to master_host='192.168.2.19',master_port=3306,master_user='masterbackup',master_password='12345678',master_log_file='master-bin.000001',master_log_pos=154;
```

* 启动 slave 数据同步
`mysql> start slave;`

* 停止 slave 数据同步（若有需要）
`mysql> stop slave;`

* 查看 slave 信息
`mysql> show slave status\G;`
`Slave_IO_Running` 和 `Slave_SQL_Running` 都为 `yes`，则表示同步成功。

##### 测试
在主服务器上登陆 mysql，且进入 test 数据库，创建 test 表，且插入一条数据
用数据库管理工具（nacicat 等）操作方便
在从服务器上登陆 mysql，且进入 test 数据库，查看 test 表 是有数据，证明同步数据成功。

##### 解决错误
若在主从同步的过程中，出现其中一条语句同步失败报错了，则后面的语句也肯定不能同步成功了。
例如，主库有一条数据，而从库并没有这一条数据，然而，在主库执行了删除这一条数据的操作，那么从库没有这么一条数据就肯定删除不了，从而报错了。
在此时的从数据库的数据同步就失败了，因此后面的同步语句就无法继续执行。
这里提供的解决方法有两种
* 在从数据库中，使用 `SET` 全局 `sql_slave_skip_counter` 来跳过事件，跳过这一个错误，然后执行从下一个事件组开始。
```
#在从数据库上操作
mysql > stop slave;
mysql > set global sql_slave_skip_counter=1;
mysql > start slave;
```
* 在从数据库中，重新连上主数据库。这种操作会直接跳过中间的那些同步语句，可能会导致一些数据未同步过去的问题，但这种操作也是最后的绝招。最好就是令从数据库与主数据库的数据结构和数据都一致了之后，再来恢复主从同步的操作。
  
```
#在从数据库上操作
# master_log_file 和 master_log_pos 可能会不同，需要在主数据库中 show master status 来查看

mysql > stop slave;
mysql > change master to master_host='192.168.2.19',master_port=3306,master_user='masterbackup',master_password='12345678',master_log_file='master-bin.000001',master_log_pos=2050;
mysql > start slave;
```

mysql 数据库的主从同步就完成了，至于读写分离，我们可以通过程序来实现，简单的实现思想。
我们可以在主服务器创建一个数据库用户（出于安全，根据需求给予相应的权限）主要用于写操作，在程序中通过这一用户连接主数据库的只用于写操作而不用读操作。
在从服务器上创建一个数据库用户（出于安全，只给予读 `select` 的权限）主要用于读操作，在程序中通过这一用户连接从数据库即可。
