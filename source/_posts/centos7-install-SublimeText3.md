---
title: 在CentOS 7上安装Sublime Text 3
top: 0
date: 2019-02-28 16:18:11
categories: Linux
tags:  
- centos
- SublimeText3
---
Sublime Text是一个专有的跨平台多功能文本和源代码编辑器，用于Web和软件开发。它非常快，并且具有许多开箱即用的强大功能。可以通过安装新插件和创建自定义设置来增强其功能。
<!--more-->

* **首先导入官方Sublime Text存储库的GPG密钥**
```
sudo rpm -v --import https://download.sublimetext.com/sublimehq-rpm-pub.gpg
```

* **使用以下命令将Yum存储库添加到系统中**
```
sudo yum-config-manager --add-repo https://download.sublimetext.com/rpm/stable/x86_64/sublime-text.repo

//输出
adding repo from: https://download.sublimetext.com/rpm/stable/x86_64/sublime-text.repo
grabbing file https://download.sublimetext.com/rpm/stable/x86_64/sublime-text.repo to /etc/yum.repos.d/sublime-text.repo
repo saved to /etc/yum.repos.d/sublime-text.repo
```
* **启用存储库后，键入以下命令安装Sublime Text 3**
```
sudo yum install sublime-text
```

Sublime Text已安装完成
可以在左上角的 应用程序->编程(Applications -> Programming) 中找到 Sublime Text