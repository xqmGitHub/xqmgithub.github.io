
---
title: JS Base64编码解码
top: 0
date: 2019-01-18 19:07:49
categories: JavaScript
tags:
 - bases64
---
Base64编码解码是经常用到的 js怎么用呢 第一反应是找 bases64.js
使用很简单，浏览器引入该JS文件，然后Base64编码这样

```
Base64.encode('123456');
// 返回：'MTIzNDU2'
```

解码就调用`decode`方法，
```
Base64.decode('MTIzNDU2');
// 返回：'123456'
```

就是这么简单。
结果，今天发现，尼玛原来浏览器很早就支持了JS Base64加密解密，还花时间去找类库，还要加载一次，只能说JS基础掌握不牢。

<!--more-->

**原生atob和btoa方法**
实际上，从IE10+浏览器开始，所有浏览器就原生提供了Base64编码解码方法，不仅可以用于浏览器环境，Service Worker环境也可以使用。

* Base64解码

语法为（浏览器中）：

`var decodedData = window.atob(encodedData);`
或者（浏览器或js Worker线程中）：

`var decodedData = self.atob(encodedData);`
例如：

`window.atob('MTIzNDU2'); // 返回：'123456'`

* Base64编码

语法为（浏览器中）：

`var encodedData = window.btoa(stringToEncode);`
或者（浏览器或js Worker线程中）：

`var encodedData = self.btoa(stringToEncode);`
例如：
`window.btoa('123456'); // 返回：'MTIzNDU2'`

还有个问题 中文Base64数据转换会有报错问题

解决方法，就是中文先encode转码和decode编码：
```
//编码：
window.btoa(window.encodeURIComponent('我是中文')); 
//返回 JUU2JTg4JTkxJUU2JTk4JUFGJUU0JUI4JUFEJUU2JTk2JTg3

//解码：
window.decodeURIComponent(window.atob('JUU2JTg4JTkxJUU2JTk4JUFGJUU0JUI4JUFEJUU2JTk2JTg3'));
//返回 我是中文
```
