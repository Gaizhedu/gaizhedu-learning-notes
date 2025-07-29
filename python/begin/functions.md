# 函数
函数是Python中的一个重要组成部分，合理运用函数可以解决很多问题

## 函数的基本内容
为了更好的学习函数的相关内容，这里将简单介绍函数，如果已经有一部分基础，可以选择直接跳过这部分

这里就不复杂介绍函数是什么了，简单说就是一个可以重复执行的代码块

### 创建一个新的函数
如何创建一个函数，其实方法很简单，直接给出例子
``` Python
def a_function(name):
    return name
```
在上面的例子中`def`就是创建函数的语法，而后面的`a_function`就是这个函数的名字，后面括号内的`name`是这个函数的一个参数

函数内的`return`指的是把后面的`name`返回给调用这个函数的人，这个return语句可以不主动填写，这时候相当于填写了`return None`

这时候就有人要问了，这个返回给调用这个函数的人是什么意思呢？

我们简单举个例子

``` Python
def plus_fun(v1, v2):
    return v1 + v2

a = 2
b = 3
print(plus_fun(a,b))

# 输出：5
```
可以看到，变量a和变量b作为参数被传进了函数`plus_fun`里面，其中`v1`对应的是`a`，`v2`对应的是`b`

而不难发现，`print`的结果刚好是`return`后面的`v1 + v2`的结果

所以，`return`返回的结果是后面跟着的东西

而这里`print`语句中，里面使用了`plus_fun()`函数，所以`print`语句中输出的东西是这个函数返回的结果

### 向函数里面传值
我们已经学会了怎么创建一个函数，接下来要知道如何往一个函数里面传参数

这时候就有人要问了，传参数有什么用呢

举一个简单的例子：
这是一个函数，数学意义上的：
$f(x) = x^2$

这里的传参相当于那数字带入这里的x

同时也说明了函数的作用：可以重复执行的代码块，只要传入参数

说回正题，要如何向一个函数传入参数呢？

首先我们要确定能传入多少参数，这由函数后面的括号里面的值的多少决定

以上面的`plus_fun()`为例，这个函数一共有两个参数，一个为`v1` 另一个为`v2`，那么在传入的时候，就只能传入两个参数

而传入参数的方法也很简单，只需要在使用函数的时候在括号里面加上参数即可

``` Python
def a_fun(list_1, list_2):
    print("这是第一个列表：",list_1)
    print("这是第二个列表：",list_2)
    return list_1 + list_2

a = [1,2,3,4,5]
b = [6,7,8,9,10]
print(a_fun(a,b))

# 输出：这是第一个列表： [1, 2, 3, 4, 5]
# 这是第二个列表： [6, 7, 8, 9, 10]
# [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
```

可以看到，传入值的顺序，是与函数定义是后面的参数的顺序相一致的

当然，如果你不想按顺序传入，只需要指定是哪几个值是什么即可：

``` Python
def a_fun(list_1, list_2):
    print("这是第一个列表：",list_1)
    print("这是第二个列表：",list_2)
    return list_1 + list_2

a = [1,2,3,4,5]
b = [6,7,8,9,10]
print(a_fun(list_2 = b,list_1 = a))

# 输出：这是第一个列表： [1, 2, 3, 4, 5]
# 这是第二个列表： [6, 7, 8, 9, 10]
# [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
```
可以发现，这里是`b`先传入，但是由于已经说明了哪个值对应传入的哪几个值，所以输出的结果是不受顺序改变的

#### 默认参数值
这时候就有人要问了，如果要的值是不变的，那怎么办？

解决方法也很简单，只需要在创建函数的时候将值说明即可
``` Python
def introduct(name,age=18):
    print("学生：",name,"年龄：",age)
    return None

a = "小明"
b = "小华"

introduct(a)
introduct(b,19)

# 输出：学生： 小明 年龄： 18
# 学生： 小华 年龄： 19
```
这里可以发现，第一个小明在传入时没有填入`age`的值，但由于函数在定义时已经将`age`的值填好了，默认为18，所以不会报错

而第二个例子小华，在传入时重新给了一个值，使得原来函数定义时的值被覆写了，这也说明了在创建函数时写入的值可以被后面使用函数时改变

#### 可变参数
接下来来讲讲可变参数，也就是`*args`和`**kwargs`

*args：接收任意数量的位置参数（元组）
**kwargs：接收任意数量的关键字参数（字典）

这里简单举个例子说明

首先是`*args`

``` Python
def add_tuple(*args):
    print(args)
    return sum(args)

print(add_tuple(1,2,3,4,5))

# 输出：(1, 2, 3, 4, 5)
# 15
```
这里可以看到：使用`*args`可以同时传进多个参数（例如这里的`1,2,3,4,5`）

同时，还将原本的参数打包成了一个元组（见输出的第一条结果）

这样有什么好处呢？当你的参数数量不确定的时候，便可以直接将所有的参数全部用`*args`传进函数，让函数自己打包，使得代码更加简洁

此外，`*args`还可以统一处理传进的参数
``` Python
def a_func(*args):
    return sum(args)

a = (1,2,3,4,5)
b = (6,7,8,9,10)
print(a_func(*a,*b))

# 输出：55
```
可以看到，这里两个元组都被`*args`统一传进了函数

还有一个点就是`*args`的名字时可以改变的，比如想叫`*exp`也是可以的，**但是星号一定要保留**，但约定俗成还是统一叫做`*args`

##### 注意内容
在使用`*args`的时候还有一些注意的点：


另外一个就是在使用`*args`的时候要注意**位置**

下面直接给出例子：
``` Python
def e_fun(a,b,*args):
    return (a + sum(args)) * b

print(e_fun(7,10,1,2,3))

# 输出：130
# 也就是 [7 + (1 + 2 + 3)] * 10 = 130
```
但如果调换了位置的话（`b`与`*args`调换），由于`*args`可以接受任意数量的参数，所以这里会连带把`b`的值给打包，这就导致了缺少一个参数的值

所以，**在定义函数时，可变参数（\*arg）要放在位置参数（a, b）之后**

接下来是`**kwargs`
`**kwargs`是一个特殊的参数，作用是把传进的 **关键字参数** 打包成字典

什么关键字参数？大概长这样：
``` Python
def a_func(**kwarys):
    return kwarys

print(a_func(name="李华",age="18",height=170,weight=59))
```
这里引用函数时括号里面的`name`、`age`、`height`、`weight`就是关键字参数

上面的输出结果如下：
``` Python
{'name': '李华', 'age': '18', 'height': 170, 'weight': 59}
```
可以看到，返回的结果是一个字典

那么这个参数有什么优点呢？

优点在于其可以处理任意数量的关键字参数，不必担心传入时出现多余的参数而无法处理

