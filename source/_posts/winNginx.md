---
title: Windows下启动、关闭Nginx命令
date: 2018-03-02 16:13:25
categories: Nginx
tags:
 - Nginx
 - Windows
 - 启动
---
**启动**

直接点击Nginx目录下的nginx.exe    或者    cmd运行`start nginx`

**关闭**

`nginx -s stop`    或者    `nginx -s quit`

* stop 表示立即停止nginx,不保存相关信息

* quit 表示正常退出nginx,并保存相关信息

**重启**
因为改变了配置,需要重启

`nginx -s reload`
