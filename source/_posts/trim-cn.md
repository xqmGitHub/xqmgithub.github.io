---
title: trim 中文乱码
top: 0
date: 2018-04-28 13:53:35
categories: PHP
tags: 
 - trim
 - 乱码
---
trim 中文乱码 ,问题来了，没有 mb_trim这样的函数 没有可以封装一个
<!--more-->
```
echo rawurlencode('河北省');//%E6%B2%B3%E5%8C%97%E7%9C%81
echo rawurlencode('广东省');//%E5%B9%BF%E4%B8%9C%E7%9C%81
echo rtrim('河北省', '省');//河北
echo rtrim('广东省', '省');//广��
//省的十六制作表示是e7 9c 81，而东的十六进制表示是e4 b8 9c，都出现了9c，哦~正因为是rtrim，所以rtrim('广东省', '省')的时候把“东”的十六进制表示的最后一位也被trim掉了。同理rtrim('河北省', '省')不存在此问题

echo trim_cn('广东省','省');//广东

function trim_cn($str, $trim, $charset = 'UTF-8') {
    $len = mb_strlen($str, $charset);
    if (!$len)
        return;

    $t1 = $t2 = false;$o=$l=0;
    for($i=0;$i<$len;$i++)
    {
        $str1 = mb_substr($str, $i, 1, $charset);
        $str2 = mb_substr($str, $len-$i-1, 1, $charset);
        if($str1 == $trim && !$t1) $o++; else $t1 = true;
        if($str2 == $trim && !$t2) $l++; else $t2 = true;
    }
    return mb_substr($str, $o, ($len-$l-$o), $charset);;
}
```
