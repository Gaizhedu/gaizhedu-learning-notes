
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