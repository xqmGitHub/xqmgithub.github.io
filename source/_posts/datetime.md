---
title: php整理常用时间戳和日期
date: 2018-01-30 12:03:02
categories: PHP
tags: 
 - datetime
---
**整理常用时间戳和日期，方便后期用到。**

<!--more-->

```
昨天0时时间戳
$yesterday_zero = strtotime(date('Y-m-d')) - 3600 * 24;
昨天此时时间戳
$yesterday_now = strtotime('-1 day');
本周一时间戳
$week_this_monday = strtotime('last Monday');
明天时间戳
$tomorrow = strtotime("+1 day");
上周一时间戳
$week_last_monday = strtotime('last Monday') - 3600 * 24 * 7;
上周日时间戳
$week_last_sunday = strtotime('last Monday') - 3600 * 24;
本月第一天时间戳
$month_first = strtotime(date("Y") . "-" . date("m") . "-1");
本月最后一天时间戳
$month_last = strtotime(date("Y") . "-" . date("m") . "-" . date("t"));
获取上个月第一天及最后一天
echo date('Y-m-01', strtotime('-1 month')); 
echo "<br/>"; 
echo date('Y-m-t', strtotime('-1 month'));
```

