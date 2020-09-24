---
title: MongoDB 数据更新操作
categories:
  - MongoDB
date: 2020-09-24 11:07:37
tags:
 - mongodb
---

#### MongoDB 更新文档
MongoDB 使用 `update()` 和 `save()` 方法来更新集合中的文档。

##### `update()` 方法

`update()` 方法用于更新已存在的文档。语法格式如下：
```
db.collection.update(
    <query>,
    <update>,
    {
      upsert: <boolean>,
      multi: <boolean>,
      writeConcern: <document>
    }
)
```

##### 参数说明：

* **`query`** : update 的查询条件，类似 sql update 查询内 where 后面的。
* **`update`** : update 的对象和一些更新的操作符（如$,$inc...）等，也可以理解为 sql update 查询内 `set` 后面的
* **`upsert`** : 可选，这个参数的意思是，如果不存在 update 的记录，是否插入 `objNew`,`true` 为插入，默认是 `false`，不插入。
* **`multi`** : 可选，mongodb 默认是 `false`,只更新找到的第一条记录，如果这个参数为 `true`,就把按条件查出来多条记录全部更新。
* **`writeConcern`** :可选，抛出异常的级别。

[官方连接连接地址](https://docs.mongodb.com/manual/reference/update-methods/)

#### 实例

向数据库插入点数据（集合名称为 test)
```
{
  _id: 100,
  sku: "abc123",
  quantity: 200,
  instock: true,
  reorder: false,
  details: { model: "1Q2", make: "xyz" },
  tags: [ "apparel", "clothing" ],
  ratings: [ { by: "ijk", rating: 1 } ]
}
```

#### 各种更新操作符

##### `$set`

用来指定一个键的值。如果这个键不存在，则创建它。
示例：更新 quantity 字段、更新 details 的内容以及更新 tags 的值。
```
db.test.update(
   { _id: 100 },
   { $set:
      {
        quantity: 500,
        details: { model: "1Q2", make: "xyz" },
        tags: [ "coats", "outerwear", "clothing" ]
      }
   }
)
```

##### `$set` 与 `.` 操作

示例：使用 "." 符号更新数据内容
```
db.test.update(
   { _id: 100 },
   { $set: { "details.make": "zzz" } }
)
```

同样可以使用 `.` 符号操作数组内容
```
db.test.update(
   { _id: 100 },
   { $set:
      {
        "tags.1": "rain gear",
        "ratings.0.rating": 2
      }
   }
)
```

创建不存在的 key 值
```
db.tset.update(
   { _id: 100 },
   { $set:
      { "name": "not the name" }
   }
)
```

##### `$unset`

从文档中移除指定的键。
若要完全删除键 “name” ,使用 `$unset` 即可：
```
db.test.update(
   { _id: 100 },
   { $unset:
      { "name": 1 }
   }
)
```

##### `$inc`

* `$inc` 修改器用来增加已有键的值，或者在键不存在时创建一个键。`inc` 就是专门来增加（和减少）数字的。

* `$inc` 只能用于整数、长整数或双精度浮点数。要是用在其他类型的数据上就会导致操作失败。

* `$inc` 可以接收正数或者负数的值。

示例：将 "quantity" 值减少 1
```
db.test.update(
   { _id: 100 },
   { $inc :
      { "quantity": -1 }
   }
)
```

##### `$rename`
操作符可以重命名字段名称，新的字段名称不能和文档中现有的字段名相同。

语法

`{ $rename: { <old name1>: <new name1>, <old name2>: <new name2>, ... } }`

示例：修改 "sku" 为 "skuName"
```
db.test.update(
   { _id: 100 },
   { $rename :
      { "sku": "skuName" }
   }
)
```

##### `$pop`
只能用于对 数组（array）进行操作。用于移除数组第一个元素，或者用于移除数组的最后一个元素。
语法 -1 表示移除数组第一个元素， 1 表示移除数组最后一个元素

`{ $pop: { <field>: <-1 | 1>, ... } }`

集合数据 `{ _id: 1, scores: [ 8, 9, 10 ] }`

* 移除第一个元素
```
db.test.update( { _id: 1 }, { $pop: { scores: -1 } } )
 
// 查询返回
{ _id: 1, scores: [ 9, 10 ] }
```

* 移除最后一个元素
```
db.test.update( { _id: 1 }, { $pop: { scores: 1 } } ) 
// 查询返回 
{ _id: 1, scores: [ 9 ] }
```

##### $push
如果指定的键已经存在，会向已有的数组末尾加入一个元素，要是没有就会创建一个新的数组。
集合数据
```
{
    "_id" : 1000,
    "details" : {
        "model" : "14Q3",
        "make" : "zzz"
    },
    "tags" : [ 
        "coats", 
        "outerwear", 
        "clothing"
    ],
    "sku" : "abc123"
}
```

* 向 tags 中增加一个元素
```
db.test.update( { _id: 1000}, { $push: {tags: "push"} } ); 
// 返回结果 
{..."tags" : [ "coats", "outerwear", "clothing", "push"], ...}

```

* 添加一个不存在的 key “name”

`db.getCollection('test').update( {_id : 100}, {$push: { name : "sku" } } );`

**注意：`push` 只能对数组进行操作。**

##### `$addToSet`
向集合数据中添加数组内容，如果数据存在就做追加操作，如果数据不存在就做新增 key 与内容操作。

语法 

`{"$addToSet" : {成员： 内容} }`

* 向数据中的 name 字段追加内容（紧接着前面"$push"操作的数据来）

`db.getCollection('test').update( {_id : 100}, { $addToSet : { name : "Name" } } );`


* 追加一个不存在的 key item （此时的操作和 `$push` 类似）

`db.getCollection('test').update( {_id : 100}, { $addToSet : { item : "Name" } } );`

##### `$pull`

语法

`{ $pull: { <field1>: <value|condition>, <field2>: <value|condition>, ... } }`

 pull操作符移除指定字段值为数组，且匹配pull操作符移除指定字段值为数组，且匹配pull语句声明的查询条件的所有元素。

* 移除 tags 中的 “push” 与 “coats” 值
```
db.test.update(
    { _id : 100 },
    { $pull: { tags: { $in: [ "push", "coats" ] } } }
)
```

* 移除 name 中的 “Name”

`db.test.update( { _id : 100 }, { $pull: { name : "Name" } } )`

##### findAndModify()

语法如下
```
db.test.findAndModify({
    query: <document>,
    sort: <document>,
    remove: <boolean>,
    update: <document>,
    new: <boolean>,
    fields: <document>,
    upsert: <boolean>,
    bypassDocumentValidation: <boolean>,
    writeConcern: <document>,
    collation: <document>,
    arrayFilters: [ <filterdocument1>, ... ]
});
```
如果我们想对 某个数据进行全部修改，就可以使用 `findAndModify()` 方法：
```
db.test.findAndModify({
   query: { _id: 100},
   update: {
    "details" : {
        "model" : "12Q3",
        "make" : "zzz"
    },
    "tags" : [ 
        "coats", 
        "outerwear", 
        "clothing", 
        "push"
    ],
    "sku" : "abc123"
   }
});
```

[官网链接](https://docs.mongodb.com/manual/reference/operator/update/)