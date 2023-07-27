---
title: MySQL随机获取数据
id: 511
categories:
  - MySql
tags:
---

&nbsp;

`SELECT * FROM `table` ORDER BY RAND() LIMIT 5;`

就可以随机查询5条数据。但是这样效率非常低，如果几万或百万时就很明显。

`SELECT *`
`FROM `table` AS t1 JOIN (SELECT ROUND(RAND() * (SELECT MAX(id) FROM `table`)) AS id) AS t2`
`WHERE t1.id &gt;= t2.id`
`ORDER BY t1.id ASC LIMIT 5;`

优化过后就