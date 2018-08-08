---
title: 激活(破解) IntelliJ IDEA
top: 0
date: 2018-08-07 14:42:32
categories: 综合
tags:
 - 激活
 - IntelliJ IDEA
---

1. ### 下载破解(crack) jar 包
[地址](http://idea.lanyus.com/jar/JetbrainsCrack-2.7-release-str.jar)
如果失效，去下面这个网站 [http://idea.lanyus.com](http://idea.lanyus.com) 自行下载
<!--more-->
2. ### 下载好了的 crack jar包 放到 idea 的 bin 目录下

3. ### 修改 bin 目录下的 idea.vmoptions 文件
把 idea.vmoptions 文件加一行如下的配置，根据你保存的文件名自行变更
`-javaagent:../bin/JetbrainsCrack-2.7-release-str.jar`
有可能版本或者操作系统不同的原因，有人可能没有 idea.vmoptions，但是有 idea.exe.vmoptions 和 idea64.exe.vmoptions 这两个文件，在这里面进行配置应该也是一样。

4. ### 在 hosts 文件里面添加如下配置
`0.0.0.0 account.jetbrains.com`

5. ### 打开 idea，输入激活码
* 激活码就可以随便填了
* 自定义你的激活信息
  * 没有自己的名字不舒服，没事 下面来教你。刚才你的Activation code不是乱写的吗，如果你填入合适的json格式 就能变成你的
```json
{
"licenseId":"ThisCrackLicenseId",//随便填
"licenseeName":"Name",//你的名字
"assigneeName":"Name",//你的名字
"assigneeEmail":"Name@mail.com",//你的邮箱
"licenseRestriction":"Thanks Rover12421 Crack",//激活信息
"checkConcurrentUse":false,
"products":[//各个产品的代码以及过期时间
{"code":"II","paidUpTo":"2099-12-31"},
{"code":"DM","paidUpTo":"2099-12-31"},
{"code":"AC","paidUpTo":"2099-12-31"},
{"code":"RS0","paidUpTo":"2099-12-31"},
{"code":"WS","paidUpTo":"2099-12-31"},
{"code":"DPN","paidUpTo":"2099-12-31"},
{"code":"RC","paidUpTo":"2099-12-31"},
{"code":"PS","paidUpTo":"2099-12-31"},
{"code":"DC","paidUpTo":"2099-12-31"},
{"code":"RM","paidUpTo":"2099-12-31"},
{"code":"CL","paidUpTo":"2099-12-31"},
{"code":"PC","paidUpTo":"2099-12-31"},
{"code":"DB","paidUpTo":"2099-12-31"},
{"code":"GO","paidUpTo":"2099-12-31"},
{"code":"RD","paidUpTo":"2099-12-31"}
],
"hash":"2911276/0",
"gracePeriodDays":7,
"autoProlongated":false
}
```


6. ### 应该没啥问题了
现在打开你的 idea 看看是不是已经注册到 2099 年了，应该够你用一辈子了吧
