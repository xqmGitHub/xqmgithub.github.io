---
title: Js禁止网页复制、查看源代码
top: 0
date: 2018-07-06 10:23:55
categories: JavaScript
tags:
 - Js
 - 复制
---
网页禁止右键、禁止查看源代码、禁止复制的代码


```javascript
document.oncontextmenu=new Function('event.returnValue=false;');
document.onselectstart=new Function('event.returnValue=false;');
```

