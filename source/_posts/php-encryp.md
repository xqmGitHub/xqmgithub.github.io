---
title: PHP中常用的加密解密方法
top: 0
date: 2018-05-07 14:01:07
categories: PHP
tags: 
 - 加密
 - 解密
 - base64
---
php加密解密:php加密和解密函数通常可以用来加密一些有用的字符串存放在数据库里或作为各个子系统间同步登陆的令牌，并且通过解密算法解密字符串，该函数使用了base64和MD5加密和解密。
<!--more-->

### 第一种加密解密算法

```
function encryptDecrypt($key, $string, $decrypt){   
    if($decrypt){   
        $decrypted = rtrim(mcrypt_decrypt(MCRYPT_RIJNDAEL_256, md5($key), base64_decode($string), MCRYPT_MODE_CBC, md5(md5($key))), "12");   
        return $decrypted;   
    }else{   
        $encrypted = base64_encode(mcrypt_encrypt(MCRYPT_RIJNDAEL_256, md5($key), $string, MCRYPT_MODE_CBC, md5(md5($key))));   
        return $encrypted;   
    }   
} 
```
### 第二种加密解密算法：


```
//加密函数  
function lock_url($txt,$key='hahaha'){  
    $txt = $txt.$key;  
    $chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-=+";  
    $nh = rand(0,64);  
    $ch = $chars[$nh];  
    $mdKey = md5($key.$ch);  
    $mdKey = substr($mdKey,$nh%8, $nh%8+7);  
    $txt = base64_encode($txt);  
    $tmp = '';  
    $i=0;$j=0;$k = 0;  
    for ($i=0; $i<strlen($txt); $i++) {  
        $k = $k == strlen($mdKey) ? 0 : $k;  
        $j = ($nh+strpos($chars,$txt[$i])+ord($mdKey[$k++]))%64;  
        $tmp .= $chars[$j];  
    }  
    return urlencode(base64_encode($ch.$tmp));  
}  
//解密函数  
function unlock_url($txt,$key='hahaha'){  
    $txt = base64_decode(urldecode($txt));  
    $chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-=+";  
    $ch = $txt[0];  
    $nh = strpos($chars,$ch);  
    $mdKey = md5($key.$ch);  
    $mdKey = substr($mdKey,$nh%8, $nh%8+7);  
    $txt = substr($txt,1);  
    $tmp = '';  
    $i=0;$j=0; $k = 0;  
    for ($i=0; $i<strlen($txt); $i++) {  
        $k = $k == strlen($mdKey) ? 0 : $k;  
        $j = strpos($chars,$txt[$i])-$nh - ord($mdKey[$k++]);  
        while ($j<0) $j+=64;  
        $tmp .= $chars[$j];  
    }  
    return trim(base64_decode($tmp),$key);  
}  
```
### 第三种加密解密算法：


```
function passport_encrypt($txt, $key = 'hahaha') {   
    srand((double)microtime() * 1000000);   
    $encrypt_key = md5(rand(0, 32000));   
    $ctr = 0;   
    $tmp = '';   
    for($i = 0;$i < strlen($txt); $i++) {   
    $ctr = $ctr == strlen($encrypt_key) ? 0 : $ctr;   
    $tmp .= $encrypt_key[$ctr].($txt[$i] ^ $encrypt_key[$ctr++]);   
    }   
    return urlencode(base64_encode(passport_key($tmp, $key)));   
}   
  
function passport_decrypt($txt, $key = 'hahaha') {   
    $txt = passport_key(base64_decode(urldecode($txt)), $key);   
    $tmp = '';   
    for($i = 0;$i < strlen($txt); $i++) {   
    $md5 = $txt[$i];   
    $tmp .= $txt[++$i] ^ $md5;   
    }   
    return $tmp;   
}   
  
function passport_key($txt, $encrypt_key) {   
    $encrypt_key = md5($encrypt_key);   
    $ctr = 0;   
    $tmp = '';   
    for($i = 0; $i < strlen($txt); $i++) {   
    $ctr = $ctr == strlen($encrypt_key) ? 0 : $ctr;   
    $tmp .= $txt[$i] ^ $encrypt_key[$ctr++];   
    }   
    return $tmp;   
}   
```
### 第四种加密解密算法：
discuz中使用的加密解密算法
项目中有时我们需要使用PHP将特定的信息进行加密，也就是通过加密算法生成一个加密字符串，这个加密后的字符串可以通过解密算法进行解密，便于程序对解密后的信息进行处理。最常见的应用在用户登录以及一些API数据交换的场景。最常见的应用在用户登录以及一些API数据交换的场景。加密解密原理一般都是通过一定的加密解密算法，将密钥加入到算法中，最终得到加密解密结果。


