---
title: JQuery中html、append、appendTo、after、insertAfter、before、insertBefore、empty、remove系列方法的使用。
id: 544
categories:
  - JavaScript
date: 2017-08-17 19:33:15
tags:
 - append
---
**html**方法，给元素添加html代码或者清空html代码（参数为空字符串）；
**append**向元素的末尾添加html代码；
**appendTo**这个方法跟append方法的很像，只是要添加的html代码的目标有所不一样；
**after**向元素的后边添加html代码，如果元素后面有元素了，那将后面的元素后移，然后将html代码插入；
**before**向元素的前边添加html代码，如果元素前面有元素了，那将前面的元素前移，然后将html代码插入；
**insertAfter**将JQuery封装好的元素插入到指定元素的后面，如果元素后面有元素了，那将后面的元素后移，然后将JQuery对象插入；
**insertBefore**将JQuery封装好的元素插入到指定元素的前面，如果元素前面有元素了，那将前面的元素前移，然后将JQuery对象插入；
**empty**清空元素内部的html代码，它只是清空内部的html代码，但是标记仍然留在DOM中；
**remove**从DOM中移除整个元素；