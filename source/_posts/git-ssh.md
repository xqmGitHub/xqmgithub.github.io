---
title: 解决git报ssh variant 'simple' does not support setting port
top: 0
date: 2018-08-14 14:26:22
categories: Git
tags:
 - Git
 - ssh
---

使用 ssh 方式拉取代码的时候，使用的命令带有端口号。而在 git 2.16.x 版本上 ssh variant 需要手动设置为 ssh。
* 解决办法
在git bash中输入命令

```
git config --global ssh.variant ssh
```

