---
title: 去掉和恢复Win10快捷方式上小箭头的方法
date: 2018-02-25 14:24:37
categories: 综合
tags:
 - win10
 - 快捷方式
---
系统快捷方式上小箭头，看的很不爽？那就把他们去掉吧！
可还原回来，亲测可行。
<!--more-->

据说此方法是此方法并不是删除了小箭头，而是将小箭头变成了透明，实际上小箭头是以透明状态存在的。

## 去掉小箭头


复制下面的代码。新建一个文本文件。粘贴后另存为.bat文件，然后以管理员身份打开。
```
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Shell Icons" /v 29 /d "%systemroot%\system32\imageres.dll,197" /t reg_sz /f
taskkill /f /im explorer.exe
attrib -s -r -h "%userprofile%\AppData\Local\iconcache.db"
del "%userprofile%\AppData\Local\iconcache.db" /f /q
start explorer
pause
```
## 恢复小箭头

复制下面的代码。新建一个文本文件。粘贴后另存为.bat文件，然后以管理员身份打开。

```
reg delete "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Shell Icons" /v 29 /f
taskkill /f /im explorer.exe
attrib -s -r -h "%userprofile%\AppData\Local\iconcache.db"
del "%userprofile%\AppData\Local\iconcache.db" /f /q
start explorer
pause
```

XP系统的有区别，不适用
Win7的没试过，应该是通用的