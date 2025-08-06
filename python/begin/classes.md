# 类
类（class），简单来说就是一个模版，用来表示各个事物**共同特征**，以及一些可以**执行的操作**

而实例（对象）是用类——这个模板，创建的一个实例，每个实例的属性可以不同，但其拥有的属性总数是相同的

举个例子：
假设把学生看成一个类，那么便可以用一些属性来表示他的一些特征（比如说性别，身高，体重等）

这些特征被称为**属性**

而你可以让这个学生写作业，学习，背诵等

这些操作就被称为**方法**

这个有这些属性的学生，就被成为**实例（对象）**

## 为什么要用类
看了以上的说明，可能有人就想到了`字典`也可以实现类似的功能

例如：
``` Python
xiaoming = {'name' : '小明','height' : 174, 'weight': 58}
xiaohua = {'name' : '小华','height' : 180, 'weight': 72}
```

确实，使用字典可以实现以上的功能，但是如果数量一多一复杂，用字典的方式就不够美观，并且阅读难度也上升

另外，如果用字典的话，在写一个自我介绍时要调用这些值则需要写一个函数

但如果用类的话，自我介绍可以直接封装到类中，使得代码更加紧凑

## 定义一个类
在Python中，若想要定义一个类，可以这样做:
``` Python
class Student:
    def __init__(self, name, height, weight):
        self.name = name
        self.height = height
        self.weight = weight    
```

这样，你就定义了一个叫做`Student`的类，并且包含了以下属性
- 姓名（name）
- 身高（height）
- 体重（weight）

接下来来逐一讲解各部分的内容
第一行的`class`是创建一个类，后面跟着的`Student`是这个类的名称
第二行的`def __init__()`是一个构造方法，它的作用是在创建实例时自动调用，为实例绑定属性。括号内跟着的第一个是参数名，也就是这个实例本身，用来访问这个实例的属性

例如，学生小明就是这个实例，也就是`self`，后面跟着的参数是这个实例的各个属性（例如说姓名，身高之类的）

其次，第一个参数你想叫什么就叫什么，但约定俗成是叫做`self`

接下来是这个函数内部的内容，每个`self.`代表着这个实例的属性，这里代表着每个属性都对应输入的部分

## 给类添加一个方法
在定义一个类之后，我们不妨来为这个类添加一个方法

``` Python
class Student:
    def __init__(self, name, height, weight):
        self.name = name
        self.height = height
        self.weight = weight   
    
    def introduce(self):
        print(f"学生{self.name}，身高为{self.height}cm，体重为{self.weight}kg")
xiaoming = Student(name="小明", height=174,weight=56)
```
如上面的代码所示，我们添加了一个`introduce()`的方法，同时新建了一个实例`xiaoming`

这时候可以用`xiaoming.introduce()`来调用这个方法

输出效果如下：

``` Python
# 输出：学生小明，身高为174cm，体重为56kg
```

这里的 `xiaoming.introduce()` 本质是将实例 xiaoming 作为参数传给 introduce 方法，等价于 `Student.introduce(xiaoming)`

## 添加一个实例
上文我们添加了一个实例，接下来来说明如何添加一个实例

首先，我们要让Python知道，这个实例是属于哪个类的

这里以上文的`xiaoming`为例

``` Python
xiaoming = Student()
```
这里将xiaoming指定为Student类的实例

这时候就有疑问了，要怎么填入属性呢？

其实很简单，有两种方式可以填入

首先第一种，你可以按照顺序填入，这里还是以`xiaoming`为例

这里回看上面初始化类的部分，可以发现属性的顺序是**name, height, weight**

也就是对应着**姓名，身高，体重**

这时候我们可以直接对照着顺序填下去

``` Python
xiaoming = Student("小明", 173, 56)
```
此时每一个值对应的就是相应的属性，特别要注意的是：**传入的值必须要按照属性的顺序传入**，否则会造成值的错位

当然，还有第二种填法，也就是直接告诉Python说我这个值是对应哪一个属性

这里同样给出示例

``` Python
xiaoming = Student(weight = 56, height = 173, name = "小明")
```
 
可以看到，这里没有按照 姓名，身高，体重 的顺序填，但由于告诉了Python说哪个属性对应是哪个值，所以这里的数据并不会出现错位的情况

## 修改实例属性
若想修改这个实例某个属性的值，我们可以添加一个新的方法
``` Python
    def change_weight(self, new_weight):
        self.weight = new_weight
        print(f"新体重为{self.weight}kg")
xiaoming.change_weight(58)
# 输出：新体重为58kg
```
这里可以看到，实例的属性（weight）被修改为传进方法的值（new_weight），使得这个实例的属性被修改

### 特别注意的一点
这里要注意的是，在初始化类的时候，初始化了几个属性，传入的就必须要几个属性

例如这里初始化了3个属性，那么在添加一个实例的时候就必须要填进3个属性，否则会报错！

但如果你想要让所有的实例都有相同的值，可以在构造的时候给对应的属性添加值

例如，我们添加了一个新的属性`age`，此时我想要让所有用这个类的实例的这个属性的值全部相同，可以这样做：

``` Python
class Student:
    def __init__(self, name, height, weight, age = 18):
        self.name = name
        self.height = height
        self.weight = weight
        self.age = age
```
此时这里创建实例就可以不用加`age`的值，因为在创建的时候已经自动添加了
``` Python
class Student:
    def __init__(self, name, height, weight, age = 18):
        self.name = name
        self.height = height
        self.weight = weight
        self.age = age

    def introduce(self):
        print(f"学生{self.name}，年龄为{self.age}岁，身高为{self.height}cm，体重为{self.weight}kg")
xiaoming = Student(name="小明", height=174, weight=56)
xiaoming.introduce()

# 输出：学生小明，年龄为18岁，身高为174cm，体重为56kg
```
要声明的一点是，如果在传入的时候有手动传入值，那么默认值将会被覆盖

``` Python
class Student:
    def __init__(self, name, height, weight, age = 18):
        self.name = name
        self.height = height
        self.weight = weight
        self.age = age

    def introduce(self):
        print(f"学生{self.name}，年龄为{self.age}岁，身高为{self.height}cm，体重为{self.weight}kg")
xiaoming = Student(name="小明", height=174, weight=56)
xiaoming.introduce()
xiaohua = Student(name="小华", height=174, weight=56, age =19)
xiaohua.introduce()

# 输出：学生小明，年龄为18岁，身高为174cm，体重为56kg
# 学生小华，年龄为19岁，身高为174cm，体重为56kg
```
这里小华的值就不再是原先的默认值18了，而是被改为19

## 示例
接下来将展示一些例子：
[自我介绍](../demo/class_student.py)
[银行账户查询](../demo/class_bank.py)
## 总结
这张笔记简单的介绍了Python中类的一些基础内容，同时讲了一些需要注意的点，以及如何新建一个新的类

---
[返回导航页](common_terms.md)