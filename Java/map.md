- Map接口
   - [x] HashMap
   - [x] TreeMap
   - [ ] （拓展）LinkedHashMap
   - [ ] （拓展）ConcurrentHashMap
   - [ ] （拓展）WeakHashMap 

- 基础：
  - [x] put
  - [x] get
  - [x] remove
  - [x] replace
  - [x] size 
  - [x] containsKey
  - [x] containsValue
  - [x] values
  - [x] keySet 
  - [x] entrySet 
  - [x] isEmpty  
  - [x] putAll
  - [x] getOrDefault
- 进阶内容
  - [x] compute  
  - [x] computeIfAbsent  
  - [x] computeIfPresent
  - [x] equals
  - [x] merge 
  - [x] putIfAbsent   
  - [x] replaceAll
  - [x] remove（双参数）
  - [x] replace（三参数）

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

## 可用方法

这里将介绍该接口的一些基础方法和进阶方法

对于日常使用，可以仅掌握基础方法

### 基础方法

#### put() & get()
首先是最常用的方法 **put()**和 **get()**

put()方法可以将一个键与一个值绑定，举个例子：

``` Java
Map<Integer, String> map = new HashMap<>();
map.put(1, "Hello");
System.out.println(map.get(1));

// 输出：
// Hello
```
在这个例子中我们可以得到这么几个点

在声明类型的时候需要在泛型里面填写键和值对应的数据类型

接下来是**get()**方法

这个方法的作用是获取键对应的值

在上面的例子中，我们通过get获取到名字为1的键对应的值

### containsKey() & containsValue()
接下来，既然我们可以查询值，为了不产生报错，要怎么确定是否存在对应的键？

这时候我们便可以使用到这个方法了：**containsKey()**和**containsValue()**

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

#### remove() & replace()

接下来介绍一下用于删除和替换的方法：**remove()**和**replace()**

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

接下来是**replace()**

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


#### size()
接下来是**size()**

这个方法的作用相当简单，返回当前map的长度

``` Java
Map<Integer, String> map = new HashMap<>();
map.put(1, "Hello");
System.out.printf("当前Map的长度：%d", map.size());

// 输出：
// 当前Map的长度：1
```

#### value()
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

#### keySet()
接下来介绍一下**keySet()**

这个方法的作用是以集合的形式返回该Map中所有的键

签名如下：
``` Java
Set<K> keySet();
```
这个方法的具体实现需要看具体的实现类如何实现

例子如下：
``` Java
Map<Integer, String> map = new HashMap<>();
map.put(1, "Hello");
map.put(3, "Apple");
map.put(2, "Pear");
map.put(5, "Banana");
System.out.printf("当前Map的所有键：%s", map.keySet());

// 输出：
// 当前Map的所有值：[1, 2, 3, 5]
```
可以看到，这里返回的内容便是这个Map中所有的键的集合

#### entrySet()
接下来介绍这个方法

该方法的作用为返回这个Map中所有的键和其对应的值

``` Java
Set<Map.Entry<K, V>> entrySet();
```
从签名中可以看到，返回类型为Set

接下来通过一个例子来说明：

``` Java
Map<Integer, String> map = new HashMap<>();
map.put(1, "Hello");
map.put(3, "Apple");
map.put(2, "Pear");
map.put(5, "Banana");
System.out.printf("当前Map的所有键和对应的值：%s", map.entrySet());

// 输出：
// 当前Map的所有键和对应的值：[1=Hello, 2=Pear, 3=Apple, 5=Banana]
```

与上文的`keySet`类似，具体的实现需要参照具体的实现类

#### isEmpty()
接下来是**isEmpty()**

这个方法的作用是检测该Map是否为空

签名如下
``` Java
boolean isEmpty();
```
可以看到，这里的返回类型为boolean

``` Java
Map<Integer, String> map = new HashMap<>();
map.put(1, "Hello");
map.put(3, "Apple");
map.put(2, "Pear");
map.put(5, "Banana");
System.out.printf("当前Map的所有键和对应的值：%s", map.isEmpty());

// 输出：
// 当前Map是否为空：false
```