与上文的`*args`一样，`**kwargs`同样支持自定义名称，只要把`**`保留皆可

另外一个用法是，可以用`**`解包一个字典

这里给出例子说明：
``` Python
def a_func(name, age):
    print(f"名字：{name}，年龄：{age}")

person = {"name" : "小明", "age" : 18}
a_func(**person)

# 输出：名字：小明，年龄：18
```
这里相当于把字典`person`解包成两个参数`name`和`age`，之后再传进函数内

##### 注意内容
与上文的`*args`一样，定义函数时若使用该可变参数同样要注意位置

这里的`*kwarys`要放到最后面

#### 返回结果与 return 语句
在Python的函数中，如果你想要返回函数的结果，可以使用`return`语句

在之前的内容中，也已经提及了大量的例子，这些例子中都包含了`return`语句

接下来来详细介绍一下：

**1.无返回值**
无返回值也就是不返回任何东西，如果没有填写`return`语句，则自动视为无返回值

举个例子：
``` Python
def a_func():
    print("Hello World!")

return_func = a_func()
print(return_func)

# 输出：Hello World!
# None
```
这里可以看到，使用`print`语句打印函数的输出结果是`None`，也就是无返回值

**2.返回单个值**
`return`可以返回很多东西，包括一个值，一条式子等都是可以的
``` Python
def a_func(a, b):
    c = a + b
    return c

def o_func(a, b):
    return a + b

a = 1
b = 2
print("第一条式子的结果是：",a_func(a, b))
print("第二条式子的结果是：",o_func(a, b))

# 输出：第一条式子的结果是： 3
# 第二条式子的结果是： 3
```

接下来是返回一个元组
``` Python
def a_func(name, age):
    return name, age

name = "李华"
age = 18
print(a_func(name, age))
print(type(a_func(name, age)))

# 输出：('李华', 18)
# <class 'tuple'>
```
可以看到，这里返回的类型为`tuple`，也就是**元组**

接下来是列表和字典：
``` Python
def l_func(a):
    return [x ** 2 for x in range(1, a)]

def d_func(name, age):
    return {
        "name" : name,
        "age" : age
    }

number = 5
name = "小明"
age = 18
print(l_func(number), type(l_func(number)))
print("名字是",d_func(name, age)["name"],"年龄是",d_func(name,age)["age"], type(d_func(name, age)))

# 输出：[1, 4, 9, 16] <class 'list'>
# 名字是 小明 年龄是 18 <class 'dict'>
```
可以看到，返回的结果分别是列表（list）以及字典（dict）

### 作用域与闭包
接下来来讲讲作用域和闭包：

**作用域**
作用域指的是程序中变量、函数和对象的可访问范围。举个鲜明的例子：假设你在自己的房间里面放一个箱子，那么只有在这个房间的人才能用这个箱子，此时便叫做**局部作用域**，但如果把这个箱子放到公共的地方，那么所有人都能用这个箱子，此时便叫做**全局作用域**

作用域一共有以下的种类：
<table>
    <thead>
        <tr>
            <th>名称</th>
            <th>变量位置</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>全局作用域（Global）</td>
            <td>位于<strong>模块顶部</strong>的变量，不在任何函数，类里面</td>
        </tr>
        <tr>
            <td>局部作用域（Local）</td>
            <td>变量位于函数内部，并且只能在该函数里面可见</td>
        </tr>
        <tr>
            <td>嵌套作用域（Enclosing）</td>
            <td>嵌套作用域的出现条件是位于嵌套函数中，此时内部函数可以访问外部函数的变量，注意这里的对象是内部函数而非外部函数</td>
        </tr>
        <tr>
            <td>内置作用域（Built-in）</td>
            <td>Python里面内置的函数或者变量</td>
        </tr>
    </tbody>
</table>

下面为每个作用域给出实例：
``` Python
a = "我位于模块最顶部，是全局作用域"

def a_func():
    b = "我是一个函数中的变量，所以位于局部作用域"
    print(b)
    def b_func():
        c = "我是一个嵌套函数中内部函数的一个变量，所以位于嵌套作用域"
        print(c)

    b_func()
    # 这里如果试图调用内部函数的变量c则会报错，因为变量c位于嵌套作用域
    # 而现在所处的位置是一个嵌套函数中的外部函数，不位于内部函数中，所以没法使用变量c

# 这里的 print 属于内置作用域，因为 print 是一个内置函数
print(a)
a_func()
```

#### 注意点
对于全局作用域而言，在当前模块（说白了就是在这个文件里面）下，你可以在任意地方访问，若位于其他模块，则需要使用`import`语句来导入该变量

对于局部作用域而言，只能在函数内部访问，并且函数结束时变量自动销毁，不可复用

对于嵌套作用域而言，有且仅有内部函数可以访问，如果需要修改外部函数的变量，可以使用`nonlocal`语句后对闭包作用域（外部函数）的变量进行修改

下面给出实例
``` Python 
def a_func():
    a = "我现在位于局部作用域"
    def b_func():
        nonlocal a
        a = "现在已使用 nonlocal 语句修改位于闭包作用域（外部函数 a_func）的变量a"
        print(a)
    print(a)
    b_func()

a_func()
```

这里额外再介绍一下Python中查找变量的规则：**LEGB规则**

L：Local
E：Enclosing
G：Global
B：Built-in

这里的L，也就是Local指的是Python先在函数内部查找变量

而E，指的是Enclosing，也就是在函数内部查找不到变量后便在外部函数里面查找

若还是找不到，那便是G，也就是Global，会在全局作用域里面查找

若以上都没有，则会在B，也就是Bulit-in，在内置作用域里面查找

这就是LEGB规则

---
**闭包**
闭包是嵌套在外部函数内部的内部函数，它的特点是在外部函数结束时，作为内部函数中的变量可以被储存起来，不会被销毁

需要注意的是，只有被闭包引用的变量才不会被销毁，而未被引用的变量是会被销毁的，同样的道理，闭包内部的变量也会随着函数的结束而被销毁，除非闭包内部还有另一个函数来引用闭包内部的变量

下面给出例子:
``` Python
def a_func():
    a = 10
    def b_func():
        print(a)
    return b_func

func = a_func()
func()
```
在这个例子中，我们可以看到内部函数`b_func`引用了外部函数`a_func`的一个变量a，此时内部函数`b_func`就形成了一个闭包

而在后边的 `return b_func` 中，这里的函数已经结束，外部函数`a_func`已经被销毁，但是由于内部函数是个闭包，导致了变量a被保存起来
这也是为什么后面`func()`可以正常输出a的值的原因

