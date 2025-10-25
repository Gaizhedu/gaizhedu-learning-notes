
[TODO]
1. List接口
   - [ ] ArrayList
   - [ ] LinkedList
   - [ ] （拓展）Vector
   - [ ] （拓展）Stack
2. Set接口
   - [ ] HashSet
   - [ ] TreeSet
   - [ ] （拓展）LinkedHashSet
   - [ ] （拓展）ConcurrentSkipListSet
   - [ ] （拓展）CopyOnWriteArraySet 
3. Map接口
   - [ ] HashMap
   - [ ] TreeMap
   - [ ] （拓展）LinkedHashMap
   - [ ] （拓展）ConcurrentHashMap
   - [ ] （拓展）WeakHashMap 
4. （拓展）Queue接口
   - [ ] ArrayDeque
   - [ ] LinkedList
   - [ ] PriorityQueue
   - [ ] ConcurrentLinkedQueue
   - [ ] ArrayBlockingQueue
   - [ ] DelayQueue
5. （扩展）配套工具
   - [ ] 迭代器（Iterator）
   - [ ] 集成工具类（Collections）

# Collection
这一份将介绍有关Collection这个抽象类的相关内容

首先，通过这里的描述我们也清楚了，这个类是一个抽象类，所以是没办法直接使用的

所以我们一般使用的是他的子接口，而他的子接口又有许多具体的实现类

## List接口
这个接口是List接口，具体的实现类有如下几个：

``` Java
ArrayList : 动态数组
LinkedList : 双向列表
Vector : 动态数组
Stack : 继承与Vector
```

接下来开始一一介绍

### ArrayList
首先是ArrayList

这个属于动态数组，也就是说如果空间不够会自己扩容

#### 如何创建
接下来讲讲如何创建一个ArrayList

最基本的框架如下：

``` Java
ArrayList<具体类型> lst = new ArrayList<泛型>(构造器参数);
```

接下来分别讲一下这里的各个内容

首先第一个，ArrayList 后面跟着的具体类型，这个具体类型的作用为：将泛型类 / 接口具体化

也就是说通过具体的类型来约束集合的操作，使得最后编译的时候类型安全

如何理解呢？类型实参可以给这个参数（lst）赋予一个具体的类型，而编译器会在编译的时候根据类型的实参在编译阶段就检查集合的取和存操作是否符合约定

也就是说，使用类型实参可以有效地防止了添加错误的类型，避免了运行时的转换错误

``` Java
ArrayList<NewObject> lst = new ArrayList<>();
// 正确做法，上面类型实参为NewObject，意味着这里只能填该类型的变量
lst.add(new NewObject(...));

// 错误做法，不应该为字符串String类型
lst.add("This is a String")
```
##### 为什么要这样干
有人可能就要问了，那为什么要这样干呢？

我们不妨假设一下，如果不进行这样，而是使用错误的做法那会怎么样

如果我们选择`lst.add("This is a String")`——也就是传入一个字符串

那么在之后读取lst的元素的时候，由于强制类型转换的原因，程序会抛出`ClassCastException`的错误：
``` Java
ArrayList lst = new ArrayList<>();
lst.add("hello");
NewObject newObject = (NewObject) lst.get(0);
System.out.println(newObject.getObjectName());

// 报错：Exception in thread "main" java.lang.ClassCastException
```

如果我们有通过填写类型实参来检查，那么就可以在编译的阶段解决这个问题

---
当然，使用参数实参肯定是不止这个的

如果使用类型实参，便可以减少在代码中出现的强制类型转换：

``` Java
// 此处未填类型实参
ArrayList lst = new ArrayList<>();
lst.add(new NewObject("测试1", 1));
NewObject newObject = (NewObject) lst.get(0);
System.out.println(newObject.getObjectName());
```

如果使用类型实参则会是这样的效果：
``` Java
ArrayList<NewObject> lst = new ArrayList<>();
lst.add(new NewObject("测试1",1));
NewObject newObject = lst.get(0);
System.out.println(newObject.getObjectName());
```
这里便可以不用手动强制类型转换，大大减少了问题的出现

接下来是后面的创建内容，首先是尖括号里面的内容

第一个部分是ArrayList后面跟着的尖括号`<>`，这个尖括号主要是起到泛型的作用，在尖括号里面填入指定的类型可以起到限定此类才可以传入的效果

不过由于版本更替，如果你在类型实参中已经有填写，那么其实是没必要在后面的尖括号里面填写的

``` Java
// 指定类型为String
ArrayList<String> list = new ArrayList<String>();
list.add("Hello");
System.out.println(list.get(0));

// 输出：
// Hello
```

这里其实把泛型的内容省略的，在Java 7+后，编译器会自动匹配
``` Java
// 这里泛型没有填写，因为编译器会自己自动匹配
ArrayList<String> list = new ArrayList<>();
list.add("Hello");
System.out.println(list.get(0));
```

