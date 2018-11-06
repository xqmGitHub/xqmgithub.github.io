---
title: Redis 入门 - 1（基本 key 操作）
top: 0
date: 2018-11-06 15:06:20
categories: Redis
tags:
 - redis
 - key
---

### **基本 key-value 操作**
Redis 的基础应用
<!--more-->
#### Key
Redis 的基础

* 获取 Key
```
// ？、*、[]、\x
KEYS [正则表达式]

// 获取所有键（不建议在生产上执行此命令）
KEYS *

// 获取所有以 post_xxxx 开头的 key
KEYS post_*
```

* 判断 Key 是否存在
```
// 存在返回整数类型 1，不存在则返回 0
EXISTS key_name
```

* 删除 Key 
```
// 返回删除键的个数（整数类型）
DEL key_name
```
    注意，DEL 不支持通配符，因此如果需要批量删除需结合 Linux 管道命令实现。

#### String
Redis 中最基本的数据类型，最大存储容量为 512 MB

* 赋值与取值
```
// 存储 key_name = "value"
SET key_name value

// 获取 key_name 的 "value"
// 注意：key_name 不存在时，返回空
GET key_name

// 同时赋值多个 key 或 获取 多个 key 的 value
MSET key_name value [key_name2 value2 ...]
MGET key_name [key_name2 ...]
```

* 末尾追加值
```
// 返回追加后字符串的总长度（Integer）
APPEND key_name value
```
    如果 key_name 不存在，则创建一个 key_name-value，相当于执行 SET key_name value

* 获取字符串长度
```
// 返回字符串的长度（Integer）
STRLEN key_name
```

#### Integer
可实现关系型数据库里的“自增”

* 递增与指定递增值
```
// 让 key_name 递增，并返回递增后的值（注意是 Integer）
INCR key_name   

// INCR 是 INCRBY key_name 1 的特例
INCRBY key_name [每次递增值]
```
    如果 key_name 不存在时，会创建 key_name 并赋值为 0，再执行 INCR 命令。因此，第一次递增后的结果是 1。

* 递减与指定递减值
```
// 递减
DECR key_name

DECRBY key_name [每次递减值]
```
    如果 key_name 不存在时，会创建 key_name 并赋值为 0，再执行 DECR 命令。因此，第一次递增后的结果是 -1。
    【引申】Redis 是原子操作，绝不会出现多个客户端同时执行 INCR 命令后，产生相同的递增或递减结果。

* 递增指定浮点数
```
// 每次递增一个双精度浮点数
INCRBYFLOAT key_name [每次递增浮点数]
```

### **总结**
![总结](http://p5tq1m3a9.bkt.clouddn.com/hexo_blog/static/redis_key.png)

[转](https://laravel-china.org/articles/8103/redis-introduction-1-basic-key-operation)