需要注意一点的是，这里内部函数在引用外部函数的变量时不需要加`nonlocal`，但是如果内部函数出现了修改变量的情况，则需要加`nonlocal`，否则内部函数会将变量认为是一个新的变量

---
## 参数（进阶）
### 位置参数与关键字参数
在之前的内容已经稍微讲过了有关位置参数和关键字参数的内容，接下来来细致介绍一下相关内容

位置参数和关键字参数都是Python中用来向函数传递参数的一种方式

首先是**位置参数**

位置参数指的是 *按照参数定义的顺序依次传递的参数*

具体的特点是：传递参数时按照定义的顺序传递，不可以调换顺序，并且不可以省略，除非有默认值

接下来给出具体例子：
``` Python
def a_func(name,age,work):
    print(f"你的名字叫做{name}，年龄为{age}，工作为{work}")

a_func("李华","28","程序员")

# 输出：你的名字叫做李华，年龄为28，工作为程序员
```
在上面这个例子中，函数 `a_func` 被引用时后面带着的三个参数就被称为位置参数，可以看到，三个参数被依次传递到函数内部

这里如果试图调换顺序，则会使得参数的位置错位：
``` Python
def a_func(name,age,work):
    print(f"你的名字叫做{name}，年龄为{age}，工作为{work}")

a_func("28","程序员","李华")

# 输出：你的名字叫做28，年龄为程序员，工作为李华
```

因此，**在使用位置参数时一定要注意参数的传入顺序**

---
接下来是**关键字参数**，正如这个参数的名字一样，关键字参数可以通过关键词来传递参数，这样的好处是当你在传递参数时，可以不考虑传递的顺序，只需要考虑关键词是否对应即可

下面给出例子：
``` Python
def a_func(name,age,work):
    print(f"你的名字叫做{name}，年龄为{age}，工作为{work}")

a_func(age = "28",work = "程序员",name = "李华")

# 输出：你的名字叫做李华，年龄为28，工作为程序员
```
可以看到，通过使用关键字参数，即使传递参数时的顺序不是定义函数时的顺序，但每个参数都被正确的传递了，这也体现了关键字参数中不依赖顺序的特点

在使用关键字参数的时候，还可以通过默认值来省略部分参数

下面照例给出例子：

``` Python
def a_func(name, work, age=20):
    print(f"你的名字叫做{name}，年龄为{age}，工作为{work}")


a_func(work="程序员", name="李华")

# 输出：你的名字叫做李华，年龄为20，工作为程序员
```

这个例子就是使用了默认值，在函数刚定义的时候将默认值声明皆可

在声明后在引用函数时便可以不导入相对应的值

#### 注意事项
在使用关键字参数的默认值时，要注意声明的时候要把默认值放到参数最后面的位置
例如：
``` Python
def a_func(name, age = 18 ,work):
    ...

def a_func(name, work, age = 18):
    ...

```
在上面两个函数中，只有第二个函数才是正确的，而第一个函数因为默认值没有放到最后而导致报错

### 默认参数的陷阱
在上面的关键字参数中，我们已经提到过默认值参数这个概念了，接下来来说说有关默认参数里面的陷阱

当默认参数是可变对象（如列表、字典、集合）时，该对象会在函数定义时被创建，并且所有调用共享同一个实例。

例如，当一个函数默认参数值是一个列表，此时如果调用函数将值加进去会导致不符合目标

``` Python
def a_func(list_v , list_a  = []):
    list_a.append(list_v)
    print(list_a)
    return None

a_func(1)
a_func(2)

# 输出：[1]
# [1, 2]
```
可以看到，在第二次输出时，并没有按照我们的要求正确输出`[2]`，而是输出了`[1,2]`
要解决这种情况也很简单，只需要将每次的列表初始化即可，下面给出修正后的例子
``` Python
def a_func(list_v , list_a  = None):
    list_a = []
    list_a.append(list_v)
    print(list_a)
    return None

a_func(1)
a_func(2)

# 输出：[1]
# [2]
```

这里其实还有一点问题，当用户主动传入一个非空列表时，如果按这里的输入，则会导致列表被重置：
``` Python
def a_func(list_v, list_a = None):
    list_a = []
    list_a.append(list_v)
    print(list_a)
    return None


list_1 = [100]
a_func(200,list_1)

# 输出：[200]
```
可以看到，这里的输出并不是我们预想的`[100, 200]`

这是因为每次调用函数`a_func`会导致列表重置一次

为了避免这种情况发生，需要在函数里面新增一个判断语句
``` Python
def a_func(list_v, list_a = None):
    if list_a is None:
        list_a = []
    list_a.append(list_v)
    print(list_a)
    return None


list_1 = [100]
a_func(200,list_1)

# 输出：[100, 200]
```
这样就成功避免了传入时原先列表非空的情况

---

另外还有就是关于默认参数的作用域问题，如果默认参数引用了外部变量，则可能导致在后面更新变量时出现变量不更新的情况
``` Python
a = 100
def a_func(a2 = a):
    print(a2)
    return None

a_func()
a = 200
a_func()

# 输出：100
# 100
```
可以看到，这里在后面更新a的值为200时，后续调用函数并没有改变结果

### 解包
接下来来讲讲解包，其实这部分的内容已经在可变参数（*args 和 **kwarys）中介绍过了，但还是详细介绍一下

首先是**位置参数解包**

当使用`*`时，你可以将一个列表或者元组拆分成多个元素，然后依次到函数的各个位置参数：

``` Python
def a_func(a1, a2, a3):
    print(f"第一个参数是{a1}，第二个参数是{a2}，第三个参数是{a3}")
    return None


list_1 = [111, 222, 333]
a_func(*list_1)

# 输出：第一个参数是111，第二个参数是222，第三个参数是333
```
从这里可以看到，列表的三个位置分别被解包为三个值，并被传到了函数里面

如果不使用解包的做法是这样的：
``` Python
def a_func(a1, a2, a3):
    print(f"第一个参数是{a1}，第二个参数是{a2}，第三个参数是{a3}")
    return None


list_1 = [111, 222, 333]
a_func(list_1[0],list_1[1],list_1[2])

# 输出：第一个参数是111，第二个参数是222，第三个参数是333
```
这里没有使用解包，而是用了传统的列表的项来向函数里面传入值，显然可读性比较低

并且如果列表的数值过多，就会导致需要传入的数值过多，大大影响了代码的可读性

---

接下来是**关键字参数解包**

关键字参数解包用于解包字典，之后将解包后的值传进函数，下面直接给出例子

``` Python
def a_func(name, age):
    print(f"名字：{name}，年龄：{age}")

person = {"name" :"李华","age":"20"}
a_func(**person)

# 输出：名字：李华。年龄：20
```
可以看到，这里`**person`将`person`这个字典解包成对应的内容

