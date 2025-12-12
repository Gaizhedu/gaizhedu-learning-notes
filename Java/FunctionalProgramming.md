# 函数式编程
这份笔记将介绍函数式编程的相关内容

基础部分的函数式编程主要分为这两大块

- Lambda
- Stream

有关Lambda的内容可以参照这里->[Lambda](.\lambda.md)

这份笔记主要结合集合的内容来介绍Stream的用法

由于在集合中stream相关的方法过多，此处只保留最基础，最常用的几个方法来作为函数式编程的开头

但在介绍之前，不妨先简单说明一下这个到底是干什么用的

正如这个的名字一样，stream意为流，即流式处理

意思是将东西像流水线一样处理

首先先介绍一些基本的概念，中间操作和终端操作

中间操作的意思是这个操作可以连接前后的方法，构建一条完整流，而终端操作意味着这个方法作为结尾的方法，只能在结尾使用（因为这种方法无法继续连接其他方法）

那么有什么方法可以判断是哪一种操作呢？其实很简单，只需要看这个操作的返回值即可

一般而言，如果返回值为`stream`的话，这个方法便为中间操作（例如`filter()`，`distinct()`等）

如果返回值不为`stream`，而是为其他的话，那么这个方法便为终端操作

## filter()
此方法返回类型为`stream`，为中间操作

签名如下
``` Java
Stream<T> filter(Predicate<? super T> predicate);
```

filter这个方法的作用是作为一个筛子筛选出对应的元素

比如说我想要筛选出所有第一个字母为`a`的元素，那么可以这么操作：
``` Java
String[] itemList = {"banana", "apple", "cherry", "blueberry", "avocado"};
ArrayList<String> arrayList = new ArrayList<>(Arrays.asList(itemList));
List<String> stringList = arrayList.stream()
        .filter(firstLetter -> firstLetter.startsWith("a"))
        .toList();
System.out.println(stringList);

// 输出：
// [apple, avocado]
```
可以看到，在上面这个例子中我们通过`filter`方法成功筛选出所有以字母a开头的元素

上面这个例子是什么意思呢？

`firstLetter`意为每个需要处理的元素，在这里便是`itemList`中的每个元素

而`startsWith()`是一个方法，签名如下
``` Java
boolean startsWith(String prefix)
```
这个方法的作用是判断传入的字符串是否以参数`prefix`对应的值开头

例如，上面的例子中，`prefix`为`a`，这意味着如果传入的字符串以`a`开头，则返回`true`，反之返回`false`

## sorter()
此方法返回类型为`stream`，故为中间操作

签名如下

``` Java
Stream<T> sorted();

Stream<T> sorted(Comparator<? super T> comparator);
```

这个方法的作用是对当前流进行排序

有点类似TreeMap或者TreeSet

``` Java
List<Integer> arrayList = new ArrayList<>(Arrays.asList(3, 5, 4, 2, 1));
List<Integer> integerList = arrayList.stream()
        .sorted()
        .toList();
System.out.println(integerList);


// 输出：
// [1, 2, 3, 4, 5]
```
可以看到，输出的集合从一个乱序的集合转变为一个正序的集合

如果你想指定排序顺序，可以使用第二个重载的方法

``` Java
List<Integer> arrayList = new ArrayList<>(Arrays.asList(3, 5, 4, 2, 1));
List<Integer> integerList = arrayList.stream()
        .sorted((a, b) -> b - a)
        .toList();
System.out.println(integerList);

// 输出：
// [5, 4, 3, 2, 1]
```
此处指定的顺序为倒序，输出的集合也以倒序的顺序排序

## limit()
该方法返回类型为`stream`，故为中间操作

签名如下

``` Java
Stream<T> limit(long maxSize);
```

接下来介绍一下这个方法

这个方法的作用是截取原流中的前n个元素并返回作为新的流

举个例子：
``` Java
String[] numbersList = {"apple", "apricot", "banana", "cherry"};
List<String> arrayList = new ArrayList<>(Arrays.asList(numbersList));
List<String> stringList = arrayList.stream()
        .distinct()
        .limit(2)
        .toList();
System.out.println(stringList);


// 输出：
// [apple, apricot]
```
可以看到，这里的输出中只剩下了两个元素

那么这也引出了一个问题，如果大于小于等于原流长度会怎么样呢？

简单概括一下：

如果原流小于截取长度，那么返回原流

