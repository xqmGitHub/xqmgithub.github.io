---
title: PHP三元运算符?:的简写
top: 0
date: 2018-12-03 14:18:50
categories: PHP
tags:
 - 三元运算符
---

在PHP中三元运算符可以简化书写，使程序更加优雅
从**PHP5.3**以后提供了更加简洁的写法
<!--more-->

```
$str = 'a';
echo $str ? $str: '哈哈哈';
```

表达式` (expr1) ? (expr2) : (expr3) `在 expr1 求值为 TRUE 时的值为 expr2，在 expr1 求值为 FALSE 时的值为 expr3。 
自 **PHP 5.3** 起，可以省略三元运算符中间那部分。表达式 `expr1 ?: expr3 `在 expr1 求值为 TRUE 时返回 expr1，否则返回 expr3。 

上面可以简化为:
```
$str = 'a';
echo $str ?: '哈哈哈';
```


