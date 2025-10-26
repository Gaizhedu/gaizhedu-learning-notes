
[TODO]
1. List接口
   - [x] ArrayList
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

---
### LinkedList
接下来讲讲LinkedList

LinkedList是一个双向链表，那么什么是双向链表呢

**双向列表**
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
