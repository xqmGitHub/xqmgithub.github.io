---
title: php生成随机字符串
id: 494
categories:
  - PHP
date: 2017-06-13 12:00:10
tags:
 - 随机字符串
---

经常会使用到生成随机字符串  封装了个方法
也可以用来生成不重复的唯一key
<!--more-->
```
function rand_key($len){
    mt_srand((double)microtime()*10000);//optional for php 4.2.0 and up.
    $charid = strtoupper(md5(uniqid(rand(), true)));
    $uuid =substr($charid, 0, $len);
    return $uuid;
}
```