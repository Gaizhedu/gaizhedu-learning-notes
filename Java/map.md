- Map接口
   - [ ] HashMap
   - [ ] TreeMap
   - [ ] （拓展）LinkedHashMap
   - [ ] （拓展）ConcurrentHashMap
   - [ ] （拓展）WeakHashMap 

- [ ] compute  
- [ ] computeIfAbsent  
- [ ] computeIfPresent  
- [x] containsKey  
- [x] containsValue  
- [ ] entrySet  
- [ ] equals  
- [x] get  
- [ ] getOrDefault  
- [x] hashCode  
- [ ] isEmpty  
- [ ] keySet  
- [ ] merge  
- [x] put  
- [ ] putAll  
- [ ] putIfAbsent  
- [x] remove  
- [x] replace  
- [ ] replaceAll  
- [x] size  
- [ ] values

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

接下来介绍一下一些用于删除和替换的方法：`remove()`和`replace()`

首先先看签名：

`remove()`有两个重载的方法：

``` Java
V remove(Object key)

boolean remove(Object key, Object value)
```
首先看只有一个参数的版本，这个方法的作用是删除对应键，包括键和键的值

由于该方法在接口中并没有直接写明，所以具体实现得看实现类是如何实现的，所以不同的Map实现的方法会略有些不同：

``` Java
// HashMap：
public V remove(Object key) {
   Node<K,V> e;
   return (e = removeNode(hash(key), key, null, false, true)) == null ?
      null : e.value;
}

// TreeMap：
public V remove(Object key) {
   Entry<K,V> p = getEntry(key);
   if (p == null)
      return null;

   V oldValue = p.value;
   deleteEntry(p);
   return oldValue;
}
```

不过作用都是一样的

这里简单举个例子来说明：

``` Java
Map<Integer, String> map = new HashMap<>();
map.put(1, "Hello");
System.out.printf("是否存在键 1：%s%n", map.containsKey(1));
System.out.printf("删除键和对应的值：%s%n", map.remove(1));
System.out.printf("是否存在键 1：%s%n", map.containsKey(1));

// 输出：
// 是否存在键 1：true
// 删除键和对应的值：Hello
// 是否存在键 1：false
```

接下来是有两个参数的，这个方法的虽然大体上看上去是相等的，但其实有很多的细节是不同的

``` Java
boolean remove(Object key, Object value)
```
这个方法是这样的，首先会提取出这个键对应的值，并与第二个参数进行比较，如果两者相等，那么返回true，并且删除原先键对应的值，如果不相等，那么不删除并且返回false

``` Java
Map<Integer, String> map = new HashMap<>();
map.put(1, "Hello");
System.out.printf("是否存在键 1：%s%n", map.containsKey(1));
System.out.printf("删除的值与参数的值是否相等：%s%n", map.remove(1, "Good"));
System.out.printf("是否存在键 1：%s%n", map.containsKey(1));

// 输出：
// 是否存在键 1：true
// 删除的值与参数的值是否相等：false
// 是否存在键 1：true
```
可以看到，这里第二个参数为`Good`，并不是`Hello`，所以返回了false，并且没有删除值

``` Java
default boolean remove(Object key, Object value) {
   Object curValue = get(key);
   if (!Objects.equals(curValue, value) ||
      (curValue == null && !containsKey(key))) {
      return false;
   }
   remove(key);
   return true;
}
```
这个方法的实现是在`Map.java`这个接口里面的，并不依靠具体实现类的实现

接下来是`replace()`

这个方法的作用是将指定的键的值进行替换：

``` Java
Map<Integer, String> map = new HashMap<>();   
map.put(1, "Hello");                          
System.out.printf("原先值：%s%n", map.get(1));    
map.replace(1, "Good");                       
System.out.printf("替换后的值：%s%n", map.get(1));  

// 输出：
// 原先值：Hello
// 替换后的值：Good
```
可以看到，这里成功替换了值

这个方法还有一个三个参数的，与上文的remove()有两个参数的版本作用差不多

首先先看签名

``` Java
boolean replace(K key, V oldValue, V newValue)
```

可以看到，这里返回的类型为布尔值

那么这个方法的作用是这样的，只有当参数`oldValue`与原先键对应的值相等才会对值进行替换

举个例子：

``` Java
Map<Integer, String> map = new HashMap<>();    
map.put(1, "Hello");                           
System.out.printf("原先值：%s%n", map.get(1));     
map.replace(1, "World", "Good");                
System.out.printf("替换后的值：%s%n", map.get(1));   

// 输出：
// 原先值：Hello
// 替换后的值：Hello
```
在上文中，`oldValue`为`World`，与值`Hello`不相等，所以不会触发替换

接下来是`size()`

这个方法的作用相当简单，返回当前map的长度

``` Java
Map<Integer, String> map = new HashMap<>();
map.put(1, "Hello");
System.out.printf("当前Map的长度：%d", map.size());

// 输出：
// 当前Map的长度：1
```

接下来介绍一下**value()**

这个方法的作用是返回所有值的一个集合

具体使用例子如下：

``` Java
Map<Integer, String> map = new HashMap<>();
map.put(1, "Hello");
map.put(3, "Apple");
map.put(2, "Pear");
map.put(5, "Banana");
System.out.printf("当前Map的所有值：%s", map.values());

// 输出：
// 当前Map的所有值：[Hello, Pear, Apple, Banana]
```
需要注意的是，在HashMap中使用该方法的时候返回的值是无序的，而在TreeMap中则是有序的