---
title: Hexo部署到 Github Pages 文件夹大小写问题
date: 2018-02-01 17:53:36
categories: Hexo
tags:
 - Git
 - Hexo
---
使用 Hexo 部署博客到 Github Pages 时经常会遇到文件夹大小写问题导致的 404问题。

比如 Hexo 生成了一个 `php` Category文件夹，但是我后来把它改成了`PHP`，即 改成大写了。Hexo会生成正确，但部署到 Github 上却老是不正确。
<!--more-->
**原因**
那是因为 git 默认忽略文件名大小写，所以即使文件夹大小写变更，git 也检测不到。

 **解决办法**
*  进入到博客项目中 `.deploy_git`文件夹，修改 `.git` 下的 `config` 文件，将 `ignorecase=true` 改为 `ignorecase=false`

*   使用 Hexo 再次生成及部署
