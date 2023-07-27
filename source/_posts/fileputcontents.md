---
title: PHP file_put_contents函数：将字符串写入或追加到文件
id: 219
categories:
  - PHP
date: 2017-02-24 15:53:29
tags:
 - file_put_contents
---
**file_put_contents() 函数用于把字符串写入文件，成功返回写入到文件内数据的字节数，失败则返回 FALSE。**
<!--more-->
**语法**
```
int file_put_contents ( string filename, string data [, int flags [, resource context]] )
```
**参数说明**
| 参数 | 说明|
|---|---|
| filename| 要写入数据的文件名|
| data| 要写入的数据。类型可以是 string，array（但不能为多维数组），或者是 stream 资源 |
| flags| 可选，规定如何打开/写入文件。可能的值：1.  FILE_USE_INCLUDE_PATH：检查 filename 副本的内置路径2.  FILE_APPEND：在文件末尾以追加的方式写入数据3.  LOCK_EX：对文件上锁|
| context| 可选，Context是一组选项，可以通过它修改文本属性|

例子：

```
echo file_put_contents("test.txt", "This is something.");
```
 输出：18

 而 test.txt 文件（与程序同目录下）内容则为：This is something.

提示:
如果文件不存在，则创建文件，相当于fopen()函数行为。
如果文件存在，默认将清空文件内的内容，可设置 flags 参数值为 FILE_APPEND 以避免（见下）。
本函数可安全用于二进制对象。

**以追加形式写入内容**
当设置 flags 参数值为 FILE_APPEND 时，表示在已有文件内容后面追加内容的方式写入新数据：

```
file_put_contents("test.txt", "This is another something.", FILE_APPEND);
```
执行程序后，test.txt 文件内容变为：This is something.This is another something.
    