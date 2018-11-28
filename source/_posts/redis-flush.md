---
title: redis 清空数据
top: 0
date: 2018-11-28 17:55:20
categories: Redis
tags:
 - redis
 - flush
---

* flushall ——> 清空整个 Redis 服务器的数据(删除所有数据库的所有 key )

* flushdb ——> 清空当前数据库中的所有 key

这两个命令要慎用，毕竟数据无价，清空了就没了
在测试的时候 清除测试数据很方便