---
title: Mysql创建用户并授权
top: 0
date: 2018-06-25 14:46:20
categories: MySql
tags:
 - mysql
---
MySQL5.7 mysql.user表没有password字段改 authentication_string；
<!--more-->
### 创建用户

* 命令
```
CREATE USER 'username'@'host' IDENTIFIED BY 'password';
```
* PS 
	* `username` - 你将创建的用户名
	* `host` - 指定该用户在哪个主机上可以登陆，此处的"localhost"，是指该用户只能在本地登录，不能在另外一台机器上远程登录，如果想远程登录的话，将"localhost"改为"%"，表示在任何一台电脑上都可以登录;也可以指定某台机器可以远程登录;
	* `password` - 该用户的登陆密码,密码可以为空,如果为空则该用户可以不需要密码登陆服务器。

* 例子
```
CREATE USER 'test'@'localhost' IDENTIFIED BY '123456';
CREATE USER 'test1'@'localhost' IDENTIFIED BY '';
```

### 授权

* 命令
```
GRANT privileges ON db_name.tablename TO 'username'@'host'

GRANT ALL privileges on db_name.* to username@'%' with grant option; #授权(MySQL8.0版本)
```
* PS:
	* `privileges` - 用户的操作权限,如`SELECT , INSERT , UPDATE `等.如果要授予所的权限则使用ALL.; 
	* `db_name` - 数据库名,`tablename`-表名,如果要授予该用户对所有数据库和表的相应操作权限则可用\* 表示, 如\*
	*  `host` - 指定该用户在哪个主机上可以登陆，此处的"localhost"，是指该用户只能在本地登录，不能在另外一台机器上远程登录，如果想远程登录的话，将"localhost"改为"%"，表示在任何一台电脑上都可以登录;也可以指定某台机器可以远程登录;

* 例子
```
GRANT SELECT, INSERT ON demo.* TO 'test'@'localhost';
```
### 刷新系统权限表

```
flush privileges;
```
### 查看用户的授权

```
show grants for dog@localhost;
```
* PS 
GRANT USAGE:mysql usage权限就是空权限，默认create user的权限，只能连库，啥也不能干.

###  删除用户

```
DROP USER 'username'@'host';
```


