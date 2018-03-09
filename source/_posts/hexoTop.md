---
title: 解决Hexo置顶问题
date: 2018-03-09 12:09:00
categories: Hexo
tags:
 - Top
 - Node
 - Hexo
---
今天发现置顶功能不起作用了，找了半天才想着起来。是在另一台电脑写的博客，重新安装（`nmp install`）过了，以前置顶功能的实现是直接替换`node_modules/hexo-generator-index/lib/generator.js`的内容，generator.js的内容被覆盖掉了，又要修改代码。这样太麻烦了，网上找到方法。
为了防止每次更新、安装都要修改代码，直接从仓库里安装就可以了，不用每次都修改了。

<!--more-->


把原来的删除了，换一个就可以了

```
 npm uninstall hexo-generator-index --save
 npm install hexo-generator-index-pin-top --save
```
置顶功能还是和以前的一样
在需要置顶的文章的front-matter中添加top值，值越大越置顶。

```
title: 标题 
tags:
categories: 
top: 1000
```
源文链接：[解决Hexo置顶问题](http://www.netcan666.com/2015/11/22/%E8%A7%A3%E5%86%B3Hexo%E7%BD%AE%E9%A1%B6%E9%97%AE%E9%A2%98/)