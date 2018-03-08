---
title: 移动站适配rel=alternate PC页和H5页适配标注
id: 254
categories:
  - 综合
date: 2017-03-09 10:38:04
tags:
 - alternate
 - 适配标注
---
鉴于移动化大潮的汹涌和H5页的炫丽普及，百度针对PC页与H5页的跳转适配方式推出了最优方案：
1.在pc版网页上，添加指向对应移动版网址的特殊链接rel="alternate"标记，这有助于百度发现网站的移动版网页所在的位置；
2.同时在移动版网页上，添加指向对应pc版网址的链接rel="canonical"标记。
<!--more-->
电脑端网站截图：

![pc](https://xqmblog.files.wordpress.com/2017/03/pc.jpg)

移动端网站截图：

![mobile](https://xqmblog.files.wordpress.com/2017/03/mobile.jpg)

如果你的网址是：
pc版网址：http://pc_url
移动版网址：http://mobile_url
那么此示例中的注释如下所示：
在pc版网页(http://pc_url) 上，添加：
`<link rel="alternate" media="only screen and(max-width: 640px)" href="http://pc_url">`

在移动版网页(http://mobile_url) 上，所需的注释应为:
`<link rel="canonical" href="http://mobile_url" >`

之前的Meta标记（mobile agent）会继续沿用，但我们推荐使用HTMAL5语言制作的移动页面使用最新方案进行跳转适配，其它如xml语言的移动页跳转适配，需要继续使用之前的meta标记方式:
`<meta name="mobile-agent"content="format=[wml|xhtml|html5]; url=mobile_url">`


转。