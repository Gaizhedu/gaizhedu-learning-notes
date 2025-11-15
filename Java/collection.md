
[TODO]
1. List接口
   - [x] ArrayList
     - [x] TODO clear()方法
     - [x] TODO isEmply()方法
     - [x] TODO contains()方法
     - [x] TODO retainAll()方法
     - [x] TODO toArray()方法
     - [ ] TODO spliterator()方法
     - [x] TODO forEach()方法
     - [x] TODO removeIf()方法
     - [ ] TODO stream()方法
       - [x] filter()
       - [ ] map()
       - [ ] mapMulti()
       - [ ] mapMultiToInt()
       - [ ] mapMultiToLong()
       - [ ] mapMultiToDouble()
       - [ ] mapToInt()
       - [ ] mapToLong()
       - [ ] mapToDouble()
       - [ ] flatMap()
       - [ ] flatMapToInt()
       - [ ] flatMapToLong()
       - [ ] flatMapToDouble()
       - [x] distinct()
       - [x] sorted()
       - [x] peek()
       - [x] limit()
       - [x] skip()
       - [x] takeWhile()
       - [x] dropWhile()
       - [x] forEach()
       - [x] forEachOrdered()
       - [x] toArray()
       - [ ] reduce()
       - [ ] collect()
       - [x] min()
       - [x] max()
       - [x] count()
       - [x] anyMatch()
       - [x] allMatch()
       - [ ] noneMatch()
       - [ ] findFirst()
       - [ ] findAny()
       - [ ] gather()
       - [ ] toList()
     - [ ] TODO parallelStream()方法
     - [x] TODO equals()方法
     - [x] TODO hashCode()方法
     - [x] TODO clone()方法
     - [x] TODO toString()方法
   - [x] LinkedList
   - [ ] （拓展）Vector
   - [ ] （拓展）Stack
2. Set接口
   - [x] HashSet
   - [x] TreeSet
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

> 当然这里也可以直接使用CopyOnWriteArrayList

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

先复制51\~100位的元素到50\~99位，之后设定100位为`null`

之后返回替换前的50位

**size()**
接下来是`size()`

size()的作用是返回底层数组所拥有元素的数量

``` Java
ArrayList<String> list = new ArrayList<>();
list.add("往末尾添加第一个新元素");
list.add("往末尾添加第二个新元素");
System.out.printf("数组长度为：%s",list.size());

// 输出：
// 数组长度为：2
```

**clear()**
接下来是`clear()`

这个方法比较简单，主要的作用是清空当前数组

``` Java
ArrayList<String> lst = new ArrayList<>();
lst.add("测试1");
lst.clear();
lst.add("又新增回来了");
System.out.println(lst);

// 输出：
// [又新增回来了]
```

可以看到，在使用`clear()`方法后，这个数组中的元素便被清空了，之后输出也是重新添加的元素

这个方法的代码实现也很简单粗暴：
``` Java
public void clear() {
   modCount++;
   final Object[] es = elementData;
   for (int to = size, i = size = 0; i < to; i++)
      es[i] = null;
}
```
首先是将操作数`modCount`增加一个单位，之后便将es赋值为这个数组

赋值后便是一个简单的for循环，这个for循环中的条件中size为数组长度

这里有个很巧妙的点，我们在使用clear后数组为空，此时数组长度为0

此处在赋值给to后又使用了`i = size = 0`，这样就使得数组长度被设定为0，符合清空的情况

循环语句的作用为将这个数组的每一项都设定为null值，利用这种方法来实现清空数组

**isEmply()**
接下来介绍isEmply方法，这个方法的主要作用是检测当前数组是否为空，如果为空则返回true，否则返回false

``` Java
ArrayList<String> lst = new ArrayList<>();
lst.add("你好！");
System.out.printf("当前数组状态（是否为空）：%s\n", lst.isEmpty());
lst.clear();
System.out.printf("当前数组状态（是否为空）：%s\n", lst.isEmpty());

// 输出：
// 当前数组状态（是否为空）：false
// 当前数组状态（是否为空）：true
```
可以看到，在执行clear方法将数组清空后，`isEmpty()`显示为`true`

代码实现也很简单：
``` Java
public boolean isEmpty() {
   return size == 0;
}
```
可以看到这里的代码实现就是通过检测数组大小是否为0，并且返回结果

**contains()**
接下来是contains方法

这个方法有一个参数可选：`contains(Object o)`

其中`参数o`代表需要检测的元素

这个方法的检测当前数组中是否有括号内的参数

``` Java
ArrayList<String> lst = new ArrayList<>();
lst.add("你好！");
System.out.printf("当前数组是否有目标元素：%s\n", lst.contains("你好！"));

// 输出：
// 当前数组是否有目标元素：true
```
假设这个数组内有该元素，那么则会返回true

那么他的代码实现是怎么样的呢？

其实很简单：
``` Java
public boolean contains(Object o) {
   return indexOf(o) >= 0;
}
```
可以看到，这个方法实际上是复用了`indexOf`的方法，并通过这个方法的返回值是否大于等于0来判断是否为true

为什么可以这样呢？其实很简单，因为这个方法实际上是返回该元素所在位置

如果没有该元素，则返回-1

通过这种形式，成功精简了代码

> 此处实现了DRY原则

**retainAll()**
接下来介绍这个方法

这个方法拥有一个参数：`retainAll(Collection<?> c)`

这个参数的意思是支持所有实现Collection接口的集合，例如List接口，Set接口

这个方法的主要用法是`A.retainAll(B)`（A和B都是符合条件的数组）

这里代表将A赋值为A和B的交集

``` Java
ArrayList<String> arrayList1 = new ArrayList<>();
ArrayList<String> arrayList = new ArrayList<>();
for (int i = 0; i < 10; i++) {
   arrayList.add(String.valueOf(i));
}
for (int i = 0; i < 15; i++) {
   arrayList1.add(String.valueOf(i));
}
System.out.printf("当前数组arrayList1：\n%s\n", arrayList);
System.out.printf("当前数组arrayList：\n%s\n", arrayList1);
arrayList1.retainAll(arrayList);
System.out.printf("交集后数组：\n%s", arrayList1);

// 输出：
// 当前数组treeSet：
// [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
// 当前数组lst：
// [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14]
// 交集后数组：
// [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
```

**toArray()**
接下来来讲讲这个方法

首先这个方法拥有一个参数：`toArray(T[] a)`

完整的版本如下：`<T> T[] toArray(T[] a)`

当然也有没参数的版本：`Object[] toArray()`

这个方法的作用是将一个**集合转变为数组**

接下来将分别演示带参数和不带参数的版本：

``` Java
Random random = new Random();

TreeSet<Integer> treeSet = new TreeSet<>();

for (int i = 0; i < 10; i++) {
   int randomNumber = random.nextInt(0, 201);
   treeSet.add(randomNumber);
}
System.out.printf("treeSet属于的类型：%s\n", treeSet.getClass().getSimpleName());
Object[] newTreeSet = treeSet.toArray();
System.out.printf("newTreeSet属于的类型：%s\n", newTreeSet.getClass().getSimpleName());

// 输出：
// treeSet属于的类型：TreeSet
// newTreeSet属于的类型：Object[]
```

可以看到，这里选择了不加参数的版本，对应的类型也是选择了：`Object`

但是一般来讲并不建议使用这种做法，因为这种做法在使用的时候一般需要进行强制类型转换，如果不进行强制类型转化，那么会导致报错：

``` Java
Random random = new Random();
TreeSet<Integer> treeSet = new TreeSet<>();
for (int i = 0; i < 10; i++) {
   int randomNumber = random.nextInt(0, 201);
   treeSet.add(randomNumber);
}
Object[] newTreeSet = treeSet.toArray();
int addNumber = (Integer) newTreeSet[0] + (Integer) newTreeSet[1];
System.out.printf("newTreeSet第一项为：%d\n", newTreeSet[0]);
System.out.printf("newTreeSet第二项为：%d\n", newTreeSet[1]);
System.out.printf("newTreeSet第一项与第二项相加：%d\n", addNumber);

// 输出：
// newTreeSet第一项为：5
// newTreeSet第二项为：7
// newTreeSet第一项与第二项相加：12
```

上面是正确做法，但是不正确会怎么样呢（不正确也就是没有使用强制类型转换）

``` Java
Random random = new Random();
TreeSet<Integer> treeSet = new TreeSet<>();
for (int i = 0; i < 10; i++) {
   int randomNumber = random.nextInt(0, 201);
   treeSet.add(randomNumber);
}
Object[] newTreeSet = treeSet.toArray();
int addNumber = newTreeSet[0] + newTreeSet[1];
System.out.printf("newTreeSet第一项为：%d\n", newTreeSet[0]);
System.out.printf("newTreeSet第二项为：%d\n", newTreeSet[1]);
System.out.printf("newTreeSet第一项与第二项相加：%d\n", addNumber);
```
上面便是没有使用强制类型转换的代码，如果没有使用强制类型转化，则会显示出：

`运算符 '+' 不能应用于 'java.lang.Object'、'java.lang.Object'`

但如果使用带参数的形式，那么便可以十分简单地解决这个问题

``` Java
Random random = new Random();
TreeSet<Integer> treeSet = new TreeSet<>();
for (int i = 0; i < 10; i++) {
   int randomNumber = random.nextInt(0, 201);
   treeSet.add(randomNumber);
}
Integer[] newTreeSet = treeSet.toArray(new Integer[0]);
int addNumber = newTreeSet[0] + newTreeSet[1];
System.out.printf("newTreeSet第一项为：%d\n", newTreeSet[0]);
System.out.printf("newTreeSet第二项为：%d\n", newTreeSet[1]);
System.out.printf("newTreeSet第一项与第二项相加：%d\n", addNumber);
```

上面这里将原本的`Object[]`替换为`Integer[]`，相对应的，后面的参数也要填写对应的类型

在这里例子中，两个项数相加的时候便没有使用强制类型转换

在一般情况下都是建议使用带参数的版本的，一方面这样更加安全，另一方面，不带参的版本属于历史遗留问题

从性能角度看，不带参数每次都需要创建新的数组，而带参数的可能会复用传入的数组

~~当然，除非你真的需要用到`Object`~~

这里我们可以补充一个内容，上文的带参数的形式使用了`new Integer[0]`

那么这里的`[0]`是什么意思呢

其实这里是在声明创建数组的大小，那么有人就要问了：诶，0不是代表长度为0吗？

是的，但是Java在创建数组的时候有一个有意思的特性：

如果传入的集合大小是刚好与创建的数组声明的大小是一致的，那么会直接存入并返回

如果是小于（也就是空间不足），那么会创建新数组并返回

如果是大于的，那么则会在存入集合后把多余的空间用**null**填充

##### 补充点：为什么要使用数组
说了这么多，还没有体积到**为什么要使用数组**

确实，原先的集合已经很方便了，但是在性能上，数组的是要比集合更加好的：

我们这里就以ArrayList为例，这个集合的底层实现也是数组

首先，我们需要搞懂ArrayList到底是怎么存的

说的简单粗暴一点，其实里面存的东西实际上并不是直接的元素，而是**指向对应元素的引用**

> 这一点其实有点像C中的指针

这就导致了什么，每次查询都是间接查询，而不是直接查询

但是数组呢？由于其特性，每个元素都是按顺序排序的

这就导致了在查询的时候时间十分快

