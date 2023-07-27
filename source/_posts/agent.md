---
title: js判断用户的浏览器设备是移动端还是pc端
id: 247
categories:
  - JavaScript
date: 2017-03-07 18:44:59
tags:
 - 浏览器设备
---
网站页面中需要根据用户的访问设备的不同来显示不同的页面样式，主要是判断移动设备还是电脑浏览器访问的。
<!--more-->
```
function browserRedirect() {
    var sUserAgent = navigator.userAgent.toLowerCase();
    var bIsIpad = sUserAgent.match(/ipad/i) == "ipad";
    var bIsIphoneOs = sUserAgent.match(/iphone os/i) == "iphone os";
    var bIsMidp = sUserAgent.match(/midp/i) == "midp";
    var bIsUc7 = sUserAgent.match(/rv:1.2.3.4/i) == "rv:1.2.3.4";
    var bIsUc = sUserAgent.match(/ucweb/i) == "ucweb";
    var bIsAndroid = sUserAgent.match(/android/i) == "android";
    var bIsCE = sUserAgent.match(/windows ce/i) == "windows ce";
    var bIsWM = sUserAgent.match(/windows mobile/i) == "windows mobile";
    document.writeln("您的浏览设备为：");
    if (bIsIpad || bIsIphoneOs || bIsMidp || bIsUc7 || bIsUc || bIsAndroid || bIsCE || bIsWM) {
        document.writeln("phone");
    } else {
        document.writeln("pc");
    }
}
browserRedirect();
```
用电脑上的浏览器，android设备，iphone，ipad均做过测试，此代码可行，各设备判断均正确。

```
//判断是否微信浏览器中打开
function is_weixn(){  
    var ua = navigator.userAgent.toLowerCase();  
    if(ua.match(/MicroMessenger/i)=="micromessenger") {  
        return true;  
    } else {  
        return false;  
    }  
} 
```
本文转自：[http://www.cnblogs.com/babycool/](http://www.cnblogs.com/babycool/)