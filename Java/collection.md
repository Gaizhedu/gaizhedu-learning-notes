
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

#### 特点
那么有什么特点呢？首先第一个就是