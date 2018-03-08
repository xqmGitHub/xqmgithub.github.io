---
title: ajax无刷新页面切换,历史记录后退前进解决方案
date: 2018-02-26 14:10:31
categories: JavaScript
tags:
 - Ajax
 - 历史记录
---
我们在工作中常常遇到需要用ajax来显示下一页和上一页，ajax无刷新页面，因此，假如你想通过浏览器的历史记录返回上一页和下一页。那这就问题来了！一般需求要历史返回的时候，我们通常不使用ajax。但是呢，假如一个页面中，只有一个地方是动态的，其他地方都是固定的，除了使用模板之外，那么就是使用ajax来操作显得格外方便！那么如何解决ajax历史记录的返回和前进呢？
<!--more-->

## js中history相关API普及
### history.state

当前URL下对应的状态信息。如果当前URL不是通过pushState或者replaceState产生的，那么history.state是null。

### history.pushState(state, title, url)
将当前URL和history.state加入到history中，并用新的state和URL替换当前。不会造成页面刷新。

```
state：与要跳转到的URL对应的状态信息。

title：页面的题目,假如没有就穿空字符串就可以。

url：要跳转到的URL地址，不能跨域。
```
### history.replaceState(state, title, url)
用新的state和URL替换当前。不会造成页面刷新。

```
state：与要跳转到的URL对应的状态信息。

title：页面的题目,假如没有就穿空字符串就可以。

url：要跳转到的URL地址，不能跨域。
```
### window.onpopstate

history.go和history.back（包括用户按浏览器历史前进后退按钮）触发，并且页面无刷的时候（由于使用pushState修改了history）会触发popstate事件，事件发生时浏览器会从history中取出URL和对应的state对象替换当前的URL和history.state。通过event.state也可以获取history.state。

### 支持性判断
```
if ('pushState' in history) {...}
```
## 相关代码

假如我们动态的html代码id是MyDiv。
定义如下函数

```
function processAjaxData(obj, url){
     document.getElementById("MyDiv").innerHTML = obj.html;
     document.title = obj.pageTitle;
 window.history.pushState({"html":obj.html,"pageTitle":obj.pageTitle},"", url);
 }
```

obj是后台ajax返回来的数据,obj.html来替换动态haorooms下面的内容，页面标题是返回的pageTitle标题。

而当有浏览者点击浏览器“后退”或“前进”按钮时，我们用下面的代码来响应用户的操作：

```
window.onpopstate = function(event){
    if(event.state){
        document.getElementById("haorooms").innerHTML = event.state.html;
        document.title = event.state.pageTitle;
    }
};
```
## 兼容性

谷歌浏览器，火狐浏览器，Safafi浏览器、IE10+等现代浏览器都支持这种技术。假如你感兴趣，可以试试！

