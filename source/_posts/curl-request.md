---
title: PHP cURL实现发送Get和Post请求
id: 167
categories:
  - PHP
date: 2017-02-21 17:18:01
tags:
 -  cURL
---
cURL可以使用URL的语法模拟浏览器来传输数据
因为它是模拟浏览器，因此它同样支持多种协议，FTP, FTPS, HTTP, HTTPS, GOPHER, TELNET, DICT, FILE 以及 LDAP等协议都可以很好的支持，包括一些：HTTPS认证，HTTP POST方法，HTTP PUT方法，FTP上传，keyberos认证，HTTP上传，代理服务器，cookies，用户名/密码认证，下载文件断点续传，上传文件断点续传，http代理服务器管道，甚至它还支持IPv6，scoket5代理服务器，通过http代理服务器上传文件到FTP服务器等等。
<!--more-->
下面是把**post**和**get**请求封装成了一个方法，方便调用
```
/**
* curl 函数
* @param string $url 请求的地址
* @param string $type POST/GET/post/get
* @param array $data 要传输的数据
* @param string $err_msg 可选的错误信息（引用传递）
* @param int $timeout 超时时间
* @param array $cert_info 证书信息
*/
public function curl_request($url, $type, $data = false, $err_msg = null, $timeout = 20, $cert_info = array())
{
    $type = strtoupper($type);
    if ($type == 'GET' && is_array($data)) {
        $data = http_build_query($data);
    }
    $option = array();
    if ( $type == 'POST' ) {
        $option[CURLOPT_POST] = 1;
    }
    if ($data) {
        if ($type == 'POST') {
            $option[CURLOPT_POSTFIELDS] = $data;
        } elseif ($type == 'GET') {
            $url = strpos($url, '?') !== false ? $url.'&'.$data :  $url.'?'.$data;
        }
    }
    $option[CURLOPT_URL]            = $url;
    $option[CURLOPT_FOLLOWLOCATION] = TRUE;
    $option[CURLOPT_MAXREDIRS]      = 4;
    $option[CURLOPT_RETURNTRANSFER] = TRUE;
    $option[CURLOPT_TIMEOUT]        = $timeout;
    //设置证书信息
    if(!empty($cert_info) && !empty($cert_info['cert_file'])) {
    $option[CURLOPT_SSLCERT]       = $cert_info['cert_file'];
    $option[CURLOPT_SSLCERTPASSWD] = $cert_info['cert_pass'];
    $option[CURLOPT_SSLCERTTYPE]   = $cert_info['cert_type'];
    }
    //设置CA
    if(!empty($cert_info['ca_file'])) {
        // 对认证证书来源的检查，0表示阻止对证书的合法性的检查。1需要设置CURLOPT_CAINFO
        $option[CURLOPT_SSL_VERIFYPEER] = 1;
        $option[CURLOPT_CAINFO] = $cert_info['ca_file'];
    } else {
        // 对认证证书来源的检查，0表示阻止对证书的合法性的检查。1需要设置CURLOPT_CAINFO
        $option[CURLOPT_SSL_VERIFYPEER] = 0;
    }
    //初始化
    $ch = curl_init();
    curl_setopt_array($ch, $option);
    //设置，访问页面的来源地址
    curl_setopt($ch,CURLOPT_REFERER,"http://".$_SERVER['HTTP_HOST']);
    //执行并获取结果 
    $response = curl_exec($ch);
    $curl_no  = curl_errno($ch);
    $curl_err = curl_error($ch);
    //释放cURL句柄
    curl_close($ch);
    // error_log
    if($curl_no > 0) {
        if($err_msg !== null) {
            $err_msg = '('.$curl_no.')'.$curl_err;
        }
    }
    return $response;
}
```
