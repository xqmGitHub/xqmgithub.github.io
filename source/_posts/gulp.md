---
title: 利用 gulp 压缩代码
date: 2018-02-03 14:00:05
categories: Hexo
tags:
 - Gulp
 - Hexo优化
 - 构建工具
sticky: 0
---
右键查看网页源代码发现有大量留白，咋整？
实用的`Gulp`插件，帮助你的博客更加精简，快速。
<!--more-->
*   易于使用
    > 通过代码优于配置的策略，Gulp 让简单的任务简单，复杂的任务可管理。
*   构建快速
    > 利用 Node.js 流的威力，你可以快速构建项目并减少频繁的 IO 操作。
*   插件高质
    > Gulp 严格的插件指南确保插件如你期望的那样简洁高质得工作。
*   易于学习
    > 通过最少的 API，掌握 Gulp 毫不费力，构建工作尽在掌握：如同一系列流管道。

## 安装
先拷贝/创建如下文件 `package.json` (和站点配置文件同级，即根目录)

```
{
  "name": "hexo-site",
  "version": "0.0.0",
  "private": true,
  "hexo": {
    "version": "3.4.0"
  },
  "dependencies": {
    "browser-sync": "^2.18.13",
    "hexo": "^3.2.0",
    "hexo-deployer-git": "^0.3.0",
    "hexo-generator-archive": "^0.1.4",
    "hexo-generator-category": "^0.1.3",
    "hexo-generator-index": "^0.2.1",
    "hexo-generator-index2": "0.0.1",
    "hexo-generator-searchdb": "^1.0.7",
    "hexo-generator-tag": "^0.2.0",
    "hexo-renderer-ejs": "^0.2.0",
    "hexo-renderer-marked": "^0.2.10",
    "hexo-renderer-stylus": "^0.3.1",
    "hexo-server": "^0.2.2"
  },
  "devDependencies": {
    "gulp-asset-rev": "^0.0.15",
    "gulp-clean-css": "^3.9.0",
    "gulp-concat": "^2.6.1",
    "gulp-debug": "^3.1.0",
    "gulp-htmlclean": "^2.7.15",
    "gulp-htmlmin": "^3.0.0",
    "gulp-if": "^2.0.2",
    "gulp-changed": "^3.1.0",
    "gulp-make-css-url-version": "^0.0.13",
    "gulp-modify-css-urls": "^0.2.2",
    "gulp-plumber": "^1.1.0",
    "gulp-uglify": "^3.0.0",
    "gulp-useref": "^3.1.2",
    "gulp-util": "^3.0.8",
    
    "hexo-deployer-git": "^0.3.1",
    "hexo-encrypt": "^0.5.1",
    "hexo-generator-json-content": "^3.0.1",
    "hexo-generator-search": "^2.1.1",
    "hexo-generator-searchdb": "^1.0.8",
    "hexo-server": "^0.2.2",
    "run-sequence": "^2.2.0"
  }
}
```
然后输入

```
npm config set registry https://registry.npm.taobao.org
npm install
```
或者

```
npm install -g cnpm --registry=https://registry.npm.taobao.org
cnpm install
```
会直接安装 `package.json` 文件中的插件，或者可以手动一个一个安装，方式如下：
```
npm install --save-dev gulp-concat
npm install --save-dev gulp-clean-css
npm install --save-dev gulp-uglify
npm install --save-dev gulp-htmlmin
npm install --save-dev gulp-htmlclean
npm install --save-dev gulp-imagemin
...
```

