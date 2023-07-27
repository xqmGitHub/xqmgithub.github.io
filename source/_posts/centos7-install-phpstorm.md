---
title: Centos7 安装PhpStorm
top: 0
date: 2018-11-30 16:05:59
categories: Linux
tags:
 - centos
 - phpstorm
---

* 官网下载PhpStorm最新的包
    [直达链接](https://www.jetbrains.com/phpstorm/download/#section=linux1)
    * 下载好后 解压`tar -zxf PhpStorm-版本.tar.gz`
    * 将解压出来的目录移动到你喜欢的目录
       

    ```
    mv  PhpStorm  /usr/local/phpstorm
    
    cd /usr/local/phpstorm/bin
    
    chmod 777 phpstorm.sh
    
    ./phpstorm.sh
    ```

* 开始安装，根据运行提示，输入相应license
网上找到的   [IntelliJ IDEA 注册码](http://idea.lanyus.com/)  感谢大佬

   给phpstorm创建环境变量，可以在命令行直接输入phpstorm命令来启动
  `ln -s /usr/local/phpstorm/bin/phpstorm.sh  /usr/local/bin/phpstorm`

* 加入快捷方式
1.新建文件  `touch phpstorm.desktop`

2.编辑文件 `vim phpstorm.desktop`

以下是我的内容：
```
[Desktop Entry]
Categories=Development;
Comment[zh_CN]=
Comment=
Exec=/usr/local/phpstorm/bin/phpstorm.sh
GenericName[zh_CN]=IDE
GenericName=IDE
Icon=/usr/local/phpstorm/bin/phpstorm.png
MimeType=
Name=PHPStorm
Path=
StartupNotify=true
Terminal=false
Type=Application
X-DBUS-ServiceName=
X-DBUS-StartupType=
X-KDE-SubstituteUID=false
X-KDE-Username=eddie
```
保存，退出。

3.将phpstorm.desktop移动到目录

`sudo mv phpstorm.desktop  /usr/share/applications/`

4、给文件添加可执行权限
```
cd  /usr/share/applications
chmod +x phpstorm.desktop
```