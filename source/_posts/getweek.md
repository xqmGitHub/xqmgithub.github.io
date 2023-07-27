---
title: php判断今天是星期几的方法
id: 72
categories:
  - PHP
date: 2017-01-11 16:16:04
tags:
 - 星期几
---
这里主要用到了date 的 w 这个参数，关于这个参数的解释是：
w 表示星期中的第几天，数字表示 0（表示星期天）到 6（表示星期六）
<!--more-->
```
//php获取今天是星期几
function getWeek($unixTime = '') {
    $unixTime = is_numeric($unixTime) ? $unixTime : time();
    $weekarray = array('日','一','二','三','四','五','六');
    return '星期' . $weekarray[date('w', $unixTime)];
}
echo getWeek();
```
