---
title: JS判断字符串是否包含某字符串 indexOf()方法使用
id: 292
categories:
  - JavaScript
date: 2017-03-15 17:32:28
tags:
 - indexOf
---
**indexOf()方法可返回某个指定的字符串值在字符串中首次出现的位置。**
<!--more-->
语法：
`stringObject.indexOf(searchvalue,fromindex)`
| 参数| 描述|
|---|---|
| searchvalue	| 必需。规定需检索的字符串值。|
| fromindex| 可选的整数参数。规定在字符串中开始检索的位置.它的合法取值是0到stringObject.length-1。如省略该参数,则将从字符串的首字符开始检索。|

indexOf方法返回一个整数值,stringObject中的字符位置是从0开始的。如果没有找到子字符串，则返回 - 1。

```
var str = "Hello Word!";
alert(str.indexOf("Word")); //6
if(str.indexOf("Hello")!=-1){
    alert("包含");
}else{
    alert("不包含");
}
```
