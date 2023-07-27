---
title: php dirname(__FILE__) 获取当前文件的绝对路径
id: 88
categories:
  - PHP
date: 2017-02-15 11:37:09
tags:
 - dirname
---
dirname(\_\_FILE\_\_) 取到的是当前文件的绝对路径，也就是说，比起相对路径，查找速度是最快的。
<!--more-->
比如当前文件是放在(d:\www\)下，文件名是testdir.php。

测试的代码如下：
```
echo __FILE__ ; // 取得当前文件的绝对地址，结果：D:\www\testdir.php
echo dirname(__FILE__); // 取得当前文件所在的绝对目录，结果：D:\www\
echo dirname(dirname(__FILE__)); //取得当前文件的上一层目录名，结果：D:\
```
使用方法提示,
dirname(\_\_FILE\_\_) 取到的是当前文件的绝对路径，也就是说，比起相对路径，查找速度是最快的。
如果重复一次可以把目录往上提升一个层次:
比如：$d = dirname(dirname(\_\_FILE\_\_));
其实就是把一个目录给dirname()做参数了．因为dirname()返回最后的目录不带\\\或者是/
所以重复使用的时候可以认为　dirname()　把最下层的目录当成文件名来处理了．照常返回
当前目录的上级目录.这样重复就得到了它的上一级的目录.

包含得到上一级目录的文件
include(dirname(\_\_FILE\_\_).'/../filename.php');

\_\_FILE\_\_的路径是当前代码所在文件

dirname(dirname(\_\_FILE\_\_));得到的是文件上一层目录名

dirname(\_\_FILE\_\_);得到的是文件所在层目录名