该方法的具体实现需要看具体的实现类

事实上，这个方法的实现相对比较简单

以下为HashMap中的实现：

``` Java
public boolean isEmpty() {
   return size == 0;
}
```
可以看到，这里的代码实现为检测该Map的长度

如果为0，则说明是空的，返回`true`，反之返回`false`

#### putAll()
接下来是这个方法

这个方法的作用实际与`addAll()`有点类似，可以理解为批量执行`put()`

签名如下：
``` Java
void putAll(Map<? extends K, ? extends V> m)
```
我们可以看到，这里的参数里面需要放一个Map

下面是实际例子：
``` Java
Map<Integer, String> map = new HashMap<>();
map.putAll(Map.of(1,"Apple",2,"Blueberry",3,"Cherry"));
System.out.printf("当前Map的所有键和对应的值为：%s", map.entrySet());

// 输出：
// 当前Map的所有键和对应的值为：[1=Apple, 2=Blueberry, 3=Cherry]
```
从输出可以看到，我们这里成功将所有的键和值放进去对应的Map

奇数为键，偶数为对应的值

#### getOrDefault()
接下来是这个方法

这个方法可以简单理解为`get()`的加强版

签名如下：
``` Java
default V getOrDefault(Object key, V defaultValue)
```
这个方法的实现是写在`Map.java`里面的

我们可以看到这里有两个参数，第一个参数与`get()`一样，为键，而第二个参数`defaultValue`指的是若该键不存在时返回的内容

具体实现如下：

``` Java
default V getOrDefault(Object key, V defaultValue) {
V v;
return (((v = get(key)) != null) || containsKey(key))
   ? v
   : defaultValue;
}
```
可以看到，整个方法的实现就只有两个语句

一个为声明，而另一个为一段三元表达式

这段三元表达式的内容为，如果使用get()可以获取到对应的键的值，并且该值不为`null`，或者包含该键，则返回对应的值，如果不存在该键，或者值为null，那么返回设定的默认值`defaultValue`

实际例子如下：
``` Java
Map<Integer, String> map = new HashMap<>();
System.out.println();
map.putAll(Map.of(1,"Apple",2,"Blueberry",3,"Cherry"));
System.out.printf("当前Map键的值为：%s%n", map.getOrDefault(1,"没有值"));
System.out.printf("若不存在该键则返回第二个参数：%s%n", map.getOrDefault(9,"没有值"));

// 输出：
// 当前Map键的值为：Apple
// 若不存在该键则返回第二个参数：没有值
```
在上面的例子中，第一次输出存在对应的键`1`，返回了对应的内容

而第二次输出由于没有对应的键，返回的内容为第二个参数的内容

### compute
接下来介绍一下这个方法

这个方法的作用是指定一个键的这个键的值，然后通过一些计算（BiFunction）来更新这个值

这个方法签名如下：

``` Java
default V compute(K key,
            BiFunction<? super K, ? super V, ? extends V> remappingFunction)
```
可以看到，这个方法有两个参数，第一个参数用于指定是哪一个键，而第二个参数指的是对这个键的参数要进行什么操作

下面举一个例子来说明：

``` Java
Map<Integer, String> map = new HashMap<>();
map.put(1, "第一个元素");
map.put(2, "第二个元素");
System.out.println(map.get(1));
map.compute(1, (k, v) -> v + "（追加的字符串）");
System.out.println(map.get(1));

// 输出：
// 第一个元素
// 第一个元素（追加的字符串）
```
在上面这个例子中，第一个键的值被更新为原先值加上一段字符串

同时我们可以看到，在上面的例子中，`BiFunction`中的内容我们只是用到了第二个`v`，第一个参数`k`代表键，可以在日志中显示哪一个键被修改了

我们再次提供一个例子来说明这个方法的作用

