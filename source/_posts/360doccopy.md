---
title: 360个人图书馆 轻松解除网页防复制
id: 524
categories:
  - 综合
date: 2017-07-27 15:07:37
tags:
 - 解除网页防复制
sticky: 0
---

360个人图书馆会自动采集一些比较好的文章，我的博客文章也被采集过几篇，用过360个人图书馆的人都知道要复制别人的文章需要先收藏到自己的图书馆才可以复制，没有账号右键复制它会直接弹出一个提示登录框。不过如果你不经常使用360个人图书馆，你也会懒得专门去注册一个帐号吧？
<!--more-->
chrome浏览器按F12（打开谷歌浏览器的开发者工具）
点击Console
然后按F5 刷新下网页，（根据测试必须刷新下网页等下插入代码才能生效）

![360copy](https://xqmblog.files.wordpress.com/2017/07/360copy.png)



```
document.oncontextmenu=document.onselectstart=document.body.onselectstart=document.oncopy=document.body.oncopy=""
```


然后按回车键，ok！不会弹出那令人蛋疼的提示了，可以复制了。

转：[360个人图书馆 轻松解除网页防复制 | 老D博客](https://laod.cn/black-technology/360doc-copy.html "本文固定链接 https://laod.cn/black-technology/360doc-copy.html")