---
title: PHP获取每个月的最后一个周五日期
id: 305
categories:
  - PHP
date: 2017-03-16 15:02:31
tags:
 - 最后一个周五
---

在网上看到的，感觉不错就记下来了，说不定以后用到。
<!--more-->
```
/**
 * 返回指定年份的月份最后周五日期
 * 
 * @param  integer $month 月份
 * @param  integer $year  年份
 * @return 日期        YYYY-MM-DD
 */
function getFridayDate($month, $year = null)
{
    $months = [
        1  => 'January',
        2  => 'February',
        3  => 'March',
        4  => 'April',
        5  => 'May',
        6  => 'June ',
        7  => 'July',
        8  => 'August',
        9  => 'September',
        10 => 'October',
        11 => 'November',
        12 => 'December',
    ];
    if (! array_key_exists($month, $months)) {
        return false;
    }
    if ($year == null) {
        $year = date('Y');
    }
    return date('Y-m-d', strtotime('last Friday of ' . $months[$month] . ' ' . $year));
}

echo getFridayDate(2);        // 2017-02-24
echo getFridayDate(3, 2017);  // 2017-03-31
```
