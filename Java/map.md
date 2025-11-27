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

常见的一个方法为：`map.put`

这个方法可以将一个键与一个值绑定，举个例子：

``` Java
Map<Integer, String> map = new HashMap<>();
map.put(1, "Hello");
System.out.println(map.get(1));

// 输出：
// Hello
```
在这个例子中我们可以得到这么几个点

在声明类型的时候需要在泛型里面填写键和值对应的数据类型

其中的两个方法为：`map.put()`和`map.get()`

很明显，put的作用是绑定键和值，而get的作用是获取键对应的值

在上面的例子中，我们通过get获取到名字为1的键对应的值

接下来，既然我们可以查询值，为了不产生报错，要怎么确定是否存在对应的键？

这时候我们便可以使用到这个方法了：`containsKey()`和`containsValue()`

这两个方法的作用便是查找该map中是否存在对应的键和值

``` Java
Map<Integer, String> map = new HashMap<>();
map.put(1, "Hello");
System.out.printf("是否存在键 1：%s%n", map.containsKey(1));
System.out.printf("是否存在值 Hello：%s", map.containsValue("Hello"));

// 输出：
// 是否存在键 1：true
// 是否存在值 Hello：true
```
从这个例子中也可以看到，这里检测到了该map是否存在对应的键`1`和值`Hello`

需要注意的一点是这里并不是必须要键对应的值，只需要存在这个值即可