并且由于不用间接可以直接查询

这种特性对于CPU的缓存是更好的

在这一点上，数组性能是要高于集合的，尽管这两者实际使用效果差不多

**forEach**
forEach方法是一个用于批量操作的方法

其带有一个参数：`forEach(Consumer<? super E> action)`

这个参数的意思是在里面输入相对应的行为：

``` Java
Random random = new Random();
ArrayList<Integer> arrayList = new ArrayList<>();
for (int i = 0; i < 3; i++) {
   arrayList.add(random.nextInt(0, 200));
}

arrayList.forEach(System.out::println);

// 输出：
// 142
// 143
// 92
```
这里的意思的将arrayList的所有元素都使用`System.out`中的`println`方法输出

除了这种简单的方法，forEach方法还可以使用代码块来定义行为

``` Java
Random random = new Random();
ArrayList<Integer> arrayList = new ArrayList<>();
for (int i = 0; i < 3; i++) {
   arrayList.add(random.nextInt(0, 200));
}
arrayList.forEach(array -> {
   int square = array * array;
   System.out.printf("原数字为：%d，平方数字为：%d\n", array, square);
});

// 输出：
// 原数字为：188，平方数字为：35344
// 原数字为：11，平方数字为：121
// 原数字为：35，平方数字为：1225
```

**注意！在使用的过程中不可使用任何会引起modCount改变的方法，否则会抛出报错**

``` Java
Random random = new Random();
ArrayList<Integer> arrayList = new ArrayList<>();
for (int i = 0; i < 3; i++) {
   arrayList.add(random.nextInt(0, 200));
}
arrayList.forEach(array -> {
   arrayList.add(123);
   int square = array * array;
   System.out.printf("原数字为：%d，平方数字为：%d\n", array, square);
});

// 输出：
// ConcurrentModificationException
```
上面使用了`add`，这个方法会导致`modCount`发生改变，所以不可以使用

不过Iterator的remove是可以使用的，原因之前也提及到的

接下来需要补充一个点，就是forEach方法是无法获取到遍历的下标的，如果需要索引下标，则必须自己新增变量自增获得

``` Java
Random random = new Random();
ArrayList<Integer> arrayList = new ArrayList<>();
for (int i = 0; i < 3; i++) {
   arrayList.add(random.nextInt(0, 200));
}
int[] lstIndex = {0};
arrayList.forEach(array -> {
   System.out.printf("当前下标为%d\n", lstIndex[0]++);
});

// 输出：
// 当前下标为0
// 当前下标为1
// 当前下标为2
```

**removeIf()**
接下来介绍这个方法

这个方法有一个参数：

这个参数代表可以选择的筛选方法

这个方法的作用就是根据筛选的方法来删除指定元素，如果满足条件则删除该元素

筛选方法依旧支持Lambda表达式

``` Java
Random random = new Random();
ArrayList<Integer> arrayList = new ArrayList<>();
for (int i = 0; i < 10; i++) {
   arrayList.add(random.nextInt(0, 500));
}
System.out.printf("原数组：\n%s\n", arrayList);
arrayList.removeIf(array -> array % 3 == 0);
System.out.printf("筛选后的数组：\n%s\n", arrayList);

// 输出：
// 原数组：
// [211, 118, 450, 306, 130, 204, 223, 334, 444, 212]
// 筛选后的数组：
// [211, 118, 130, 223, 334, 212]
```
可以看到，上面的数组一部分满足条件的元素被删除了

这个方法还可以用于删除`null`值
 
``` Java
Random random = new Random();
ArrayList<Integer> arrayList = new ArrayList<>();
for (int i = 0; i < 10; i++) {
   if (random.nextBoolean()) {
         arrayList.add(random.nextInt(0, 500));
   } else {
         arrayList.add(null);
   }
}
System.out.printf("原数组：\n%s\n", arrayList);
arrayList.removeIf(Objects::isNull);
System.out.printf("筛选后的数组：\n%s\n", arrayList);

// 输出：
// 原数组：
// [491, null, 141, 395, 313, null, 168, 487, 6, 216]
// 筛选后的数组：
// [491, 141, 395, 313, 168, 487, 6, 216]
```

**equals()**
接下来介绍这个方法

这个方法的作用为判断是否相等

这个方法有一个参数：`equals(Object o)`

参数o代表一个对象

在这里的用法为判断两个集合的元素是否相等：

``` Java
ArrayList<String> arrayList = new ArrayList<>();
arrayList.add("Hello");
ArrayList<String> arrayList1 = new ArrayList<>();
arrayList1.add("Hello");
System.out.printf("判断两个集合是否相等：%s",arrayList.equals(arrayList1));

// 输出：
// 判断两个集合是否相等：true
```
可以看到，这两个集合的元素完全一致，所以返回`true`

注意，如果两者属于不同接口，那么即使元素相同也会返回`false`

``` Java
ArrayList<Integer> arrayList = new ArrayList<>();
TreeSet<Integer> treeSet = new TreeSet<>();
for (int i = 0; i < 5; i++) {
   arrayList.add(i);
   treeSet.add(i);
}
System.out.printf("判断两个集合是否相等：%s",arrayList.equals(treeSet));

// 输出：
// 判断两个集合是否相等：false
```
这里分别为两个不同的接口，所以即使内容相同，也是返回`false`

但如果接口相同，内容相同，但是实现类不同，那也是会正常返回`true`的：

``` Java
ArrayList<String> arrayList = new ArrayList<>();
LinkedList<String> linkedList = new LinkedList<>();
System.out.printf("两个集合是否相等：%s",linkedList.equals(arrayList));

// 输出
// 两个集合是否相等：true
```

为什么会这样？这是因为在源码中已经写清楚了：

``` Java
public boolean equals(Object o) {
   if (o == this)
      return true;
   if (!(o instanceof List))
      return false;
   ...
}
```

可以看到，这里的第二个if语句便是判断是否属于同一接口的方法，上文输出为false的例子一个为List接口，而另一个为Set接口，所以返回为false

##### 补充点：null安全
这里补充一点，`equals()`方法是**null安全**的

什么是null安全呢？简单来说就是在处理集合中的null元素的时候不会抛出空指针报错：`NullPointerException`

那么为什么要特意强调这一点呢？

因为在Java中null指的是**没有指向任何对象的引用**

如果试图对null调用任何方法，则会抛出**NullPointerException**

但是`equals()`是如何处理的呢？

可以在源码里面看到

``` Java
if (!(o1==null ? o2==null : o1.equals(o2)))
      return false;
```
这里是一个三元表达式，具体的逻辑如下：

如果o1为null，那么则判断o2是否为null

如果也为null，那么条件正确，返回true，但由于为!，所以实际为false，不执行判断内的语句

而如果o2不为null，那么则返回false，进而转变为true，执行语句`return false`，这就跟我们的目的相一致（因为一个为null一个不为null）

而如果o1不为null，那么就执行`o1.equals(o2)`

如果两者相等，那么则返回true，转换为false，不执行语句

可以看到，无论怎么样，这里都会正确的比较

那么问题来了，为什么不直接用`equals()`

我们不妨看看这里（指的是o1.equals(o2)）的equals源码是怎么写的：

> 这里的equals来自这个文件 -> Object.java
``` Java
public boolean equals(Object obj) {
   return (this == obj);
}
```
可以清楚地看到，这里并没有对null进行处理

不进行处理会导致什么后果呢？很明显，那就是：**NullPointerException**

**hashcode()**

接下来是hashcode方法

这个方法没有参数，主要的使用用途为计算指定元素的哈希值：

``` Java
ArrayList<String> arrayList = new ArrayList<>();
arrayList.add("Hello！");
System.out.printf("该元素的哈希值%s",arrayList.getFirst().hashCode());

// 输出：
// 该元素的哈希值：-2137002865
```

一个比较常见的用法是通过比较生成的哈希值来判断两个值是否相等：

``` Java
ArrayList<String> arrayList = new ArrayList<>();
ArrayList<String> arrayList1 = new ArrayList<>();
arrayList.add("Hello！");
arrayList1.add("Hello！");
int arrayListHashCode = arrayList.getFirst().hashCode();
int arrayList1HashCode = arrayList1.getFirst().hashCode();
System.out.printf("这两个元素是否相等：%s", arrayList1HashCode == arrayListHashCode);

// 输出：
// 这两个元素是否相等：true
```

不过需要说明的一点是，上面的比较方法是有点问题的

在Java中经常是有些元素的哈希值是相同的，比如**通话**和**重地**

``` Java
ArrayList<String> arrayList = new ArrayList<>();
ArrayList<String> arrayList1 = new ArrayList<>();
arrayList.add("通话");
arrayList1.add("重地");
int arrayListHashCode = arrayList.getFirst().hashCode();
int arrayList1HashCode = arrayList1.getFirst().hashCode();
System.out.printf("这两个元素是否相等：%s", arrayList1HashCode == arrayListHashCode);

// 输出：
// 这两个元素是否相等：true
```

那么要怎么解决这个问题呢？其实很简单：

``` Java
ArrayList<String> arrayList = new ArrayList<>();
ArrayList<String> arrayList1 = new ArrayList<>();
arrayList.add("通话");
arrayList1.add("重地");
int arrayListHashCode = arrayList.getFirst().hashCode();
int arrayList1HashCode = arrayList1.getFirst().hashCode();
System.out.printf("这两个元素是否相等：%s", arrayList1HashCode == arrayListHashCode && arrayList1.getFirst().equals(arrayList.getFirst()));

// 输出：
// 这两个元素是否相等：false
```

通过先比较哈希值再比较字符串是否相等，这样便可以解决**哈希碰撞**的问题

> 更多的内容可以参考后面HashSet的 补充点：底层实现

**clone()**
接下来讲讲这个方法

在讲这个方法的具体用法之前，需要先补充一下`浅拷贝`和`深拷贝`的内容

##### 补充点：浅拷贝与深拷贝
> 此处可能会使用到C里面的指针来辅助理解
首先是浅拷贝

假设现在有一个数组，你使用浅拷贝拷贝这个数组，那么拷贝后的新数组中是原来的元素吗

虽然说表面上是一样的，但实际上是不一致的

新数组拷贝的是老数组中的对各个元素的引用，这意味了什么？

意味着假设你修改了老数组中引用对应的元素，那么拷贝后的数组也会被修改

``` Java
ArrayList<StringBuffer> arrayList = new ArrayList<>();
for (int i = 0; i < 5; i++) {
   arrayList.add(new StringBuffer("Hello" + i));
}
ArrayList<StringBuffer> arrayListClone = (ArrayList<StringBuffer>) arrayList.clone();
arrayList.get(2).append(3);
System.out.printf("原数组：%s\n",arrayList);
System.out.printf("复制后的数组：%s\n",arrayListClone);

// 输出：
// 原数组：[Hello0, Hello1, Hello23, Hello3, Hello4]
// 复制后的数组：[Hello0, Hello1, Hello23, Hello3, Hello4]
```
可以看到，即使是先复制再修改也没办法改变，因为实际上是复制引用而不是直接复制对应的元素

这里可能有人就要说了：诶，那为什么我的结果跟这里说的不一样：

