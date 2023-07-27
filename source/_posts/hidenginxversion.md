---
title: 隐藏Nginx版本号
id: 548
categories:
  - Nginx
date: 2017-08-24 18:44:38
tags:
 - Nginx
---
隐藏Nginx版本号，Nginx的版本号主要在两个地方会有，
<!--more-->
第一个是HTTP header，有个Server:nginx/1.x.x类似会暴露Web服务器所用软件名称以及版本号，这个也是大多数Web服务器最容易暴露版本号的地方，如下：

```[root@bkjz ~]# curl -I www.nginx.org
HTTP/1.1 200 OK
Server: nginx/0.8.44
Date: Tue, 13 Jul 2010 14:05:11 GMT
Content-Type: text/html
Content-Length: 8284
Last-Modified: Tue, 13 Jul 2010 12:00:13 GMT
Connection: keep-alive
Keep-Alive: timeout=15
Accept-Ranges: bytes
```

第二个地方是Nginx出错页面，比如404页面没有找到等，这是如果用户没有指定页面的话，那么Nginx自己的页面会有版本号。

但是可以修改配置文件来打达我们的目的

1.打开Nginx主配置文件：nginx.conf，取消注释或添加配置语句。
```
http {
   # ...省略一些配置
　　sendfile on;
　　tcp_nopush on;
　　keepalive_timeout 60;
　　tcp_nodelay on;
    server_tokens off; 　　#默认是注释掉的
　　# ...省略一些配置
}
```
2.编辑php-fpm配置文件，如fastcgi.conf或fcgi.conf（这个配置文件名也可以自定义的，根据具体文件名修改）

找到：
`fastcgi_param SERVER_SOFTWARE nginx/$nginx_version;`

改为：
`fastcgi_param SERVER_SOFTWARE nginx;`

3.重启

这样就完全对外隐藏了nginx版本号了，就是出现404、501等页面也不会显示nginx版本。