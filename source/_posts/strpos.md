---
title: 'php 类似 js indexof与lastindexof 的方法 : strpos() strrpos()'
id: 134
categories:
  - PHP
date: 2017-02-17 16:25:16
tags:
 - strpos
 - strrpos
---
strpos()字符串在另一个字符串中第一次出现的位置。
strripos()字符串在另一个字符串中最后一次出现的位置。
<!--more-->
**PHP strpos() 函数**
strpos() 函数返回字符串在另一个字符串中第一次出现的位置。
如果没有找到该字符串，则返回 false。

语法

| 参数| 描述|
|---|---|
| string| 必需。规定被搜索的字符串。|
| find| 必需。规定要查找的字符。|
| start| 可选。规定开始搜索的位置。 |
```
strpos(string,find,start)

mb_strpos(string,find,start,charset)//截取中文 (charset 字符集 如utf-8，gb2312)
```
提示:该函数对大小写敏感。如需进行对大小写不敏感的搜索，请使用 stripos() 函数。

例子:


```
echo strpos("Hello world!","wo"); //输出：6
```

**PHP strripos() 函数**

strrpos() 函数查找字符串在另一个字符串中最后一次出现的位置。
如果成功，则返回位置，否则返回 false。

语法
```
strrpos(string,find,start)
```
| 参数| 描述|
|---|---|
| string| 必需。规定被搜索的字符串。|
| find| 必需。规定要查找的字符。|
| start| 可选。规定开始搜索的位置。 |
提示：该函数对大小写不敏感。如需进行大小写敏感的查找，请使用 strrpos()。

例子

```
echo strripos("Hello world!","WO"); //输出：6
```
