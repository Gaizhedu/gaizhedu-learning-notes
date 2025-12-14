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

## 线程池
我们已经学会了创建线程，接下来将介绍如何管理这些线程

我们先从一个例子讲起，假设我们现在有一家超市，这家超市早上来的顾客少，晚上来的客人多

假设来了10个客人，那么我们就招募10个店员，来多少个顾客就招募多少个店员

但是，一等到顾客少的情况，之前招募的店员有很多是浪费的

那么，我们要怎么办呢？

线程这边也是这样的，假设你遇到新任务就创建线程，那么等到任务较少的时候，很多线程就处于闲置状态，资源被大大浪费了

并且由于创建线程也需要消耗资源，所以遇到新客人就创建线程是不可行的

我们可以这么干

先提前创建好10个线程，把这些线程放到一个地方待命，等到有任务的时候就让线程去处理，没有任务就待在原地不动

我们把这个地方成为**线程池**

那么我们要怎么创建线程池呢？下面给出例子：

``` Java
ExecutorService service = Executors.newFixedThreadPool(10);
```
在上面的例子中，我们使用了`newFixedThreadPool`，这是个固定线程池，线程数量固定为括号内的数量

此外还有这些常见的线程池

- newCachedThreadPool() 缓存线程池
- newSingleThreadExecutor() 单线程线程池
- newScheduledThreadPool() 定时调度线程池

接下来通过一个例子来说明实际的用法：
``` Java
int count = 0;
ExecutorService service = Executors.newFixedThreadPool(10);
for (int i = 0; i < 10; i++) {
    count++;
    service.submit(() -> System.out.println("正在处理请求"));
}
System.out.printf("一共执行的次数：%d%n", count);
service.shutdown();
```

在上面的例子中，我们创建了一个固定线程池，且这个线程池的线程大小为10个线程

之后在for循环中重复10次提交任务，每一次都将这个打印的任务提交给队列

但是提交任务并不意味着执行任务，主线程的任务为计数+打印，其他线程的任务才是打印`正在处理请求`

所以会出现这种情况：

``` Java
// 输出：
// 一共执行的次数：10
// 正在处理请求
// 正在处理请求
// ...
```

需要特别强调的一点是，使用完线程池后需要加上`.shutdown()`来关闭线程池

## 线程的生命周期
接下来介绍有关线程的生命周期

线程有以下的状态

- NEW 线程被创建
- RUNNABLE 线程正在JVM中执行，或者准备好执行
- BLOCKED 线程试图进入synchronized同步代码块或方法，但锁被其他线程持有
- WAITING 线程等待其他线程执行操作
- TIMED_WAITING 线程等待有一定的时间限制，到时自动恢复
- TERMINATED 线程执行完毕，或者无法捕获异常而结束

如果想要查看当前线程的状态，可以使用`.getState()`：

## 锁
假设现在有一幅画，A正在画画，还没画完B就在画板上画，于是这两者都不乐意

换到线程，有A线程和B线程，A线程想要修改变量C，B线程也要修改变量C，这就导致最后程序不知道要选哪个线程修改的变量C

什么是锁呢？锁可以防止以上的事情发生

假设A线程开始修改变量C，修改的时候把C上锁，B试图修改变量C，但是因为上锁没办法修改，等到A线程修改完把锁打开，线程B才可以修改

这样就把一个同时操作的工作转换成了一个带有前后顺序的操作

那么Java中有什么锁呢？

主要有这些锁：

- synchronized 内置锁，自动加锁和释放
- ReentrantLock 显式锁，需要手动释放
- ReentrantReadWriteLock 读写锁，多个读线程可以同时读
- AtomicInteger 乐观锁，基于

接下来通过一个例子来实际说明锁的作用

假设用户想要分5次在银行取款，每次20块

``` Java
class Bank{
    private int total = 1000;

    public void withdraw(int amount){
        if (total >= amount){
            total -= amount;
        }
        System.out.printf("剩余余额：%d\n", total);
    }
}

public class MyBank {
    public static void main(String[] args) {
        int count = 0;
        ExecutorService service = Executors.newFixedThreadPool(10);
        Bank bank = new Bank();
        for (int i = 0; i < 5; i++) {
            service.submit(() -> bank.withdraw(20));
        }
        System.out.printf("一共执行的次数：%d%n", count);
        service.shutdown();
    }
}

// 输出：
// 一共执行的次数：5
// 剩余余额：920
// 剩余余额：940
// 剩余余额：920
// 剩余余额：920
// 剩余余额：940
```
可以看到，在输出中剩余余额是不正确的，并没有出现我们预期的状态，也就是分别取5次，每次减少20

如果有锁呢？

``` Java
public synchronized void withdraw(int amount){
    if (total >= amount){
        total -= amount;
    }
    System.out.printf("剩余余额：%d\n", total);
}

// 输出：
// 一共执行的次数：5
// 剩余余额：980
// 剩余余额：960
// 剩余余额：940
// 剩余余额：920
// 剩余余额：900
```
可以看到，此处便不会出现上文线程冲突的情况了，这也就是锁的一大用途，解决线程冲突的问题