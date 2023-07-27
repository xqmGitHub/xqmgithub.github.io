---
title: 计算php运行时间（毫秒数）
id: 418
categories:
  - PHP
date: 2017-05-15 10:41:43
tags:
 - 运行时间
---

有时候想看看某一块代码的运行时间，看看是如何计算的
<!--more-->
非常简单
```
$t1 = microtime(true);
//php script here
$t2 = microtime(true);
echo (($t2-$t1)*1000).'ms';
```

