---
title: PHP页面转UTF-8编码问题
id: 78
categories:
  - PHP
date: 2017-01-13 17:41:33
tags:
 - 字符编码
---
**php页面中文乱码，那时因为字符编码问题，一行代码搞定**
<!--more-->
在代码开始出加入一行
```
header("Content-Type:text/html;charset=utf-8");
```
charset 字符编码 可换成相应的编码