``` Java
ArrayList<String> arrayList = new ArrayList<>();
for (int i = 0; i < 5; i++) {
   arrayList.add("Hello" + i);
}
ArrayList<String> arrayListClone = (ArrayList<String>) arrayList.clone();
arrayList.add(2,"3");
System.out.printf("原数组：%s\n",arrayList);
System.out.printf("复制后的数组：%s\n",arrayListClone);

// 输出：
// 原数组：[Hello0, Hello1, 3, Hello2, Hello3, Hello4]
// 复制后的数组：[Hello0, Hello1, Hello2, Hello3, Hello4]
```
可以看到，这里即使修改了原数组复制后的数组依旧没有改变

难道是出问题了吗？**不是**，其实这里跟所选的类型有关

我们可以看到，在第一个例子中我们选择的类型为：`StringBuffer`

而第二个例子中我们选择的是`String`

诶，那这俩有什么区别呢？

很简单，一个可变，一个不可变

说白了就是`StringBuffer`是可变的，所以当原数组变了复制的数组也就变了

而`String`是不可变的，该怎么样就怎么样，不管是不是被修改的

---
那么此处来通过C的例子来简单说明一下浅拷贝

假设我们有一个装满指针的数组，浅拷贝就是复制这个数组

这个数组有什么呢？有指针，指向不同的内存地址

那么，假设我现在修改原数组中某一个指针指向的一个元素，

那么这个指针指向的就是这个新的元素

由于复制的只是指针，所以复制的数组也会指向这个元素（由于内存地址不变，这个指针指向的还是那个地址）

那么要怎么解决这个问题呢？其实很简单，使用**深拷贝**即可

诶，那深拷贝又是复制什么呢？

准确来讲，深拷贝其实是创建了一个新的对象，然后递归复制所有原先数组引用的底层对象

说白了就是直接复制元素而不是复制引用

> 不过有一说一，之前举的String的例子其实就有点深拷贝的意味了
> ~~不过这玩意由于是误打误撞实现了，所以不能这么记~~

---
在讲完浅拷贝和深拷贝之后，就要正式介绍有关`clone()`方法的内容了

首先这个方法并没有任何的参数：`Object clone()`

并且在使用的时候还要记得**显式类型转换**，否则会报错：
``` Java
ArrayList<String> arrayList = new ArrayList<>();
for (int i = 0; i < 5; i++) {
   arrayList.add("Hello" + i);
}
ArrayList<String> arrayListClone = arrayList.clone();
arrayList.add(2,"3");
System.out.printf("原数组：%s\n",arrayList);
System.out.printf("复制后的数组：%s\n",arrayListClone);

// 输出：
// java: 不兼容的类型: java.lang.Object无法转换为java.util.ArrayList<java.lang.String>
```

正确的写法是这样的：
``` Java
ArrayList<String> arrayList = new ArrayList<>();
for (int i = 0; i < 5; i++) {
   arrayList.add("Hello" + i);
}
ArrayList<String> arrayListClone = (ArrayList<String>) arrayList.clone();
arrayList.add(2,"3");
System.out.printf("原数组：%s\n",arrayList);
System.out.printf("复制后的数组：%s\n",arrayListClone);

// 输出：
// 原数组：[Hello0, Hello1, 3, Hello2, Hello3, Hello4]
// 复制后的数组：[Hello0, Hello1, Hello2, Hello3, Hello4]
```
可以看到，这里就正常运行了

##### 补充点：为什么会有警告
如果你使用IntelliJ IDEA并且打出上面那段代码，那么你会发现编译器会给你一个警告：
`未检查的转换: 'java.lang.Object' 转换为 'java.util.ArrayList<java.lang.String>'`

那么这是什么意思呢？简单来说就是编译器没办法在运行的时候判断其正确性

虽然说ArrayList重写了`clone()`方法，但为了兼容性，返回类型依旧为`Object`

``` Java
// 来自ArrayList.java

public Object clone() {
   ...
}
```
那么有什么问题呢？

为了正常运行，我们在使用`clone()`的时候是有进行显式类型转换的

但是Java的泛型在运行时会被擦除（Type Erasure）

虽然JVM知道这玩意是ArrayList，但是不知道是哪个类型

这就导致了无法确定这玩意是不是真的是装着`String`的ArrayList

那要怎么办呢？其实很简单：那就是换一种复制方法：

``` Java
ArrayList<StringBuffer> arrayList = new ArrayList<>();
for (int i = 0; i < 5; i++) {
   arrayList.add(new StringBuffer("Hello" + i));
}
ArrayList<StringBuffer> arrayListClone = new ArrayList<>(arrayList);
arrayList.get(2).append(3);
System.out.printf("原数组：%s\n",arrayList);
System.out.printf("复制后的数组：%s\n",arrayListClone);

// 输出：
// 原数组：[Hello0, Hello1, Hello23, Hello3, Hello4]
// 复制后的数组：[Hello0, Hello1, Hello23, Hello3, Hello4]
```
可以看到，这里使用了`new ArrayList<>(arrayList)`，这种方法就不会抛出警告了
> 顺带一提，这种方式也是浅拷贝（看输出也可以明白）

不过如果你真的很想使用原先的`clone()`方法，但不想看到警告，那么可以在这个语句的上一行加上这么一句：

``` Java
ArrayList<StringBuffer> arrayList = new ArrayList<>();
for (int i = 0; i < 5; i++) {
   arrayList.add(new StringBuffer("Hello" + i));
}
@SuppressWarnings("unchecked")
ArrayList<StringBuffer> arrayListClone = (ArrayList<StringBuffer>) arrayList.clone();
arrayList.get(2).append(3);
System.out.printf("原数组：%s\n",arrayList);
System.out.printf("复制后的数组：%s\n",arrayListClone);
```

这里加上了`@SuppressWarnings("unchecked")`语句，成功消除了警告

**toString()**
接下来讲讲toString方法，这个方法有点类似Python中的`__str__`魔术方法

一般而言，这个方法会被重写成想要的方法来方便输出对应的数据

``` Java
class Aclass{
    private String whatName;

    public Aclass(String whatName){
        this.whatName = whatName;
    }

    @Override
    public String toString(){
        return String.format("这个对象的名字是：%s",whatName);
    }
}

public class Test {
    public static void main(String[] args) {
        Aclass aclass = new Aclass("测试");
        System.out.println(aclass.toString());
    }
}

// 输出：
// 这个对象的名字是：测试
```
可以看到，我们这里重写了这个方法：`toString()`，是的他可以按我们规定的输出方式输出

那么在ArrayList里面又是如何的呢：

``` Java
ArrayList<String> arrayList = new ArrayList<>();
for (int i = 0; i < 5; i++) {
   arrayList.add("hello" + i);
}
System.out.printf("使用toString方法: %s", arrayList.toString());

// 输出：
// 使用toString方法: [hello0, hello1, hello2, hello3, hello4]
```
可以看到，这里输出的结果实际上和直接使用该集合作为参数是一致的：

那么具体又是如何的呢？
``` Java
public String toString() {
   Iterator<E> it = iterator();
   if (! it.hasNext())
      return "[]";

   StringBuilder sb = new StringBuilder();
   sb.append('[');
   for (;;) {
      E e = it.next();
      sb.append(e == this ? "(this Collection)" : e);
      if (! it.hasNext())
            return sb.append(']').toString();
      sb.append(',').append(' ');
   }
}
```
这段代码来自：`AbstractCollection.java`，ArrayList中toString方法的实现就是来自这里

此处的基本原理是：如果一开始无法用迭代器返回下一个元素，则直接返回：`[]`
> 这里其实也就是在处理 null

如果不属于null，那么则处理另一种情况：

首先第一步：是往StringBuilder里面添加：`[`来模拟数组的输出

之后开始一个一个遍历元素

此处用到了一些很巧妙的点，注意看这里的for循环三个表达式都是没有的，唯一的退出条件就是迭代器无法返回下一个元素（也就是结束的情况）

这样的好处是可以完全遍历这个集合

此处是先检测是否集合遍历结束才来加上逗号和空格的

ArrayList也可以重写这个方法，与之前演示的例子没有太大差异，这里便不多阐述

**stream()**
接下来是stream()方法，这个方法下面有高达35个方法，这里将依次介绍

但是在这之前我们需要介绍一下stream是来干什么的

首先简单介绍一下，这个方法正如他的名字一样：可以进行流式处理

相当于说把这玩意通过一个流水线一点一点进行处理，最后输出想要的结果

但在正式介绍这个方法之前，我们需要先介绍一下里面的一些小概念：

首先是**中间操作**和**终端操作**

中间操作的意思是这个操作可以连接前后的方法，构建一条完整流，而终端操作意味着这个方法作为结尾的方法，只能在结尾使用（因为这种方法无法继续连接其他方法）

那么有什么方法可以判断是哪一种操作呢？其实很简单，只需要看这个操作的返回值即可

一般而言，如果返回值为`stream`的话，这个方法便为中间操作（例如`filter()`，`distinct()`等）

如果返回值不为`stream`，而是为其他的话，那么这个方法便为终端操作

---
这里再讲深入一点

中间操作为惰性操作，也就是不会立刻执行

而终端操作是会立刻执行的，进而激活整个流

上文也提及到，终端操作属于结尾的操作，所以只能有一个

而中间操作属于整个流里面的一个组成部分，所以是可以有多个的

**filter()**
此方法返回类型为`stream`，为中间操作

filter这个方法的作用是作为一个筛子筛选出对应的元素

比如说我想要筛选出所有第一个字母为`a`的元素，那么可以这么操作：
``` Java
String[] itemList = {"banana", "apple", "cherry", "blueberry", "avocado"};
ArrayList<String> arrayList = new ArrayList<>(Arrays.asList(itemList));
arrayList.stream()
         .filter(a -> a.startsWith("a"))
         .forEach(System.out::println);

// 输出：
// apple
// avocado
```
可以看到，在上面这个例子中我们通过`filter`方法成功筛选出所有以字母a开头的元素

虽然这玩意可以筛选指定元素，但是并不会对原来集合进行修改

**distinct()**
此方法返回类型为`stream`，为中间操作

接下来介绍一下distinct()这个方法

这个方法的作用是去除所有的重复元素，只保留一个

效果有点像是Set接口的实现类

``` Java
String[] numbersList = {"1","2","1","2","5","3","2","3","4","3","2","3","3"};
ArrayList<String> arrayList = new ArrayList<>(Arrays.asList(numbersList));
arrayList.stream()
         .distinct()
         .forEach(System.out::println);

// 输出：
// 1
// 2
// 5
// 3
// 4
```
从上面便可以看出，在通过`distinct()`处理之后，输出的元素便没有任何重复的内容了

我们可以利用这个方法去重

这个方法的底层实现也是很有意思的，其去重的原理跟Set接口其实差不多，通过使用`equals()`和`hashcode()`方法来实现去重

**sorted()**
此方法返回类型为`stream`，故为中间操作

接下来是sorted()，这个方法的作用是对当前流进行排序

有点类似TreeMap或者TreeSet

这里我们依旧以上文`distinct()`中的例子作为例子
``` Java
String[] numbersList = {"1","2","1","2","5","3","2","3","4","3","2","3","3"};
ArrayList<String> arrayList = new ArrayList<>(Arrays.asList(numbersList));
arrayList.stream()
         .distinct()
         .sorted()
         .forEach(System.out::println);

// 输出：
// 1
// 2
// 3
// 4
// 5
```
可以看到，在使用了sorted()之后，输出的结果便不是之前的乱序了，而是以正序排列

既然这个可以实现排序，那么自然也可以定义排序，相关的内容可以参照TreeSet的`补充点：定义排序规则`

