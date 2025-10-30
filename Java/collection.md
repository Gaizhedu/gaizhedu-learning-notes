
[TODO]
1. List接口
   - [x] ArrayList
     - [ ] TODO clear()方法
     - [ ] TODO isEmply()方法
     - [ ] TODO contains()方法
     - [ ] TODO retainAll()方法
     - [ ] TODO toArray()方法
     - [ ] TODO spliterator()方法
     - [ ] TODO forEach()方法
     - [ ] TODO removeIf()方法
     - [ ] TODO stream()方法
     - [ ] TODO parallelStream()方法
     - [ ] TODO equals()方法
     - [ ] TODO hashCode()方法
     - [ ] TODO clone()方法
     - [ ] TODO toString()方法
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

[TODO]

**floor() & ceiling()**


**headSet()**
接下来是headSet()方法

这个方法的作用是限制只有小于括号内的元素才可以输出

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

需要注意的一点是，这个参数的范围为左闭右开区间

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

[TODO]

接下来是`NavigableSet`接口的内容

#### 补充点：定义排序规则