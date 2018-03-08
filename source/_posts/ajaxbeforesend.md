---
title: JQuery中巧用Ajax的beforeSend方法
id: 536
categories:
  - JavaScript
date: 2017-08-17 19:28:38
tags:
 - Ajax
 - beforeSend
---
jQuery是经常使用的一个开源js框架，其中的$.ajax请求中有一个**beforeSend**方法，用于在向服务器发送请求前执行一些动作。
<!--more-->
```$.ajax({
beforeSend: function(){
// Handle the beforeSend event
},
complete: function(){
// Handle the complete event
}
// ......
});
```

**防止重复数据**
在实际项目开发中，提交表单时常常由于网络或者其原因，用户点击提交按钮误认为自己没有操作成功，进而会重复提交按钮操作次数，如果页面前端代码没有做一些相应的处理，通常会导致多条同样的数据插入数据库，导致脏数据的增加。要避免这种现象，在$.ajax请求中的beforeSend方法中把提交按钮禁用掉，等到Ajax请求执行完毕，在恢复按钮的可用状态。

```
// 提交表单数据到后台处理
$.ajax({
type: "post",
data: studentInfo,
contentType: "application/json",
url: "/Home/Submit",
beforeSend: function ()
{
// 禁用按钮防止重复提交
    $("#submit") . attr({ disabled: "disabled" });
}, success: function (data) {
    if (data == "Success") {
        //清空输入框
        clearBox();
    }
},complete: function ()
{
    $("#submit") . removeAttr("disabled");
},error: function (data) {
    console . info("error: " + data . responseText);
}
});
```


ajax请求服务器加载数据列表时提示loading(“加载中，请稍后...”)
```
$.ajax({
type: "post",
contentType: "application/json",
url: "/Home/GetList",
beforeSend: function ()
{
    $("loading") . show();
}, success: function (data) {
    if (data == "Success") {
// ...
    }
}, complete: function ()
{
    $("loading") . hide();
}, error: function (data) {
    console . info("error: " + data . responseText);
}
});
```
