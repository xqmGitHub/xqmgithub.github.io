---
title: php获取当前毫秒时间戳
id: 319
categories:
  - PHP
date: 2017-03-23 11:06:49
tags:
 - 时间戳
---
用php的time()函数来获取时间戳，获取的时间精确到秒级别，但是想获取到毫秒级就不行了
虽然在php没有自带的函数能获取毫秒时间戳，但提供了一个microtime()函数
<!--more-->
`echo microtime();`

输出的是：0.02593300 1490238047

它的结果是分两部分的，也就是前半部分是毫秒（但是单位是秒），后半部分是秒。
这样我们获取获取到毫秒就好办了，修改一下就阔以了
```
function  msectime(){
    list($msec, $sec) = explode(' ', microtime());
    return (float)sprintf('%.0f', (floatval($msec) + floatval($sec)) * 1000);
}
echo msectime();
```
输出：1490238248638

注意：sprintf('%.0f', $num) 是输出不含小数部分的浮点数

我把时间戳改成毫秒级别后，再次更新数据库数据时，却提示超出范围，原来之前我在数据库中是用int型来存储time()函数获取的秒级别的时间戳，存储范围是够的，改成毫秒级别的，就得改成BIGINT类型了。