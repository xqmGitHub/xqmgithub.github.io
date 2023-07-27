---
title: mysql批量执行sql文件
date: 2018-02-25 17:43:09
categories: MySql
tags:
 - mysql
 - 批量执行
---
最近在做数据库迁移工作，需要批量执行MySQL的脚本文件，手工执行太麻烦
网上找了一下，还真有
<!--more-->
1、待执行的sql文件为1.sql、2.sql、3.sql、4.sql等
2、写一个batch.sql文件：

```
source 1.sql;
source 2.sql;
source 3.sql;
source 4.sql;
```
3、在mysql下执行source batch.sql;

注意路径问题。