由于这里解包之后的参数为关键字参数，所以可以不用在意传入顺序，只需要确保关键字是正确的皆可

接下来是**混合解包**，说白了就是这两种解包方式可以同时使用：

``` Python
def a_func(a1, a2, a3, a4, a5):
    print(f"列表解包为：{a1}、{a2}、{a3}，字典解包为：{a4}、{a5}")
    return None


list_1 = [1, 2, 3]
dic = {"a4": 4, "a5": 5}
a_func(*list_1, **dic)

# 输出：列表解包为：1、2、3，字典解包为：4、5
```

可以看到，这里分别使用了位置参数解包以及关键字参数解包

`list_1`的三个值分别传递给`a1`，`a2`，`a3`，而字典`dic`因为为关键字参数，所以被分别传递给各自的参数

---
## 高阶函数
接下来来讲讲高阶函数，高阶函数并不是指这个函数更加高级，而是指这个函数可以接受其他函数作为参数，或者将函数当做返回值

这样的函数有很多，之后会逐一介绍

首先我们需要理解第一个高阶函数的概念：**将函数作为参数**

---
### 将函数作为参数
正如字面上的意思一致，你可以将一个函数作为一个参数，接下来将用实际例子介绍一下：
``` Python
def a_func(a1, a2):
    return a1 + a2

def b_func(a_func, b1, b2):
    return a_func(b1 , b2)

print(b_func(a_func,1,2))

# 输出：3
```
我们来逐一解释这个例子的语句：

首先先从这里看起：`print(b_func(a_func,1,2))`

这里的可以拆分成几部分，分别是：
- 负责打印的`print()`
- 负责调用函数的`b_func()`
- 以及传进去的参数`a_func,1,2`

之后我们来看一下调用的这个函数内容是什么：
``` Python
def b_func(a_func, b1, b2):
    return a_func(b1 , b2)
```
很明显，这里是这样的，返回一个以参数`a_func`的值的函数，其中这个函数传进了两个值（b1和b2）

需要注意的是，这里函数定义时的参数名`a_func`与我们导入的函数名相同纯属巧合，你可以随便更改这个函数名：
``` Python
def b_func(thisisafunc, b1, b2):
    return thisisafunc(b1 , b2)
```
而让我们重新看一下我们传入了什么：很明显是`a_func`，所以这里就是调用了函数`a_func`

接下来让我们看看`a_func`函数的内容：
``` Python
def a_func(a1, a2):
    return a1 + a2
```

很明显，这里是接受两个值：a1和a2，然后返回其相加的值

而这里的a1和a2是是什么？细心往前观察可以看到，就是我们传入的值b1和b2，而这个b1和b2又是什么？再次回看传进函数`b_func`的值可以发现，b1是1，而b2是2

由此，这里输出的值也就是3了

---
在理解完高阶函数在将函数作为参数这方面的应用后，我们可以写一个简单的四则计算器：
``` Python
def plus(p1, p2):
    return p1 + p2

def minus(mi1, mi2):
    return mi1 - mi2

def multiply(mu1, mu2):
    return mu1 * mu2

def divide(d1, d2):
    return d1 / d2

def operate(func, s1, s2):
    return func(s1, s2)

print(operate(plus,2,5))
print(operate(minus,9,2))
print(operate(multiply,5,6))
print(operate(divide,6,2))

# 输出：7
# 7
# 30
# 3.0

# 这里其实有个小问题，就是除法没有检测除数不能为0，不过就当忽略这个点了
# 当然如果要加上这个功能只需要在除法的函数那里加上一个检测d2 == 0 即可
```

---
### 返回函数
接下来来讲讲返回函数，也就是返回的结果是个函数，这是什么意思呢，直接举个例子分析一下
``` Python
def a_func(a):
    def b_func(b):
            return a * b
    return b_func

func = a_func(2)
print(func(3))

# 输出：6
```
接下来还是逐一解析语句：

首先看最主要的内容，也就是`print(func(3))`

这里很明显是往`func`里面塞一个参数`3`，诶，那`func`是什么呢？

往上看我们可以得知：哦，原来`func`代表的是将参数2传进函数`a_func`

这时候我们就已经了解到我们的操作是干什么了，接下来来实际看看函数

首先是第一个，也就是函数`a_func`：
``` Python
def a_func(a):
    def b_func(b):
            return a * b
    return b_func
```
可以看到这个函数里面还有一个函数，我们这里先不考虑，直接看到下面

可以发现返回语句返回的是一个函数，也就是`b_func`。这里需要注意一点的是，这里函数`a_func`的参数a已经被我们在一开始调用的时候传入了值（也就是2）

我们看到函数`b_func`
``` Python
def b_func(b):
        return a * b
```
可以看到，这里的函数内容是返回外部参数a和内部变量b的乘积

这里可能就有人要问了：诶，我刚才看用`return`语句调用函数的时候没有加括号传进值吗，这不是稳报错吗，你是不是写错了

我们可以回看我们一开始的`print`语句里面写了什么，也就是：`func(3)`，可以看到这里传进了一个值`3`，其实这里等价于`a_func(2)(3)`，在调用函数`a_func`后返回调用的函数`b_func`时相当于`b_func(3)`

这里可以看到传入了一个值3，也就是函数`b_func`里面的位置参数b

所以，这也就是为什么输出结果为6的原因

---
### 常见内置高阶函数
在Python中，有很多内置的高阶函数，接下来来逐一介绍

#### map()
map()函数的作用是返回一个迭代器，具体如下：`map(func, iterable)`
接下来给出例子：
``` Python
s = [1,2,3,4,5]
list_1 = map(lambda x,:x ** 2, s)
print(list(list_1))

# 输出：[1, 4, 9, 16, 25]
```
接下来来逐一解析一下这个语法

首先看一下最主要的函数内容，也就是`map(lambda x,:x ** 2, s)`

按照之前map函数的说明，我们可以看到这里的`lambda x,:x ** 2`是这里的`func`

而后面的列表s也就是`iterable`的内容

这里的`map(lambda x,:x ** 2, s)`也就是将列表s里面的值逐一传入前面的匿名函数，并收集函数的返回值，形成一个迭代器

但如果直接`print(list_1)`就只会得到一个标识信息，用于显示迭代器（也就是map）对象，但不是一个具体的信息

若想要变成一个列表，则需要用`list()`转换成列表

此外，如果不需要返回全部的列表，可以以下操作（此处涉及到 **生成器** 的内容）
``` Python
s = [1,2,3,4,5]
list_1 = map(lambda x,:x ** 2, s)
print(list(next(list_1) for _ in range(3)))

# 输出：[1, 4, 9]
```
此处不多说明，有关`next()`的语法可到生成器的部分阅读