```
//函数authcode($string, $operation, $key, $expiry)中的$string：字符串，明文或密文；$operation：DECODE表示解密，其它表示加密；$key：密匙；$expiry：密文有效期。  
function authcode($string, $operation = 'DECODE', $key = '', $expiry = 0) {     
    // 动态密匙长度，相同的明文会生成不同密文就是依靠动态密匙     
    $ckey_length = 4;     
         
    // 密匙     
    $key = md5($key ? $key : $GLOBALS['discuz_auth_key']);     
         
    // 密匙a会参与加解密     
    $keya = md5(substr($key, 0, 16));     
    // 密匙b会用来做数据完整性验证     
    $keyb = md5(substr($key, 16, 16));     
    // 密匙c用于变化生成的密文     
    $keyc = $ckey_length ? ($operation == 'DECODE' ? substr($string, 0, $ckey_length): substr(md5(microtime()), -$ckey_length)) : '';     
    // 参与运算的密匙     
    $cryptkey = $keya.md5($keya.$keyc);     
    $key_length = strlen($cryptkey);     
    // 明文，前10位用来保存时间戳，解密时验证数据有效性，10到26位用来保存$keyb(密匙b)，   
    //解密时会通过这个密匙验证数据完整性     
    // 如果是解码的话，会从第$ckey_length位开始，因为密文前$ckey_length位保存 动态密匙，以保证解密正确     
    $string = $operation == 'DECODE' ? base64_decode(substr($string, $ckey_length)) :  sprintf('%010d', $expiry ? $expiry + time() : 0).substr(md5($string.$keyb), 0, 16).$string;     
    $string_length = strlen($string);     
    $result = '';     
    $box = range(0, 255);     
    $rndkey = array();     
    // 产生密匙簿     
    for($i = 0; $i <= 255; $i++) {     
        $rndkey[$i] = ord($cryptkey[$i % $key_length]);     
    }     
    // 用固定的算法，打乱密匙簿，增加随机性，好像很复杂，实际上对并不会增加密文的强度     
    for($j = $i = 0; $i < 256; $i++) {     
        $j = ($j + $box[$i] + $rndkey[$i]) % 256;     
        $tmp = $box[$i];     
        $box[$i] = $box[$j];     
        $box[$j] = $tmp;     
    }     
    // 核心加解密部分     
    for($a = $j = $i = 0; $i < $string_length; $i++) {     
        $a = ($a + 1) % 256;     
        $j = ($j + $box[$a]) % 256;     
        $tmp = $box[$a];     
        $box[$a] = $box[$j];     
        $box[$j] = $tmp;     
        // 从密匙簿得出密匙进行异或，再转成字符     
        $result .= chr(ord($string[$i]) ^ ($box[($box[$a] + $box[$j]) % 256]));     
    }     
    if($operation == 'DECODE') {    
        // 验证数据有效性，请看未加密明文的格式     
        if((substr($result, 0, 10) == 0 || substr($result, 0, 10) - time() > 0) &&  substr($result, 10, 16) == substr(md5(substr($result, 26).$keyb), 0, 16)) {     
            return substr($result, 26);     
        } else {     
            return '';     
        }     
    } else {     
        // 把动态密匙保存在密文里，这也是为什么同样的明文，生产不同密文后能解密的原因     
        // 因为加密后的密文可能是一些特殊字符，复制过程可能会丢失，所以用base64编码     
        return $keyc.str_replace('=', '', base64_encode($result));     
    }     
}   
```
### 第五种加密解密算法：


```
//函数encrypt($string,$operation,$key)中$string：需要加密解密的字符串；$operation：判断是加密还是解密，E表示加密，D表示解密；$key：密匙。  
function encrypt($string,$operation,$key=''){   
    $key=md5($key);   
    $key_length=strlen($key);   
      $string=$operation=='D'?base64_decode($string):substr(md5($string.$key),0,8).$string;   
    $string_length=strlen($string);   
    $rndkey=$box=array();   
    $result='';   
    for($i=0;$i<=255;$i++){   
           $rndkey[$i]=ord($key[$i%$key_length]);   
        $box[$i]=$i;   
    }   
    for($j=$i=0;$i<256;$i++){   
        $j=($j+$box[$i]+$rndkey[$i])%256;   
        $tmp=$box[$i];   
        $box[$i]=$box[$j];   
        $box[$j]=$tmp;   
    }   
    for($a=$j=$i=0;$i<$string_length;$i++){   
        $a=($a+1)%256;   
        $j=($j+$box[$a])%256;   
        $tmp=$box[$a];   
        $box[$a]=$box[$j];   
        $box[$j]=$tmp;   
        $result.=chr(ord($string[$i])^($box[($box[$a]+$box[$j])%256]));   
    }   
    if($operation=='D'){   
        if(substr($result,0,8)==substr(md5(substr($result,8).$key),0,8)){   
            return substr($result,8);   
        }else{   
            return'';   
        }   
    }else{   
        return str_replace('=','',base64_encode($result));   
    }   
}   
```

