---
title: 回车键搜索
date: 2018-01-31 15:07:39
categories: JavaScript
tags:
 - jQuery
 - 回车键搜索
---
一般搜索的习惯是输入关键字后就敲个回车键搜索，刚好做个CMS的时候有个搜索功能需要输入关键，回车就可以搜索。
<!--more-->
可以用JQ实现这个功能
这个是PC端的
```
$(".keyword").keydown(function (e) {
    if (e.keyCode == 13) {
        alert('回车搜索');
    }
});
```
移动端的要想手机输入法的显示“搜索”或者“前往”，就需要修改搜索的input标签的属性
type="search"
```
<input type="search" class="keyword">
$(".keyword").bind("search", function() {
    alert('回车搜索');
})
```
用手机打开，就会发现输入法的上的搜索就出来了