##### 一些小事项
如果你细心观察可以发现，诶，这里似乎也可以用列表推导式来实现`map()`函数的内容：
``` Python
s = [1, 2, 3, 4, 5]
print([x ** 2 for x in s])

# 输出：[1, 4, 9, 16, 25]
```
是的，使用列表推导式或者for语句同样可以实现相同的内容，但使用map有一个优势：节省内存

下面给出例子来说明：
``` Python
import sys

s = range(100000)
l = [x ** 2 for x in s]
print("使用列表推导式使用内存：",sys.getsizeof(l))
m = map(lambda x: x ** 2, s)
print("使用map()函数使用内存：",sys.getsizeof(m))
a = []
for i in s:
    a.append(i ** 2)
print("使用传统for语句使用内存：",sys.getsizeof(a))

# 输出：使用列表推导式使用内存： 800984
# 使用map()函数使用内存： 48
# 使用传统for语句使用内存： 800984

```
这里调用了`sys`库来检测内存使用情况，可以看到，使用map()函数（前提是不转换成列表）只消耗48字节的内存，而其他的方式都消耗了大量的内存

需要注意的一点是，这里如果用 `list` 将map返回的迭代器转换成列表，消耗的内存是一样的

诶，这里就有人要追问了，那如果消耗的内存是一样的话，那还不是没有用

别急，让我们看一个例子：
``` Python
s = range(1, 100000)
l = [x ** 2 for x in s]
l2 = l[:10]
m = map(lambda x: x ** 2, s)
m2 = list((next(m) for _ in range(10)))

if l2 == m2:
    print(True)
else:
    print(False)
# 输出：True
```
可以看到，这两者的输出结果完全正确，但是使用`map()`所需的内存要更少

这是因为使用列表推导式的时候，需要把所有的数据全列出来，再对列表进行切割

而使用迭代器的时候，只有在对列表取项的时候才会列出数据

这里的话列表推导式总列出数据为99999项，而使用迭代器`map()`则只列出了10项

---
这里需要注意的一个点是，迭代器是一次性的，不可重复使用：
``` Python
s = [1,2,3]
a = map(lambda x:x+2,s)
print(list(a))
print(list(a))

# 输出：[3, 4, 5]
# []
```
可以看到这里第二次`print(list(a))`的时候，输出的是一个空的列表，这说明了迭代器只能使用使用一次

---
#### filter
接下来是`filter()`其格式如下`filter(function, iterable)`

这个函数的作用是对输入的内容进行筛选，筛选规则是：`function`，而筛选的内容为：`iterable`，如果筛选的内容符合筛选的规则，则返回`True`

下面给出例子：
``` Python
a = range(20)
s = list(filter(lambda x:x % 2 == 0, a))
print(s)

# 输出：[0, 2, 4, 6, 8, 10, 12, 14, 16, 18]
```
这里可以看到，函数`filter()`将满足条件的值都提取了出来，这里的条件为这个值除2的余数为0，也就是返回偶数

这是可能就有人要问了，诶，使用`filter()`用来检测值的方法可以通过if语句来实现，那为什么还要用`filter()`函数呢

首先，`filter()`跟`map()`返回的对象是一致的，都是一个**迭代器**，这就导致了，当你需要处理大量数据的时候，使用`filter()`会相较于使用if语句更省内存，当然，同上文`map()`一样，迭代器都只能使用一次

##### 其他细节点
`filter()`在设置过滤时，可以设置成`None`，此时便可以过滤掉假值：
``` Python
a = [0, 1, 2, 3, 4, 5, "", "0", None, "123", "字符串"]
print(list(filter(None, a)))

# 输出：[1, 2, 3, 4, 5, '0', '123', '字符串']
```
可以看到这里输出的字符串中，将所有假值（0，""，None）都过滤掉了（注："0"是一个字符串，不是一个假值）

> 关于假值的补充：
> 以下内容均为假值:
> 常量：None、False
> 数值：0、0.0、0j（复数零）
> 空序列 / 集合：""（空字符串）、[]（空列表）、()（空元组）、{}（空字典 / 集合）

---
还有一个点是，`filter()`返回的值不一定是严格的布尔值，如果返回的结果也可表示为布尔值，那也一样可以
``` Python
a = [0, 1, 2, 3, 4, 5, -1, -2, -3]
print(list(filter(lambda x:x, a)))

# 输出：[1, 2, 3, 4, 5, -1, -2, -3]
```
可以看到，这里`0`并没有返回到结果中，这是因为`0`也可以表示为`False`，所以这里并没有返回，而其他值，由于均不为0（也就是不为`False`），所以都可以成功返回

---
#### reduce
`reduce()`是Python中的一个内置的高阶函数，其作用是多次调用实现累计的效果，具体用法如下：`reduce(function, iterable[, initializer])`

这里的`function`是累计的规则，也就是每次执行什么函数

接下来的`iterable`是迭代的具体值，后面的`initializer`是初始值

需要注意的一点是，使用`reduce()`语句的时候需要导入外部库`functools`
``` Python
from functools import reduce
```

接下来举一个例子来实际说明：
``` Python
from functools import reduce

a = [2,3,4,5,6,7,8]
print(reduce(lambda x,y:x * y,a))

# 输出：40320
```
可以看到，这里的输出结果为列表a的各个值的相乘结果（2 * 3 * 4 * 5 * 6 * 7 * 8 = 40320）

这也说明了`reduce()`的核心作用是多次迭代

接下来来讲讲加初始值，顾名思义，也就是第一次的时候使用这个值
``` Python
from functools import reduce

a = [2,3,4,5,6,7,8]
print(reduce(lambda x,y:x + y,a,10))

# 输出：45
```
可以看到，若不加起始值，则结果为35，但是这里加了起始值，所以还要加上起始值

---
接下来来讲讲一下有意思的操作

由于`reduce()`可以实现多次调用的效果，所以可以用这个特性实现一些效果
``` Python
from functools import reduce

a = [1,2,3,34,54,45,5,56,6,32,3,4,122,3,4,4,2,34,4,56]
s = reduce(lambda x,y: x if x > y else y,a)
print(f"数列a中的最大值为：{s}")

# 输出：数列a中的最大值为：122
```

---
#### sorted
`sorted()`的作用是对任何可迭代对象（如列表、元组、字符串）进行排序，返回一个新的已排序列表，原对象保持不变，使用格式如下：`sorted(iterable, *, key=None, reverse=False)`

接下来来逐一说明一下：
`iterable`，也就是要排序的内容，后面的`*`意味着后面的`key`和`reverse`必须要用**关键字参数**，`key`是指定函数提取出比较的元素，后面的`reverse`为布尔值，当为`False`时为升序排列（默认），而为`True`时就为降序排列