###### 特别注意
如果你需要指定泛型为整数类，或者是浮点数类

必须要使用其包装类，而不能使用基本数据类型：

``` Java
ArrayList<int> list = new ArrayList<int>();// 错误，不应该使用基本数据类型
ArrayList<int> list = new ArrayList<Integer>();// 正确，使用了整数类型的包装类
```

---
接下来讲讲圆括号内的内容

圆括号主要是调用构造方法，你可以在这里面指定默认的大小，或者是复制一个集合到这里面去

如果你在圆括号里面填写一个数字，便可以直接指定这个集合的默认大小

``` Java
ArrayList<String> list = new ArrayList<>(10);
```

在上面的例子中，我们将这个集合的默认大小指定为10个元素

如果你选择不填写（也就是默认），那么这个集合的长度将会设定为10个的大小

接下来是另一个，复制集合

假设我们之前已经创建过一个集合，并且往这个集合里面填写了元素

``` Java
ArrayList<String> source = new ArrayList<>();
source.add("New Collection");
```

那么我们便可以在新的集合的圆括号里面填写这个集合的名字（例如这里是source）

这样便可以把旧集合的元素复制到新的集合里面

``` Java
ArrayList<String> source = new ArrayList<>();
source.add("New Collection");

ArrayList<String> list = new ArrayList<>(source);
System.out.println(list.get(0));

// 输出：
// New Collection
```

#### 特点
那么有什么特点呢？首先第一个就是ArrayList是一个动态数组，也就是说，其可以自动的扩容

假设我们一开始的长度为10，将这个10个大小全部用完后，这个数组会自动扩容，默认扩容大小为原大小的1.5倍

为什么是1.5倍呢？如果倍率太小，那么扩容的空间太小，扩容的次数便会大大增加，这意味着会频繁的复制元素

但是复制元素是耗时的，所以倍率太小会导致浪费一些时间

既然这样，那为什么不要选择大一点的倍率呢？

这是因为如果倍率太大，可能会导致占用过多的内存

权衡之下，选择1.5倍是最好的选择

---
ArrayList还有一些特性

作为一种动态数组，ArrayList支持存放相同元素

ArrayList可以存放`null`：

``` Java
ArrayList<String> list = new ArrayList<>();
list.add(null);
System.out.println(list.get(0));

// 输出：
// null
```
ArrayList具有有序性，意味着元素的插入顺序和访问顺序是一致的

在访问ArrayList的元素的时候，通过索引`get(int index)`可以很快地找到元素

其时间复杂度为：**O(1)**

假设需要往这个数组中间插入或者删除元素，那么其时间复杂度为：O(n)

这是因为每次从其中删除或者添加元素的时候需要将这个元素后面的元素移动一个单位

此外，由于ArrayList的所有方法都是没有同步锁的，这就导致了多线程操作的时候可能会出现并发的问题

如果需要线程安全，那么可以使用：

``` Java
List<String> list = Collections.synchronizedList(new ArrayList<>());
```

使用集成工具类中的`synchronizedList`方法，便可以解决多线程的问题

> 当然这里也可以直接使用CopyOnWriteArrayList，不过这个是属于Set接口的内容，这里讲的是ArrayList

#### 使用方法
这里将接下ArrayList的一些具体使用方法

> 由于这些方法基本上是通用的，所以在这里讲过一次后，接下来的实现类便不会再讲
ArrayList包括了List接口的所有方法

**add()**
`add()`方法用于往数组末尾添加元素

``` Java
ArrayList<String> list = new ArrayList<>();
list.add("往末尾添加第一个新元素");
System.out.printf("当前列表长度为：%d，添加的元素为：%s\n",list.size(),list.getLast());
list.add("往末尾添加第二个新元素");
System.out.printf("当前列表长度为：%d，添加的元素为：%s\n",list.size(),list.getLast());

// 输出：
// 当前列表长度为：1，添加的元素为：往末尾添加第一个新元素
// 当前列表长度为：2，添加的元素为：往末尾添加第二个新元素
```

如果在添加元素的时候发现数组不够用了，那么会先扩容在添加

此外，`add()`还可以指定插入的位置

假设我们想要插入的位置为第二项，那么只需要这样填写参数即可

``` Java
list.add(1,"插入第二项")
```
第一个参数为插入的位置，由于数组计数从零开始，所以这里得填写1来代表第二项

而第二个参数代表插入的内容

**get()**
`get()`为返回指定索引位置的元素

需要注意的一点是，这里返回的内容其实为底层数组`elementData[index]`

##### 什么是elementData
这里可能就有人要问了，诶，那什么是elementData呢？

在ArrayList.java里面是这样写的：

``` Java
private static final Object[] DEFAULTCAPACITY_EMPTY_ELEMENTDATA = {};

...

public ArrayList() {
   this.elementData = DEFAULTCAPACITY_EMPTY_ELEMENTDATA;
}
```
可以基本理解，这个`elementData`便是ArrayList底层的数组，平时丢进去的元素都会存放在这里面

