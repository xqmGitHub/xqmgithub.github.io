---
title: mysql-rank
top: 0
date: 2018-04-13 15:46:00
categories: MySql
tags:
 - mysql
 - 排名
 - 名次
---
MySQL中没有Rank排名函数，当我们需要查询排名时，只能使用MySQL数据库中的基本查询语句来查询普通排名。
<!--more-->
```
mysql> select * from score;
+----+-------+             
| id | score |             
+----+-------+             
|  1 |    66 |             
|  2 |    80 |             
|  3 |    90 |             
|  4 |    88 |             
|  5 |    89 |             
|  6 |    60 |             
|  7 |    90 |             
|  8 |    99 |             
|  9 |    98 |             
+----+-------+             
9 rows in set (0.00 sec)   
```
排序后的结果
```
+-------+------+
| Score | Rank |
+-------+------+
|    99 |    1 |
|    98 |    2 |
|    90 |    3 |
|    90 |    3 |
|    89 |    4 |
|    88 |    5 |
|    80 |    6 |
|    66 |    7 |
|    60 |    8 |
+-------+------+
9 rows in set (0.00 sec)
```


### 方案一
```
SELECT
  Score,
  @rank := @rank + (@prev <> (@prev := Score)) Rank
FROM
  Scores,
  (SELECT @rank := 0, @prev := -1) init
ORDER BY Score desc
```

### 方案二
```
SELECT
  Score,
  (SELECT count(distinct Score) FROM Scores WHERE Score >= s.Score) Rank
FROM Scores s
ORDER BY Score desc
```
### 方案三
```
SELECT
  Score,
  (SELECT count(*) FROM (SELECT distinct Score s FROM Scores) tmp WHERE s >= Score) Rank
FROM Scores
ORDER BY Score desc
```
### 方案四

```
SELECT s.Score, count(distinct t.score) Rank
FROM Scores s JOIN Scores t ON s.Score <= t.score
GROUP BY s.Id
ORDER BY s.Score desc
```