``` Java
Map<String, Integer> map = new HashMap<>();
List<String> list = new ArrayList<>(List.of("A","C","B","A","B","C","A","A","B","C","B","A","C","C","A","B","C","A","B","C"));
for (String s : list) {
   map.compute(s, (k, v) -> (v == null) ? 1 : v + 1);
}
System.out.println(map);

// 输出：
// {A=7, B=6, C=7}
```
这是一个简单的计数器装置，运行原理是，如果map中没有数组中的元素（也就是`null`），则设置这个单词为键，并且值为1（起到起始化的作用）

如果再一次出现这个键，则值+1

这样便实现了一个基础的计数器

## computeIfAbsent
`computeIfAbsent`的作用是将获取指定的key值，如果该key的值不存在，则利用其映射函数计算一个新的值，并放入Map中

签名如下：
``` Java
default V computeIfAbsent(K key, Function<? super K, ? extends V> mappingFunction)
```

``` Java
Map<Integer, Integer> map = new HashMap<>();
map.computeIfAbsent(1,(k) -> k * 2);
System.out.println(map);

// 输出：
// {1=2}
```
可以看到，`map`没有键1，意味着没有对应的值，所以通过第二个参数计算得出一个新的值，并放入map中

这个方法的一个特性便是**免初始化**，这一特点使得该方法可以用于很多领域

假设我们有很多个物品，物品有10000种类别，但我们只会取10个物品出来并分类

很明显，在这种情况下选择创建10000个键是十分不合理的行为，真正的做法是使用`computeIfAbsent`，如果没有则自动创建对应的键，以及自动创建该类别，这样，至多只需要10个类别即可完成任务，相较于之前的10000个减少了很多资源的浪费

## computeIfPresent
上文的`computeIfAbsent`是没有对应的键才进行操作，这个方法的作用是有对应的键才进行操作

签名如下：
``` Java
default V computeIfPresent(K key, BiFunction<? super K, ? super V, ? extends V> remappingFunction)
```

> 此处为BiFunction的原因是只有当键和值都存在时才会根据第二个参数来计算新的值
> 而BiFunction便是接收两个值，输入一个值的类型

我们举一个例子：
``` Java
// 初始化 Map
Map<String, Boolean> map = new HashMap<>();
// 初始化购买清单
List<String> shoppingList = new ArrayList<>(List.of("Apple","Strawberry","Watermelon"));
// 将购买清单里面的物品放入Map中，并设置值为false
for (String item : shoppingList) {
   map.compute(item, (k, v) -> v != null);
}
// 设置今日特价商品
List<String> specialPrice = new ArrayList<>(List.of("Apple","Banana","Grape"));
// 通过 computeIfPresent 方法来判断是否有制定的键，如果有制定的键，则设置值为true
for (String item : specialPrice){
   map.computeIfPresent(item, (k, v) -> true);
}
// 最后查找是否有为 true 的值
System.out.printf("今日是否有特价商品在购买清单中：%s",map.containsValue(true));

/* 输出：
今日是否有特价商品在购买清单中：true
*/
```
在上面的例子中，我们实现了一个判断购买清单中是否存在今日特价商品的例子

使用的思路是先将购买清单中的物品放入Map中，并设置为键，而后利用`computeIfPresent`只能在有的键中执行`BiFunction`的特性，实现对指定物品的筛选

## equals
`equals`方法的作用是比价两个Map的键值对是否相等

签名如下：
``` Java
boolean equals(Object o);
```

接下来通过一个例子来说明

``` Java
// 初始化 两个Map，一个保存折扣过的商品，一个保存当前折扣的商品
Map<String, Boolean> pastDiscountedProducts = Map.of("Apple",true, "Banana",true, "Grape",true);

Map<String, Boolean> specialPrice = Map.of("Apple",true, "Banana",true, "Grape",true);
// 通过 equals 方法来比较两个 Map 是否相等
if (specialPrice.equals(pastDiscountedProducts)){
   System.out.println("这次的打折活动之前也有过一次");
} else {
   System.out.println("这次的打折活动从未有过");
}

/* 
输出：
这次的打折活动之前也有过一次
*/
```
上面例子比较了两个Map的键值对，需要注意的一点是，比较仅比较是否相同，顺序是可以不一致的

