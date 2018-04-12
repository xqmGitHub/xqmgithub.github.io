---
title: MySQL存储引擎InnoDB与Myisam的区别
top: 0
date: 2018-04-10 16:01:40
categories: MySql
tags: 
 - mysql
 - 存储引擎
 - InnoDB
 - Myisam
---
MySQL有多种存储引擎，每种存储引擎有各自的优缺点，可以择优选择使用：MyISAM、InnoDB、MERGE、MEMORY(HEAP)、BDB(BerkeleyDB)、EXAMPLE、FEDERATED、ARCHIVE、CSV、BLACKHOLE。
<!--more-->
MySQL有多种存储引擎，每种存储引擎有各自的优缺点，可以择优选择使用：

MyISAM、InnoDB、MERGE、MEMORY(HEAP)、BDB(BerkeleyDB)、EXAMPLE、FEDERATED、ARCHIVE、CSV、BLACKHOLE。

MySQL支持数个存储引擎作为对不同表的类型的处理器。MySQL存储引擎包括处理事务安全表的引擎和处理非事务安全表的引擎：

* MyISAM管理非事务表。它提供高速存储和检索，以及全文搜索能力。MyISAM在所有MySQL配置里被支持，它是默认的存储引擎，除非你配置MySQL默认使用另外一个引擎。

* MEMORY存储引擎提供“内存中”表。MERGE存储引擎允许集合将被处理同样的MyISAM表作为一个单独的表。就像MyISAM一样，MEMORY和MERGE存储引擎处理非事务表，这两个引擎也都被默认包含在MySQL中。

 注释：MEMORY存储引擎正式地被确定为HEAP引擎。

* InnoDB和BDB存储引擎提供事务安全表。BDB被包含在为支持它的操作系统发布的MySQL-Max二进制分发版里。InnoDB也默认被包括在所 有MySQL 5.1二进制分发版里，你可以按照喜好通过配置MySQL来允许或禁止任一引擎。

* EXAMPLE存储引擎是一个“存根”引擎，它不做什么。你可以用这个引擎创建表，但没有数据被存储于其中或从其中检索。这个引擎的目的是服务，在 MySQL源代码中的一个例子，它演示说明如何开始编写新存储引擎。同样，它的主要兴趣是对开发者。

* NDB Cluster是被MySQL Cluster用来实现分割到多台计算机上的表的存储引擎。它在MySQL-Max 5.1二进制分发版里提供。这个存储引擎当前只被Linux, Solaris, 和Mac OS X 支持。在未来的MySQL分发版中，我们想要添加其它平台对这个引擎的支持，包括Windows。

* ARCHIVE存储引擎被用来无索引地，非常小地覆盖存储的大量数据。

* CSV存储引擎把数据以逗号分隔的格式存储在文本文件中。

* BLACKHOLE存储引擎接受但不存储数据，并且检索总是返回一个空集。

* FEDERATED存储引擎把数据存在远程数据库中。在MySQL 5.1中，它只和MySQL一起工作，使用MySQL C Client API。在未来的分发版中，我们想要让它使用其它驱动器或客户端连接方法连接到另外的数据源。

**比较常用的是MyISAM和InnoBD**


