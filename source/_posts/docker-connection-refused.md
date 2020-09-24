---
title: "使用 PHP 连接 docker 容器中的 MySQL 、 Redis 时 报错：Connection refused"
top: 0
date: 2019-11-27 09:39:23
categories: PHP
tags:
- docker
- Connection refused
---
环境时基于 docker-compose 管理的 PHP 和 MySQL 服务
使用 PHP 连接 docker 容器中的 MySQL 和 Redis 时，报错：Connection refused，也就是在代码中使用 MySql Redis 会报错
<!--more-->
连接 MySQL 测试代码

```php
<?php
try {
    $pdo = new PDO('mysql:dbname=test;host=127.0.0.1;charset=utf8mb4;port=3306', 'root', '123456');
    echo "Connection to server sucessfully";
}catch(PDOException $pe) {
    echo $pe->getMessage();
}
```

报错

`SQLSTATE[HY000] [2002] Connection refused`

连接 Redis 测试代码

```php
<?php
try {
    $redis = new Redis();
    $redis->connect('127.0.0.1', 6379);
    echo "Connection to server sucessfully";
}catch(Exception $e) {
    echo $e->getMessage();
}
```

报错

`Connection refused`

但是在宿主机用 Navicat 可以连接 MySql 各种操作都没问题，用 RedisDesktopManager 连接 Redis 也没问题

后来在网上找到了原因
主要是对 Docker 容器的隔离机制理解不够，其实每个容器之间都是隔离的，有相互依赖的服务，需要进行显示的关联，比如使用选项 --link
简单来说，容器之间相互隔绝，在进行了端口映射之后，宿主机可以通过 127.0.0.1:6379 访问 Redis ，127.0.0.1:3306 访问 MySql ，但 PHP 容器不行

**测试连接 MySQL 的代码其实是运行在 PHP 对应的容器里，而 MySQL 服务是在它自己对应的容器里，当我们的 host 填写 127.0.0.1 时候，其实对应的是 PHP 容器里面，所以不可能找到对应的服务，从而引起上面拒绝连接的错误。Redis 同理。**
* 其实容器之间关联之后，可以通过容器名进行连接
* MySQL 服务对应的容器名是 mysql，PHP 容器与它关联的名字也是 MySQL，所以把 127.0.0.1 改成 mysql（对应的容器名） 再进行连接即可！

 