这里简单举几个例子：
``` Java
String[] numbersList = {"apple", "apricot", "banana", "cherry", "coconut", "avocado", "durian"};
ArrayList<String> arrayList = new ArrayList<>(Arrays.asList(numbersList));
arrayList.stream()
         .distinct()
         .sorted(Comparator.comparing(String::length)
               .thenComparing(Comparator.naturalOrder()))
         .forEach(System.out::println);

// 输出：
// apple
// banana
// cherry
// durian
// apricot
// avocado
// coconut
```
这里的排序规则是这样的：
`Comparator.comparing(String::length).thenComparing(Comparator.naturalOrder())`

那么这个是什么意思的，简单来说就是先按字符串长度排序（String::length）

然后再以自然排序的方式排序（Comparator.naturalOrder()）

##### 补充点：有关如何排序
sorted()的底层使用了`双轴快排（Dual-Pivot Quicksort）`

这个东西是传统快排的一个改进版本，使用了三个分区，而传统快排只用了两个分区

使用双轴快排的好处是减小**常数因子**（两种快排的时间复杂度都是O(n log n)）

通过减少常数因子来得到更好的效率，这也就是为什么选择双轴快排的原因

**peek()**
此方法返回值为stream，故为中间操作

接下来介绍peek()这个方法

这个方法很简单，就是在流的指定的地方来进行一次操作（这个操作不会产生影响）

一般而言，这个东西会用于日志这一类操作里面

不过这里就简单的演示一下：

``` Java
String[] numbersList = {"apple", "apricot", "banana", "cherry"};
ArrayList<String> arrayList = new ArrayList<>(Arrays.asList(numbersList));
arrayList.stream()
         .distinct()
         .peek(a -> System.out.printf("当前数组元素有：%s%n", a))
         .sorted(Comparator.comparing(String::length)
               .thenComparing(Comparator.naturalOrder()))
         .forEach(System.out::println);

// 输出：
// 当前数组元素有：apple
// 当前数组元素有：apricot
// 当前数组元素有：banana
// 当前数组元素有：cherry
// apple
// banana
// cherry
// apricot
```
可以看到，这里插入了一个打印的操作

需要注意的一个点是，如果没有任何的终端操作，那么是不会执行peek的操作的

**limit()**
该方法返回类型为stream，故为中间操作

接下来介绍一下这个方法

这个方法的作用是截取原流中的前n个元素并返回作为新的流

举个例子：
``` Java
String[] numbersList = {"apple", "apricot", "banana", "cherry"};
ArrayList<String> arrayList = new ArrayList<>(Arrays.asList(numbersList));
arrayList.stream()
         .distinct()
         .limit(2)
         .forEach(System.out::println);

// 输出：
// apple
// apricot
```
可以看到，这里输出部分就只有两个了

那么这也引出了一个问题，这玩意如果大于小于等于原流长度会怎么样呢？

简单概括一下：

如果原流小于截取长度，那么返回原流

如果原流等于截取长度，那么返回原流

如果原流大于截取长度，那么返回截取的长度

##### 扩展：短路操作（Short-Circuiting Operation）

这里是一个用于扩展的用法，主要说明limit()方法的实际使用

---
不过由于此处还需一些终端操作，便不多扩展

假设你有一个很长很长的数组，你需要选取这个数组里面的一些元素，于是你打算遍历这个数组来寻找想要的元素

所以你向机器发送了“遍历这个数组”的指令

过了一会后，机器返回给你想要的元素，但是你发现了一个点，所需的元素其实很快就找到的，但是由于要遍历整个数组，所以花费时间和资源很多

那么要怎么解决这个问题呢？其实很简单，只需要使用**短路操作**即可

所谓短路操作，指的是在实现某个条件后就直接中断（类似短路）

假设我们把这个数组变成无限长度，此时我们想要前5个偶数

假设我们是通过遍历的方法，那么无论如何都得不到输出，因为中间操作为惰性方法，必须有终端操作才行，而数组是无限长的，所以永远达不到

但是如果我们选择短路操作，便可以达到这个目的：

``` Java
Stream.iterate(1, i -> i + 1)
         .filter(i -> i % 2 == 0)
         .limit(5)
         .forEach(System.out::println);

// 输出：
// 2
// 4
// 6
// 8
// 10
```
可以看到，这里在一个无限数组里面成功输出了前五个偶数

**skip()**
该方法返回类型为`stream`，故为中间操作

接下来介绍一下skip()方法，这个方法比较简单，具体的功能为跳过指定的n个元素（或者说从第n + 1个元素开始）

``` Java
String[] numbersList = {"apple", "apricot", "banana", "cherry"};
ArrayList<String> arrayList = new ArrayList<>(Arrays.asList(numbersList));
arrayList.stream()
         .skip(2)
         .forEach(System.out::println);

// 输出：
// banana
// cherry
```
可以看到，这里输出的内容是从第三项开始的，也就是跳过了两项

不过需要提醒的一点是，如果这个是有序流（例如这里的ArrayList），那么则会正常的跳过前n项

但如果是无序流（例如Set接口里面的集合），由于不知道顺序是什么，所以跳过的元素是随机的

这里同样引出一个问题：如果数组长度大于等于小于原流会怎么样

简单概括如下

如果大于原流，那么什么都不返回

如果等于原流，也是什么都不返回

如果小于原流，那么按正常结果返回

除此之外，如果n小于等于0，那么会抛出这个报错：

``` Java
String[] numbersList = {"apple", "apricot", "banana", "cherry"};
ArrayList<String> arrayList = new ArrayList<>(Arrays.asList(numbersList));
arrayList.stream()
         .skip(-1)
         .forEach(System.out::println);

// 输出：
// IllegalArgumentException
```

---
在实际的应用中，你可以利用这个方法实现翻页效果

> 此处仅限小数据！大规模数据这里花费时间为n，太慢了！
``` Java
String[] itemList = {"apple", "apricot", "banana", "cherry", "coconut", "avocado", "durian", "damson"};
ArrayList<String> arrayList = new ArrayList<>(Arrays.asList(itemList));
int eachPage = 2;
int startPage = 3;
arrayList.stream()
         .skip(eachPage * (startPage - 1))
         .limit(eachPage)
         .forEach(System.out::println);

// 输出：
// coconut
// avocado
```
可以看到，这里输出的便是第三页的内容

每页有两个元素，从第三页开始，那么便跳过了 2 * (3 - 1) 个元素

**takeWhile()**
该方法返回的类型为stream，故为中间操作

该方法有一个可填参数，该参数用于判断

接下来是takeWhile方法，这个方法的作用是按顺序选取流里面的元素，直到出现不满足条件的元素，并返回新流

举个例子：

``` Java
String[] itemList = {"apple", "banana", "cabbage", "date", "brush", "comb"};
ArrayList<String> arrayList = new ArrayList<>(Arrays.asList(itemList));
arrayList.stream()
         .takeWhile(a -> a.length() > 4)
         .forEach(System.out::println);

// 输出：
// apple
// banana
// cabbage
```
可以看到，这里选择的标准为：**若该元素长度大于4，则返回为真**

我们可以稍微模拟一下：

首先第一次：`apple`，长度为5，大于4，所以为真

第二次：`banana`，长度为6，大于4，所以为真

第三次：`cabbage`，长度为7，大于4，所以为真

第四次：`date`，长度为4，等于4，不满足条件，退出

可以看到，第四次条件不满足，所以直接退出了，返回的新流为一到三次的结果

与上文的limit一样，这个方法也可以用于短路操作

由于这个方法读取顺序是按顺序读取，所以如果为无序流则会随机读取

**dropWhile()**
此方法返回类型为stream，故属于中间操作

这个方法的作用与takeWhile差不多，主要效果与上文的takeWhile效果是相反的

换句话说，这个方法的作用是在判断为真时跳过，如果判断为假，则截断并选取后面所有的元素

我们通过一个例子来说明：

``` Java
String[] itemList = {"apple", "banana", "cabbage", "date", "brush", "comb"};
ArrayList<String> arrayList = new ArrayList<>(Arrays.asList(itemList));
arrayList.stream()
         .dropWhile(a -> a.length() > 4)
         .forEach(System.out::println);

// 输出：
// date
// brush
// comb
```
通过上文我们可以知道此处在第四次的时候返回为假，所以返回的结果就是该项后面的各个元素

**forEach()**
该方法返回类型**不为**stream，故为终端操作

接下来介绍这个方法，这个方法属于终端操作，所以只能放置在最后一个位置

并且在上文也提及到了，**每个操作流中只能有一个终端操作**

在简单介绍完终端操作之后，便开始介绍这个方法：

这个方法的作用是对流中的**每一个元素执行指定的操作**

> 在上文其实很多例子都使用了这个方法，但是此处还是再次举个例子来说明

``` Java
String[] itemList = {"banana", "bag", "ball", "comb", "band", "bath"};
ArrayList<String> arrayList = new ArrayList<>(Arrays.asList(itemList));
arrayList.stream()
         .takeWhile(a -> a.startsWith("ba"))
         .forEach(System.out::println);

// 输出：
// banana
// bag
// ball
```
可以看到，这里`forEach`语句对所有的元素都使用了`System.out::println`，也就是将流里面的每一个元素都打印出来

**forEachOrdered()**
接下来的这个方法与forEach方法是一致的，但是在细节上有些不同，此处重点讲不同，具体的使用方法可以参照`forEach()`

首先这个方法的一大特点就是**必定按顺序输出**

诶，这里可能就有人有疑惑了，什么叫做必定按顺序输出呢？

要讲这个的话就得简单引入`parallelStream()`，**并行流**

这个流在处理的时候会使用到多线程，在合并的时候可能出现一些合并上的问题，比如说使用`forEach()`时，如果线程2比线程1先完成，那么会直接执行，不等线程1，举个例子：

假设被操作的流中元素为A B C

其中A耗时最大，C耗时最少

此时若使用`parallelStream().forEach()`的话，那么会导致耗时较少的C先输出

而耗时较长的A反而慢输出

这很明显不符合我们的预期

所以便有了这个方法来强制按顺序输出

但这样做是有代价的，`forEachOrdered()`的性能是不如`forEach()`的，如果你在使用并行流的时候不在意输出的顺序，那么请使用`forEach()`来提高性能

##### 扩展：为何有序
接下来简单讲一讲这个方法是如何实现有序的：

首先当你在一个并行流里面调用这个方法的时候，这个流会被分割成好几块（forEach也会分割成好几块，但是后面的处理是不一样的）

在分割完之后便分别开始处理，在开始处理的时候会保留这个元素原先在哪个位置

系统会自动创建一个队列用于缓存，每当有一个处理完之后，不会直接执行，而是把这些放到缓存区里面去

最后，便会有一个专门的线程（不一定是新的，有可能是主线程）来按照顺序取出元素并对其使用`action`

也正因如此，`forEachOrdered`比`forEach`多了一系列的操作，所以会更费性能

**toArray()**
这个方法返回类型为Object，所以为**终端操作**

接下来简单介绍这个方法，这个方法很简单，作用就是将当前的流转换为数组：

