---
title: 解压缩报错tar：Error is not recoverable：exiting now
top: 0
date: 2019-01-12 16:54:26
categories: Linux
tags: tar
---

解压缩报错tar: Error is not recoverable: exiting now
[root@root]# tar -zxvf /home/data/data.tar.gz.xz
gzip: stdin: not in gzip format
tar: Child returned status 1
tar: Error is not recoverable: exiting now

解决方法：
去掉z参数，使用 tar -xvf 解压正常

