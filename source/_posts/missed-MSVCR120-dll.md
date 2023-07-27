---
title: MySQL免安装版，遇到MSVCR120.dll文件丢失错误
top: 0
date: 2018-08-02 15:49:28
categories: MySql
tags:
 - mysql
 - MSVCR120.dll
---

在进行mysql zip版本的安装时，遇到`无法启动此程序，因为计算机中丢失MSVCR120.dll。尝试重新安装该程序已解决问题`
在网上找了相关的文件拷贝到相应目录下，但还是不行。 
后来终于找到解决方法：下载 [VC redist packages for x64](https://www.microsoft.com/en-us/download/details.aspx?id=40784)，下载完成，点击运行即可。
