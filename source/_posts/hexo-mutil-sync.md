---
title: 多终端编辑hexo博客
date: 2018-03-08 14:19:45
categories: Hexo
tags:
 - Hexo
 - 多终端
 - 同步
---
如果我想要在公司写博客怎么办，或者说如果我换电脑了怎么办，因为在github中的我们github.io项目是只有编译后的文件的，没有源文件的，也就是说，如果我们的电脑坏了，打不开了，我们的博客就不能进行更新了，所以需要把源文件也上传到github上，然后对我们的源文件进行版本管理，这样我们就可以在另一台电脑上pull我们的源码，然后编译完之后push上去。

<!--more-->

### 思路

同步思路与Github推拉源码思路相同，使用git指令，保持本地的博客文件与Github上的博客文件相同即可
仓库分两个分支：hexo和master。hexo作为默认分支，存放博客源代码，master分支存放博客生成页面。

### 创建hexo分支

默认已经有 master 分支了，创建 hexo 就可以了（名字不一定要hexo），并将hexo设置为默认分支（**Default branch**）
- 这个hexo分支就是存放我们源文件的分支，我们只需要更新hexo分支上的内容据就好，master上的分支hexo编译的时候会更新的

### 配置gitignore文件

为了筛选出配置文件、主题目录、博文等重要信息，作为需要GItHub管理的文件
public内文件是根据source文件夹内容自动生成，不需要备份，不然每次改动内容太多
即使是私有仓库，除去在线服务商员工可以看到的风险外，还有云服务商被攻击造成泄漏等可能，所以不建议将配置文件传上去
```
.DS_Store
Thumbs.db
db.json
*.log
node_modules/
public/
.deploy*/
_config.yml

```
### 初始化仓库及提交

然后我们再初始化仓库，重新对我们的代码进行版本控制

```
git init  //初始化本地仓库
git add -A //添加本地所有文件到仓库		
git commit -m "blog源文件" //添加commit
git branch hexo //添加本地仓库分支hexo
git remote add origin <server>	//添加远程仓库 <server> 是指在线仓库的地址 origin是本地分支,remote add操作会将本地仓库映射到云端
git push origin hexo //将本地仓库的源文件推送到远程仓库hexo分支

```
这时候博客的源文件就同步到github的hexo分支上了。

<blockquote class="blockquote-center">注意这里有个坑！！！如果你用的是第三方的主题theme，是使用git clone下来的话，要把主题文件夹下面把.git文件夹删除掉，不然主题无法push到远程仓库，导致你发布的博客是一片空白。</blockquote>

### 另一台电脑的操作

- 首先需要搭建环境（Node，Git）

- 直接clone下来，修改发布后提交本地修改到远程master分支就ok.

将hexo分支clone到本地，再进入目录安装npm

```
git clone <server> hexo //<server> 是指在线仓库的地址
cd hexo 
npm install
```
`npm install`的时候会根据package.json中的插件列表自动加载相应插件。
本机的同步完成。

<blockquote class="blockquote-center">因为在上传博客源文件的时候忽略了配置文件（`_config.yml`这是站点的配置文件）的上传，也就是没有上传配置文件的，在克隆下来的时候记得把配置文件拿过来，不然会报错。主题里面的配置文件也要（`themes/next/_config.yml`这是主题配置文件）</blockquote>
