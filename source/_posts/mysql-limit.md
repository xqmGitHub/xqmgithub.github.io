---
title: limit分页查询性能问题
top: 0
date: 2020-01-04 14:48:54
categories: Mysql
tags:
 - limit
 - mysql
---

分页查询时，我们会在 `LIMIT` 后面传两个参数，一个是偏移量（`offset`），一个是获取的条数（`limit`）。当偏移量很小时，查询速度很快，但是当 `offset` 很大时，查询速度就会变慢。

MySQL Limit 语法格式：

```mysql
SELECT * FROM table LIMIT [offset,] rows | rows OFFSET offset
```

假设有一张 300w 条数据的表，对其进行分页查询。

```mysql
select * from tbl limit 1, 10		// 31.6ms
select * from tbl limit 10, 10		// 34.9ms
select * from tbl limit 100, 10		// 35.6ms
select * from tbl limit 1000, 10	// 38.3ms
select * from tbl limit 10000, 10	// 5561ms
select * from tbl limit 100000, 10	// 60.6s
select * from tbl limit 1000000, 10	// 272.3s
```

LIMIT分页查询的时间与偏移量值成正比。当偏移量越大时，查询时间越长。这种情况，会随着业务的增加，数据的增多，会越发的明显。那么，如何优化这种情况呢？答案是，覆盖索引。

<!--more-->

**优化思路**

对于LIMIT分页查询的性能优化，主要思路是利用覆盖索引字段定位数据，然后再取出内容。

* #### 子查询分页方式

```mysql
SELECT * FROM tbl
WHERE id >= (SELECT id FROM tbl limit 100000, 1)
LIMIT 20  // 55ms
```

子查询分页方式，首先通过子查询和覆盖索引定位到起始位置ID，然后再取所需条数的数据。

缺点是，不适用于结果集不以ID连续自增的分页场景。在复杂分页场景，往往需要通过过滤条件，筛选到符合条件的ID，此时的ID是离散且不连续的。如果使用上述的方式，并不能筛选出目标数据。

**改造版**

```mysql
SELECT t1.* FROM tbl t1
WHERE t1.id in (SELECT t2.id from (SELECT id FROM tbl limit 100000, 10) as t2)  // 53.8ms
```

查询效率很高。但是，这种写法比较繁琐。我们可以使用下面的  `join`  分页方式，达到相同的优化效果。实际上，两者的原理是相同的。

* #### join 分页方式

```mysql
SELECT * FROM tbl t1 
JOIN (SELECT id from tbl WHERE status=1 
limit 100000, 10) t2
ON t1.id = t2.id  // 53.3 ms
```

这条SQL是，通过自连接与`join`定位到目标 `ids`，然后再将数据取出。在定位目标 `ids`时，由于 `SELECT`的元素只有主键 `ID`，且`status` 存在索引，因此MySQL只需在索引中，就能定位到目标 `ids`，不用在数据文件上进行查找。因而，查询效率非常高。

#### 覆盖索引（Cover Index）

> 如果索引包含所有满足查询需要的数据的索引成为覆盖索引(Covering Index)，也就是平时所说的不需要回表操作。

简单的说，覆盖索引覆盖所有需要查询的字段（大于或等于所查询的字段）。MySQL可以通过索引获取查询数据，因而不需要读取数据行。

**覆盖索引的好处：**
* 索引大小远小于数据行大小。因而，如果只读取索引，则能极大减少对数据访问量。
* 索引按顺序储存。对于IO密集型的范围查询会比随机从磁盘读取每一行数据的IO要少。
* 避免对主键索引的二次查询。二级索引的叶子节点包含了主键的值，如果二级索引包含所要查询的值，则能避免二次查询主键索引（聚簇索引，聚簇索引既存储了索引，也储存了值）。

#### 总结
通过利用覆盖索引，能极大的优化了Limit分页查询的效率。在真正的实践中，除了使用覆盖索引，优化查询速度外，我们还可以使用 Redis 缓存，将热点数据进行缓存储存。

也可以根据应用场景来选择限制分页，即在不影响阅读体验的前提下，只允许用户可以查看前几千条的数据。