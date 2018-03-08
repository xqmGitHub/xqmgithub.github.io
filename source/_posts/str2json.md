---
title: js中将字符串转换成json的三种方式
id: 600
categories:
  - JavaScript
date: 2017-11-08 15:46:06
tags:
 - json
 - JavaScript
---

将字符串转换成json对象，IE不支持通过JSON.parse将字符串转换成JSON对象的方法。

让人不由得认为IE的基本核心是无法使用JSON.parse的所以只能退而求其次采用老版本的方法
<!--more-->
1、**eval方式解析**，恐怕这是最早的解析方式了。如下：

`function strToJson(str){
var json = eval('(' + str + ')');
return json;
} `

2、**new Function形式**，比较怪异哦。如下

`function strToJson(str){
var json = (new Function("return " + str))();
return json;
} `

3、**使用全局的JSON对象**，如下：

`function strToJson(str){
return JSON.parse(str);
} `



转：http://www.jb51.net/article/25987.htm