*   `gulp-concat`–合并javascript文件，减少网络请求[文档](https://github.com/wearefractal/gulp-concat)
*   `gulp-clean-css`–压缩css文件，减小文件大小，并给引用url添加版本号避免缓存[文档](https://github.com/scniro/gulp-clean-css)
*   `gulp-uglify`–压缩javascript文件，减小文件大小[文档](https://github.com/terinjokes/gulp-uglify)
*   `gulp-htmlmin`–压缩html，可以压缩页面javascript、css，去除页面空格、注释，删除多余属性等操作[文档](https://github.com/jonschlinkert/gulp-htmlmin)
*   `gulp-htmlclean`–清理html中的部分内容
*   `gulp-imagemin`–压缩 png/jpg/git/svg 格式图片文件[文档](https://github.com/sindresorhus/gulp-imagemin)
*   `browser-sync`–保持多浏览器、多设备同步、在前端开发是非常有用，可谓是必备组件。[文档](http://www.browsersync.io/)
*   `hexo-encrypt`– 加密网页内容，输入密码可查看[文档](http://edolphin.site/2016/05/31/encrypt-post/#comments) [github](https://github.com/edolphin-ydf/hexo-encrypt)


如果在安装的过程中有报类似错误，npm ERR！ errno -4048 npm ERR！ Error：EPERM：operation not permitted, scandir
看我之前写的 [npm install 报错（npm ERR！ errno -4048 npm ERR！ Error：EPERM：operation not permitted, scandir） 解决方法](https://xqmgithub.github.io//npmERR.html)
  


## 配置
根目录下新建文件：`gulpfile.js`

```
var gulp = require('gulp');
var debug = require('gulp-debug');
var cleancss = require('gulp-clean-css');   //css压缩组件
var cssversion = require('gulp-make-css-url-version');   //css资源添加版本号
var uglify = require('gulp-uglify');        //js压缩组件
var htmlmin = require('gulp-htmlmin');      //html压缩组件
var htmlclean = require('gulp-htmlclean');  //html清理组件
var assetRev = require('gulp-asset-rev');   //版本控制插件
var runSequence = require('run-sequence');  //异步执行组件
var changed = require('gulp-changed');      //文件更改校验组件
var gulpif = require('gulp-if')             //任务 帮助调用组件
var plumber = require('gulp-plumber');      //容错组件（发生错误不跳出任务，并报出错误内容）
var isScriptAll = true;     //是否处理所有文件，(true|处理所有文件)(false|只处理有更改的文件)
var isDebug = true;         //是否调试显示 编译通过的文件
// 压缩js文件
gulp.task('compressJs', function () {
    var option = {
        // preserveComments: 'all',//保留所有注释
        mangle: true,           //类型：Boolean 默认：true 是否修改变量名
        compress: true          //类型：Boolean 默认：true 是否完全压缩
    }
    return gulp.src(['./public/**/*.js','!./public/**/*.min.js'])  //排除的js
        .pipe(gulpif(!isScriptAll, changed('./public')))
        .pipe(gulpif(isDebug,debug({title: 'Compress JS:'})))
        .pipe(plumber())
        .pipe(uglify(option))                //调用压缩组件方法uglify(),对合并的文件进行压缩
        .pipe(gulp.dest('./public'));         //输出到目标目录
});
// 压缩css文件
gulp.task('compressCss', function () {
    return gulp.src('./public/**/*.css')
        .pipe(gulpif(!isScriptAll, changed('./public')))
        .pipe(gulpif(isDebug,debug({title: 'Compress CSS:'})))
        .pipe(plumber())
        .pipe(cleancss({rebase: false}))
        .pipe(gulp.dest('./public'));
});
// 压缩html文件
gulp.task('compressHtml', function () {
    var cleanOptions = {
        protect: /<\!--%fooTemplate\b.*?%-->/g,             //忽略处理
        unprotect: /<script [^>]*\btype="text\/x-handlebars-template"[\s\S]+?<\/script>/ig //特殊处理
    }
    var minOption = {
        collapseWhitespace: true,           //压缩HTML
        collapseBooleanAttributes: true,    //省略布尔属性的值  <input checked="true"/> ==> <input />
        removeEmptyAttributes: true,        //删除所有空格作属性值    <input id="" /> ==> <input />
        removeScriptTypeAttributes: true,   //删除<script>的type="text/javascript"
        removeStyleLinkTypeAttributes: true,//删除<style>和<link>的type="text/css"
        removeComments: true,               //清除HTML注释
        minifyJS: true,                     //压缩页面JS
        minifyCSS: true,                    //压缩页面CSS
        minifyURLs: true                    //替换页面URL
    };
    return gulp.src('./public/**/*.html')
        .pipe(gulpif(isDebug,debug({title: 'Compress HTML:'})))
        .pipe(plumber())
        .pipe(htmlclean(cleanOptions))
        .pipe(htmlmin(minOption))
        .pipe(gulp.dest('./public'));
});
// 默认任务
gulp.task('default', function () {
    runSequence.options.ignoreUndefinedTasks = true;
    runSequence('compressHtml','compressCss','compressJs');
});
```
## 执行

准备工作都做好了，执行命令：
1.  编译工程
`hexo -g`
2.  执行 构建工具
`gulp或gulp default`
3.  上传工程
`hexo -d`

这里的这段代码执行 gulp 后不支持 hexo s 本地调试，且必须 deploy 到 Github Pages 上才能查看到效果，具体为啥我也不知道，知道的小伙伴，请在下方评论说明。

