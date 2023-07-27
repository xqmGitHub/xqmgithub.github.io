---
title: 利用CSS改变图片颜色的100种方法！
top: 0
date: 2018-11-07 17:00:38
categories: CSS
tags:
 - css
 - filter
---

### 前言

> “说到对图片进行处理，我们经常会想到PhotoShop这类的图像处理工具。作为前端开发者，我们经常会需要处理一些特效，例如根据不同的状态，让图标显示不同的颜色。或者是hover的时候，对图片的对比度，阴影进行处理。”
> 
> 本文略长，请耐心阅读

![](https://mmbiz.qpic.cn/mmbiz_png/12mPmHVcSulMDl8IsL3PkRVPHH5eFHQUeOr6qcW9OXbqYp4pribI0vx3TtBIjzA2sBdt4uIdiaseoBs7lNkia8qEQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

你以为这些是经过PS软件处理出来的？不不不，纯粹的是用css写出来的，很神奇把。 
<!--more-->
### 强大的 CSS:filter

CSS滤镜（filter）属提供的图形特效，像模糊，锐化或元素变色。过滤器通常被用于调整图片，背景和边界的渲染。 MDN

CSS标准里包含了一些已实现预定义效果的函数。
```language
filter: none        
    | blur() 
    | brightness() 
    | contrast() 
    | drop-shadow() 
    | grayscale() 
    | hue-rotate() 
    | invert() 
    | opacity() 
    | saturate() 
    | sepia() 
    | url();
```

![](https://mmbiz.qpic.cn/mmbiz_jpg/12mPmHVcSulMDl8IsL3PkRVPHH5eFHQUeVNib7icTbV168s8DxUlOIXiawZ1ich0zEic1RPjTGKRmy0LcbhpS6aHZnA/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

#### **filter: none**

没有任何效果，默认filter就为none

#### **filter:blur( ) 高斯模糊**

给图像一个高斯模糊效果，length值越大，图像越模糊

我们来尝试一下
```CSS
img {
    filter:blur(2px);;
}
```


![](https://mmbiz.qpic.cn/mmbiz_png/12mPmHVcSulMDl8IsL3PkRVPHH5eFHQUwkn2iapNGGZ11rlSnf5udoephrtsPnOS31DeicuwNQFibYwribToRUwibDw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

#### **brightness(%) 线性乘法**

可以让图片看起来更亮或者更暗
```CSS
img {
    filter:brightness(70%);
}
```

![](https://mmbiz.qpic.cn/mmbiz_png/12mPmHVcSulMDl8IsL3PkRVPHH5eFHQUsSQJ4BJ9OdW1uibC5uBWSOoNfLzGQU6icuSO85esibibYMMOgqysM51Lag/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

#### **contrast(%) 对比度**

调整图像的对比度。
```CSS
img {
    filter:contrast(50%);
}
```

![](https://mmbiz.qpic.cn/mmbiz_png/12mPmHVcSulMDl8IsL3PkRVPHH5eFHQUb4epYBZZzP4SqibDILaNopvrpa7FSHlV2hsonicrvSLFmPKUbJOW1gbg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

#### **drop-shadow(h-shadow v-shadow blur spread color)**

给图像设置一个阴影效果。阴影是合成在图像下面，可以有模糊度的，可以以特定颜色画出的遮罩图的偏移版本。 函数接受<shadow>(在CSS3背景中定义)类型的值，除了"inset"关键字是不允许的。该函数与已有的box-shadow box-shadow属性很相似；不同之处在于，通过滤镜，一些浏览器为了更好的性能会提供硬件加速

利用这个方案，我们其实改变类似于一些图标的颜色，比如黑色的图标变成蓝色的图标。

PNG格式小图标的CSS任意颜色赋色技术
```CSS
img {
    filter: drop-shadow(705px 0 0 #ccc);
}
```

在这里，我们将图片投影形成一个同等大小的灰色区域。 

![](https://mmbiz.qpic.cn/mmbiz_png/12mPmHVcSulMDl8IsL3PkRVPHH5eFHQUeKYTUonMmib7d3VWD99lOwWL4QH6mAcKNsTYo4y22asbFwOCicoGMq1A/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

#### **hue-rotate(deg) 色相旋转**
```CSS
img {
    filter:hue-rotate(70deg);
}
```

看，我的小姐姐变成了阿凡达！ 

![](https://mmbiz.qpic.cn/mmbiz_png/12mPmHVcSulMDl8IsL3PkRVPHH5eFHQUDap70z7gcQrjwM967vCqMTqKfX0IKgG2hnlJarciaVLKuVnlZlWv0mQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

#### **invert(%) 反转**

这个函数的作用是反转输入图像，有点像曝光的效果

```CSS
img {
    filter:invert(100%)
}
```

![](https://mmbiz.qpic.cn/mmbiz_png/12mPmHVcSulMDl8IsL3PkRVPHH5eFHQUUk46UqCicvibM896s5TzsyibmWcQzOiaH0hhyZZVsFJ03AP4Xs9OdpOP7g/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

#### **grayscale(%) 将图像转换为灰度图像**

这个效果可以将图片做旧，有一种时代沧桑感。喜欢古风的人一定会喜欢上这个效果的
```CSS
img {
    filter:grayscale(80%);
}
```

![](https://mmbiz.qpic.cn/mmbiz_png/12mPmHVcSulMDl8IsL3PkRVPHH5eFHQUBWpx9JZbZ4DQ0AV0iaSE5IFNnCcgicXE9OHibMZF0zz7wmXrchcylFUuw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

除了古风还有一种用法是有的时候需要将全站变成灰色，如大屠杀纪念日的时候。

![](https://mmbiz.qpic.cn/mmbiz_png/12mPmHVcSulMDl8IsL3PkRVPHH5eFHQU1icGCC9gLMnQf7H3xyZXmb06l3bO0TzVDlbRN3ibZouR9TJ8FGibnltYg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

可以这样设置
```CSS
*{
    filter: grayscale(100%);
    -webkit-filter: grayscale(100%);
    -moz-filter: grayscale(100%);
    -ms-filter: grayscale(100%);
    -o-filter: grayscale(100%);
} 
```

#### **sepia(%) 将图像转换为深褐色**

下面给我的小姐姐一个暖暖的色调。
```CSS
img {
    filter:sepia(50%)
}
```


![](https://mmbiz.qpic.cn/mmbiz_png/12mPmHVcSulMDl8IsL3PkRVPHH5eFHQU0PjA1V9M2RLHRnONrYHF6X6nmDRfdSUVBiaTb8jYtUaSoYvsAcAy59A/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

大家是不是发现我并没有把url()方法写到这上面来

没错，因为我想把这个内容放到最后来说，filter:url()就是css滤镜改变图片的终极方法。CSS:filter可以导入一个svg滤镜，作为他自己的滤镜。

### 终极变色解决方案！ filter:url();

为什么说filter:url()是图片变色的终极解决方案呢，请容我慢慢道来。

我们先科普一下PS的工作原理，我们都知道网页是有三原色的R(红) G(绿) B(蓝)，常见的RGBA还包括一个opicity值，而opcity值是根据alpha通道计算出来的。也就是说，我们见到的网页的每一个像素点都是由红蓝绿再加alpha四个通道组成，每一个通道我们称之为色板，PS中的8位板的意思就是2的八次方256，意思就是每一个通道的取值范围都是(0-255) --SVG 研究之路 (11) - filter:feColorMatrix

如果我们可以改变每个通道的值是不是就能完美的得到我们想要的任意颜色了呢，原理上，我们可以像ps那样利用svg滤镜得到任何我们想要的图像，不仅仅是变色。我们甚至可以凭空生成一幅图像。

#### **svg feColorMatrix大法好**
```
<svg height="0" xmlns="http://www.w3.org/2000/svg">
    <defs>
        <filter id="change">
                <feColorMatrix type="matrix" values="
                0 0 0 0 0.55
                0 0 0 0 0.23 
                0 0 0 0 0 
                0 0 0 0 1" />
        </filter>
    </defs>
</svg>
<img src="https://note.youdao.com/yws/res/237/WEBRESOURCE7e77df2551fe1a1db1b9d91f4d518917" alt="">
```

```CSS
img {
    filter:url(#change);
} 

```

通过单通道我们可以将图片变成单一的颜色 

![](https://mmbiz.qpic.cn/mmbiz_png/12mPmHVcSulMDl8IsL3PkRVPHH5eFHQUyvOI2vOpnycBHHdHt7CXS3rkXdkF9iaguiaOW0cWdKRKm1l56ibUNxic9w/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)
```
<svg height="0" xmlns="http://www.w3.org/2000/svg">
    <defs>
        <filter id="change">
               <feColorMatrix values="3 -1 -1 0 0
                       -1 3 -1 0 0
                       -1 -1 3 0 0
                       0 0 0 1 0" />
        </filter>
    </defs>
</svg>

```

通过双通道我们可以的到一些非常炫酷的PS效果

![](https://mmbiz.qpic.cn/mmbiz_png/12mPmHVcSulMDl8IsL3PkRVPHH5eFHQUvq9Zp4iacyDMAdumibkHv9NyMDMvvwoyRZ4jHtpeI7uqUvQwgAwfTVfA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

当然，在这里，只是举个例子，通过配置矩阵中的值，我们可以配置每一个像素点的值按照我们定义的规则显示

我们在这里详细讲一下feColorMatrix 矩阵的计算方式

![](https://mmbiz.qpic.cn/mmbiz_png/12mPmHVcSulMDl8IsL3PkRVPHH5eFHQUvxHazaibz58acaSZGoicicbKxE9iawv6ViaiaCkaUSnHXwob8uwJ82g10wuQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

其中Rin Gi

n Bin a(alpha) 为原始图片中每个像素点的rgba值

通过矩阵计算，得到的Rout Gout Bout Aout就是最终显示出来的rgba值。

#### 将图片转为单色 拿棕色rgba(140,59,0,1)作为例子

根据上面的公式，我们可以简化一些计算，同一行中，只设置一个通道的值，其他通道为0

不难得出矩阵
```
0 0 0 0 目标值R
0 0 0 0 目标值G
0 0 0 0 目标值B
0 0 0 0 1
```



根据规则，只需要计算，255/想要显示的颜色对应通道 = 目标值

我们想要的棕色rgba(140,59,0,1) 换算成色板 rgba 为 140 59 0 255

可以算出目标值
```
0 0 0 0 0.55
0 0 0 0 0.23
0 0 0 0 0 
0 0 0 0 1
```

#### 多通道设置出炫酷的效果来

就如同之前我们看到的双通道形成的炫酷图片一般

> 我們今天要把圖片的飽和度提高，該怎麼做呢？首先當然是想想飽和度的成因，就是紅的越紅，藍的越藍，綠的越綠，由這個成因出發，我們的矩陣就可以寫成下面的樣子，看到矩陣當中出現了 3 和 -1，一定會很那悶這是怎麼來的，箇中原理其實很容易理解，讓我們假設某一個像素的 RGB 分別是 (200/255),(100/255),(50/255)，呈現的應該是有點暗沉的橘色，經過矩陣的換算，R 變成了 200/255x3-100/255-50/255= 1.76, G 變成 200/255x(-1)+100/255*3-50/255=0.2，B 變成 200x(-1)+100x(-1)+50x3=-0.59，因此 RGB 轉換後就是：200x1.76,100x0.2,50x-0.5。SVG 研究之路 (11) - filter:feColorMatrix

```
<svg height="0" xmlns="http://www.w3.org/2000/svg">
    <defs>
        <filter id="change">
               <feColorMatrix values="3 -1 -1 0 0
                       -1 3 -1 0 0
                       -1 -1 3 0 0
                       0 0 0 1 0" />
        </filter>
    </defs>
</svg>
```


#### 其他方案

除了feColorMatrix svg滤镜还有很多的方法可以定义滤镜，他们同样可以作用到图片上。由于篇幅限制，这里就不详细展开了

### 总结

*   css3提供了filter这个属性，使得通过前端技术实现更多炫酷的特效成为了可能

*   依赖于svg的滤镜，我们可以实现复杂的滤镜效果

### 注意

*   css：filter与ie上的filter并不是相同的概念

*   css:filter在不同的浏览器上兼容性不一样，您在使用的时候需要注意浏览器的兼容性 

*   ![](https://mmbiz.qpic.cn/mmbiz_png/12mPmHVcSulMDl8IsL3PkRVPHH5eFHQUE6C2hjmt3YHfkqexOOKAiaYf9WJp83GyvhGvDD2sVDbyXFSeeKbIh4g/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

### 参考文献

*   SVG 研究之路 (11) - filter:feColorMatrix

*   css:filter MDN

*   Color Filters Can Turn Your Gray Skies Blue

*   PNG格式小图标的CSS任意颜色赋色技术

### 写在最后

本次源码我已经放在了[codePen]( https://codepen.io/nanhupatar/pen/eLQoVM)上 欢迎查看

文章难免会有疏漏，希望大家能够指正批评

原文出处： [前端指南](https://mp.weixin.qq.com/s/_8vpfui02sW7DFG-1TXnsw)