| | MyISAM | InnoDB|
|---|---|---|
| 构成上的区别| 每个MyISAM在磁盘上存储成三个文件。第一个文件的名字以表的名字开始，扩展名指出文件类型。  .frm文件存储表定义。 数据文件的扩展名为.MYD (MYData)。  索引文件的扩展名是.MYI (MYIndex)。| 基于磁盘的资源是InnoDB表空间数据文件和它的日志文件，InnoDB 表的大小只受限于操作系统文件的大小，一般为 2GB|
| 事务处理上方面| MyISAM类型的表强调的是性能，其执行数度比InnoDB类型更快，但是不提供事务支持| InnoDB提供事务支持事务，外部键（foreign key）等高级数据库功能 |
| SELECT,UPDATE,INSERT,Delete操作| 如果执行大量的SELECT，MyISAM是更好的选择| 1.如果你的数据执行大量的`INSERT`或`UPDATE`，出于性能方面的考虑，应该使用InnoDB表。 2.`DELETE   FROM table`时，InnoDB不会重新建立表，而是一行一行的删除。3.`LOAD TABLE FROM MASTER`操作对InnoDB是不起作用的，解决方法是首先把InnoDB表改成MyISAM表，导入数据后再改成InnoDB表，但是对于使用的额外的InnoDB特性（例如外键）的表不适用|
|  对`AUTO_INCREMENT`的操作| 每表一个AUTO_INCREMEN列的内部处理。MyISAM为`INSERT`和`UPDATE`操作自动更新这一列。这使得AUTO_INCREMENT列更快（至少10%）。在序列顶的值被删除之后就不能再利用。(当AUTO_INCREMENT列被定义为多列索引的最后一列，可以出现重使用从序列顶部删除的值的情况）。 AUTO_INCREMENT值可用ALTER TABLE或myisamch来重置.对于AUTO_INCREMENT类型的字段，InnoDB中必须包含只有该字段的索引，但是在MyISAM表中，可以和其他字段一起建立联合索引.更好和更快的auto_increment处理| 如果你为一个表指定AUTO_INCREMENT列，在数据词典里的InnoDB表句柄包含一个名为自动增长计数器的计数器，它被用在为该列赋新值。自动增长计数器仅被存储在主内存中，而不是存在磁盘上.关于该计算器的算法实现，请参考AUTO_INCREMENT列在InnoDB里如何工作|
|  表的具体行数| `select count(*) from table`,MyISAM只要简单的读出保存好的行数，注意的是，当`count(*)`语句包含   `where`条件时，两种表的操作是一样的| InnoDB 中不保存表的具体行数，也就是说，执行`select count(*) from table`时，InnoDB要扫描一遍整个表来计算有多少行|
|   锁| 表锁|  提供行锁(locking on row level)，提供与 Oracle 类型一致的不加锁读取(non-locking read in SELECTs)，另外，InnoDB表的行锁也不是绝对的，如果在执行一个SQL语句时MySQL不能确定要扫描的范围，InnoDB表同样会锁全表， 例如`update table set num=1 where name like "%aaa%"`|
**MySQL存储引擎MyISAM与InnoDB如何选择？ **
虽然MySQL里的存储引擎不只是MyISAM与InnoDB这两个，但常用的就是它俩了。可能有站长并未注意过MySQL的存储引擎，其实存储引擎也是数据库设计里的一大重要点，那么博客系统应该使用哪种存储引擎呢？
下面我们分别来看两种存储引擎的区别。

一、InnoDB支持事务，MyISAM不支持，这一点是非常之重要。事务是一种高级的处理方式，如在一些列增删改中只要哪个出错还可以回滚还原，而MyISAM就不可以了。

二、MyISAM适合查询以及插入为主的应用，InnoDB适合频繁修改以及涉及到安全性较高的应用

三、InnoDB支持外键，MyISAM不支持

四、MyISAM是默认引擎，InnoDB需要指定

五、InnoDB不支持FULLTEXT类型的索引

六、InnoDB中不保存表的行数，如`select count(*) from table`时，InnoDB需要扫描一遍整个表来计算有多少行，但是MyISAM只要简单的读出保存好的行数即可。注意的是，当count(*)语句包含where条件时MyISAM也需要扫描整个表

七、对于自增长的字段，InnoDB中必须包含只有该字段的索引，但是在MyISAM表中可以和其他字段一起建立联合索引

八、清空整个表时，InnoDB是一行一行的删除，效率非常慢。MyISAM则会重建表

九、InnoDB支持行锁（某些情况下还是锁整表，如 `update table set a=1 where user like '%lee%'`)

**MyISAM：**

每个MyISAM在磁盘上存储成三个文件。第一个文件的名字以表的名字开始，扩展名指出文件类型。.frm文件存储表定义。数据文件的扩展名为.MYD (MYData)。

MyISAM表格可以被压缩，而且它们支持全文搜索。不支持事务，而且也不支持外键。如果事物回滚将造成不完全回滚，不具有原子性。在进行updata时进行表锁，并发量相对较小。如果执行大量的SELECT，MyISAM是更好的选择。

MyISAM的索引和数据是分开的，并且索引是有压缩的，内存使用率就对应提高了不少。能加载更多索引，而Innodb是索引和数据是紧密捆绑的，没有使用压缩从而会造成Innodb比MyISAM体积庞大不小

MyISAM缓存在内存的是索引，不是数据。而InnoDB缓存在内存的是数据，相对来说，服务器内存越大，InnoDB发挥的优势越大。

优点：查询数据相对较快，适合大量的select，可以全文索引。

缺点：不支持事务，不支持外键，并发量较小，不适合大量update

**InnoDB：**

这种类型是事务安全的。.它与BDB类型具有相同的特性,它们还支持外键。InnoDB表格速度很快。具有比BDB还丰富的特性,因此如果需要一个事务安全的存储引擎，建议使用它。在update时表进行行锁，并发量相对较大。如果你的数据执行大量的INSERT或UPDATE，出于性能方面的考虑，应该使用InnoDB表。

优点：支持事务，支持外键，并发量较大，适合大量update

缺点：查询数据相对较快，不适合大量的select

对于支持事物的InnoDB类型的表，影响速度的主要原因是AUTOCOMMIT默认设置是打开的，而且程序没有显式调用BEGIN 开始事务，导致每插入一条都自动Commit，严重影响了速度。可以在执行sql前调用begin，多条sql形成一个事物（即使autocommit打开也可以），将大大提高性能。

基本的差别为：MyISAM类型不支持事务处理等高级处理，而InnoDB类型支持。

MyISAM类型的表强调的是性能，其执行数度比InnoDB类型更快，但是不提供事务支持，而InnoDB提供事务支持已经外部键等高级数据库功能。

说InnoDB不适合做count是不对的，MyISAM也是一样的慢，只不过MyISAM将正表的行数缓存起来，所以count整表很快，如果有查询条件，并且不是主键查询，那就没有什么区别，主键count慢的原因是innodb是按照主键组织的，按照主键count的时候，会加载数据

InnoDB的页式存储会使得InnoDB更容易做整表缓存和热备份
如果表索引很多，那么InnoDB的更新速度要大于MyISAM，因为InnoDB的辅助索引关联的是表的主键，是一个逻辑的值，而MyISAM的所有索引关联的是数据的物理位置，更新时有可能数据的物理位置发生变化，如果发生变化，那么所有的索引都要做更新
