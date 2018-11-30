---
title: php：找不到命令
top: 0
date: 2018-11-30 16:30:34
categories: Linux
tags:
 - linux
 - command 
---

在终端输入一个命令，而系统提示你说命令没有找到（Command not found）的话，要么是因为你没有装相应的软件包，要么就是因为路径设置的问题。如果是因为软件包的问题，那没有别的好说的，安装相应的软件包就好了。而另外一种情况，则需要对用户的路径进行设置。
<!--more-->

 php：找不到命令  php 已经安装了 那就是环境变量问题
 解决：
`export PATH=$PATH:/usr/local/php/bin`
然后，再 `echo $PATH` 看看，就看见了。
`usr/local/sbin:/usr/local/bin:/sbin:/bin:/usr/sbin:/usr/bin:/root/bin:/usr/local/php/bin`