---
接下来回到正题，get()通过访问底层数组`elementData`来获取到指定位置的元素

假设此时索引的范围超过底层数组（也就是越界），或者数组的这个位置没有任何元素，那么会抛出这个错误：

``` Java
ArrayList<String> list = new ArrayList<>();
list.add("往末尾添加第一个新元素");
System.out.printf("当前列表长度为：%d，添加的元素为：%s\n",list.size(),list.getLast());
// 数组只有一个元素，索引第二个元素（get(1)）会导致报错
System.out.printf("%s",list.get(1));

// 输出：
// 当前列表长度为：1，添加的元素为：往末尾添加第一个新元素
// Exception in thread "main" java.lang.IndexOutOfBoundsException
```

---
**set()**
接下来是`set()`

这个方法的作用是替换指定位置的元素为新的元素

这个方法具有两个参数：

第一个参数为替换的位置，而第二个参数为想要替换的新元素

与上文的`get()`同理，这里本质也是对底层的数组`elementData`进行修改

此处也需要先检查是否越界，如果越界一样会报错

``` Java
ArrayList<String> list = new ArrayList<>();
list.add("往末尾添加第一个新元素");
list.add("往末尾添加第二个新元素");
System.out.printf("未替换的元素为：%s\n",list.get(1));
list.set(1,"新元素");
System.out.printf("替换的元素为：%s\n", list.get(1));

// 输出：
// 未替换的元素为：往末尾添加第二个新元素
// 替换的元素为：新元素
```

此处为什么不写成这样呢？
``` Java
ArrayList<String> list = new ArrayList<>();
list.add("往末尾添加第一个新元素");
list.add("往末尾添加第二个新元素");
System.out.printf("未替换的元素为：%s\n",list.get(1));
System.out.printf("替换的元素为：%s\n", list.set(1,"新元素"););
```

这是由于在`ArrayList.java`中，`set()`的实现代码为：
``` Java
public E set(int index, E element) {
   Objects.checkIndex(index, size);
   E oldValue = elementData(index);
   elementData[index] = element;
   return oldValue;
}
```
可以看到，这里现将变量`oldValue`赋值为旧的值`elementData(index)`

而后才替换为新的值`elementData[index] = element;`

而返回的值为`oldValue`，这意味着返回的结果为替换前的值

**remove()**
``` Java
ArrayList<String> list = new ArrayList<>();
list.add("往末尾添加第一个新元素");
System.out.printf("当前列表长度为：%d，添加的元素为：%s\n",list.size(),list.getLast());
System.out.printf("%s",list.remove(1));

// 输出：
// 当前列表长度为：1，添加的元素为：往末尾添加第一个新元素
// Exception in thread "main" java.lang.IndexOutOfBoundsException
```
如果当前位置有元素，那么会返回这个删除的元素：

``` Java
ArrayList<String> list = new ArrayList<>();
list.add("往末尾添加第一个新元素");
list.add("往末尾添加第二个新元素");
System.out.printf("删除的元素为：%s\n",list.remove(1));

// 输出：
// 删除的元素为：往末尾添加第二个新元素
```

诶，在之前也有提到一个点：
> 假设需要往这个数组中间插入或者删除元素，那么其时间复杂度为：O(n)
> 
> 这是因为每次从其中删除或者添加元素的时候需要将这个元素后面的元素移动一个单位

这里的意思是，在删除一个中间元素后会将后面的所有元素向前移动一个单位，说白了就是将后面的元素复制一遍

从底层代码我们也可以看到这一点：
``` Java
public E remove(int index) {
   Objects.checkIndex(index, size);
   final Object[] es = elementData;

   @SuppressWarnings("unchecked") E oldValue = (E) es[index];
   fastRemove(es, index);

   return oldValue;
}

private void fastRemove(Object[] es, int i) {
   modCount++;
   final int newSize;
   if ((newSize = size - 1) > i)
      System.arraycopy(es, i + 1, es, i, newSize - i);
   es[size = newSize] = null;
}
```

通过观察这段代码，我们也可以发现一个很有意思的点

`remove()`移除指定位置的底层实现，其实是**覆盖**，也就是先将这个元素后面的所有元素移动前一位，而后将原本的最后一位设定为null

为什么要设定为null呢？这里其实在帮助GC回收

举个具体例子

假设我们有个数组为100位

我想要删除第50位，那么底层的实现是这样的：

先复制51~100位的元素到50~99位，之后设定100位为`null`

之后返回替换前的50位

**size()**
接下来是`size()`

size()的作用是返回底层数组的长度

``` Java
ArrayList<String> list = new ArrayList<>();
list.add("往末尾添加第一个新元素");
list.add("往末尾添加第二个新元素");
System.out.printf("数组长度为：%s",list.size());

// 输出：
// 数组长度为：2
```