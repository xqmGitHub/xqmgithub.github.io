---
title: php排序之快速排序、冒泡排序
id: 188
categories:
  - PHP
date: 2017-02-24 11:43:34
tags:
 - 快速排序
 - 冒泡排序
---

通过一趟排序将要排序的数据分割成独立的两部分，其中一部分的所有数据都比另外一部分的所有数据都要小，然后再按此方法对这两部分数据分别进行快速排序，整个排序过程可以`递归`进行，以此达到整个数据变成有序序列。

<!--more-->

### 快速排序
![quick_sort](https://xqmblog.files.wordpress.com/2017/02/quick_sort.gif)
```
    //快速排序
    function quick_sort($array)
    {
        $size=count($array);//得到数组总长度
        if($size>1)
        {
            $first=$array[0];//拿出第一个作为标尺
            $front=array();//前面的数组 存比标尺小的数
            $back=array();//后面的数组 存比标尺大的数
            for ($i=1; $i < $size; $i++) 
            { 
                if($array[$i]<=$first)
                {
                    $front[]=$array[$i];//如果小于等于标尺 就放入前面的数组
                }else
                {
                    $back[]=$array[$i];//如果大于标尺 就放入后面的数组
                }
            }
            $front=quick_sort($front);//递归的对前面一半数组排序
            $back=quick_sort($back);//递归的对后面一半数组排序
            return array_merge($front,array($first),$back);//合并开始前面 中间 后面
        }else
        {
            return $array;//如果数组只有一个长度 没必要排序 直接返回
        }
    }
    //调用
    $array=array(10,9,8,7,6,5,4,3,2,1);
    $result=my_quick_sort($array);
    var_dump($result);
    //输出
    array(10) { [0]=> int(1) [1]=> int(2) [2]=> int(3) [3]=> int(4) [4]=> int(5) [5]=> int(6) [6]=> int(7) [7]=> int(8) [8]=> int(9) [9]=> int(10) }

```
### 冒泡排序
冒泡排序比较简单。作为很多公司面试笔试题常常出现，要求手写该排序算法。
双层循环，不断的与后面的比较，如果大于后面的，调换两者顺序即可。
    演示效果如图：
![bubblesort](https://xqmblog.files.wordpress.com/2017/02/bubblesort.gif)
```
    //冒泡排序
    function bubbleSort($array=array())
    {
        $length=count($array);//获取数组长度
        for ($i=0; $i < $length ; $i++)
        {
            //循环数组
            for ($j=$i+1; $j < $length ; $j++)
            {
                //本身与本身后面的人进行比较
                if($array[$i]>$array[$j])
                {
                    //顺序不对 要调换  实现冒泡
                    //两数换值
                    $tmp=$array[$i];//将第一个值给临时变量
                    $array[$i]=$array[$j];//把j的值给i
                    $array[$j]=$tmp;//把tmp给j
                }
            }
        }
        return $array;//返回数组
    }
    //调用
    $array=array(10,9,8,7,6,5,4,3,2,1);
    $result=bubbleSort($array);
    var_dump($result);
	//输出
	array(10) { [0]=> int(1) [1]=> int(2) [2]=> int(3) [3]=> int(4) [4]=> int(5) [5]=> int(6) [6]=> int(7) [7]=> int(8) [8]=> int(9) [9]=> int(10) }
```