``` Java
String[] itemList = {"banana", "bag", "ball", "comb", "band", "bath"};
ArrayList<String> arrayList = new ArrayList<>(Arrays.asList(itemList));
String[] newList =  arrayList.stream()
         .takeWhile(a -> a.startsWith("ba"))
         .toArray(String[]::new);
System.out.printf("筛选后的数组为：%s", Arrays.toString(newList));

// 输出：
// 筛选后的数组为：[banana, bag, ball]
```
可以看到，这里将用takeWhile筛选后的流转换一个新的数组

这里括号内的参数实际为：`类型[]::new`，是一种方法引用，不过这里不多阐述

注意，如果没有在toArray的括号里面添加说明想要转换成什么类型的话，会默认转换成Object类型，这就导致了想要使用的时候必须进行强制类型转换

##### 补充点：有何意义
在上文的例子中可能有人看到了这一点：`Arrays.toString(newList)`

很明显，这里是重新转换为字符串了

可能就有人想问这样有什么意义，但事实上这里只是为了简单演示才使用这个转换的

实际上，使用toArray转换为数组可以让我们使用流中的方法简化一系列操作

假设我们想要筛选整个数组，那么原先的做法是使用for语句加上判断来查找，但是如果使用流只需要使用takeWhile就可以了

这也就是为什么要使用toArray的原因：**简化操作**

**min() & max()**
这两个操作都属于终端操作，并且由于效果是很接近的，所以放到一起讲

这个方法其实很简单，就是通过括号内的比较规则来比较出最小 / 最大的那个元素

举个很简单的例子：

``` Java
String[] itemList = {"banana", "bag", "ball", "comb", "band", "bath"};
ArrayList<String> arrayList = new ArrayList<>(Arrays.asList(itemList));
Optional<String> newItem = arrayList.stream()
         .takeWhile(a -> a.startsWith("ba"))
         .min(Comparator.comparing(String::length));
newItem.ifPresent(a -> System.out.printf("最小长度元素为：%s", a));

// 输出：
// 最小长度元素为：bag
```
max方法同理，返回的是最大的

此处使用到了两个新东西(`Optional`和`ifPresent`)，这里只是为了介绍min的使用效果，所以不多介绍

上面的这个代码排序的规则是根据元素字符串的长度来比较的（String::length），此处使用了方法引用

**count()**
该方法返回类型为long，故为终端操作

接下来介绍count()

count()这个方法十分简单，作用为计数：

``` Java
String[] itemList = {"banana", "bag", "ball", "comb", "band", "bath"};
ArrayList<String> arrayList = new ArrayList<>(Arrays.asList(itemList));
long howMany = arrayList.stream()
         .takeWhile(a -> a.startsWith("ba"))
         .count();
System.out.printf("满足条件的个数：%s", howMany);

// 输出：
// 满足条件的个数：3
```

需要注意的一点是，这个方法返回的类型为long，**不是int！！！**

这个方法有个很有意思的点，如果这个流来自一个大小已知的源，并且没有执行任何会修改的操作（比如filter或者takeWhile），那么会直接返回底层的size，时间复杂度为`O(1)`

但如果有的话则需要遍历整个数组，时间复杂度会变为`O(n)`

**anyMatch()**
该方法返回类型boolean，所以为终端操作

接下来是这个方法，这个方法的作用是检查是否有元素满足括号内的条件，如果有的话就返回true，如果没有就返回为false

接下来给个具体例子来说明一下：

``` Java
String[] itemList = {"banana", "bag", "ball", "comb", "band", "bath"};
ArrayList<String> arrayList = new ArrayList<>(Arrays.asList(itemList));
boolean status = arrayList.stream()
         .peek(a -> System.out.printf("判断元素：%s%n", a))
         .anyMatch(a -> !a.startsWith("ba"));
System.out.printf("数组里面是否有不符合规则的：%s", status);

// 输出：
// 判断元素：banana
// 判断元素：bag
// 判断元素：ball
// 判断元素：comb
// 数组里面是否有不符合规则的：true
```
可以看到，这个方法实现了一次**短路操作**，在判断满足条件的元素后直接返回`true`，这样就可以不用遍历整个数组

##### 补充点：关于空流
现在假设这个流里面是没有任何东西的（也就是空流），这时对这个流进行操作怎么样呢？

``` Java
String[] itemList = {};
ArrayList<String> arrayList = new ArrayList<>(Arrays.asList(itemList));
boolean status = arrayList.stream()
         .peek(a -> System.out.printf("判断元素：%s%n", a))
         .anyMatch(a -> !a.startsWith("ba"));
System.out.printf("数组里面是否有不符合规则的：%s", status);

// 输出：
// 数组里面是否有不符合规则的：false
```
可以看到，这里并没有执行peek的操作，而是直接返回false

**allMatch()**
该方法依旧为终端操作

这个方法与上文的`anyMatch()`效果差不多，一个是找到一个就直接输出true，一个是要所有都满足才会输出true

举个简单的例子：
``` Java
List<String> lst = Arrays.asList("ba", "bag", "ball", "comb", "band", "bath");
ArrayList<String> arrayList = new ArrayList<>(lst);
boolean isContains = arrayList.stream()
         .allMatch(s -> s.startsWith("ba"));
System.out.printf("是否全部为ba开头：%s", isContains);

// 输出：
// 是否全部为ba开头：false
```
在上面这里例子中，我们判断该集合是否全部以`ba`作为开头，但是该集合中含有不以`ba`开头的元素，所以返回了`false`

##### 补充点：关于空流
在上文的`anyMatch`中，对空流执行操作会返回false，那么对空流使用allMatch()会怎么样呢

``` Java
String[] itemList = {};
ArrayList<String> arrayList = new ArrayList<>(Arrays.asList(itemList));
boolean status = arrayList.stream()
         .peek(a -> System.out.printf("判断元素：%s%n", a))
         .allMatch(a -> !a.startsWith("ba"));
System.out.printf("数组里面是否有不符合规则的：%s", status);

// 输出：
// 数组里面是否有不符合规则的：true
```
可以看到，这里返回的是true，与上面的anyMatch是不同的


**noneMatch()**
该方法依旧为终端操作

这个方法与上文的两个方法效果差不多的，主要的作用依旧为判断，返回类型依旧为boolean

具体的用法是，如果不满足noneMatch条件内，那么返回true：

举个例子：
``` Java
List<String> lst = Arrays.asList("ba", "bag", "ball", "comb", "band", "bath");
ArrayList<String> arrayList = new ArrayList<>(lst);
boolean isContains = arrayList.stream()
         .noneMatch(s -> s.startsWith("s"));
System.out.printf("是否不存在以s为开头：%s", isContains);

// 输出：
// 是否存在不以ba为开头：true
```
可以看到，这里输出为true，这说明没有以s开头的元素

##### 补充点：关于空流
这里补充一下如果是空流的是时候会出现什么情况：

``` Java
String[] itemList = {};
ArrayList<String> arrayList = new ArrayList<>(Arrays.asList(itemList));
boolean status = arrayList.stream()
         .peek(a -> System.out.printf("判断元素：%s%n", a))
         .noneMatch(a -> a.startsWith("ba"));
System.out.printf("数组里面是否有不符合规则的：%s", status);

// 输出：
// 数组里面是否有不符合规则的：true
```
可以看到，这里输出的结果为true，与上文的allMatch是一致的

---
### LinkedList
接下来讲讲LinkedList

LinkedList是一个双向链表，那么什么是双向链表呢

**双向链表**
简单来讲，双向链表是一种线性数据结构，特点是链表中的每个元素都包含**两个指针**

这两个指针分别指着什么呢？一个指针指向前一个节点，而第二个指针指向后一个节点

这样做的好处是各个元素之间紧密相连

而这意味着什么？以往的单向链表只有一个后驱指针，意味着如果想要查询上一个元素，**必须要把整个链表遍历一遍**，这大大影响了运行效率

双向链表由于带两个指针，所以在查询上一个元素时会快很多


#### 特性 / 优点
接下来讲讲有关LinkedList的一些特性

在上文也提及到了其作为双向列表，所以其可以快速查询上一个元素的特性有什么作用呢？

由于这个特点，LinkedList在插入元素的效率是**很快**的

我们可以举个例子：
``` Java
ArrayList<String> arrayList = new ArrayList<>();
Instant arrayStartTime = Instant.now();
for(int i = 0;i < 1000000; ++i){
   arrayList.add("Hello");
}
Instant arrayEndTime = Instant.now();
System.out.printf("ArrayList插入元素时间为：%s\n",Duration.between(arrayStartTime,arrayEndTime).toMillis());
```
在上面这个例子中，我们使用了计时器计时插入1000000个元素的时间

ArrayList花费的时间大概为11毫秒左右

那么LinkedList呢？

``` Java
LinkedList<String> linkedList = new LinkedList<>();
Instant linkedStartTime = Instant.now();
for(int i = 0;i < 100000; ++i){
   linkedList.add("Hello");
}
Instant linkedEndTime = Instant.now();
System.out.printf("LinkedList插入元素时间为：%s\n",Duration.between(linkedStartTime,linkedEndTime).toMillis());
```
这里同样计时了1000000个元素插入所需要的时间

不同的是，这里使用的是LinkedList，花费的时间大概为**4毫秒**

在插入元素方面，LinkedList的效率要**远快于**ArrayList！

#### 具体用法
在讲完LinkedList的一些特点之后，便可以开始介绍其具体的用法了

由于LinkedList本质还是属于`Link接口`，所以很多方法还是通用的（比如说`add()`、`get()`）

接下来主要介绍那些特有的方法

**offer()**
offer()是一个用于插入元素的方法，具体实现效果跟add()差不多

举个例子：
``` Java
LinkedList<String> linkedList = new LinkedList<>();
LinkedList<String> linkedList1 = new LinkedList<>();
linkedList.add("Hello,this is add()");
linkedList1.offer("Hello,this is offer()");
System.out.println(linkedList.getFirst());
System.out.println(linkedList1.getFirst());

// 输出：
// Hello,this is add()
// Hello,this is offer()
```
可以看到，这两个方法都可以实现插入的效果

offer()拥有与add()一样的两个方法，首位插入和末尾插入：`offerFirst()`、`offerLast()`

##### add()与offer()
诶，这里可能就有人要说了，那这样算不算一种设计冗余呢？

其实不然

在LinkedList中，offer()方法实现的是Deque接口 / Queue接口

而add()方法实现了List接口，两者虽然效果上是相等的，但是并不属于同一个接口

那么还有什么区别呢？

首先，add方法一般是作为列表的插入操作，而offer一般用于队列

假设我们现在想要插入一个满空间的列表，使用add方法会导致抛出报错`IllegalStateException`

但是，offer方法不会抛出报错，只会返回`false`

> 不过由于LinkedList是无界的，所以不存在空间不够的情况~~（当然内存不够依旧会报错）~~

说的直白一点就是：**add()是不成功就报错，而offer()是不成功就返回false**

---
**poll()**
接下来讲的方法是poll()，与前文的offer()一样，这个方法归属于Deque接口 / Queue接口

所以，在List接口中等价的方法为：`remove()`

以下是其基本的使用方法

``` Java
LinkedList<String> linkedList = new LinkedList<>();
for (int i = 0; i <100; ++i){
   linkedList.add("Hello,this is poll() _"+(i+1));
}
for (int i = 0; i < 3 ;++i){
   System.out.println(linkedList.poll());
}

// 输出：
// Hello,this is poll() _1
// Hello,this is poll() _2
// Hello,this is poll() _3
```
poll()的返回值为其删除的元素，这一点与remove()是一致的

