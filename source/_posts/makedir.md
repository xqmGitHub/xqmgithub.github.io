---
title: php自动创建目录并保存文件函数
id: 15
categories:
  - PHP
date: 2017-01-06 18:47:49
tags:
 - 自动创建目录
---

**在做文件上传时有一个非常必须要做的功能就是上传文件会按日期生成目录并把文件保存在目录下了，下面我来为各位介绍一段php自动创建目录并保存文件函数**
<!--more-->
php保存文件，还可以根据文件路径自动连续创建目录，代码如下（注：PHP要版本5以上）：

```
/** 
 * 保存文件 
 * @param string $fileName 文件名（含相对路径） 
 * @param string $text 文件内容 
 * @return boolean 
 */
function saveFile($fileName, $text)
{
    if (!$fileName || !$text) return false;
    if (makeDir(dirname($fileName))) {
        if ($fp = fopen($fileName, "w")) {
            if (@fwrite($fp, $text)) {
                fclose($fp);
                return true;
            } else {
                fclose($fp);
                return false;
            }
        }
    }
    return false;
}

/** 
 * 连续创建目录 (此外0777不能加单引号和双引号， 加了以后，"0400" = 600权限，处以为会这样，我也想不通)
 * @param string $dir 目录字符串 
 * @param int $mode 权限数字 
 * @return boolean
 */
function makeDir($dir, $mode = 0755)
{ 
    if (!dir) return false;
    if (!file_exists($dir)) {
        return mkdir($dir, $mode, true);
    } else {
        return true;
    }
}
```
以下是测试内容,并调用上面的函数
```
$content = '这里是测试内容';
if (saveFile('dir/test.txt', $content)) {
    echo '写入成功';
} else {
    echo '写入失败';
} 
```
注意：makeDir就是一个目录创建函数，我们使用的是递归创建了．

来源:转载