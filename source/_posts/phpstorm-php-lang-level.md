---
title: "修改 PhpStorm 的默认 PHP 版本语法为 7.0+"
top: 0
date: 2019-11-28 09:20:02
categories: PHP
tags:
- phpstorm
---

在项目中使用 PHP7 新特性时 PHPStorm 出现了红色波浪线错误，鼠标移上去看，提示 `Coalesce operator is available in PHP 7 Only`，这明显不是代码错误，项目基于 PHP7.0+的，有点强迫症，必须把这个给干掉
<!--more-->
首先自己的机子上的 PHP 版本是 7.3.8 的，排除安装的 PHP 版本过低的问题
查了一下发现 PHPStorm 默认支持的 PHP 版本语法问题
通过在偏好设置中查看发现默认是 PHP5.6 ，修改为 PHP7.+ 即可
在 `Setting -> Languagers & Framework -> PHP` 可看到 `PHP language level` 是 5.6 的
但状态时不可编辑的，是因为 PhpStorm 自动开启了 Composer 配置文件同步的机制，只需要关闭就可以编辑了
在 `Setting -> Languagers & Framework -> PHP -> Composer -> Synchronize IDE Setting with composer.json` 默认勾选了，取消勾选 然后 Apple 应用
这时候 `Setting -> Languagers & Framework -> PHP ` 的 `PHP language level` 可以编辑了 选一个 PHP7.+ 的 选好 Apply 并点击 OK 保存

这就修改成功了
红色波浪错误不见了，看着舒服多了

比较懒 就不上图了