下面给出例子来说明：
``` Python
a = [2,6,7,12,6,1,4,6,2,4,6,2,8,9,2,1]
s = sorted(a)
print(s)

# 输出：[1, 1, 2, 2, 2, 2, 4, 4, 6, 6, 6, 6, 7, 8, 9, 12]
```
这里给出的例子就是最基本的排序的例子

接下来给出一个使用`key`提取比较元素的例子：
``` Python
a = ["directly", "apart","rare","withstand"]

s = sorted(a,key=lambda x:x[0],reverse=False)
print(s)
t = sorted(a,key=lambda x:x[1],reverse=False)
print(t)
# 输出：['apart', 'directly', 'rare', 'withstand']
# ['rare', 'directly', 'withstand', 'apart']
```
可以看到，第一个例子是以第一个字母的排列顺序为排序标准，而第二个例子是以第二个字母作为排序标准

使用`sorted()`排序的对象有很多，可以是列表，元组，甚至是字符串
``` Python
a = (1, 4, 2, 62, 4, 1, 25, 6, 12, 4)
b = "HelloWorld!"

print(sorted(a))
print(sorted(b))

# 输出：[1, 1, 2, 4, 4, 4, 6, 12, 25, 62]
# ['!', 'H', 'W', 'd', 'e', 'l', 'l', 'l', 'o', 'o', 'r']
```
可以看到，这里第二个例子的字符串排序标准是**先符号，后大写，最后小写**

在说明一些例子后，来具体说明一下参数`key`

`key`排序的规则有很多，可以使用长度`len`，绝对值`abs`或者自定义函数规则

例子可以在上文看到，接下来来说明多级排序

多级排序，顾名思义，可以按照多个规则排序
``` Python
a = (
    {"name": "Emma", "age": 20},
    {"name": "Liam", "age": 22},
    {"name": "Olivia", "age": 19},
    {"name": "Noah", "age": 24},
    {"name": "Ava", "age": 21}
)

print(sorted(a ,key=lambda x:(x["name"],x["age"])))

# 输出：[{'name': 'Ava', 'age': 21}, {'name': 'Emma', 'age': 20}, {'name': 'Liam', 'age': 22}, {'name': 'Noah', 'age': 24}, {'name': 'Olivia', 'age': 19}]
```
在上面这个例子中，排序的规则是先以名字首字母为排序标准，而后以年龄为排序标准

若需要翻转排序，直接使用`reverse`会导致全部翻转，当需要指定一部分翻转的时候，可以如下操作：
``` Python
a = ([1, 9], [1, 6], [2, 5], [2, 7], [5, 9])
print(sorted(a, key=lambda x: (x[0], -x[1])))

# 输出：[[1, 9], [1, 6], [2, 7], [2, 5], [5, 9]]
```
可以看到，这里排序的结果是第一个元素按正序排列，而第二个元素按倒序的顺序排列

排列规则还可以用出现的次数来排序：
``` Python
from collections import Counter

a = ["air","air","ant", "ant", "banana","banana", "book", "book", "book", "bus", "cat", "car", "cake"]
print(sorted(a, key=lambda x: (-Counter(a)[x],x)))

# 输出：['book', 'book', 'book', 'air', 'air', 'ant', 'ant', 'banana', 'banana', 'bus', 'cake', 'car', 'cat']
```
这里用了`Counter()`来统计出现的频率，后面你的排序标准先按频率排序，如果频率相同就按出现的字母顺序排序

---
##### 注意事项
使用`sorted()`排序的时候，要注意排序的对象不可以混合（例如数字列表里面带了字符串）、
``` Python
a = [5,3,8,2,"apple"]

print(sorted(a))

# 输出：TypeError: '<' not supported between instances of 'str' and 'int'
```
可以看到，这里的报错原因是**无法将字符串和整数类型比较**

另外，`sorted()`排序字母的时候默认以大写字母优先：
``` Python
a = ["Apple","ant","Book","Bunny","Cherry","apple"]

print(sorted(a))

# 输出：['Apple', 'Book', 'Bunny', 'Cherry', 'ant', 'apple']
```
可以看到，下面输出的结果是优先排列大写字母

那要怎么解决这个情况呢，很简单，排序的时候，在规则`key`填入将字符串全部转换为小写（.lower()）即可：
``` Python
a = ["Apple","ant","Book","Bunny","Cherry","apple"]

print(sorted(a,key=lambda x:x.lower()))

# 输出：['ant', 'Apple', 'apple', 'Book', 'Bunny', 'Cherry']
```

---
#### max & min
`max()`和`min()`语句关联性极高，使用方法完全一样，但是输出的结果相反，一个输出最大值，一个输出最小值

具体语法如下：`max(iterable, *[, key, default])`

照例依次解读：

`iterable`需要比较的值

后面的`*`同理，需要用关键词传递

`key`代表比较的标准

`default`指的是默认值，如果不填的话，传入的值如果是一个空值，则会导致报错，若填入，并且默认值有填，则返回的值为默认值，不会报错

由于这两者使用的方法一致，所以这里只展示一种

接下来来给出例子
``` Python
a = [3,2,5,1,72,64,7,5,3,23,7,23,7,2,4,7,32,56,2,3,5,23,3]

print(max(a))

# 输出：72
```
上面是一个最基本的例子，直接遍历找出最大值

接下来给出另一个例子：
``` Python
a = ["dog", "jump", "red", "flower", "eat", "slow", "star"]

print(max(a,key=lambda x:x[0]))

# 输出：slow
```
这里的输出结果为`slow`的原因是：使用`key`的时候检测的是第一个字母中字典序最大的字符，也就是`s`，所以返回的也是`slow`

除此之外，`max`比较的对象还可以是元组：
``` Python
a = [(1,5),(5,2),(3,5),(1,2),(5,5),(5,7),(3,9)]

print(max(a))

# 输出：(5, 7)
```
这里先比较元组内的第一个值，得出结果是`5`，而随后会在第一个值为5的元组中比较第二个值，得出结果为`7`

因此结果为(5, 7)

接下来展示默认值的用法：
``` Python
a = []
print(max(a,default=0))

# 输出：0
```
此处如果没有写默认值则会报错：
``` Python
a = []
print(max(a))

# 输出：max() iterable argument is empty
```

##### 注意事项
`max()`和`min()`的注意事项与`sorted`大同小异，可以直接参照`sorted()`的内容

---
#### zip
`zip()`同样是Python中的一个内置高阶函数，其用法如下：`zip(*iterables)`

接下来照例来说明其具体的使用方法