同remove()一致，poll()也有用于移除首尾项的方法：`pollFirst()`、以及`pollLast()`

##### poll()与remove()
接下来讲讲这两者的区别

由于这两个功能上基本一致，所以差异的地方只有一些细节的点

假设现在LinkedList是一个空的链表，那么此时使用remove会抛出一个叫做`NoSuchElementException`的报错

``` Java
LinkedList<String> linkedList = new LinkedList<>();
System.out.println("文件正常编译");
System.out.println(linkedList.remove());

// 输出：
// 文件正常编译
// Exception in thread "main" java.util.NoSuchElementException
```

> 在IntelliJ IDEA中，如果使用该操作，则会有一个警告：对空集合 'linkedList' 进行的更新操作无效

但如果选择poll()来删除元素，那么就大不相同了：

``` Java
LinkedList<String> linkedList = new LinkedList<>();
System.out.println("文件正常编译");
System.out.println(linkedList.poll());

// 输出：
// 文件正常编译
// null
```
可以看到，这里并没有报错，而是选择了返回一个`null`

从`LinkedList.java`观察两者的源代码可以发现这一点：

``` Java
// 这里是poll()的实现代码
// 可以发现如果为空则返回null
public E poll() {
   final Node<E> f = first;
   return (f == null) ? null : unlinkFirst(f);
}
```

接下来是`remove()`

由于remove()的实现方法稍微有点抽象，这里把两个方法都展示出来
``` Java
public E remove() {
   return removeFirst();
}

public E removeFirst() {
   final Node<E> f = first;
   if (f == null)
      throw new NoSuchElementException();
   return unlinkFirst(f);
}
```
对比两者可以发现，两者的逻辑是一致的（一个用三元表达式一个用if语句），只是一个选择返回null，而另一个选择抛出异常`NoSuchElementException`

---
**peek()**
接下来介绍的方法是peek()

这个方法的作用是返回头部元素的值：
``` Java
LinkedList<String> list = new LinkedList<>();
list.offer("Hello! Nice to meet you");
list.offer("Hello! How are you?");
System.out.println(list.peek());

// 输出：
// Hello! Nice to meet you
```
可以看到，这个方法成功返回了我们的第一项元素

这里可能有人就会想到一个方法了：`get()`

但与之前的两个方法不同的是，这个方法并不与`get()`方法类似

`get()`可以返回指定的索引，而`peek()`却只能固定返回一个位置的索引

---
接下来是`peek()`的两个额外的方法，分别是返回头部元素的`peekFirst()`、和返回尾部元素的`peekLast()`

通过一个简单的例子来说明这两个方法的实际用途：
``` Java
LinkedList<String> list = new LinkedList<>();
for(int i = 0 ;i < 100 ; ++i){
   list.offer("Hello!This is Number "+ (i+1));
}
System.out.printf("第一个元素为：%s\n",list.peekFirst());
System.out.printf("最后一个元素为：%s",list.peekLast());

// 输出：
// 第一个元素为：Hello!This is Number 1
// 最后一个元素为：Hello!This is Number 100
```

##### 一些补充的话
由于`LinkedList`实现了Deque接口以及Queue接口这些ArrayList没有的接口，所以此处会补充这部分的内容

#### 补充用法
接下来将补充一些Queue和Deque接口有的方法：

一些基本的（如getFirst()，getLast()）就不再说明

**push()**
`push()`方法来源于Deque接口

这个方法等价于`addFirst()`

``` Java
LinkedList<String> list = new LinkedList<>();
list.push("使用push方法添加元素\n");
list.addFirst("使用addFirst方法添加元素\n");
System.out.printf(list.getFirst());
System.out.printf(list.getLast());

// 输出：
// 使用addFirst方法添加元素
// 使用push方法添加元素
```
从输出结果来看，这两个方法的结果是完全一致的，那么，这两个方法有没有什么不同呢？

其实是几乎没有的，我们不妨看看这两个方法的源代码：

``` Java
public void addFirst(E e) {
   linkFirst(e);
}

public void push(E e) {
   addFirst(e);
}
```
可以看到，push方法的实现其实也就是调用了addFirst方法

但一般而言，如果将LinkedList当做栈使用，则会使用push（代表压入栈顶）

这样可以使得代码更加明确

**removeFirstOccurrence**
这个方法有另外一个版本：`removeLastOccurrence`

不过核心功能大同小异，主要是索引方向不同

这个方法的作用为从首项开始搜寻是否有存在目标项，如果存在，则移除并返回`true`

接下来是具体的例子

``` Java
LinkedList<String> list = new LinkedList<>();
for (int i = 0 ;i <100 ; ++ i){
   list.offer("Hello" + i);
}
System.out.printf(String.valueOf(list.removeFirstOccurrence("Hello2")));

// 输出：
// true
```
我们不妨看看他的源代码是如何实现的：
``` Java
public boolean removeFirstOccurrence(Object o) {
   return remove(o);
}

public boolean remove(Object o) {
if (o == null) {
   for (Node<E> x = first; x != null; x = x.next) {
         if (x.item == null) {
            unlink(x);
            return true;
         }
   }
} else {
   for (Node<E> x = first; x != null; x = x.next) {
         if (o.equals(x.item)) {
            unlink(x);
            return true;
         }
   }
}
return false;
}
```
可以看到，这里`removeFirstOccurrence()`其实也就是调用了`remove()`这个方法

**descendingIterator**
接下来将说明一下这个方法

这个方法的作用是将当前数组反向

在反向的时候需要新创建一个迭代器对象才可以起到效果：

``` Java
LinkedList<String> list = new LinkedList<>();
for (int i = 0 ;i <100 ; ++ i){
   list.offer("Hello" + i);
}
System.out.printf("未使用降序迭代器的首项：%s\n",list.peek());
Iterator<String>lst =  list.descendingIterator();
System.out.printf("使用降序迭代器后的首项：%s\n",lst.next());

// 输出：
// 未使用降序迭代器的首项：Hello0
// 使用降序迭代器后的首项：Hello99
```

## Set接口
Set接口是另一个常见的接口，主要分为以下几个实现类：
``` Java
HashSet：基于哈希表的实现类，可以存储不重复元素，查询效率高（时间复杂度O(1)）
TreeSet：基于红黑树的实现类，可以存储不重复元素，可以用于排序
LinkedHashSet：基于哈希表和链表的实现类，存储不重复元素并且保持插入顺序（链表特性）
ConcurrentSkipListSet：基于跳表，支持并发操作（线程安全），同时可以保持元素排序
CopyOnWriteArraySet：基于CopyOnWriteArrayList，由于边写边复制所以线程安全，可以存储不重复元素
```
那么接下来将依次介绍这些实现类

### HashSet
首先第一个是HashSet

HashSet是一个经典的实现类，其底层为HashMap，这个实现类支持哈希表，由于这个原因，HashSet查找元素时平均时间复杂度为`O(1)`

#### 特性
接下来讲讲HashSet的一些特性：

首先第一个便是Set接口的通性：**不允许存放相同元素**

第二个特性是无序性，简单来说就是传入的顺序与输出的顺序是不同的

举个简单例子：
``` Java
HashSet<String> list = new HashSet<>();
for(int i = 0; i < 5; ++i){
   list.add("Hello" + i);
}
for(String num : list){
   System.out.println(num);
}

// 输出：
// Hello0
// Hello1
// Hello4
// Hello2
// Hello3
```
通过这个例子可以充分体现出其无序性，这一点与链表相分开

此外，HashSet是允许`null`元素的

``` Java
HashSet<String> list = new HashSet<>();
list.add(null);
for(String num : list){
   System.out.println(num);
}

// 输出：
// null
```
一个需要注意的点是，HashSet并不是一个线程安全的实现类，如果在多线程的情况下，必须要做到外部同步

#### 具体用法
在介绍完这些特性之后，便要来介绍HashSet的具体用法了，与前文的List接口一致，此处介绍的方法如果在下面的实现类中再次出现将不会再次介绍

但由于HashSet的接口Set接口完全继承与Collection接口，而Collection接口的方法我们在前文ArrayList的部分已经讲过了，所以这里便不再复述

也就是说，HashSet并没有**任何独立**的公共方法

#### HashSet存在的意义
既然没有独立的方法，那么HashSet存在的意义是什么呢？

在之前我们也提到过了，HashSet存储不重复的元素，这也就导致了如果有相同的元素被相继加入到数组中，那么HashSet只会存储前一个，而后一个并不会存储

``` Java
HashSet<String> list = new HashSet<>();
list.add("aaa");
list.add("bbb");
list.add("aaa");
for(String num : list){
   System.out.println(num);
}
// 输出：
// aaa
// bbb
```
> 事实上是，如果你在IntelliJ IDEA里面add()两个相同的元素，那么会抛出一个警告：重复的 Set 元素

接下来是其独特的特性：**极快的查询速度**

``` Java
ArrayList<String> arrayList = new ArrayList<>();
for(int i = 0;i < 99999999; ++i){
   arrayList.add("Hello" + i);
}
Instant arrayStartTime = Instant.now();
System.out.println(arrayList.contains("Hello"+9999999));
Instant arrayEndTime = Instant.now();
System.out.printf("ArrayList查询指定元素时间为：%s\n", Duration.between(arrayStartTime,arrayEndTime).toNanos());

// 输出：
// true
// ArrayList查询指定元素时间为：65384600
```

那么让我们看看HashSet咋以相同代码下的查询速度：
``` Java
for (int i = 0; i < 99999999; i++) {
   hashList.add("hello"+ i);
}
Instant hashStartTime = Instant.now();
System.out.println(hashList.contains("hello"+9999999));
Instant hashEndTime = Instant.now();
System.out.printf("HashSet查询指定元素的时间为：%s\n",Duration.between(hashStartTime,hashEndTime).toNanos());

// 输出：
// true
// HashSet查询指定元素的时间为：0
```

可以看到，这里HashSet查找的速度远远大于ArrayList，这也可以突出其特点

#### 补充点：快速失败（fail-fast）
快速失败是一个很有意思的机制，部分实现类拥有这个特性

会出现这个特性的原因是因为迭代器的问题

如果你在使用迭代器的时候同时用非迭代器方法修改这个集合（比如说add()），那么此时迭代器会瞬间检测到这一修改并且抛出错误：

``` Java
HashSet<String> hashList = new HashSet<>();
hashList.add("hello！");
Iterator<String> iterator = hashList.iterator();
for (; iterator.hasNext(); iterator.next() ) {
   hashList.add("hello");
}

// 输出：
// Exception in thread "main" java.util.ConcurrentModificationException
```

可以看到，这里抛出了报错`ConcurrentModificationException`

那么为什么会这样呢？

首先我们需要知道一个有意思的点：`modCount`

这个是什么呢？简单来说就是记录你对这个集合操作的次数

我们直接看源码可以发现：
``` Java
// HashMap.java
// putVal()方法
...//省略
++modCount;
if (++size > threshold)
   resize();
afterNodeInsertion(evict);
return null;
```

也就是说，如果你对这个集合进行了一些操作，那么这个计数器都会记录操作的次数

那这跟快速失败有什么关联呢

在生成一个迭代器的时候，迭代器会讲modCount的值复制一遍，存储到：`expectedModCount`中

使用迭代器的方法`next()`或者`remove()`的时候，便会将这个值与`modCount`进行对比，如果两者相等则说明没有进行任何修改操作

