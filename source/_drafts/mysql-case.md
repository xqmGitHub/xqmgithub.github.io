在做运营后台时，遇到了需要同时对多节课程进行序号更改的场景。就在思考，如何使用一条SQL，对不同 `ID`的课程进行排序（`sort`）修改。最后通过标准SQL的 `CASE...WHEN` 解决了问题（原本以为是存储过程的语法，原来是标准SQL）。

例如，假设有三节课程 A、B、C，当前三节课程的序号分别为第一节、第二节、第三节。现在需要将课程A更改为第三节，课程B更改为第一节，课程C更改为第二节。课程与课程之间，不能出现重复排序的课程。也就是说，课程的排序是唯一的。

![img](https:////upload-images.jianshu.io/upload_images/1674837-14e6635e3f944446.png?imageMogr2/auto-orient/strip|imageView2/2/w/398/format/webp)

课程排序前

排序后：

![img](https:////upload-images.jianshu.io/upload_images/1674837-88ec080a62f0dcde.png?imageMogr2/auto-orient/strip|imageView2/2/w/368/format/webp)

课程更改排序后

# CASE...WHEN 基本介绍

**作用：**CASE 函数允许根据筛选条件，当与第一个条件符合时返回一个值。
 **适用场景：**适用于一个条件判断有多种值分别执行不同的操作的场景。
 **语法：**

```xml
CASE <单值表达式>
    WHEN <表达式值> THEN <SQL语句或返回值>
    WHEN <表达式值> THEN <SQL语句或返回值>
   ...
    WHEN <表达式值> THEN <SQL语句或返回值>
    ELSE <SQL语句或返回值>
END
```

## 用法

### 用法一

将单值描述放入`case`后

```php
SELECT *,
       (CASE sex  # 注意此处 sex
            WHEN '1' THEN '男'
            WHEN '0' THEN '女'
            ELSE '保密'
        END) AS sex_text
FROM USER
```

### 用法二（推荐用法）

```php
SELECT *,
       (CASE
            WHEN sex='1' THEN '男'
            WHEN sex='0' THEN '女'
            ELSE '保密'
        END) AS sex_text
FROM USER
```

方法一适用于等值条件判断场景，不适用于不等于、大于、小于的判断。
 方法二适用于复杂判断场景，可用于等于、不等于、大于、小于的判断。且使用组合判断。

组合判断例子如下：

```php
CASE
    WHEN score>=90 THEN '优秀'
    WHEN score<90
         AND score >=80 THEN '良好'
    WHEN score<80
         AND score>=60 THEN '普通'
    ELSE '不及格'
END
```

# 使用注意

## 注意一： 没有ELSE

```php
UPDATE ae44
SET price = CASE
                WHEN ID = 'AT259793380' THEN '500'
                WHEN ID = 'AT271729590' THEN '600'
                WHEN ID = 'AT275981020' THEN '700'
            END
```

此句中，没有对 `ELSE` 情况进行处理，则 price 会根据条件ID进行更新，其他没有命中ID行， `price`会被设置为 `NULL`值。

CASE 函数的在没有匹配到结果时的处理规则如下：

- 若没有匹配到结果值，则返回 ELSE后结果；
- 若没有ELSE部分，则返回值为 NULL；
- 若字段为 NOT NULL，则根据字段类型返回不同值。（例如，字符串类型时，返回空字符串，数字类型返回 0）。

解决办法有两个，一个限定更新的范围，另一种是给没有命中的ID赋原来值。

解法一：

```php
UPDATE ae44 SET
    Price = CASE
    WHEN ID = 'AT259793380' THEN '500'
    WHEN ID = 'AT271729590' THEN '600'
    WHEN ID = 'AT275981020' THEN '700'
    END
WHERE 
    ID IN ('AT259793380', 'AT271729590', 'AT275981020')
LIMIT 3 # 进一步优化，使用limit限制更新的条数
```

解法二：

```php
UPDATE ae44 SET
    Price = CASE
    WHEN ID = 'AT259793380' THEN '500'
    WHEN ID = 'AT271729590' THEN '600'
    WHEN ID = 'AT275981020' THEN '700'
    ELSE Price END
```

## 注意二：没有WHERE字句

当没有 WHERE字段时，将会对全表扫描。因此，对于需要特定ID进行处理时，最好在 WHERE字段后限定特定ID。

例如，对课程进行重新排序，但没有使用`where`

```objectivec
UPDATE course
SET
SORT = (CASE
            WHEN course_id=1 THEN 3
            WHEN course_id=2 THEN 1
            WHEN course_id=3 THEN 2
        END)
```

查看执行计划

![img](https:////upload-images.jianshu.io/upload_images/1674837-cd69efb1eb9af39f.png?imageMogr2/auto-orient/strip|imageView2/2/w/1200/format/webp)

未使用where限定范围时的执行计划

可以看到，即使`course_id`是主键ID，但是没有使用`where`限定范围，将会对全表进行扫描。

改造:

```objectivec
EXPLAIN
UPDATE course
SET
SORT = (CASE course_id
            WHEN 1 THEN 3
            WHEN 2 THEN 1
            WHEN 3 THEN 2
        END)
WHERE course_id IN(1, 2, 3)
```

![img](https:////upload-images.jianshu.io/upload_images/1674837-006e86efd718fe8e.png?imageMogr2/auto-orient/strip|imageView2/2/w/1200/format/webp)

限定更新的范围的执行计划

# 总结

第一次知道MySQL中竟有如此好用的神器。差一点，使用遍历方法更新课程排序以原本以为仅能在储存过程或触发器中使用，深入了解后，原来是SQL的标准语法。可以使用在SELECT、UPDATE、触发器、储存过程等场景。非常方便地解决了同一条件多种值执行不同操作的问题。