`zip()`的参数很简单，只有一个`*iterables`，这时候就有人要说了，诶，这里有星号，所以后面得用`iterables=`来传递参数

但其实并不是这样的，只有单独将`*`列出来（例如`sorted(iterable, *, key=None, reverse=False)`）才说明后面的参数需要用到关键字参数

这里的星号作用为 **“位置参数收集符”**，它的作用是将调用时传入的多个位置参数并将其打包成一个元组

接下来来举个例子说明：
``` Python
name = ["Zoe", "Jack", "Lily"]
age = [19, 21, 22]

print(list(zip(name, age)))

# 输出：[('Zoe', 19), ('Jack', 21), ('Lily', 22)]
```
可以看到，这里的每个列表里面的参数都被收集起来并打包成一个元组

使用`zip()`打包元组的时候，若打包的数据存在多余，则会自动舍弃：
``` Python
name = ["Zoe", "Jack", "Lily", "Aliya"]
age = [19, 21, 22]

print(list(zip(name, age)))

# 输出：[('Zoe', 19), ('Jack', 21), ('Lily', 22)]
```
可以看到，这里输出的结果还是与上面一样，因为这里`age`只有三个值，所以自动舍弃掉`name`多出的值

此外，`zip()`还可以用于解压数据，接下来给出例子说明：
``` Python
a = ["apple", "banana", "cherry"]

price = [12, 3, 28]
tuple_1 = list(zip(a,price))
print(tuple_1)

# 解压数据
item_1 ,price_1 = zip(*tuple_1)
print(item_1,price_1)

# 输出：[('apple', 12), ('banana', 3), ('cherry', 28)]
# ('apple', 'banana', 'cherry') (12, 3, 28)
```
在上面这个例子中，先用了`zip()`打包数据并转换成列表为变量`tuple_1`，之后再使用`zip(*tuple_1)`对`tuple_1`的数据进行解包，`item_1`和`tuple_1`分别是接受元素的变量

此外，在循环中，还可以用`zip()`来遍历多个可迭代的对象：
``` Python
p = ["Alice","Ethan", "Chloe"]
d = ["2025-07-23","2025-07-25","2025-07-27"]

for pe,da in zip(p,d):
    print(f"打卡记录：员工{pe}在{da}成功打卡！")
    
# 输出：打卡记录：员工Alice在2025-07-23成功打卡！
# 打卡记录：员工Ethan在2025-07-25成功打卡！
# 打卡记录：员工Chloe在2025-07-27成功打卡！
```
这里的原理是，每次for循环都会让变量`pe`和`da`分别接收`zip()`里的数据

而后循环内依次对数据进行引用，引用结束后重新接收数据

`zip()`还可以将两个列表合并成一个字典：
``` Python
th = ["name", "age"]
td = ["Alice", "20"]
print(dict(zip(th, td)))

# 输出：{'name': 'Alice', 'age': '20'}
```

可以看到，这里输出的结果是一个字典，而这个字典的键就是传入的第一个列表，而对应的值就是第二个传入的列表

##### 注意事项
如果使用`zip()`遍历的对象是一个字典，此时返回的结果为这个字典的键，而不是值
``` Python
a = {"name":"Alice","age":23}
b = {"name":"Aliya","age":19}

print(list(zip(a,b)))

# 输出：[('name', 'name'), ('age', 'age')]
```
若想要返回的结果为对应的值，则需要在对应的对象后面加上`.values()`：
``` Python
a = {"name":"Alice","age":23}
b = {"name":"Aliya","age":19}

print(list(zip(a.values(),b.values())))

# 输出：[('Alice', 'Aliya'), (23, 19)]
```
可以看到，这里的结果就为对应的值了

---
#### reversed
`reversed()`的作用是返回一个反向的迭代器，说白了就是把传入的东西反向输出

具体的语法如下：`reversed(seq)`

这里`seq`指的是序列，包括**列表、元组、字符串、range对象等**

也就是说**字典是不可以的**

接下来给出例子说明：
``` Python
a = [1,4,5,6,2,1,2,4,4,7,1,3,1,7]
print(list(reversed(a)))

# 输出：[7, 1, 3, 1, 7, 4, 4, 2, 1, 2, 6, 5, 4, 1]
```

在给出基础的例子后，接下来分别讲一下各个序列使用后的结果：
``` Python
a_l = [1,4,7,32,89,3,6,2,4,35]
a_t = (1,3,8,5,12,3,4,6,8)
a_s = "HelloWorld！"
a_r = list(range(0,10))

print(f"初始序列：{a_l}\n{a_t}\n{a_s}\n{a_r}")

r_l = list(reversed(a_l))
r_t = tuple(reversed(a_t))
r_s = "".join(reversed(a_s))
r_r = list(reversed(a_r))

print(f"\n反转序列：{r_l}\n{r_t}\n{r_s}\n{r_r}")

# 输出：初始序列：[1, 4, 7, 32, 89, 3, 6, 2, 4, 35]
# (1, 3, 8, 5, 12, 3, 4, 6, 8)
# HelloWorld！
# [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
# 
# 反转序列：[35, 4, 2, 6, 3, 89, 32, 7, 4, 1]
# (8, 6, 4, 3, 12, 5, 8, 3, 1)
# ！dlroWolleH
# [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
```
##### 一些小技巧
如果需要反转不是序列的值，可以先转换成列表后再对其反转：
``` Python
d = {"a": 1, "b": 2, "c": 3}

print(list(reversed(d.values())))

# 输出：[3, 2, 1]
```


## 匿名函数 Lambda
Lambda的作用是创建一个一次性的简单函数，支持传入参数等操作

与普通的函数相比，匿名函数不需要`def`语句，并且即写即用。如果需要用到一些一次性的语句，便可以使用Lambda语句

接下来来详细介绍Lambda

### 语法与使用场景
Lambda的语法非常简单，主要由下面三部分组成
``` Python
lambda x, y : x * y
```
这里的`lambda`是告诉Python说下面的内容是有关匿名函数的内容，而后面的`x, y`就是这个匿名函数的位置参数，而后面的`x * y`就是匿名函数的表达式

下面给出一个实际例子：
``` Python
multiply = lambda x, y : x * y
print(multiply(1,2))

# 输出：2
```
在这个例子中，我们定义了一个匿名函数，并通过变量`multiply`引用它

当然，如果你不想用变量引用，也可以用下面这种形式：
``` Python
print((lambda x, y: x * y)(1, 2))
```
这样的话代码会比较简洁，但缺点是不能通过变量调用

使用Lambda的场景大部分是在需要使用一些简单的一次性操作中，这类场景由于语句比较简单，所以不需要使用具名函数`def`来定义函数，故使用匿名函数

