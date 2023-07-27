---
title: Redis 入门 - 2（散列 + 列表）
top: 0
date: 2018-11-06 15:51:23
categories: Redis
tags:
 - redis
 - hash
 - list
---
Hash、List 最基本的结构化数据类型

<!--more-->

### 散列（Hash）

> 散列，是种“键 + 字段 + 字段值”的数据结构。实际应用上，可以用它将一个“大块”的内容，分割为一个个的“小块”内容，进而提高效率和性能，减少运行时的资源浪费

所有散列命名均以 “H” 开头

* #### 设定与获取

```
// 设定散列的 key + field + value

// 注意：field_value 只能是字符串，当然不支持类型嵌套
HSET key_name field_name field_value

// 获取散列的 key with field
HGET key_name field_name
```

* #### 批量设定与批量获取

```
// 批量设定
HMSET key_name field_name1 field_value1 field_name2 field_value2 ...

// 批量获取
HMGET key_name field_name1 field_name2 ...
```

* #### 获取全部

```
// 获取 key_name 下的全部 fields 和 values
HGETALL key_name
```

* #### 判断字段是否存在

```
// 存在返回 1，否则返回 0（包括键不存在或字段不存在）
HEXISTS key_name field_name
```

* #### 当字段不存时设定

```php
// 不存在则设定 返回 1；存在则什么也不做，返回 0
HSETNX key_name field_name field_value
```

* #### 增加数字

```php
// 返回（Integer）增加后的数值。如果字段不存在，则创建，返回 1
HINCRBY key_name field_name 每次递增的数值
```

* #### 删除字段

```php
HDEL key_name field_name1 field_name2 ...
```

* #### 只获取字段名或字段值

```php
// 获取 key_name 下的所有字段名
HKEYS key_name

// 获取 key_name 下的所有字段值
HVALS key_name
```

* #### 获取字段数量

```php
// 返回字段的数量
HLEN key_name
```

### 列表

> 存储一个有序字符串列表，为双向链表，越接近两端的元素读取速度越快。实际应用上，可以用来表示“最新的XXX”、“新鲜事”、“日志”等场景，以突出列表的链表优势

* #### 增加元素

```php
// 这里的 key_name 可以理解为 list_name

// 向左边添加元素，返回增加元素后的列表长度（该命令具备批量添加）
LPUSH key_name value [value ...]

// 向右边添加元素，返回增加元素后的列表长度（该命令具备批量添加）
RPUSH key_name value [value ...]
```
    注意：多个 values 时，则顺次添加，且可以有相同 value 值

* #### 弹出元素
    注意：“弹出”后，该元素将从列表中消失。执行步骤为：先从列表中移除元素，后返回该元素。

```php
// 从左边移除一个元素，返回列表值
LPOP key_name

// 从右边移除一个元素，返回列表值
RPOP key_name
```
    可以实现栈和队列的功能：

```php
// 栈（Strack）
LPUSH my_strack A B C
LPOP my_strack  // C 弹出

// 队列（Queue）
LPUSH my_queue A B C
RPOP my_queue   // A 弹出
```

* #### 获取元素个数

```php
// 返回列表的长度
LLEN key_name
```

* #### 获取列表片段

```php
// 返回 start 至 end 间的所有元素，包括 end
LRANGE key_name start end   
```
    同时，也支持负索引，表示从右侧开始计算序列。 -1 代表最右侧元素，-2 代表最右侧倒数第二个元素
    注意：
    1.  如果 start 大于 end，则返回空列表：(empty list or set)
    2.  如果 end 大于实际值，则返回至最右侧元素
    3.  无 `RRANGE` 命令

* #### 删除元素

```php
// 删除 count 个值为 value 的元素
LREM key_name count value
```

* #### 获得/设置 指定索引的元素值

```php
// 返回索引 index 处的 value
LINDEX key_name index
```

    这样就可以将 list 当做数组来使用

```php
// 将索引为 index 的值设定为 value
LSET key_name index value
```

* #### 只保留列表指定片段

```php
// 用法同 LRANGE，但只保留指定范围内的元素
LTRIM key_name start end
```
    可以用来实现日志的管理，例如“动态日志”，只保留100条最新的动态日志记录，就可以：

```php
LPUSH logs value
LTRIM logs 0 100
```

* #### 向列表中插入元素

```php
// 先查找 find_value 的元素，再根据 BEFORE|AFTER 在 find_value 前或后插入 set_value 值，返回调整后的列表元素个数
LINSERT key_name BEFORE|AFTER find_value set_value
```

* #### 将元素从一个列表转到另一个列表

```php
// 从 form_key_name 列表的最右侧弹出一个元素，再在最左侧添加至 to_key_name 列表中
RPOPLPUSH from_key_name to_key_name
```

### 总结

![总结](http://p5tq1m3a9.bkt.clouddn.com/hexo_blog/static/redis2.png)

[转](https://laravel-china.org/articles/8103/redis-introduction-1-basic-key-operation)
