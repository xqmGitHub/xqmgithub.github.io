---
title: 忘记mysql密码
top: 0
date: 2018-04-12 17:09:38
categories: MySql
tags: 
 - mysql
 - password
---
MySQL下创建新用户、新数据库、设定访问权限控制都需要用到root密码。万一把root密码忘了，该怎么办？
<!--more-->
### 安全模式重置法
基本的思路是，以安全模式启动mysql，这样不需要密码可以直接以root身份登录，然后重设密码。
先，我们停掉MySQL服务：`sudo service mysql stop`
以上命令适用于Ubuntu和Debian。CentOS、Fedora和RHEL下使用mysqld替换mysql。
以安全模式启动MySQL：
`sudo mysqld_safe --skip-grant-tables --skip-networking &`
注意我们加了`--skip-networking`，避免远程无密码登录 MySQL。
这样我们就可以直接用root登录，无需密码：
`mysql -u root`
接下来重设密码：

```
mysql> use mysql; 
mysql> update user set password=PASSWORD("mynewpassword") where User='root';
mysql> flush privileges;
```
`flush privileges;`是刷新权限

注意，命令后需要加分号。
重设完毕后，退出
`mysql > quit`
然后重启 MySQL 服务：
`service mysql restart`
同样，以上命令适用于Ubuntu和Debian，Centos、Fedora和RHEL需要用`mysqld`替换`mysql`。

现在可以尝试用新密码登录了：
`mysql -u root -p`
再提示输入密码就可以了

### 修改MySQL的登录设置
这是在centos下的
`vim /etc/my.cnf`
在[mysqld]的段中加上一句：
`skip-grant-tables`
例如：
```
[mysqld]
skip-grant-tables
datadir=/var/lib/mysql
socket=/var/lib/mysql/mysql.sock
user=mysql
```
保存并且退出(ESC后输入`:wq`，表示保存并退出)。
重新启动mysqld:`service mysqld restart`
登录并修改MySQL的root密码
`mysql -u root`

接下来重设密码：
```
mysql> use mysql; 
mysql> update user set password=PASSWORD("mynewpassword") where User='root'; 
mysql> flush privileges;
```
退出
记得将MySQL的登录设置修改回来
将刚才在[mysqld]的段中加上的`skip-grant-tables`删除
保存并且退出
重启MySql：`service mysqld restart`


这里有个坑：由于mysql版本不同，可能user表的字段也是不相同的，比如在5.7版本中，验证密码字段不是叫`password` 而是 `authentication_string`，在修改密码的时候就需要修改字段了。