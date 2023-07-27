---
title: mysql-select-repeat
top: 0
date: 2018-09-29 15:25:59
categories: MySql
tags: 
  - mysql
  - 重复记录
---
MYSQL数据库经常会遇到有重复记录的问题，需要查看哪些重复了。这里有几个方法，记录一下方便以后查看。

<!--more-->

### 查找全部重复记录
* 查找全部重复记录(可查询多个重复字段，用`distinct`的话就不可以)
```MySql
SELECT * FROM 表 WHERE 重复字段 IN (SELECT 重复字段 FROM表 GROUP BY 重复字段 HAVING COUNT(id)>1) ORDER BY 重复字段
```

* 过滤重复记录(只显示一条 id最大的)
```MySql
SELECT * FROM 表 WHERE id IN (SELECT MAX(id) FROM 表 GROUP BY 重复字段)
```

### 删除重复记录
* 删除全部重复记录（慎用）
```MySql
DELETE 表 WHERE 重复字段 IN (SELECT 重复字段 FROM 表 GROUP BY 重复字段 HAVING COUNT(id)>1)
```

* 保留一条(保留id最大的)
```MySql
DELETE 表 WHERE id NOT IN (SELECT MAX(id) FROM 表 GROUP BY 重复字段)
```
