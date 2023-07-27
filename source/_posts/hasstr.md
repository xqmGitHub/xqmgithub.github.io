---
title: PHP 判断是否包含某字符串
id: 26
categories:
  - PHP
date: 2017-01-08 20:16:29
tags:
 - 字符串
---

PHP判断字符串的包含,可以使用PHP的内置函数 strstr,strpos,stristr直接进行判断.也可以通过explode函数的作用写一个判断函数
<!--more-->

**1、strstr 和 stristr的用法 **
strstr: 返回一个从被判断字符开始到结束的字符串,如果没有返回值,则不包含. stristr: 它和strstr的使用方法完全一样.唯一的区别是stristr不区分大小写.
```
$email = 'user@example.com';
$domain = strstr($email, '@');
echo $domain; // prints @example.com
```
**2、 strpos的用法**
strpos: 返回boolean值.FALSE和TRUE不用多说.用 “===”进行判断.strpos在执行速度上都比以上两个函数快,另外strpos有一个参数指定判断的位置,但是默认为空.意思是判断整个字符串.缺点是对中文的支持不好.
PHP判断字符串的包含代码如下:
```
$str= 'abc';
$needle= 'a';
$pos = strpos($str, $needle);
```
**3、explode 的用法**

```
function checkstr($str)
{
    $needle = 'a';//判断是否包含a这个字符
    $tmparray = explode($needle, $str);
    if (count($tmparray) > 1) {
        return 'ok';
    } else {
        return 'no';
    }
}
```


**4、in_array — 检查数组中是否存在某个值例子**

(1). in_array() 例子
```
$os= array("Mac", "NT", "Irix", "Linux");
if (in_array("Irix", $os)) {echo "Got Irix";} 
if (in_array("mac", $os)) {echo"Got mac";} 
```
第二个条件失败，因为 in_array() 是区分大小写的，所以以上程序显示为：Got Irix

(2). in_array() 严格类型检查例子
```
$a= array('1.10', 12.4, 1.13);
if (in_array('12.4', $a, true)) {echo"'12.4' found with strict check\n";} 
if ( in_array(1.13, $a, true)) {echo"1.13 found with strict check\n";}
```
上例将输出：
1.13 found with strict check

(3). in_array() 中用数组作为 needle
```
$a = array(array('p', 'h'), array('p', 'r'), 'o');
if ( in_array(array('p', 'h'), $a)) {echo "'ph' was found\n";}
if ( in_array(array('f', 'i'), $a)) {echo "'fi' was found\n";}
if ( in_array('o', $a)) {echo "'o' was found\n";}
```
上例将输出：
'ph' was found
'o' was found

array_search — 在数组中搜索给定的值，如果成功则返回相应的键名