# Lambda
这篇笔记将介绍有关Lambda表达式的相关内容

## 基础语法
Lambda可以看做是一种匿名函数，可以理解为这是个没有函数名称的函数

其基本的语法如下：

``` Java
(a) -> b;
(a) -> {b;}
```

这意味着Lambda可以选择单一一个参数或者是一个代码块

在上面中，圆括号内的`a`代表了参数列表

后面的`b`代表了一段表达式或是一个代码块

举个例子：

假设我们现在需要使用`.sort()`来定义一个自定义排序规则，那么我们可以这么写

``` Java
List<Integer> list = new ArrayList<>(Arrays.asList(3,2,5,1,4,6,7,9,8));
list.sort((a,b) -> b - a);
System.out.println(list);

// 输出：
// [9, 8, 7, 6, 5, 4, 3, 2, 1]
```

可以看到，此处定义了一个排序的规则，此处结果>0，说明b应该在a的前面，如果<0，说明a应该在b的前面

假设没有使用Lambda表达式，那么要怎么去写相同的逻辑呢？

如果我们使用传统的方法，那么就需要使用到匿名类，写法如下：

``` Java
List<Integer> list = new ArrayList<>(Arrays.asList(3,2,5,1,4,6,7,9,8));
list.sort(new Comparator<Integer>() {
    @Override
    public int compare(Integer o1, Integer o2) {
        return o2 - o1;
    }
});
System.out.println(list);

// 输出：
// [9, 8, 7, 6, 5, 4, 3, 2, 1]
```
传统写法相对于Lambda写法，不仅写法更加复杂，而且可读性也比Lambda要低

Lambda表达式诞生的一个目的就是简化这些复杂的表达

## 函数式接口
在介绍为Lambda表达式的基础语法后，接下来讲一下有关函数式接口的相关内容

为什么要介绍这个内容呢？一个很重要的原因就是Java是一种**强类型**的语言

而Lambda本质是匿名函数，所以必须知道这个函数的签名

那么Java中有那些函数式接口呢？主要有这四个

``` Java
Function<T, R>
Predicate<T>
Consumer<T>
Supplier<T>
```

哪里可以看到这些函数式接口呢？一般来讲，如果一个方法的签名里面带有这些函数式接口，便意味着可以使用Lambda表达式

我们举个例子，在上文排序的例子中，`.sort()`的签名如下

``` Java
default void sort(Comparator<? super E> c)
```

此处的`Comparator<? super E> c`便是一个函数式接口

再例如一些`Stream API`中的方法：

``` Java
map(Function<? super T, ? extends R> mapper);

forEach(Consumer<? super T> action);
```
从签名中不难看出，这些都是函数式接口，这也就是为什么这些方法可以使用Lambda表达式的原因

但是这些函数式接口有什么作用呢？


### Function
首先是第一个`Function<T, R>`

这个接口的作用是，输入类型为T，通过**一些转换**后输出一个类型为R的值

举个例子，`stream.map()`

``` Java
List<Integer> list = new ArrayList<>(Arrays.asList(3,2,5,1,4,6,7,9,8));
List<String> newString = list.stream()
        .map(a -> a.toString())
        .toList();
System.out.println(newString);

// 输出：
// [3, 2, 5, 1, 4, 6, 7, 9, 8]
```
在上面这个例子中，Function的T和R分别为`Integer`和`String`

也就是`Function<Integer, String>`

### Predicate
接下来是`Predicate<T>`

这个接口的作用是**判断**，

一个比较经典的例子为`stream.filter()`

具体签名如下：`filter(Predicate<? super T> predicate)`

``` Java
List<Integer> newString = list.stream()
        .filter(a -> a > 5)
        .toList();
System.out.println(newString);

// 输出：
// [6, 7, 9, 8]
```
在上面的例子中，如果输入的参数a>5，则返回true，也就是只有大于5的数字才能被过滤

### Consumer
接下来介绍一下`Consumer<T>`

这个函数式接口的作用是接受一个输入，而后输出一个操作，不返回任何结果

举个例子，`stream.forEach()`

方法签名如下
``` Java
forEach(Consumer<? super T> action)
```

