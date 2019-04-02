---
title: PHPMailer发送的时候出现的 SMTP connect() failed 错误
top: 0
date: 2019-04-02 16:51:00
categories: PHP
tags:
 - PHPMailer
 - SMTP
---

PHPMailer发送的时候出现的 SMTP connect() failed 错误
以前封装好的方法 测试过没问题的 突然今天有问题了
查了一下 说是 因为从php5.6以后加入了一些安全校验，这样一来在连接有SSL验证的服务器的话，可能就会产生这样的问题。

解决方法就是加入这样一段内容：

```
$mail->SMTPOptions = array(
    'ssl' => array(
        'verify_peer' => false,
        'verify_peer_name' => false,
        'allow_self_signed' => true
    )
);
```

