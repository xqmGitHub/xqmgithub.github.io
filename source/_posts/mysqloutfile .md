---
title: mysql把查询结果保存为sql文件
id: 275
categories:
  - MySql
date: 2017-03-10 15:31:35
tags:
 - outfile 
---

有时候需要从表中抽取一部分数据，然后导出来，没必要用导出命令是mysqldump 导出整张表

下面两个指令就可以解决这个问题了
<!--more-->
在服务器端可以用select into outfile 命令把查询结果保存到一个可写的目录中：

使用Navicat for MySql等也适用

`select * from article limit 150 into outfile '/test/article.sql';`

然后把article.sql文件下载到本地电脑上，通过load data local infile into table 命令来导入这个查询结果文件：

`load data local infile "D:/study/article.sql" into table article;`

这样就阔以了。