则正常进行

但如果修改（例如上面提到的例子一样），则会直接抛出报错：ConcurrentModificationException

特别补充的一点是，modCount这个属性是`private`的，所以不用担心会被修改

另外，如果需要删除元素可以选择迭代器自带的删除方法：`remove()`

---
#### 补充点：底层实现
接下来聊聊HashSet的底层实现

首先第一个点，我们可以思考一下HashSet是如何实现存储不重复元素的

> 由于源代码putVal巨抽象，这里就简单讲讲

首先从创建讲起，假设你现在创建了一个HashSet集合

那么在底层，会顺带创建一个HashMap数组用于存储，一般而言，这个数组桶个数为16个（这个值是默认值，可以修改的）

假设你往这个HashSet里面添加一个值，那么这个值会先使用`hashcode()`得到一个值，在经过一些系列处理后得到桶索引，这个索引将告诉我们添加的这个值应该被放到哪个桶里面

> 至于怎么计算出这个桶索引的，就太复杂了，涉及到一系列杂七杂八乱七八糟的操作，这里就不补充了

那么至此，这个值就得到了两个有意思的东西，分别是它的**哈希值**（通过hashcode()）获得，还有是它的**桶索引**（通过获取到哈希值后经过一系列操作得到）

假设我们需要往里面再添加一个新的值，则会继续这一步操作

此时如果我们试图添加一个与之前添加的值相同的值，那么会发生什么呢？

依旧进行之前的步骤，首先是计算其哈希值，以及其桶索引，在将要把这个值放进去桶的时候，会先将这个元素的哈希值进行比较，如果这个值与桶里面元素的哈希值都不相同，则添加进桶里面

那么如果相等就可以直接丢掉吗？

当然不是！有时候哈希值相同值却不同，所以这个时候还需要`equals()`方法来检测其是否相同

如果相同，则不添加；如果不相同，则添加进桶里面去

#### 补充点：哈希冲突后处理
接下来将讲一下哈希冲突

在上面的补充点中我们提到一个点：不同元素的哈希值经过计算转换成桶索引后会出现相同的情况

这就是**哈希冲突**，说白了就是：一个桶里面塞了不止一个东西

那么HashSet（根本上讲应该是HashMap）是怎么处理的呢？

首先，假设我们在一个桶里面塞了超过7个元素，那么此时HashSet会直接将桶的数量翻倍（假设为默认的16，那么就变成32个桶了）

由于桶索引的计算与桶的个数是相关的，所以这里会重新分配桶

诶，这里就有人要说了，假设又塞满了呢？

如果此处又出现了一个桶里面塞的元素超过7个，那么会继续翻倍桶的数量

那么是不是就这样一直翻倍下去呢？

肯定不是，如果桶的数量大于64个，仍然出现了一个桶装了超过7个，那么会把这个桶从链表转换为红黑树

利用这种方法来增加查找效率

那么是不是意味着只有一个桶里面塞了大于7个元素才会翻倍桶数量呢？

**当然不是**，HashMap里面有个东西叫做**负载因子**，这玩意的机制是，如果总元素的数量大于`总桶数 * 负载因子`，那么也会触发桶翻倍的机制

比如我在一个桶里面塞了4个，另一个桶塞了5个，另一个塞了6个，那么此时总元素个数为15个，大于`总桶数 * 负载因子`（16 * 0.75 = 12）

那么此时即使任何一个桶没有大于7个元素，也会触发桶数翻倍

而一般默认的负载因子为：**0.75**，多了少了都不行，少了触发太快，多了的话冲突又过多，查询的时间复杂度直接变为**O(n)**

所以，这里选择0.75是折中的选择

最后总结一下：

触发桶数翻倍需满足以下两点中的任意一点：
1. 总元素数大于 `总桶数 * 负载因子`（负载因子默认为0.75）
2. 单个桶的元素数量大于7，并且此时总桶数小于64

触发链表转红黑树（只有满足条件的桶才转换）
1. 单个桶的元素数量大于7，并且此时总桶数大于64

### TreeSet
接下来讲讲TreeSet

TreeSet是一个很有意思的实现类

这个实现类的特点就是会将这个类中的元素自动排序

``` Java
TreeSet<Integer> treeSet = new TreeSet<>();
for (int i = 0; i < 10; i++) {
   treeSet.add(random.nextInt(0,20));
}
System.out.println(treeSet);

// 输出：
// [2, 3, 6, 8, 9, 10, 11, 13]
```
可以看到，即使将生成的随机数字填入这个数组中，输出的时候依旧会按顺序输出

这也体现了这个类的特点：对输入的元素自动排序

#### 特有方法
接下来介绍一下TreeSet特有的方法，这些方法主要实现`SortedSet`接口和`NavigableSet`接口

首先讲讲`SortedSet`接口中实现的方法：

**first() & last()**
这个方法的作用为返回第一个元素（最低）和返回最后一个元素（最高）

``` Java
Random random = new Random();
TreeSet<Integer> treeSet = new TreeSet<>();
for (int i = 0; i < 10; i++) {
   treeSet.add(random.nextInt(0,20));
}
int lower = treeSet.first();
int higher = treeSet.last();
System.out.printf("该数组为：%s\n",treeSet);
System.out.printf("该数组最低元素为：%d，最高元素为：%d",lower,higher);

// 输出：
// 该数组为：[0, 2, 5, 8, 9, 11, 12, 18, 19]
// 该数组最低元素为：0，最高元素为：19
```
可以看到，在分别对该数组使用first()方法和last()方法后，相对应的值变成了其最低项和最高项

**headSet()**
接下来是headSet()方法

这个方法拥有1个可填参数：`headSet(E toElement)`

其中参数`toElement`代表规定的范围

这个方法的作用是限制只有小于括号内的参数（toElement）才可以输出

``` Java
Random random = new Random();
TreeSet<Integer> treeSet = new TreeSet<>();
for (int i = 0; i < 10; i++) {
   treeSet.add(random.nextInt(0,20));
}
SortedSet<Integer> headset = treeSet.headSet(10);
System.out.printf("该数组为：%s\n",treeSet);
System.out.printf("该数组中小于数的有：%s",headset);

// 输出：
// 该数组为：[2, 3, 5, 10, 17, 19]
// 该数组中小于数的有：[2, 3, 5]
```

**tailSet()**
既然有小于，那就一定有大于，`tailSet()`便是返回大于括号内参数的数的方法

这个方法的同样拥有一个参数：`tailSet(E fromElement)`

与上文的headSet()一致，这里也是用于限制范围

``` Java
Random random = new Random();
TreeSet<Integer> treeSet = new TreeSet<>();
for (int i = 0; i < 10; i++) {
   treeSet.add(random.nextInt(0,20));
}
SortedSet<Integer> headset = treeSet.tailSet(10);
System.out.printf("该数组为：%s\n",treeSet);
System.out.printf("该数组中大于数的有：%s",headset);

// 输出：
// 该数组为：[1, 3, 5, 6, 8, 9, 10, 12, 13, 17]
// 该数组中大于数的有：[10, 12, 13, 17]
```

**subSet()**
既然有查找小于的`headSet()`，也有查找大于的`tailSet()`

自然而然的便有可以返回指定数字范围的方法：`subSet()`

这个方法有两个参数：`subSet(E fromElement, E toElement)`

第一个`fromElement`，代表最低的元素大小，而第二个参数`toElement`，代表了最高的元素大小

需要注意的一点是，这个参数的范围为**左闭右开区间**

接下来给出实例：

``` Java
Random random = new Random();
TreeSet<Integer> treeSet = new TreeSet<>();
for (int i = 0; i < 10; i++) {
   treeSet.add(random.nextInt(0,20));
}
SortedSet<Integer> subSet = treeSet.subSet(10,15);
System.out.printf("该数组为：%s\n",treeSet);
System.out.printf("该数组中位于固定范围的数有：%s",subSet);

// 输出：
// 该数组为：[1, 2, 3, 4, 7, 12, 14, 15, 19]
// 该数组中位于固定范围的数有：[12, 14]
```

接下来是`NavigableSet`接口的内容

**lower() & higher()**
接下来是这两个方法

首先第一个方法`lower()`的作用是返回最大不小于该数的数，例如规定数字为10，则返回所有比10小的数中最大的那个数

第二个方法`higher()`的作用与`lower()`类似，返回最小不小于该数的数，例如规定数字为10，则返回所有比10大的数中最小的数

这两个方法都拥有一个可填的参数：`lower(E e)`、`higher(E e)`

其中`参数e`分别代表最大不能超过这个数字的数，以及最小不能小于这个数的数

接下来看看具体用法：

``` Java
Random random = new Random();
TreeSet<Integer> treeSet = new TreeSet<>();
for (int i = 0; i < 10; i++) {
   treeSet.add(random.nextInt(0,20));
}
int lower = treeSet.lower(10);
System.out.printf("该数组为：%s\n",treeSet);
System.out.printf("该数组小于规定数的数字中最大的是：%s",lower);

// 输出：
// 该数组为：[6, 8, 10, 11, 14, 18]
// 该数组小于规定数的数字中最大的是：8
```
`higher()`的用法与之类似，这里不再演示

需要注意的一点是，这里的数字只能小于或大于规定的数，**不可以等于**，相当于开区间

---
**floor() & ceiling()**
接下来是这个方法

这两个方法的参数都只有一个：`floor(E e)`和`ceiling(E e)`

其中`参数e`代表最大或最小可以选取到的数字

`floot()`和`ceiling()`方法与上文的`lower()`和`higher()`方法类似，不过区别是`floot()`方法和`ceiling()`方法是闭区间而`lower()`方法和`higher()`方法都是开区间

``` Java
Random random = new Random();
TreeSet<Integer> treeSet = new TreeSet<>();
for (int i = 0; i < 10; i++) {
   treeSet.add(random.nextInt(0,20));
}
int floor = treeSet.floor(10);
System.out.printf("该数组为：%s\n",treeSet);
System.out.printf("该数组中大于等于规定数的有：%s",floor);

// 输出：
// 该数组为：[5, 6, 7, 8, 10, 11, 12, 13]
// 该数组中大于等于规定数的有：10
```
可以看到，在该程序中，`floor()`选取的标准是大于等于括号内最小（最接近）的数

而`ceiling()`也是相同的道理

**headSet() & tailSet & subSet()**
由于`NavigableSet接口`继承与`SortedSet接口`，所以这个接口也有`SortedSet接口`的一些方法

那么重复定义是不是过于冗余呢？其实不然，在`NavigableSet接口`中，这三个方法要比父接口要更加灵活

接下来介绍`NavigableSet接口`中的`headSet()`、`tailSet()`、`subSet()`方法

首先这三个方法的具体功能与`SortedSet接口`是一致的，所以此处不再次介绍

不一样的是，这三个方法都多了一到两个可选参数：

``` Java
headSet(E toElement, boolean inclusive)

tailSet(E fromElement, boolean inclusive)

subSet(E fromElement, boolean fromInclusive, E toElement, boolean toInclusive)
```

通过其类型为`boolean`便可以简单推断这个参数的作用

没错，便是使其可以**自由调整**为开闭区间

这一点便与其父接口不一致了

