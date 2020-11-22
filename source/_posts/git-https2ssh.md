---
title: git 远程连接由 https 换成 ssh
top: 0
date: 2020-09-20 14:26:22
categories: Git
tags:
 - Git
 - ssh
---

在github.com上 建立了一个小项目，push 的时候，提示 
```
fatal: unable to access 'https://github.com/xxx.git/': error setting certificate verify locations: 
CAfile: D:/Git/mingw64/ssl/certs/ca-bundle.crtle 
CApath: none
```
而且用 https 在 push 都要输入用户名和密码，很是麻烦

还是 ssh 方便 下面把它换成 ssh 方式的

`git remote -v `

可以看到形如一下的返回结果
```
origin https://github.com/xxx.git (fetch)

origin https://github.com/xxx.git (push)
```

* 移除本地分支
`git remote rm origin`
* 添加远程分支 
`git remote add origin 'git@github.com:xxx/***.git'`
* 最后就阔以愉快的用 ssh 方式了（前提是配置了 ssh key）



