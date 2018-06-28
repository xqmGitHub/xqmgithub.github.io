---
title: tp5模型belongsTo和hasOne的区别
top: 0
date: 2018-06-28 14:00:37
categories: PHP
tags:
 - tp5
 - php
---
在使用tp5模型的ORM的时候出现belongsTo和hasOne都有表示一对一的关系，但是二者并不相同。
<!--more-->
以下举例说明两者的区别：
首先有user表 字段 id name password字段 
然后有user_address表 id user_id city字段
* 在User模型中关联user_address表的时候使用`hasOne`，因为在user表中没有关联两个表的外键

* 在UserAddress模型中关联user表的时候使用`belongsTo`，因为在user_address表中有关联两个表的外键user_id

