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

### ReentrantLock锁
接下来介绍这个锁

这个锁的特性为：可重入性和互斥性

可重入性意味着同一个线程可以获取同一把锁而不会导致死锁

互斥性意味着同一时刻只有一个线程才能拥有这个锁

这个锁有一些有意思的特性

#### 定时
使用这个锁可以来设定时间，如果时间到还没有获取到锁，则自动放弃

``` Java
if (lock.tryLock(3, TimeUnit.SECONDS)){
    try {

    } catch (Exception e){

    } finally {
        lock.unlock();
    }
}
```
在上面这个语句中，`lock.tryLock(3, TimeUnit.SECONDS)`代表在三秒内试图获取到锁，如果不获取到锁，则自动跳过

可以用于一些需要让用户等待的场景，防止一直获取不到锁导致卡住

#### 中断
使用ReetrantLock还可以中断操作

``` Java
ReentrantLock lock = new ReentrantLock();
try {
    lock.lockInterruptibly();
} catch (InterruptedException e){
    Thread.currentThread().interrupt();
} finally {
    lock.unlock();
}
```
在上面这里使用到了`lock.lockInterruptibly()`，这个方法的作用是试图获取锁，但是与以往的方法不同，这个方法可以被其他线程中断，也就是当其他线程调用了`interrupt()`的时候，会抛出`InterruptedException`来中断等待

后面的`Thread.currentThread().interrupt()`是恢复状态，因为抛出错误的时候线程的中断状态会被自动清除，如果不使用这个的话可能会导致一些逻辑发生错误

#### 等待/通知
在ReentrantLock中，你可以通过调用`Condition`来实现等待和通知的功能

什么意思呢？

假设我们有两个线程，第一个线程可以负责往仓库里面放东西，第二个线程负责往仓库里面放东西

为了防止第一个线程在仓库满的情况下还继续放东西，我们需要在仓库满的时候使得这个线程等待

同理，如果仓库空了，第二个线程便要停止，等待第一个线程往仓库里面放东西

具体需要用到这两个方法

``` Java
await()

signal()
```
第一个`await()`代表线程进入等待状态，而第二个方法`signal()`代表通知该线程继续运作

也就是**等待**和**通知**

#### 公平模式
在以往的锁中，一般为谁先抢到锁就是谁的，这样就导致有些线程可能一直抢不到

但是在`ReentrantLock`中，你可以通过创建的使用选择在圆括号内填入`true`来打开公平模式

在这个模式下，便是先来就得到锁

## 原子操作
接下来介绍原子操作

那么什么是原子操作呢？简单来说就是一个操作开始执行，就必须完整执行完，不可以中途停止

举一个简单的例子

``` Java
int count = 0;
count++;
```
在上面这个例子中，这个自增的操作**并不是一个原子操作**

为什么呢？事实上我们可以将这个操作看为三步

1. 读，CPU读取`count`的值
2. 加，`count`自增
3. 写，把自增的值写回`count`

如果有两个不同的线程同时执行这一操作，那么就有可能导致值发生错误

那么要怎么让操作变成原子的呢？其实很简单，只需要使用`java.util.concurrent.atomic`这个工具包中的原子类即可

``` Java
public static void add(AtomicInteger integer){
    System.out.println(integer.addAndGet(100));
}

public static void main(String[] args) throws InterruptedException {
    ExecutorService service = Executors.newFixedThreadPool(10);
    AtomicInteger integer = new AtomicInteger(1000);
    for (int i = 0; i < 20; i++) {
        service.submit(() -> {
            add(integer);
        });
    }
    service.shutdown();
    if (!service.awaitTermination(5, TimeUnit.SECONDS)) {
        service.shutdownNow();
    }
    System.out.println("最终值为：" + integer.get());
}

// 输出：
// 1100
// 1300
// 1400
// 1200
// 1500
// 最终值为：1500
```
在上面的例子中，这一句负责声明原子类整数，并设定初始值为1000

``` Java
AtomicInteger integer = new AtomicInteger(1000);
```

接下来的for循环，这个代码块代表创建5个线程，每个线程都提交一次任务，属于并发操作

> 实际上你可以把add()方法打印的部分稍微修改一下
>
> System.out.println(Thread.currentThread().getName() + ": " + integer.addAndGet(100));
>
> 这样在打印的时候便会把线程名称也打印出来
>
> 输出：
> pool-1-thread-4: 1500
> pool-1-thread-3: 1400
> pool-1-thread-5: 1200
> pool-1-thread-1: 1300
> pool-1-thread-2: 1100
> 最终值为：1500

这里为了保证这些线程可以在主线程完成前完成，加了一个定时的语句：

``` Java
if (!service.awaitTermination(5, TimeUnit.SECONDS)) {
    service.shutdownNow();
}
```
如果等待5秒后线程没有完成，那么就中断所有任务

反之则说明线程已完成任务，可以正常结束

这样做的目的是，主线程需要等待所有工作线程完成它们的任务后，才能安全地读取共享状态，否则就有可能出现最后数据不对的情况

## 线程安全
既然介绍了锁和原子操作，那么接下来将介绍有关多线程中一个比较重要的点：线程安全

什么是线程安全呢？简单来讲就是在多个线程操作的时候，没有额外同步的操作，最后结果仍然符合预期

那么为什么会线程不安全呢？主要是并发破坏了三个特性：**原子性**、**可见性**、**有序性**

- 原子性：操作不可以被分割，上面在介绍原子操作的时候也有说明这一特点
- 可见性：指的是当一个线程修改一个变量的时候，其他线程也可以看到这一修改
  比如说在修改一个数字的时候，A修改了一次，之后B也修改一次，如果B可以看到A的修改（也就是可见性）那么便会在A修改的值的基础上进行修改
  如果没有可见性，便会在原先的值上进行修改，也就出现了结果与预期不一致的现象
- 有序性：指的是指令不可随意重排，一个对象的顺序一般为先创建对象，再赋值引用，如果顺序重排，就会出现空指针的情况

那么要怎么确保线程安全呢？除了最简单的加锁和使用原子类外，还可以选择**不共享变量**和**让状态不可变**

不共享变量也就是在方法内使用局部变量，这样每个线程所使用的变量便是私有的

让状态不可变指的是通过关键字修饰使得该变量不可被修改，通过这样的办法来实现线程安全