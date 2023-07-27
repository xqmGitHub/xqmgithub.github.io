---
title: centos7 安装 mysql5.7
top: 0
date: 2020-07-04 14:36:41
categories: MySql
tags:
- mysql
---

##### 安装 mysql-server

* 下载并安装 mysql yum 源
```
wget -i -c http://dev.mysql.com/get/mysql57-community-release-el7-10.noarch.rpm
yum -y install mysql57-community-release-el7-10.noarch.rpm
```

运行查看可安装的mysql的命令：`yum repolist all| grep mysql`
可以修改 yum 配置（`enabled=1` 想要安装哪个版本就在哪个版本的后面把 0 换成 1，因为默认是最新版，所以需要把最新版的 1 换成 0，5.7 的换为 1）
路径 `/etc/yum.repos.d/mysql-community.repo`
这里下载的是 5.7 版本的源就不要修改了

* 安装 mysql-server
`yum -y install mysql-community-server`

<!--more-->

##### mysql 初始化安装的一些配置

* 启动 mysql-serer 
`systemctl start mysqld`

* 开机自启
`systemctl enable mysqld`

* 查看是否启动成功，即是否存在 3306 端口
`netstat -tnlp | grep 3306`

* 查询 root 密码
`grep "password" /var/log/mysqld.log`

* 登录到 mysql
`mysql -uroot -p`

* 首次操作要求重置密码,必须大小写特殊字符组成
`mysql> ALTER USER 'root'@'localhost' IDENTIFIED BY '新密码';`

* 配置使用弱密码 (不想设置复杂的密码)
  mysql 升级到 5.7 版本后，对密码进行了加强，默认密码策略要求密码必须是大小写字母数字特殊字母的组合，至少8位
  `mysql.user` 中的 `password` 字段修改为了 `authentication_string`
    
  增加了密码验证插件 查看当前密码规则 
  ```
  mysql> show variables like 'validate_password%';  
  +--------------------------------------+--------+
  | Variable_name                        | Value  |
  +--------------------------------------+--------+
  | validate_password_check_user_name    | OFF    |
  | validate_password_dictionary_file    |        |
  | validate_password_length             | 8      | 密码最小长度
  | validate_password_mixed_case_count   | 1      | 密码大写小写混合个数
  | validate_password_number_count       | 1      | 密码数字个数
  | validate_password_policy             | MEDIUM | 密码检查等级
  | validate_password_special_char_count | 1      | 密码特殊字符个数
  +--------------------------------------+--------+
  ```

  解决办法有两种
  一种是改验证规则
  ```
  mysql> set global validate_password_policy=0;
  mysql> set global validate_password_mixed_case_count=0;
  mysql> set global validate_password_number_count=3;
  mysql> set global validate_password_special_char_count=0;
  ```
    
    
  二是直接卸载这个密码验证插件
  `mysql> uninstall plugin validate_password;`
  
    
* 授权远程访问 % 表示所有主机都可以访问
`mysql> grant all privileges on *.* to 'root'@'%' identified by '自己的密码' with grant option;`

* 刷新权限信息
`mysql> flush privileges;`

> 最后要注意防火墙开放3306端口 不然链接不上