## merge
这个方法的作用是更新或插入键值对

方法签名如下：
``` Java
V merge(K key, V value, BiFunction<? super V, ? super V, ? extends V> remappingFunction)
```

这个方法的具体作用是，如果`key`存在，并且这个`key`的值不为空，则执行后面的`BiFunction`

如果`key`不存在，则将这个`key`和第二个参数的`value`放入Map中

举一个例子来说明：

``` Java
// 初始化一个 Map 用于存储物品
Map<String, Integer> inventory = new HashMap<>(Map.of("Apple", 1, "Banana", 1, "Grape", 1));
// 初始化物品列表
List<String> newItems = new ArrayList<>(List.of("Apple", "Pineapple", "Banana", "Strawberry"));
// 将新的物品添加到存储的 Map 当中
for (String item : newItems) {
   inventory.merge(item, 1, Integer::sum);
}
System.out.printf("当前拥有的物品有：%s", inventory);

/*
输出：
当前拥有的物品有：{Pineapple=1, Apple=2, Strawberry=1, Grape=1, Banana=2}
*/
```
在上面这里例子中，`merge`的具体使用位于`inventory.merge(item, 1, Integer::sum);`

实际的意思是，如果指定的键存在（也就是这里有存货），则运行后面的`Integer::sum`，这里相加的值为原先`key`的值与第二个参数`value`相加

如果指定的键不存在，则直接将新的键和`value`放入Map中

## putIfAbsent
这个方法的作用是，只有Map中没有指定的键的时候，才会将这个键值对放入Map中

具体的例子如下：
``` Java
// 初始化一个 Map 用于存储物品
Map<String, Boolean> inventory = new HashMap<>(Map.of("Apple", true, "Banana", true, "Grape", true));
// 初始化物品列表
List<String> newItems = new ArrayList<>(List.of("Apple", "Pineapple", "Banana", "Strawberry"));
// 将新的物品添加到存储的 Map 当中
for (String item : newItems) {
   inventory.putIfAbsent(item, true);
}
System.out.printf("当前拥有的物品有：%s", inventory);

/*
输出：
当前拥有的物品有：{Apple=true, Pineapple=true, Grape=true, Strawberry=true, Banana=true}
*/
```
在上面的例子中，只有检测到不存在的键才会将对应的键值对放入Map中

## replaceAll
这个方法的作用是，将该Map中所有的值进行批量操作

方法签名如下：

``` Java
void replaceAll(BiFunction<? super K, ? super V, ? extends V> function)
```

通过一个简单的例子来说明：
``` Java
// 初始化一个 Map 用于存储物品
Map<String, Integer> inventory = new HashMap<>(Map.of("Apple", 1, "Banana", 1, "Grape", 1));
// 将所有的值都增加1
inventory.replaceAll((k,v)-> ++v);
System.out.printf("当前拥有的物品有：%s", inventory);

/*
输出：
当前拥有的物品有：{Apple=2, Grape=2, Banana=2}
*/
```

## HashMap
HashMap是Map的一个实现类，用于存储键值对，底层实现为哈希表，默认初始容量为16，负载因子为0.75

这个实现类并不是线程安全的。插入的顺序为随机顺序

其他内容可以参照HashSet的内容

## TreeMap
TreeMap同样为Map的一个实现类，这个实现类的一个特点是可以自动为键进行排序

通过一个简单的例子来说明：

``` Java
// 初始化一个 Map 用于存储物品
Map<Integer, Integer> inventory = new TreeMap<>(Map.of(2, 2, 3, 3, 1, 1));
System.out.println(inventory);

/* 
输出
{1=1, 2=2, 3=3}
*/
```
可以看到，在上面例子的输出中，原先顺序为2,3,1被自动排序为正序