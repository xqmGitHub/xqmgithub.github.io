---
title: JS中获取当前日期（年-月-日）
id: 423
categories:
  - JavaScript
date: 2017-05-20 17:01:57
tags:
 - date
---
需要获取当前的日期，但是js有没有像PHP那样有date('Y-m-d',time())就可以获取
<!--more-->
所以就只能自己拼接

```
// 获取当前日期
var date = new Date();
// 获取当前月份（月份是从0开始，所以要加1）
var nowMonth = date.getMonth() + 1;
// 获取当前是几号
var strDate = date.getDate();
// 添加分隔符“-”
var seperator = "-";
// 对月份进行处理，1-9月在前面添加一个“0”
if (nowMonth >= 1 && nowMonth <= 9) {
    nowMonth = "0" + nowMonth;
}
// 对月份进行处理，1-9号在前面添加一个“0”
if (strDate >= 0 && strDate <= 9) {
    strDate = "0" + strDate;
}
```
// 最后拼接字符串，得到一个格式为(yyyy-MM-dd)的日期（date.getFullYear()得到的是4位数得年份，比如：2017 ；date.getYear()得到得是2位数得年份，比如：17）
`var nowDate = date.getFullYear() + seperator + nowMonth + seperator + strDate;`