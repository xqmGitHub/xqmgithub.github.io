---
title: linux下安装composer
top: 0
date: 2019-02-26 14:26:33
categories: PHP
tags:
 - composer
---

```
//安装composer
php -r "copy('https://install.phpcomposer.com/installer', 'composer-setup.php');"
php composer-setup.php
sudo mv composer.phar /usr/local/bin/composer
//切换中国镜像
composer config -g repo.packagist composer https://packagist.phpcomposer.com
//更新composer
composer selfupdate
```

