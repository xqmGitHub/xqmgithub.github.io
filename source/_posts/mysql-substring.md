---
title: MySQL字符串函数substring：字符串截取
id: 51
categories:
  - MySql
date: 2017-01-10 16:15:04
tags:
 - substring
 - 字符串截取
---

 **MySQL 字符串截取函数：left(), right(), substring(), substring_index()。还有 mid(), substr()。其中，mid(), substr() 等价于 substring() 函数，substring() 的功能非常强大和灵活。**
<!--more-->
**1\. 字符串截取：left(str, length)**
`select left('example.com', 3);`
+-------------------------+
| left('example.com', 3) |
+-------------------------+
| exa |
+-------------------------+

**2\. 字符串截取：right(str, length)**
` select right('example.com', 3);`
+--------------------------+
| right('example.com', 3) |
+--------------------------+
| com |
+--------------------------+

实例：
```
-- 查询某个字段后两位字符
select right(last3, 2) as last2 from historydata limit 10;

-- 从应该字段取后两位字符更新到另外一个字段
update `historydata` set `last2`= right(last3, 2);
```
**3\. 字符串截取：substring(str, pos); substring(str, pos, len)**

3.1 从字符串的第 4 个字符位置开始取，直到结束。
` select substring('example.com', 4);`
+------------------------------+
| substring('example.com', 4) |
+------------------------------+
| ple.com |
+------------------------------+

3.2 从字符串的第 4 个字符位置开始取，只取 2 个字符。
`mysql&gt; select substring('example.com', 4, 2);`
+---------------------------------+
| substring('example.com', 4, 2) |
+---------------------------------+
| pl |
+---------------------------------+

3.3 从字符串的第 4 个字符位置（倒数）开始取，直到结束。
`mysql&gt; select substring('example.com', -4);`
+-------------------------------+
| substring('example.com', -4) |
+-------------------------------+
| .com |
+-------------------------------+

3.4 从字符串的第 4 个字符位置（倒数）开始取，只取 2 个字符。
`select substring('example.com', -4, 2);`
+----------------------------------+
| substring('example.com', -4, 2) |
+----------------------------------+
| .c |
+----------------------------------+
我们注意到在函数 substring(str,pos, len)中， pos 可以是负值，但 len 不能取负值。

**4\. 字符串截取：substring_index(str,delim,count)**

4.1 截取第二个 '.' 之前的所有字符。
`select substring_index('www.example.com', '.', 2);`
+------------------------------------------------+
| substring_index('www.example.com', '.', 2) |
+------------------------------------------------+
| www |
+------------------------------------------------+

4.2 截取第二个 '.' （倒数）之后的所有字符。
`select substring_index('www.example.com', '.', -2);`
+-------------------------------------------------+
| substring_index('www.example.com', '.', -2) |
+-------------------------------------------------+
| com.cn |
+-------------------------------------------------+

4.3 如果在字符串中找不到 delim 参数指定的值，就返回整个字符串
`select substring_index('www.example.com', '.coc', 1);`
+---------------------------------------------------+
| substring_index('www.example.com', '.coc', 1) |
+---------------------------------------------------+
| www.example.com |
+---------------------------------------------------+


来源：转载