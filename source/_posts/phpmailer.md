---
title: PHPMailer发邮件
tags:
  - PHPMailer
id: 445
categories:
  - PHP
date: 2017-06-10 18:45:21
---
**PHPMailer 是一个强大的 PHP 编写的邮件发送类，使用它可以更加便捷的发送邮件，并且还能发送附件和 HTML 格式的邮件，同时还能使用 SMTP 服务器来发送邮件。**
<!--more-->

PHPMailer支持多种邮件发送方式

qq邮箱为例

进入qq邮箱点击设置，选中账户选项，在账户下设置POP3/IMAP/SMTP/Exchange/CardDAV/CalDAV服务：

![mail](https://xqmblog.files.wordpress.com/2017/06/mail.png)

授权码 也是要用到的  自己去验证

引用了两个文件 [class.phpmailer.php、class.smtp.php](https://github.com/PHPMailer/PHPMailer)

写发邮件函数

```
function sendMail($body) {
    // mail($toaddress, $subject, $mailcontent, $fromaddress);
    date_default_timezone_set('Asia/Shanghai');//设定时区东八区
    require_once('class.phpmailer.php');
    include('class.smtp.php');
    $mail = new PHPMailer;
    $mail->SMTPDebug = 2;                               // Enable verbose debug output
    $mail->isSMTP();                                      // Set mailer to use SMTP
    $mail->Host = 'smtp.qq.com';  // Specify main and backup SMTP servers
    $mail->SMTPAuth = true;                               // Enable SMTP authentication
    $mail->Username = '***';                 // SMTP 账号（一般是qq号）
    $mail->Password = '****';    // SMTP 授权码 （这个是上面生成的授权码）
    $mail->SMTPSecure = 'ssl';                            // Enable TLS encryption, `ssl` also accepted
    $mail->Port = 465;  //端口号
    $mail->Host;                                  // TCP port to connect to
    $mail->setFrom('***@qq.com', 'Mailer'); //发件人地址，称呼
    // $mail->addAddress('***@qq.com', 'Joe User');     // Add a recipient
    $mail->addAddress('***@qq.com');               // 收件人
    //$mail->addReplyTo('***@qq.com', 'Information');
    // $mail->addCC('***@qq.com');
    // $mail->addBCC('***@qq.com');
    // $mail->addAttachment('/var/tmp/file.tar.gz');         // Add attachments
    // $mail->addAttachment('/tmp/image.jpg');    //附件（注意路径）
    $mail->isHTML(false);                                  // Set email format to HTML
    $mail->Subject = 'Here is the subject';//标题
    $mail->Body    = $body; //内容
    $mail->AltBody = 'This is the body in plain text for non-HTML mail clients';
    if(!$mail->send()) {
        echo 'Message could not be sent.';
        echo 'Mailer Error: ' . $mail->ErrorInfo;
    } else {
        echo ucwords('Message has been sent');
    }
}
```

调用sendMail就可以了 
这个知识简单的实现了发送邮件
具体的自己灵活运用

