---
title: mysql中修改表字段名/字段长度/字段类型详解
id: 438
categories:
  - MySql
date: 2017-05-26 13:49:09
tags:
 - ALTER TABLE
---
在mysql中我们对数据表字段的修改命令只要使用ALTER就可以了
<!--more-->
**1.增加一个字段**
```
-- 增加一个字段，默认为空
ALTER TABLE user add COLUMN new1 VARCHAR(20) DEFAULT NULL;
-- 增加一个字段，默认不能为空
ALTER TABLE user add COLUMN new2 VARCHAR(20) NOT NULL;
```

**2.删除一个字段**
```
-- 删除一个字段
ALTER TABLE user DROP COLUMN new2;
```

**3.修改一个字段**
```
-- 修改一个字段的类型
ALTER TABLE user MODIFY new1 VARCHAR(10); 
-- 修改一个字段的名称，此时一定要重新
ALTER TABLE user CHANGE new1 new4 int;

-- 主键
ALTER TABLE tabelname add new_field_id int(5) unsigned default 0 not null auto_increment ,add primary key (new_field_id);

-- 增加一个新列
ALTER TABLE t2 add d timestamp;
ALTER TABLE infos add ex tinyint not null default 0;

-- 删除列
ALTER TABLE t2 drop column c;`

-- 重命名列
ALTER TABLE t1 change a b integer;`

-- 改变列的类型
ALTER TABLE t1 change b b bigint not null;
ALTER TABLE infos change list list tinyint not null default 0;

-- 重命名表
ALTER TABLE t1 rename t2;

-- 加索引
ALTER TABLE tablename change depno depno int(5) not null;
ALTER TABLE tablename add index 索引名 (字段名1[，字段名2 …]);
ALTER TABLE tablename add index emp_name (name);

-- 加主关键字的索引
ALTER TABLE tablename add primary key(id);

-- 加唯一限制条件的索引
ALTER TABLE tablename add unique emp_name2(cardnumber);

-- 删除某个索引
ALTER TABLE tablename drop index emp_name;

-- 增加字段：
ALTER TABLE table_name ADD field_name field_type;

-- 修改原字段名称及类型：
ALTER TABLE table_name CHANGE old_field_name new_field_name field_type;

-- 删除字段：
ALTER TABLE table_name DROP field_name;

-- mysql修改字段长度
ALTER TABLE 表名 modify column 字段名 类型;
```