``` Java
Random random = new Random();
TreeSet<Integer> treeSet = new TreeSet<>();
for (int i = 0; i < 10; i++) {
   treeSet.add(random.nextInt(0,20));
}
NavigableSet<Integer> headset = treeSet.headSet(10,true);
System.out.printf("该数组为：%s\n",treeSet);
System.out.printf("该数组中小于等于数的有：%s",headset);

// 输出：
// 该数组为：[5, 6, 9, 10, 11, 13, 14, 18, 19]
// 该数组中小于等于数的有：[5, 6, 9, 10]
```

可以看到，这里设定为`true`，输出也包括了规定的数字

而`subSet()`的参数有两个是决定范围的，分别决定前后数字为开闭区间

##### 补充点：源码中有趣的事情
如果你曾阅读过`TreeSet.java`中有关这部分的内容

那么你会发现一件事情：
``` Java
public SortedSet<E> headSet(E toElement) {
   return headSet(toElement, false);
}

public NavigableSet<E> headSet(E toElement, boolean inclusive) {
   return new TreeSet<>(m.headMap(toElement, inclusive));
}
```
可以看到，这里`SortedSet<E> headSet(E toElement)`返回的结果刚好是下面的`NavigableSet<E> headSet(E toElement, boolean inclusive)`，只不过将第二个决定开闭区间的参数固定为`false`

而`subSet()`也有类似的内容：

``` Java
public SortedSet<E> subSet(E fromElement, E toElement) {
   return subSet(fromElement, true, toElement, false);
}
```
可以看到，这里默认便为左闭右开区间

##### 补充点：关于多态
在上文提及到：`NavigableSet接口`继承与`SortedSet接口`，也就是说，下面这种语法也是正确的：

``` Java
SortedSet<Integer> headset = treeSet.headSet(10,true);
```

这里使用到了面向对象中的多态：**父类/接口引用指向子类/实现类对象**

---
**pollFirst() & pollLast()**
`pollFirst()`和`pollLast()`是两个相对应的方法，作用为**移除并返回首项 / 末项**

这两个方法均没有可填的参数

接下来看看具体例子

``` Java
Random random = new Random();
TreeSet<Integer> treeSet = new TreeSet<>();
for (int i = 0; i < 10; i++) {
   treeSet.add(random.nextInt(0,20));
}
System.out.printf("该数组为：%s\n",treeSet);
Integer pollFirst = treeSet.pollFirst();
System.out.printf("使用pollFirst()方法移除了首项：%s\n",pollFirst);
System.out.printf("移除后数组为：%s\n",treeSet);

// 输出：
// 该数组为：[3, 4, 6, 10, 11, 13, 15, 18]
// 使用pollFirst()方法移除了首项：3
// 移除后数组为：[4, 6, 10, 11, 13, 15, 18]
```
另一个方法`pollLast()`则为移除并返回末项


**descendingSet()**
接下来是这个方法

这个方法依旧没有参数可以选择

这个方法的作用是反转数组：

``` Java
Random random = new Random();
TreeSet<Integer> treeSet = new TreeSet<>();
for (int i = 0; i < 10; i++) {
   treeSet.add(random.nextInt(0,20));
}
System.out.printf("原数组为：%s\n", treeSet);
NavigableSet<Integer> reverseTreeSet = treeSet.descendingSet();
System.out.printf("反转后数组为：%s\n", reverseTreeSet);

// 输出：
// 原数组为：[8, 9, 10, 12, 14, 16, 17]
// 反转后数组为：[17, 16, 14, 12, 10, 9, 8]
```

##### 补充点：与reverse()方法的区别
看到这个方法可能会有人想到另一个方法：`reverse()`

这两个方法都可以做到反转数组的功能，那么有什么差别呢？

一个最简单的差别就是加入时间

`descendingSet()`在Java 6便加入了，而`reverse()`直到Java 21才加入

不过有意思的一点在源代码上：

``` Java
default NavigableSet<E> reversed() {
   return this.descendingSet();
}
```
可以看到，这里的reversed()方法其实就是复用descendingSet()方法

诶，这是为什么呢？其实在Java 21中新增了一个接口`SequencedCollection`，这个接口又被`NavigableSet接口`继承，这个接口有个可以返回反转数列的方法（也就是`reversed()`），但是原本就有一个方法——`descendingSet()`，再次实现多少有点不太方便，所以便复用了这个方法

#### 补充点：定义排序规则

> 注意！！！！！
> 由于自定义排序规则的方法太多了！！！此处仅演示Lambda表达式的方法

接下来是自定义排序规则

诶，那么要怎么自定义排序规则呢

其实很简单，只需要在创建的时候在`TreeSet<>()`后面的圆括号上加上对应的规则即可：

``` Java
Random random = new Random();
TreeSet<Integer> sequentialTreeSet = new TreeSet<>((a,b) -> a - b);
TreeSet<Integer> reverseTreeSet = new TreeSet<>((a,b) -> b - a);
for (int i = 0; i < 10; i++) {
   sequentialTreeSet.add(random.nextInt(0,20));
   reverseTreeSet.add(random.nextInt(0,20));
}
System.out.printf("使用正序规则：%s\n",sequentialTreeSet);
System.out.printf("使用倒序规则：%s\n",reverseTreeSet);

// 输出：
// 使用正序规则：[5, 7, 11, 13, 14, 15, 17, 19]
// 使用倒序规则：[19, 17, 14, 13, 11, 8, 6, 4, 3, 1]
```

##### 安全的排序规则
在圆括号内部的是**lambda表达式**，这样存在一个十分严重的问题，如果两者的差过大(一个整数a减一个负数b)，可能会导致溢出

``` Java
TreeSet<Integer> sequentialTreeSet = new TreeSet<>((a,b) -> a - b);
for (int i = 0; i < 10; i++) {
   sequentialTreeSet.add(2147483647);
   sequentialTreeSet.add(-2147483648);
}
System.out.printf("使用正序规则：%s\n",sequentialTreeSet);

// 输出：
// 使用正序规则：[2147483647, -2147483648]
```
由于比较规则为前后相减，原本应为`4294967295`，但这个值溢出了，变成了-1

如果为负数，那么就意味着前面的数比后面的数小，但我们这个情况，正常应该是正数在前

那要怎么解决这个问题呢？其实很简单，我们可以使用到**静态工厂方法**：

``` Java
TreeSet<Integer> sequentialTreeSet = new TreeSet<>(Comparator.comparingInt(a -> a));
for (int i = 0; i < 10; i++) {
   sequentialTreeSet.add(2147483647);
   sequentialTreeSet.add(-2147483648);
}
System.out.printf("使用正序规则：%s\n",sequentialTreeSet);

// 输出：
// 使用正序规则：[-2147483648, 2147483647]
```
这种写法还有一些类似的写法：

``` Java
// 使用对应包的compare
new TreeSet<>(Integer::compare)

// 使用Comparator.naturalOrder()
new TreeSet<>(Comparator.naturalOrder())

// 直接不填！因为不填算是自然排序，等价于上文的naturalOrder()
new TreeSet<>()
```

---
我们还可以给出一些更加自定义的规则：

``` Java
var comparatorRule =
         Comparator.comparing(String::length).thenComparing(Comparator.naturalOrder());
var comparatorRuleReversed =
         (Comparator.comparing(String::length).thenComparing(Comparator.naturalOrder())).reversed();

TreeSet<String> sequentialTreeSet = new TreeSet<>(comparatorRule);
TreeSet<String> reverseTreeSet = new TreeSet<>(comparatorRuleReversed);

for (int i = 0; i < 5; i++) {
   String randomInt = String.valueOf(random.nextInt(0, 999999));
   sequentialTreeSet.add(randomInt);
   reverseTreeSet.add(randomInt);
}
System.out.println("排序规则为字符长度：\n");
System.out.printf("使用正序规则：%s\n", sequentialTreeSet);
System.out.printf("使用倒序规则：%s\n", reverseTreeSet);

// 输出：
// 使用正序规则：[82100, 213078, 484793, 858731, 965938]
// 使用倒序规则：[965938, 858731, 484793, 213078, 82100]
```
可以看到，这里的比较规则是先比较字符串长度，再用自然规则（naturalOrder）进行排序

##### 自定义类排序
除此之外，还可以使用自定义类来排序
``` Java
class Product{
    private final String productName;
    private final int productPrice;

    public Product(String productName, int productPrice){
        this.productName = productName;
        this.productPrice = productPrice;
    }

    public int getProductPrice() {
        return productPrice;
    }

    public String getProductName() {
        return productName;
    }
}

public class TreeSetLearning {
    public static void main(String[] args) {
        Random random = new Random();
        TreeSet<Product> products = new TreeSet<>(Comparator.comparingInt(Product::getProductPrice));
        for (int i = 0; i < 5; i++) {
            int randomPrice = random.nextInt(100,3000);
            products.add(new Product("货物" + (i+1), randomPrice));
        }
        System.out.println("排序后商品价格为：");
        for (Product lst : products){
            System.out.printf("商品：%s， 价格：%s\n",lst.getProductName(),lst.getProductPrice());
        }
    }
}

// 输出：
// 商品：货物3， 价格：1079
// 商品：货物1， 价格：1659
// 商品：货物4， 价格：2003
// 商品：货物2， 价格：2027
// 商品：货物5， 价格：2938
```
接下来开始解析这段代码：

首先第一个部分，这里新建了一个类：`Product`

这个类里面定义了两个属性：`productName`和`productPrice`

这两个属性分别记录商品的名字和商品的价格

接下来看到声明`TreeSet`中的自定义排序规则部分：

``` Java
Comparator.comparingInt(Product::getProductPrice)
```

此处使用了这个规则，括号内部是一个匿名函数，意思是使用`Product`的`getProductPrice`的返回值进行比较

而前面的`Comparator.comparingInt`意思是比较的内容为数字

又因为`getProductPrice`的返回值为数字（productPrice），所以是合法的

当然这里有个小问题，如果价格相等是不会加入的

所以需要在这个规则后面加上一句，如果相等则比较其他的内容：

``` Java
TreeSet<Product> products = new TreeSet<>(Comparator.comparingInt(Product::getProductPrice)
      .thenComparing(Product::getProductName));
```
此处由于类中只有名字还可以用，所以就使用名字作为第二个比较的标准

> 实际上还可以再继续比较下去：
> Comparator.comparingInt(...).thenComparing(...).thenComparing(...)
> 不过没有什么意义就对了

这种格式的写法为**静态工厂**写法，更加安全


##### 处理null值
如果数组存在null值，不加处理会导致报错：

``` Java
TreeSet<Integer> treeSet = new TreeSet<>();
for (int i = 0; i < 10; i++) {
   treeSet.add(123);
   treeSet.add(null);
}
System.out.printf("数组排序后：%s\n",treeSet);

// 输出：
// Exception in thread "main" java.lang.NullPointerException
```
可以看到这里的报错为`NullPointerException`

那要怎么办呢？其实很简单，只需要在排序规则那里加入如何处理`null`值即可

``` Java
TreeSet<Integer> treeSet = new TreeSet<>(Comparator.nullsFirst(Integer::compare));
for (int i = 0; i < 10; i++) {
   treeSet.add(123);
   treeSet.add(null);
}
System.out.printf("数组排序后：%s\n",treeSet);

// 输出：
// 数组排序后：[null, 123]
```
> 此处使用Integer::compareTo也可以，本质上compareTo就是调用compare
可以看到，这里使用了`Comparator.nullsFirst(Integer::compare)`，用于将null值放到最前面

除此以外还有`nullsLast`，用于将null值放到最后面