### 与常规函数对比
匿名函数与具名函数的对比很明显，接下来列个表格来说明
<table>
    <thead>
        <tr>
            <th>特性</th>
            <th>匿名函数lambda</th>
            <th>具名函数def</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>定义方式</td>
            <td>使用<strong>Lambda</strong>关键字</td>
            <td>使用<strong>def</strong>关键字</td>
        <tr>
        <tr>
            <td>函数名称</td>
            <td>无函数名称（要不然为什么叫匿名函数），但仍可以用变量引用</td>
            <td>必须有名称，否则无法调用</td>
        <tr>
        <tr>
            <td>函数主体</td>
            <td>只能有一条表达式</td>
            <td>可以用多个表达式，甚至可以有其他函数</td>
        <tr>
        <tr>
            <td>返回结果</td>
            <td>自动返回</td>
            <td>用return语句，忘记加自动识别为return None</td>
        <tr>
        <tr>
            <td>适合场景</td>
            <td>简单的语句</td>
            <td>需要复杂运算（表达式多于一行）</td>
        <tr>
    </tbody>
</table>

可以看到，匿名函数与具名函数各有各的特点

接下来用一个具体的例子来说明：
``` Python
def a_func(a1, a2):
    print(f"传入的值为{a1}和{a2}")
    return a1 ** a2

print("相加的值为：",(lambda x, y:x + y)(a_func(10,2),3))

# 输出：传入的值为10和2
# 相加的值为： 103
```
可以看到在这个例子中，有多个语句的使用了具名函数，而简单计算使用了匿名函数

---
## 装饰器
装饰器是Python中一个强大的语法糖，其作用是在不改变函数原有结构的前提下，给函数添加新的功能

其基本结构如下：
``` Python
def a_func(func):
    # body
    func()

@a_func
def m_func():
    # body
    return None

m_func()
```

给出基本结构后，接下来给出例子：
``` Python
def a_func(func):
    def s_func():
        print("在装饰器执行之前")
        func()
        print("在装饰器执行之后")
    return s_func

@a_func
def m_func():
    print("正在执行装饰器")

m_func()

# 输出：在装饰器执行之前
# 正在执行装饰器
# 在装饰器执行之后
```

接下来来逐一讲解一下：

首先，一开始函数定义的时候，便会自动执行以下步骤
``` Python
m_func = a_func(m_func)
```

此时`m_func`就相当于`a_func()`返回的值，也就是`s_func()`，后面调用`m_func()`实际上是调用`s_func()`

接下来就是正常执行了，也就是执行`m_func()`，但实际上是`s_func()`

这里可能就有人要问了，诶，那我看`s_func()`里面有个外部参数`func()`啊，怎么没有传来呢？

其实这里一开始就传进来了，我们可以看到这里，还记得一开始`m_func`是怎么变成`s_func`的吗？没错！`m_func = a_func(m_func)`，这里其实已经传进值了，并且由于内部函数`s_func()`是个闭包，这里的参数没有因为`return`而被销毁


### 常见的装饰器
接下来来讲讲Python中常见的装饰器，主要有`计时器`、`日志`、`权限验证`
#### 计时器
首先来讲讲计时器，计时器是装饰器的一个常见的用途，用于记录函数运行的时间，下面给出一个例子来说明：
``` Python
import time
import functools

def timer(func):
    @functools.wraps(func)
    def check(*args, **kwargs):
        start_time = time.time()
        result = func(*args, **kwargs)
        end_time = time.time()
        print(f"函数{func.__name__}的执行时间为：{end_time - start_time:.4f}s")
        return result

    return check


@timer
def test1(a, b):
    time.sleep(0.5)  # 模拟耗时操作
    return a + b
 

print(test1(3,5))

# 输出：函数test1的执行时间为：0.5001s
# 8
```
接下来来逐一介绍其功能

首先是照例，函数一开始的**定义阶段**，当执行`@timer`时（一开始的时候），`test1(3,5)`转换为`check()`，顺带把两个参数丢进去闭包里面，之后开始执行`check()`，所以此时执行的实际上是`check(3,5)`

`check()`一开始先记录时间（`start_time`），之后开始执行函数`func()`（这里也就是`test1()`）在执行后便再次记录时间（`end_time`），这里两次计时是为了算出总执行时间

最后打印结果：`func.__name__`为执行的函数的名字，后面的两个时间相减便是函数执行总耗时，`:.4f`则为精确到小数点后4位（不取小数点结果则为：0.5001778602600098s）

这里需要另外补充的一点是`check(*args, **kwargs)`中`*args, **kwargs`的目的是为了传入所有的值，包括位置参数和关键字参数，这样就可以有效地避免了有参数没传进去，后面的`func(*args,**kwargs)`则是把传进的数据重新解包出来，然后再传进原函数`func()`

而一开始的`@functools.wraps(func)`是为了保存原函数的元数据，也就是`test1()`的元数据，这里如果不这样做的话，那么使用`print(test1.__name__)`的结果为`check()`而不是原先的`test1()`

#### 日志
通过使用装饰器还可以实现日志的功能：
``` Python
import functools
import logging

logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')


def log(func):
    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        logging.info(f"调用函数{func.__name__}，参数：args = {args}和 kwargs = {kwargs}")
        result = func(*args, **kwargs)
        logging.info(f"函数返回值：{result}")
        return result

    return wrapper


@log
def a_func(a1, b1):
    if a1 > b1:
        return a1 + b1
    else:
        return a1 * b1


list_1 = [(1, 3), (2, 6)]

for a, b in list_1:
    a_func(a, b)

# 输出：2025-07-29 16:12:43,548 - INFO - 调用函数a_func，参数：args = (1, 3)和 kwargs = {}
# 2025-07-29 16:12:43,548 - INFO - 函数返回值：3
# 2025-07-29 16:12:43,548 - INFO - 调用函数a_func，参数：args = (2, 6)和 kwargs = {}
# 2025-07-29 16:12:43,548 - INFO - 函数返回值：12
```

接下来来逐一讲解

首先先讲讲`logging.basicConfig()`

`level=logging.INFO`的作用的只让INFO及以上级别的日志能被输出，级别如下：`DEBUG < INFO < WARNING < ERROR < CRITICAL`

接下来是`format='%(asctime)s - %(levelname)s - %(message)s'`

这个指的是输出时的默认格式，分别是**时间**，**名称**，**具体内容**

首先还是老样子，在函数定义的时候，`a_func(a, b)`将参数传给`log(func)`，并且`a_func()`变为`wrapper()`

之后开始运行的时候，调用`wrapper()`，`*args`和`**kwargs`一开始定义的时候就被传进去了

接下来来说说`wrapper()`里面的内容

`logging.info`，的作用是输出一条`INFO`级别的信息