---
title: 在CentOS 7上安装Google Chrome Web浏览器
top: 0
date: 2019-02-28 16:17:36
categories: Linux
tags:
- centos
- GoogleChrome
---
谷歌浏览器是世界上使用最广泛的网络浏览器。它是为现代网络构建的快速，易用且安全的浏览器。
Chrome不是一个开源浏览器，它不包含在CentOS存储库中。它基于Chromium，这是一个开源浏览器，可在EPEL存储库中找到。
<!--more-->
### 安装Google Chrome
**前提：请确保以具有sudo权限的用户身份登录。**

在CentOS上安装Google Chrome
* 首先打开终端，使用以下wget命令下载最新的Google Chrome 包：
```
wget https://dl.google.com/linux/direct/google-chrome-stable_current_x86_64.rpm
```
* 下载文件后，键入以下命令在CentOS 7系统上安装Google Chrome：
```
sudo yum localinstall google-chrome-stable_current_x86_64.rpm
```
上面的命令将提示您输入用户密码，然后它将安装Chrome和所有其他必需的软件包。

### 启动Google Chrome
现在您已经在CentOS系统上安装了Google Chrome(应用程序->互联网->Google Chrome)
![](https://raw.githubusercontent.com/xqmGitHub/xqmgithub.github.io/img/hexo/20190228162647.png)

当您第一次启动Google Chrome时，会出现如下窗口，询问您是否要将Google Chrome设置为默认浏览器，并向Google发送使用统计信息和崩溃报告
根据您的偏好选择，然后单击OK继续。

### 更新Google Chrome
在安装过程中，官方Google存储库将添加到您的系统中。您可以使用cat命令验证文件内容：
```language
cat /etc/yum.repos.d/google-chrome.repo

//输出
[google-chrome]
name=google-chrome
baseurl=http://dl.google.com/linux/chrome/rpm/stable/x86_64
enabled=1
gpgcheck=1
gpgkey=https://dl.google.com/linux/linux_signing_key.pub
```
这可确保在通过桌面标准软件更新工具发布新版本时，您的Google Chrome安装将自动更新。
