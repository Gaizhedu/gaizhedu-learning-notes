- Map接口
   - [ ] HashMap
   - [ ] TreeMap
   - [ ] （拓展）LinkedHashMap
   - [ ] （拓展）ConcurrentHashMap
   - [ ] （拓展）WeakHashMap 

# Map
这份笔记将讲述一下Map接口的相关内容

这个接口主要有这几个实现类：

``` Java
HashMap：无序的Map
TreeMap：有序的Map
LinkedHashMap：拥有双向链表的HashMap
ConcurrentHashMap：线程安全，但是不支持null
WeakHashMap：一种弱引用的Map 
```

## HashMap

接下来介绍一下这个实现类

那么在介绍这个实现类之前需要先介绍一下Map的基本组成

Map的组成主要由键和值构成