``` Java
List<Integer> list = new ArrayList<>(Arrays.asList(3, 2, 5, 1, 4, 6, 7, 9, 8));
list.stream().forEach(System.out::println);

// 输出：
// 3
// 2
// 5
// 1
// 4
// 6
// 7
// 9
// 8
```
可以看到，此处对list中的元素挨个执行了`System.out::println`

满足了输入内容为值，输出为一个操作，并且没有返回任何值

### Supplier
接下来介绍一下Supplier<T>

这个接口的作用是**不接受任何元素，生成并输出一个新的值**

举个例子，`Stream.generate()`

``` Java
Stream<Integer> stream = Stream.generate(() -> new Random().nextInt(100));
stream.limit(5).forEach(System.out::println);

// 输出：
// 25
// 38
// 3
// 91
// 43
```

这个方法的签名为：
``` Java
generate(Supplier<? extends T> s)
```

## 方法引用
接下来要介绍的内容为方法引用，这一部分可以理解为Lambda的一个**语法糖**

简单举个例子，以往我们想要将List中的元素通过流打印出来，可以这么写：

``` Java
List<Integer> list = new ArrayList<>(Arrays.asList(1,2,3,4,5));
list.stream().forEach(s -> System.out.println(s));
```

可以看到，这里使用了一个Lambda表达式

虽然这样是可以运行的，但为了打印创建一个临时变量`s`感觉有点多余

所以我们可以使用到方法引用：

``` Java
List<Integer> list = new ArrayList<>(Arrays.asList(1,2,3,4,5));
list.stream().forEach(System.out::println);
```

具体使用方法如下：

``` Java
类名::实例方法名
```

假设我们需要将所有的字符串全部大写，我们可以这样操作：

``` Java
List<String> list = new ArrayList<>(Arrays.asList("hello","world"));
list.stream().map(String::toUpperCase).forEach(System.out::println);

// 输出：
// HELLO
// WORLD
```
可以看到，相较于传统的写法，使用方法引用会让整体的代码变得更加紧凑

## Lambda捕获
在介绍这一部分的内容之前，我们需要介绍一下`Effective final`的内容

### Effective final
我们知道，如果想要将一个变量设置为不可修改，可以在声明的时候在前面加上`final`

例如：

``` Java
final int a = 1;
```

此处整数a是没办法被修改的

什么是`Effective final（有效final）`呢？简单来说就是没有通过final修饰，但是后续也没有被修改的变量

例如说
``` Java
public static void main(String[] args) {
    int a = 1;
    System.out.println(a);
}
```
可以看到，在上面的例子中，变量a始终都没有被修改过，可以视为`final`，我们称这种变量为`Effective final`（也就是有效final）

---
接下来正式讲一下Lambda捕获

什么叫做Lambda捕获呢？简单来讲就是在Lambda表达式中，语句使用到了外部作用域的变量

例如：
``` Java
int num = 2;
Function<Integer, Integer> function = (s -> s * num);
List<Integer> list = new ArrayList<>(Arrays.asList(1,2,3,4,5));
list.stream().map(function).forEach(System.out::println);

// 输出：
// 2
// 4
// 6
// 8
// 10
```
可以看到，在上面的例子中，我们在Lambda语句中使用到了外部变量`num`

这个变量在声明后便没有再次被修改，所以可以看作是`Effective final`的

如果试图修改会发生什么？
``` Java
int num = 2;
num = 3;
Function<Integer, Integer> function = (s -> s * num);
List<Integer> list = new ArrayList<>(Arrays.asList(1,2,3,4,5));
list.stream().map(function).forEach(System.out::println);
```
事实上，如果你试图运行上面的代码，会发现是没办法编译的

在IntelliJ IDEA中，Lambda表达式中的num会被标记为错误：`lambda 表达式中使用的变量应为 final 或有效 final`

### 为什么要求为final或有效final
首先我们需要明确一个点，局部变量的位置是在栈上，这意味着局部变量是会在方法结束后被销毁的

而Lambda对象存活的时间可能很久，如果试图引用可变局部变量，那么当方法结束后，局部变量被销毁，此时便会出现数据不一致，或者是悬空引用的情况

所以，Lambda捕获的变量必须为final或者有效final