如果原流等于截取长度，那么返回原流

如果原流大于截取长度，那么返回截取的长度

## skip()
该方法返回类型为`stream`，故为中间操作

签名如下：
``` Java
Stream<T> skip(long n);
```

这个方法的具体的功能为跳过指定的n个元素（或者说从第n + 1个元素开始）

``` Java
String[] itemList = {"apple", "apricot", "banana", "cherry"};
List<String> arrayList = new ArrayList<>(Arrays.asList(itemList));
List<String> stringList = arrayList.stream()
        .skip(2)
        .toList();
System.out.println(stringList);

// 输出：
// [banana, cherry]
```
可以看到，这里输出的内容是从第三项（banana）开始的，也就是跳过了两项（`.skip(2)`）

不过需要提醒的一点是，如果这个是有序流（例如这里的ArrayList），那么则会正常的跳过前n项

但如果是无序流（例如Set接口里面的集合），由于不知道顺序是什么，所以跳过的元素是随机的

这里同样引出一个问题：如果数组长度大于等于小于原流会怎么样

简单概括如下

如果大于原流，那么什么都不返回

如果等于原流，也是什么都不返回

如果小于原流，那么按正常结果返回

除此之外，如果n小于等于0，那么会抛出这个报错：

``` Java
String[] itemList = {"apple", "apricot", "banana", "cherry"};
List<String> arrayList = new ArrayList<>(Arrays.asList(itemList));
List<String> stringList = arrayList.stream()
        .skip(-1)
        .toList();
System.out.println(stringList);

// 输出：
// IllegalArgumentException
```

## peek()
此方法返回值为`stream`，故为中间操作

签名如下：
``` Java
peek(Consumer<? super T> action);
```

这个方法的作用为在流的指定的地方进行一次操作（这个操作不会对原流产生影响）

一般而言，这个东西会用于日志这一类操作里面

例子如下：

``` Java
String[] itemList = {"apple", "apricot", "banana", "cherry"};
List<String> arrayList = new ArrayList<>(Arrays.asList(itemList));
List<String> stringList = arrayList.stream()
        .peek(a -> System.out.printf("当前数组元素有：%s%n", a))
        .toList();
System.out.println(stringList);

// 输出：
// 当前数组元素有：apple
// 当前数组元素有：apricot
// 当前数组元素有：banana
// 当前数组元素有：cherry
// [apple, apricot, banana, cherry]
```
在上面的例子中，插入了一个打印的操作

## forEach()
该方法返回类型**不为**stream，故为终端操作

签名如下：
``` Java
void forEach(Consumer<? super T> action);
```
这个方法的作用是对流中的**每一个元素执行指定的操作**

``` Java
String[] itemList = {"apple","banner","bike","cafe","ankle"};
ArrayList<String> arrayList = new ArrayList<>(Arrays.asList(itemList));
arrayList.stream()
    .filter(firstLetter -> firstLetter.startsWith("a"))
    .forEach(System.out::println);

// 输出：
// apple
// ankle
```
可以看到，这里`forEach`语句对所有的元素都使用了`System.out::println`，也就是将流里面的每一个元素都打印出来

## toList()
这个方法为终端操作

签名如下：

``` Java
default List<T> toList()
```

接下来介绍这个方法，这个方法的作用很简单，将这个流打包为一个集合，之后返回给变量

``` Java
List<Integer> lst = Arrays.asList(15, 73, 128, 4, 196, 88, 51, 142);
List<Integer> num = lst.stream()
         .filter(s -> s % 3 == 0)
         .toList();
System.out.printf("集合中满足条件的元素有：%s%n", num);

// 输出：
// 集合中满足条件的元素有：[15, 51]
```
可以看到，这里输出的结果是一个集合，这个集合打包了满足条件的元素

此处返回的集合是**不可变对象**，所以**不可以使用任何修改集合的方法尝试修改这个集合**，比如说add()，remove()

如果试图修改，则会抛出报错`UnsupportedOperationException`
``` Java
List<Integer> lst = Arrays.asList(15, 73, 128, 4, 196, 88, 51, 142);
List<Integer> num = lst.stream()
         .filter(s -> s % 3 == 0)
         .toList();
System.out.printf("集合中满足条件的元素有：%s%n", num);
num.add(2);

// 输出：
// 集合中满足条件的元素有：[15, 51]
// Exception in thread "main" java.lang.UnsupportedOperationException
```

