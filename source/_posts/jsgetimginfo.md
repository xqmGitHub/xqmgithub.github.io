---
title: js获取图片名称、大小、类型、上次修改时间
id: 565
categories:
  - JavaScript
date: 2017-08-28 16:48:31
tags:
 - 图片信息
---

input[type='file']上传图片时，获取图片的基本信息（名称、大小、类型和修改时间）
<!--more-->
html代码：

```
<div class="upload-img">
    <div class="input">
        <label>上传图片:</label>
        <input type="file" id="input-file" class="input-file">
    </div>
    <div class="show-img">
        <label>图片预览:</label>
        <img src="" id="show-img">
    </div>
    <div class="show-info" id="show-info">
    </div>
</div>
```

js代码：
```
document.getElementById('input-file').addEventListener('change',function () {
    var files=this.files, //FileList，类数组，不是数组哦
        file=files[0],
        fileName=file.name,//文件名
        fileType=file.type,//文件类型
        fileSize=file.size,//文件大小
        modifiedDate=file.lastModifiedDate,//上次修改时间
        html='';
    getImageSize(file,function (imgWidth,imgHeight) {
        html='文件名称：'+fileName+'
            +'文件类型：'+fileType+'
            +'文件大小：'+fileSize+'
            +'上次修改时间：'+modifiedDate+'
            +'文件宽高：'+imgWidth+'----'+imgHeight;
        document.getElementById('show-info').innerHTML=html;
    });
});

//获取选择图片的宽高
function getImageSize(file,callback) {
    var render=new FileReader();
    render.onload=function (e) {
        var data=e.target.result;//读取的结果
        var image=new Image();
        image.onload=function () {
            var width=image.width,
                height=image.height;
            callback(width,height);
        };
        image.src=data;
        //预览图片
        document.getElementById('show-img').src=data;
    };
    render.readAsDataURL(file);
}
```


转：http://y.dobit.top/Detail/312.html