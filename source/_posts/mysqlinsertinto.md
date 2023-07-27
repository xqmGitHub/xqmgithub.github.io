---
title: 将一个表的查询结果插入到另一个表中
id: 74
categories:
  - MySql
date: 2017-01-12 16:35:08
tags:
 - insert into 
---

**如果表存在（要注意两个表中的字段数要一样）：**
insert into tab1 select * from tab2;
**如果表不存在：**
create table tab1 as select * from tab2;