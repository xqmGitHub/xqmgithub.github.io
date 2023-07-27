---
title: npm install 报错（npm ERR！ errno -4048 npm ERR！ Error：EPERM：operation not permitted, scandir） 解决方法
date: 2018-02-02 16:17:39
categories: Node
tags:
 - npm ERR
 - install
 - EPERM
 - 4048
---
今天在安装插件的时候，发现安装出错
`npm ERR! errno -4048，Error: EPERM: operation not permitted`
看到`npm ERR! Please try running this command again as root/Administrator.`这句
以为还真是权限不够，感觉有点奇怪，用管理员权限执行，有的还真有用，但是有个别还是报错，好气呀！！
后面查了下，开始看到是因为npm和node问题的版本
就看看版本是多少
*`npm -v` 是：5.3.0
*`node -v` 是：v8.6.0
结果发现并不是版本问题，而是缓存的问题，清理下缓存就行，不用管理员权限。
<!--more-->

**方法1**

需要删除npmrc文件。

强调：不是nodejs安装目录npm模块下的那个npmrc文件

而是在C:\Users\{账户}\下的.npmrc文件..

**方法2**

或者直接用命令清理就行，控制台输入：

`npm cache clean --force`

清除成功后，再安装插件，成功安装插件。
