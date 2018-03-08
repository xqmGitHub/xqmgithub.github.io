---
title: checkall
date: 2018-01-31 14:58:59
categorys: JavaScript
tags:
---
让复选框全部选中和全部取消是比较常用的
<!--more-->
**JavaScript部分：**

```
function checkAll(obj){
    $("#box input[type='checkbox']").prop('checked', $(obj).prop('checked'));
}
```
**html部分：**

```
<div id="box">
    <input type="checkbox" onclick="checkAll(this)">全选<br>
    <input type="checkbox"><br>
    <input type="checkbox"><br>
    <input type="checkbox"><br>
    <input type="checkbox"><br>
    <input type="checkbox"><br>
    <input type="checkbox"><br>
    <input type="checkbox"><br>
    <input type="checkbox"><br>
    <input type="checkbox"><br>
</div>
```