## map()
这个方法为中间操作

签名如下：
``` Java

```

接下来介绍有关函数式编程的核心之一——map()以及有关的一系列方法

首先简单介绍一下`map()`，这个方法的作用是**在不对原先流里面元素产生任何影响的情况下返回一个新的流**（无副作用）

什么意思呢，简单来说就是在不对原先产生任何影响的情况下返回一个新的流

举一个具体的例子来说明：

``` Java
List<Integer> list = Arrays.asList(2, 3, 5, 6);
ArrayList<Integer> arrayList = new ArrayList<>(list);
List<Integer> integerList = arrayList.stream()
        .map(n -> n * n)
        .toList();
System.out.printf("新的集合为：%s%n", integerList);

// 输出：
// 新的集合为：[4, 9, 25, 36]
```
可以看到，这里返回了一个新的流，并且这个流的每一个元素都是由原先的流经过`map()`产生得来的

接下来再举一个比较复杂的例子

``` Java
List<String> list = Arrays.asList("apple", "banana", "grape");
List<String> arrayList = new ArrayList<>(list);
List<String> stringList = arrayList.stream()
        .map(word -> Character.toUpperCase(word.charAt(0)) + word.substring(1))
        .toList();
System.out.printf("新的集合为：%s%n", stringList);

// 输出：
// 新的集合为：[Apple, Banana, Grape]
```
可以看到，这里使用了一些操作使得每个单词的首字母大写

首先获取到该单词的首字母`word.charAt(0)`，然后将其转换为大写`Character.toUpperCase()`，在大写后就要拼接没有大写的部分了，说的直白点就是除去首字母的部分，那么对字符串操作我们可以使用到这个方法`word.substring(1)`，这个方法去除了第一个字母，也就是首字母

最后将这两者拼起来皆可得到我们想要的结果

如果使用传统的命令式编程，则需要对每一个操作都写出来（遍历，拆分，转大写）

而使用函数式编程则直接对想要修改的地方直接修改即可，相对来讲会方便很多

## mapToInt()
这些方法均为中间操作

签名如下
``` Java
IntStream mapToInt(ToIntFunction<? super T> mapper);
```

这个方法与map()其实功能上差不多，都是将流里面的一个东西转变为另一个东西

但是`mapToInt()`还多了一个转换为int类型的过程，这一细微的处理直接影响了很多操作

举一个例子，假设我们需要返回该流里面所有数字的平方和，那么我们可以这样干：

``` Java
List<Integer> lst = Arrays.asList(2, 3, 4, 5, 6);
int numList = lst.stream()
         .map(n -> n * n)
         .mapToInt(Integer::intValue)
         .sum();
System.out.printf("平方后各个元素之和为：%d", numList);

// 输出：
// 平方后各个元素之和为：90
```

可以看到，这里使用到了`.mapToInt(Integer::intValue)`，这里的这个方法引用的作用是将Integer类型拆包为int类型

为什么要这么干呢？这是因为原先的map返回对象为Stream，而Stream是没有.sum这个方法的，而`.mapToInt(Integer::intValue)`将原先的流转换为`IntStream`，这个类型才有`.sum()`求和的方法

但是，这样做其实是有点多此一举的，事实上可以直接这样写：

``` Java
List<Integer> lst = Arrays.asList(2, 3, 4, 5, 6);
int numList = lst.stream()
         .mapToInt(n -> n * n)
         .sum();
System.out.printf("平方后各个元素之和为：%d", numList);

// 输出
// 平方后各个元素之和为：90
```
这样直接用`.mapToInt()`代替原先的`.map()`，简化了一步转换

## reduce()
这个方法为终端操作

签名如下
``` Java
int reduce(int identity, IntBinaryOperator op)

OptionalInt reduce(IntBinaryOperator op);
```
这个方法的作用为整合整理，简单举一个例子来说明

``` Java
List<Integer> list = Arrays.asList(2, 3, 4, 5, 6);
List<Integer> arrayList = new ArrayList<>(list);
OptionalInt sumAll = arrayList.stream()
        .mapToInt(num -> num * num)
        .reduce(Integer::sum);
sumAll.ifPresent(number -> System.out.printf("集合总和为：%d", number));

// 输出：
// 集合总和为：90
```

可以看到，此处输出的内容为原流中所有数字平方后的和，也就是reduce把所有的数字都整合合并