# 结构
这一章将讲讲C中有关结构的内容

首先我们需要理解结构是什么

结构，说白了便是一个以一个或多个变量组成的集合，而这些集合中的变量是可以为不同类型的

为什么要使用结构呢？这是因为结构可以将一组相关的变量看做一个单元而不是各自独立的实体，因此，使用结构可以更加灵活地处理复杂的元素，特别是用于一些大型的程序里面

举个实际的例子，假设我们需要记录很多个员工的工资记录，那么每个员工便由一些相同的属性构成

例如姓名，地址，职位，工资等

而这些属性也可以为结构，例如地址可以为结构，里面再由区，街道，门牌号这些元组组成

一个比较经典的例子是图形绘制，点可以由一对坐标定义，而矩形可以由两个点定义

而在ANSI标准（C89）之后，结构便多了一些操作，比如说拷贝、赋值、传递给函数等，函数也可以返回一个结构类型的值

> ~~怎么感觉有点像OOP~~

这便是结构的一些基础内容

## 结构的基本知识
接下来来讲讲结构的相关知识

首先第一个点，我们将创建一个结构用于表示坐标轴里面的坐标：

在明白需求后，我们便要知道如何创建一个结构

其最基本的框架如下：
``` C
struct [结构声明]{
    结构中的成员;
}
```
首先最基本的便是`struct`，后面跟着的**结构标记**就是这个结构的名字

而在结构中定义的变量就是成员了，需要提醒的一点是，假设结构标记，结构成员和普通变量都使用同一个名称，那也是没关系的

但一般来讲，除非两个东西之间关系十分密切，否则不会使用相同的名称

`struct`声明定义了一种数据类型，在标志结构成员表结束的右花括号之后可以跟着一个变量表

``` C
struct {
    ...
} x , y , z;
```

从语法的角度上讲，这种声明是类似于下面这种的

``` C
int x, y, z;
```

这两种声明都将变量声明为指定类型的变量，并且为他们分配存储空间

假设结构声明的后面不带参数表，那么不需要尾鳍分配存储空间

但是，如果结构声明中带有标记，那么在定义结构实例的时候便可以该标记定义

举个例子：
``` C
struct point pt;
```
在上面的例子中，我们定义了一个`struct point`类型的变量pt

如果需要对这个结构进行初始化，那么可以在之后的初值表进行

需要注意的一点是，初值表的每个成员必须为常量表达式

举个例子：
``` C
struct point {
    int px;
    int py;
};

struct point maxpt = {320,200};

int main() {
    printf("x:%d y:%d",maxpt.px,maxpt.py);
}

// 输出：
// x:320 y:200
```
在这里，我们初始化了一个标记`point`，并且定义了一个变量`maxpt`

并且在初值表里面定义了其成员`px`和`py`的值

---
假设我们需要使用这些结构的成员，那么只需要使用`结构名.成员`即可

举个例子，我们的结构名为`maxpt`，而另外的成员分别为`px`和`py`

需要使用的时候只需要这样便可以了

``` C
maxpt.px
maxpt.py
```

### 嵌套结构
结构是可以嵌套的，比如说：

``` C
struct jiegou1{
    struct jiegou2{
        ...
    }
}
```

举个实际的例子。我们稍微修改之前的那个程序：
``` C
struct rect {
    struct point {
        int px;
        int py;
    };
    struct point ppx;
    struct point ppy;
};

struct rect screen;

int main() {
    printf("x:%d y:%d", screen.ppx.px, screen.ppy.py);
}
```
在这里例子中，我们可以发现，在结构`rect`里面我们声明了另一个结构`point`

并且在下一行定义了两个变量`ppx`和`ppy`

这里也就是说，结构`rect`里面包含了结构`point`的两个成员

而在后面我们声明了一个`struct rect`类型的变量`screen`

在声明之后，便可以使用`screen.ppx.px`来调用`point`的成员了

### 需要提到的一些点
这里需要注意的一点是

> 此处struct rect有少许调整，里面声明的两个point的成员变为pt1和pt2

假设我们新建了两个`struct rect`的成员，分别为`test1`和`test2`

那么每个成员便都可以使用`struct point pt1`以及`struct point pt2`

但是需要注意的一点是，这里的两个成员对应的`point` 成员是不相同的

假设我们新建一个方法`makepoint`

这个方法的具体代码如下

``` C
struct point makepoint(int x, int y){
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}
```

而此时如果我们使用

``` C
test1.pt1 = makepoint(0,1);
test2.pt1 = makepoint(2,1);
```
那么这两个成员的pt1是不同的

第一个test1的pt1为`0,1`，而第二个test2的pt1为`2,1`

## 结构与函数
接下来将讲讲结构与函数这一节的内容

首先我们需要明白对结构而言，什么操作是合法的

对于结构的合法操作只有这几种：

1. 作为一个整体复制和赋值
2. 通过&运算符取地址
3. 访问其成员

而在这些之中，复制和赋值包括向函数传递参数，或者函数返回值

特别提醒的一点是结构之间**不可以进行比较**

接下来我们来编写三个函数，这三个函数都与点和矩形的操作有关

首先第一个函数为`makepoint`

这个函数的作用是传入两个坐标的x和y，之后返回一个point类型的结构

``` C
struct point makepoint(int x,int y){
    struct point temp;

    temp.x = x;
    temp.y = y;

    return = temp;
}
```

这里我们可以举一个例子来说明这个函数是怎么用的

我们的基本框架如下：
``` C
/* 
创建结构point，其中有两个普通变量，分别为x，y，和一个成员middle
其中，middle代表两个点的中点
*/
struct point {
    int x;
    int y;
}middle;


/* 
创建结构rect，并在其中定义了两个point类型的成员：pt1和pt2
同时还有一个成员screen
*/
struct rect {
    struct point pt1;
    struct point pt2;
}screen;

struct point makepoint(int x, int y) {
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}
```

接下来我们要创建两个点：

``` C
screen.pt1 = makepoint(0,0);
screen.pt2 = makepoint(100,100);
```
可以看到，我们使用了`makepoint()`函数成功创建了两个点，一个为`0,0`另一个为`100,100`

接下来我们想要获取这两个点的中点，我们便可以这样做：

``` C
middle = makepoint((screen.pt1.x + screen.pt2.x)/2 + (screen.pt1.y+screen.pt2.y)/2);
```

接下来来说明一下：

首先，结构point里面声明了两个普通变量，分别为x和y

而结构的成员是可以使用这个结构的普通变量的

在rect里面我们定义了两个point结构的成员，这两个成员对于结构rect来说，跟point里面的x和y是一致的

这也就是为什么后面定义的rect的成员可以使用`screen.pt1.x`来使用结构point中x的原因
