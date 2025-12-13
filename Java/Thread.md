# 线程
这份笔记将介绍有关线程的相关内容

首先是最基本的两个概念：进程和线程

什么是进程呢？简单来讲就是操作系统分配资源的基本单位

例如现在运行着一个程序，那么这个程序就是一个进程

什么是线程呢？线程是CPU调度和执行的一个基本单位，一个进程可以包含多个线程

## 基本语法
接下来正式介绍一下Java中的线程

我们可以通过这个方式来创建一个线程

``` Java
class CarRun extends Thread{
    @Override
    public void run(){
        System.out.println("汽车启动！");
    }
}
```
上面的这个例子是什么意思呢？

首先可以看到，这个类继承了`Thread`

而接下来选择了重写run()方法，这是因为这个类的执行逻辑在run()中，如果我们需要定义该线程要干什么，就必须重写这个方法

简单来讲就是

继承`Thread`来创建线程，重写`run()`来定义线程的任务

当然，只有这样是不够的，我们还需要创建这个线程

首先先新建一个对象：
``` Java
CarRun carRun = new CarRun();
```

在新建完这个对象后，我们就可以启动这个线程了

``` Java
carRun.start();
```

此时JVM会新建一个线程，并调用`run()`方法

需要注意的一点是，不要直接调用run()方法

``` Java
carRun.run();
```

虽然这样也是可以编译的，但是直接调用`run()`方法是直接在当前线程中执行，并不会启动新线程，也就失去了多线程的意义

---
在上面的例子中，我们可以发现，这个类已经继承了Thread，这意味着如果使用这种写法便无法继承其他的类了

那么我们要怎么办呢？

我们可以使用另外一种创建线程的办法，**Runnable**

Runnable是一个函数式接口，这个接口只有一个方法，也就是`run()`

如果将上面的例子用Runnable写，大概长这样：

``` Java
class CarRun implements Runnable{
    @Override
    public void run(){
        System.out.println("汽车启动！");
    }
}

public class Mission {
    public static void main(String[] args) {
        CarRun carRun = new CarRun();
        Thread thread = new Thread(carRun);
        thread.start();
    }
}

// 输出：
// 汽车启动！
```
在上面的例子中，`Thread thread = new Thread(carRun);`的作用是将该任务对象传递给线程

因为在这里例子中`CarRun`类并没有继承Thread，所以需要将任务传给线程

由于Runnable是个函数式接口，而函数式接口是可以使用Lambda的，所以上面的例子可以简化成这样

``` Java
new Thread(() -> System.out.println("汽车启动！")).start();
```