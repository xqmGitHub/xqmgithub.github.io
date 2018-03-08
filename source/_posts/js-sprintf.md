---
title: 用JS实现PHP的sprintf函数
id: 92
categories:
  - JavaScript
date: 2017-02-16 15:40:45
tags:
 - sprintf
 - 拼接字符串
---
**在拼接字符串时，将字符串与变量穿插拼接，看起来很眼花缭乱，如果象PHP中的sprintf函数那个，将需要用变量表示的地方用“%s”来表示，看起来就清楚多了。**
<!--more-->
```
function sprintf()
   {
      var arg = arguments,
         str = arg[0] || '',
         i, n;
      for (i = 1, n = arg.length; i 
         str = str.replace(/%s/, arg[i]);
      }
      return str;
   }
   var str = "大家好，我叫%s。今年%s岁了，喜欢%s。呵呵！",
   var1 = "点点",
   var2 = "18",
   var3 = "睡觉",
   str = sprintf(str, var1, var2, var3);
   alert(str);
```
