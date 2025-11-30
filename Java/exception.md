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

```