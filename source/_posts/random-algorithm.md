---
title: 红包的随机算法基础实现
top: 0
date: 2018-08-08 14:25:21
categories: PHP
tags:
 - 算法
 - 红包
---
### 说明

* 假设有 n 个人领红包；
* 每个人领到红包总和为 m 元；
* 每个人至少领到 0.01 元红包；
* 每个人领到红包额度相差范围小。
<!--more-->

### 思维逻辑

当 n 为1时：n1 = m

当 n 为2时：n1 = 0.01 ~ m       n2 = m - n1

当 n 为3时：n1 = 0.01 ~ m       n2 = 0.01 ~ ( m - n1 )       n3 = m - n1 - n2
...

### 算法实现

```php
$m=m;      //M元红包
$n=n;      //N个人领取
$min=0.01; //每个人最少能收到0.01元
$moneyArr = [];
for ($i=1;$i<$n;$i++)
{
   $avg = ($m-($n-$i)*$min)/($n-$i);
   $money = mt_rand($min*100,$avg*100)/100;
   $m -= $money;
   $moneyArr[$i] = $money;
   echo '第' . $i . '个红包：' . $money . '元，余额：' . $m . '元';
}
var_dump($moneyArr);
```

