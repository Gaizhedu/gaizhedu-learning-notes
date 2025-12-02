# 异常处理
这份笔记将介绍有关异常处理的部分

Java中使用异常处理可以巧妙的应对一些错误的发生，防止在关键时候出现一些致命的错误

## 异常的分类
那么在介绍异常处理之前，我们有必要了解一下异常的类型有那些

首先，Java中所有的异常都继承于`java.lang.Throwable`

一般分为两大类：`Error`和`Exception`

**Error**代表那些没办法处理的问题，程序不应该捕获这些错误，因为这种错误来自一些没办法恢复的问题，比如说`OutOfMemoryError`（内存不足）`StackOverflowError`（递归过深）

从描述上看，便可以发现这些Error是没办法通过捕获来处理掉的，所以上文说没必要捕获这些错误

**Exception**代表的是异常，这些异常是可以处理的，一般可以通过捕获来处理，例如经典的`NullPointerException`（空指针）`ArrayIndexOutOfBoundsException`（数组越界）`UnsupportedOperationException`（不支持操作）

如果将异常再次细分，可以分为`受检异常`和`非受检异常`

`受检异常`父类为`Exception`，这种异常编译器是强制处理的，如果没有对这种错误进行处理，那么是没办法通过编译的

而`非受检异常`父类为`RuntimeException`，这种异常编译器不强制处理，意味着可以正常通过编译，一般会在运行的时候会抛出错误

## 如何异常处理
异常处理的方式有很多，比较常用的有：`try-catch`

这个方法的基本结构如下：
``` Java
try {
    // 代码
} catch (Exception e) {
    // 遇到错误执行什么
}
```

从这个片段中可以看到，假设我们的代码执行时抛出了错误e，那么便会执行`catch`花括号内的代码片段

如果有多个错误需要捕获，那么可以使用多个catch语句
``` Java
try {
    // 代码
} catch (IOException e) {
    // 遇到错误执行什么
} catch (ArrayIndexOutOfBoundsException e) {
    // 遇到错误执行什么
}
```
如果你有很多个错误需要捕获，并且希望其同时以相同的操作来处理，那么可以这么写：

``` Java
try {
    // 代码
} catch (IOException | ArrayIndexOutOfBoundsException e) {
    // 遇到这两种异常中的一种便执行什么
}
```

接下来给出一个实际例子来说明：

``` Java
List<String> list = new ArrayList<>(Arrays.asList("1","2","3","4","5"));
try {
    for (int i = 0; i < 10; i++) {
        System.out.println(list.get(i));
    }
} catch (IndexOutOfBoundsException e) {
    System.err.println("数组出现了越界的现象");
}
// 输出：
// 1
// 2
// 3
// 4
// 5
// 数组出现了越界的现象
```
可以看到，在捕获到数组越界的情况后，没有像往常一样直接抛出错误，而是输出对应的内容

除了这个基本的结构外，我们还可以加上一个`finally`块

`finally`块的作用是无论try发生异常，catch是否执行，都执行里面的内容

### 补充点：关于finally的执行顺序
这里补充一下有关finally执行顺序的内容

## try-with-resource
接下来是try-with-resource，这个方法的作用是让资源使用后可以自动关闭

举个例子：

``` Java
try(FileInputStream fileInputStream = new FileInputStream("test.txt");
    BufferedReader reader = new BufferedReader(new InputStreamReader(fileInputStream))){
    String line;
    while ((line = reader.readLine()) != null) {
        System.out.println(line);
    }
} catch (IOException e){
    System.out.println("文件不存在");
}
```
使用try-with-resource的结构是把需要使用的资源放到try后面的括号内

这里需要注意的几点是，如果你已经在括号内声明了，那么就没办法在花括号内再次声明

可以理解为在圆括号中声明的变量都是`final`的

前文也提及到了，try-with-resource会在使用完文件后自动关闭文件，有效地防止了传统try-catch语句到最后忘记关闭文件的问题

## throw和throws
接下来介绍这方面的内容

首先先大概介绍这两个的作用

`throw`：直接抛出一个异常，在官方库中很多地方都会看到

`throws`：声明可能会出现的异常，这些声明的异常有些是必须要处理，有些则可以不用处理

---
首先是**throw**

作用为抛出一个异常，这个异常如果在main中被抛出则会直接中断当前程序的运行

``` Java
int[] ints = {1,2,3,4,5};
for (int i = 0; i < ints.length + 1; i++) {
    if(i == 2){
        throw new RuntimeException("遍历到第三个了");
    }
    System.out.println(ints[i]);
}

// 输出：
// 1
// 2
// Exception in thread "main" java.lang.RuntimeException: 遍历到第三个了
```

如果这个异常被catch捕获到了，那么不会中断程序

``` Java
int[] ints = {1,2,3,4,5};
try {
    for (int i = 0; i < ints.length + 1; i++) {
        if(i == 2){
            throw new RuntimeException("遍历到第三个了");
        }
        System.out.println(ints[i]);
    }
} catch (RuntimeException e){
    System.out.println("成功捕获丢出的异常");
}
System.out.println("程序继续运行");

// 输出：
// 1
// 2
// 成功捕获丢出的异常
// 程序继续运行
```

可以看到，这里异常被捕获了，程序并没有中断，而是继续执行

---
接下来是**throws**，这个的作用是声明可能会出现的异常

接下来先简单给个例子：
``` Java
public static void main(String[] args) throws RuntimeException {
    int[] ints = {1,2,3,4,5};
    try {
        for (int i = 0; i < ints.length + 1; i++) {
            if(i == 2){
                throw new RuntimeException("遍历到第三个了");
            }
            System.out.println(ints[i]);
        }
    } catch (RuntimeException e){
        System.out.println("成功捕获丢出的异常");
    }
    System.out.println("程序继续运行");
}
```
在上面这个例子中，标明可能会出现RuntimeException的异常

不过这里`RuntimeException`属于非受检异常，所以其实有没有标都是无所谓的

但是受检异常就必须标明