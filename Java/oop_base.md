# 面向对象的内容
今天来讲讲有关面向对象（OOP）的相关内容，在介绍这部分的内容的时候，将会使用一个实际的例子来分别介绍各个功能

主要围绕**继承，封装，多态**这三个方面的内容来介绍

## 引入
现在恭喜你，你拥有了一家店铺，那么此时你需要为你的店铺添加一些东西来维持生计，同时，由于你需要交房租，所以如果没有合理售出一些东西的话，你的店铺便会被查封，所以，是时候来开启一家店铺了

那么我们要怎么开启一家店铺呢？很简单，只需要设置物品名称，类别和价格就行了

## 类
既然我们需要分类，不妨这里先创建一个大的类`Goods`，这时候可能有人就要晕了：我不知道要怎么创建啊！

没事，这里最基本的框架是这样的：
``` Java
class [类名称]{
   [内容]
}
```

诶，是不是很简单呢！那么让我们创建一个商品的类吧：
``` Java
class Goods{

}
```

很明显，只有这些内容是完全不行的，还需要有一些实际的内容

让我们想想看，作为一个商品，你需要什么东西呢？

商品名是必须要有的吧，类别也必须要有的吧，价格也必须要有的吧

很好，那么我们便可以开始创建这三个东西了

首先要先对这三个内容起个名字

商品名就叫做`name`，由于是名字，所以类型得设置成字符串：
``` Java
String name;
```

同理，类别我们可以设置成type：
``` Java
String type;
```

这时候便要设置价格了，称为`price`倒是没错，但是类型要选什么呢？

我们可以思考一下，生活中的价格不可能只有整数，肯定是有小数的，所以这里便选择了double类型（为什么不使用float呢？一般来讲价格是不会超出限制的，但万一就一不小心超出呢？所以以防万一，这里设置成double要安心得多，再加上Java里面，默认的小数类型便是double，所以这里也就使用这个了）

> ~~当然你说选择BigDecimal，这也没问题，但是现在没必要用这玩意，超纲了！！！！！~~

首先我们需要初始化这些变量：
``` Java
class Goods{
   String name;
   String type;
   double price;
}
```
好的，在成功设置完这一部分的基础内容之后，我们便要开始进入正题了

假设我们需要创建一个商品，那么就必须得把这些属性赋予这个商品

不可能说初始化一个变量就自动赋予这个商品，这不合理，所以必定有赋予商品属性的方法

``` Java
class Goods{
    String name;
    String type;
    double price;

    public Goods(String name, String type, double price){
        this.price = price;
        this.name = name;
        this.type = type;
    }
}
```
在这里我们在这个类里面创建了一个公共的构造方法：Goods，眼尖的同学可以发现这个名字跟我们的类是一样的，没错！利用这个方法便可以将对应的属性绑定到这个类上

举个具体的例子，假设我有个一个商品为矿泉水，在没有这个方法绑定属性的时候他是没有任何属性的，包括名字，类别，价格都没有

但是，当我们使用这个方法后，这个商品就赋予了这三个属性

这里真正发挥作用的是这里：
``` Java
this.price = price;
this.name = name;
this.type = type;
```
`this`指的是这个东西，而后面的.xxx指的是这个东西的这个属性

这里就有人要问了，我上哪里去找这些东西呢？如果我想新增属性想要怎么办呢？

这些.xxx的来源是一开始初始化的那里：
``` Java
    String name;
    String type;
    double price;
```
在一开始我们定义了这三个属性，此时只需要输入this.xxx就可以绑定属性了

如果没有在一开始初始化，那么就不能绑定属性

---
再举一个例子：我想新增一个属性：数量（nums）

假设没有先初始化：
``` Java
class Goods{
    String name;
    String type;
    double price;

    public Goods(String name, String type, double price){
        this.price = price;
        this.name = name;
        this.type = type;
        this.nums = 10;// 此处并没有初始化数量
    }
}
```
那么程序便不知道这个数量是什么类型，自然也就会报错了

解决的方法也很简单，只需要将这个数量(nums)初始化即可：

``` Java
class Goods{
    String name;
    String type;
    double price;
    int nums;// 东西总不能是半个的吧，所以这里用整数类型

    public Goods(String name, String type, double price){
        this.price = price;
        this.name = name;
        this.type = type;
        this.nums = 10;// 此处已经由上文初始化了，所以不会报错
    }
}
```
在成功绑定属性之后，我们就可以来创建这个商品了

我们需要回到main的那个地方

但是这里就有疑问了，诶，要怎么创建商品呢

具体的框架如下：
``` Java
[类名称] [变量名] = new [类名称](属性详细值)
```
举个例子：

我们想要创建一个叫做water的对象，这个是矿泉水，类别为饮料，价格为2块

首先回想一下，类的名称是什么？通过回看可以发现，这里商品类的名称为Goods，所以这里可以填写为：

``` Java
Goods water = new Goods();
```
那接下来，要怎么填写名称这些属性呢？

我们不妨回看之前的`public Goods`的那个地方

可以发现后面跟着的括号内容为：`String name, String type, double price`

这里分别为：名字，类别，价格

我们在填写属性的时候，**必须**要根据顺序来填写，既然这里是名字，类别，价格，那么在填写的时候就必须要按照这个顺序

``` Java
Goods water = new Goods("矿泉水", "饮料", 2);
```
很好，我们成功创建一个新的商品

---
接下来就是要实现显示商品和购买的功能了

首先，顾客是不知道有什么商品的，所以我们要将商品显示在顾客面前

这里如果直接在main里面写输出语句，虽然可以做到效果，但是如果商品一多，就不是很方便了，所以我们要在这个类里面创建一个方法，专门用于输出对应的商品信息

那么要怎么创建呢？基本的框架如下：
``` Java
[是否为公共对象] [返回值类型] [方法名](){

}
```
> 这里的公共对象需要到多文件管理的时候才来具体说明，这里举例子就全部设置为公共的啦！

我们想要创建一个专门用来打印商品信息的方法，命名为`showGoods()`

由于这个方法只是打印而已，并没有返回任何东西，所以返回值类型为`void`

所以，这个方法这样写：

``` Java
public void showGoods(){
    System.out.println("商品：" + name + " 类型：" + type + " 价格：" + price);
}
```
这里的`name、type、price`对应的是这个商品的各个属性

那么在完成这个方法之后呢，我们便要使用这个方法，那么问题就来了，如何使用这个方法

假设这里我们需要展示的是我们之前创建的一个商品矿泉水（water），只需要在main里面写上这个便可以对其使用这个方法

``` Java
water.showGoods();
```

具体的结构为：
``` Java
这个物品的变量名.想要使用的方法;
```

比方说我们这里想要对矿泉水（water）使用这个方法，那么在点号之前的变量名便是我们之前创建的变量名，后面的便是我们刚才声明的方法（showGoods）

接下来，这个要放到哪里去呢？

我们不妨想想看程序主要运行什么地方的语句，没错，便是main()，所以要把这个放到main里面去

``` Java
    public static void main(String[] args) {
        Goods water = new Goods("矿泉水", "饮料", 2);
        water.showGoods();
    }
```
那么购买物品也是同理，这里就不展示过程了，最后，让我们看看我们写的内容

``` Java
public class NewShop {
    public static void main(String[] args) {
        Goods water = new Goods("矿泉水", "饮料", 2);
        water.showGoods();
    }
}

class Goods {
    String name;
    String type;
    double price;

    public Goods(String name, String type, double price) {
        this.price = price;
        this.name = name;
        this.type = type;
    }

    public void showGoods(){
        System.out.println("商品：" + name + " 类型：" + type + " 价格：" + price);
    }
    
    public void buyGoods(){
        System.out.println("商品：" + name + "成功购买");
    }
}


// 输出：
// 商品：矿泉水 类型：饮料 价格：2.0
// 商品：矿泉水成功购买
```

## 封装
接下来我们来进行下一项内容

这一天你突然发现一件严重的事情，你的营业额突然之间少了一半！！！这对你来说可以是个大灾难，因为如果没有及时发现，那么利润便会大大减少，最后甚至交不起房租了

所以你要赶紧找到问题所在，通过查看代码你发现了问题所在：
``` Java
public class NewShop {
    public static void main(String[] args) {
        Goods water = new Goods("矿泉水", "饮料", 2);
        water.showGoods();
        water.price = 1;
        water.buyGoods();
    }
}
```

你发现代码里面出现了一个设置价格的语句，没错，虽然在创建的时候将价格设置为2，但是有坏孩子偷偷在你展示完商品后，将价格设置为1

你思来想去，打算解决这个问题，这时候就需要用到一个东西了，那就是**封装**

---
封装是这样的，将一个对象的元素保护起来，不能外界修改

封装的核心是这个：`private`关键字

那么我们要怎么用呢？很简单，我们不妨思考一下这个属性是从哪里来的

没错，便是在对应的类里面：
``` Java
class Goods {
    String name;
    String type;
    double price;
    ...//此处省略
}
```
要不被外面修改，我们只需要在声明的时候加上这个关键字即可：
``` Java
class Goods {
    private String name;
    private String type;
    private double price;
    ...//此处省略
}
```
这样，外界就没办法修改你的这个属性了

---
问题又来了，随着物价增长，你发现矿泉水成本飞涨，这时候只有涨价才能保住自己不喝西北风

这时你想要修改价格，但是你想起来自己用封装保护住属性了，难道没办法修改吗？

当然不是，封装只是防止外界修改，在类里面仍然可以被修改

所以，我们可以写一个方法，通过接收对应的参数来修改价格

``` Java
class Goods{
    ...// 省略前面的内容
    public void setPrice(double newPrice){
        this.price = newPrice;
        System.out.println("商品" + name + "的新价格为： " + price);
    }
}
```
在这个方法中，我们在括号里面声明了一个参数`newPrice`，这个参数可以在外部调用这个方法的时候接收输入的值

而里面的核心语句为将调用这个方法的对象的价格（属性price）设置为接收到的价格

下面，让我们使用这个方法，看看效果如何：
``` Java
public static void main(String[] args) {
    Goods water = new Goods("矿泉水", "饮料", 2);
    water.showGoods();
    water.setPrice(3);
    water.buyGoods();
}

// 输出：
// 商品：矿泉水 类型：饮料 价格：2.0
// 商品矿泉水的新价格为： 3.0
// 商品：矿泉水成功购买
```
可以看到，矿泉水的价格被设置为3块了，这样就成功解决了问题

## 继承
接下来介绍继承的内容

随着日子渐渐增长，你货架上的东西越来越多，并且有些商品的属性也变多了起来，食物有保质期，武器有攻击力

此时你发现，如果总是用Goods，那么也太混乱了，所以你打算用多个类来存放不同的物品

但是，如果每次创建新类的时候都要写一样的内容，那也太不优雅了

有没有可以减少重复劳动的操作呢？当然有，那就是**继承**

继承的核心是这个关键字：`extends`

具体的框架长这样：
``` Java
class [子类] extends [父类/超类]{
    ...// 此处省略内容
}
```
假设我们要新建一个食物的类，那么我们可以这么写：

``` Java
class Food extends Goods{

}
```
接下来的事情很简单了，只需要往里面填充内容即可

那么要填充什么内容呢，如果是食物的话，那肯定得有保质期，并且由于这个类为食物，那么在大类Goods里面的声明类也可以去除了，直接在食物这个类里面写清楚即可：

``` Java
class Food extends Goods{
    private int shelfLife;
}
```

``` Java
class Goods {
    ...//省略内容
    public Goods(String name, double price) {
        this.price = price;
        this.name = name;
        this.type = "其他";
    }
    ...//省略内容
}
```

接下来就是要让食物类使用父类Goods的一些属性了，这里跟之前创建新类的时候是一样的方法：
``` Java
public Food(String name,double price,int shelfLife){
    
}
```
诶，这里可能有人要问了，这个类并没有像大类Goods一样初始化属性啊，是不是出问题了

其实不然，这也是继承的优点：**不用重复初始化元素**

这里我们需要使用到这个语句：`super()`

这个语句括号内填的内容为大类里面的属性名称，既然有括号，就到了老生常谈的顺序问题了

这里的填入顺序是什么呢？

这里的顺序与大类绑定属性那里有关，我们来看看Goods的这一部分代码 ：

``` Java
class Goods {
    ...//省略内容
    public Goods(String name, double price) {
        this.price = price;
        this.name = name;
        this.type = "其他";
    }
    ...//省略内容
}
```
可以看到，在绑定属性的时候，括号内使用了两个参数，第一个为商品名（name），第二个为价格（price）

所以，在`super()`的括号内填入的顺序也得是这个顺序，**先名字，后价格**

``` Java
public Food(String name,double price,int shelfLife){
    super(name,price);
    this.type = type;
    this.shelfLife = shelfLife;
}
```

需要注意的一点是，`super()`需要放到最前面，也就是说下面这种写法是错误的：
``` Java
public Food(String name,double price,int shelfLife){
    this.type = type;
    super(name,price); // 错误写法，super()要放到第一位
    this.shelfLife = shelfLife;
}
```

接下来，由于这个类属于食物，如果是食物，那就得在展示的时候显示出其保质期，这里我们可以使用继承中的一个功能，那就是**重写**

这个功能有什么作用呢？简单来讲就是将父类有的方法重写一遍

我们上面的展示商品的方法`showPrice`内容如下：

``` Java
public void showGoods(){
    System.out.println("商品：" + name + " 类型：" + type + " 价格：" + price);
}
```
但这个商品介绍并没有说明保质期，要是顾客买到临期食品，那店大概率是开不下去的

所以我们便要重写这个方法，而重写需要用到这个东西：`@Override`

具体用法就是在这个的下一行写上你要重写的方法：

``` Java
@Override
public void showGoods(){
    System.out.println("商品：" + name + " 类型：" + type + " 价格：" + price + " 保质期：" + shelfLife);
}
```
需要注意的是，**建议**每次重写一个方法就使用一次@Override来注明该方法被重写

---
这里有人就发现一件事情了，诶，为什么我没办法使用来自父类`Goods`的属性name和price啊

这里就得回到封装的内容了

在封装的时候，为了保护价格不被外界改动，我们使用了关键字`private`，这个关键字十分严格，即使是子类也没办法使用

那就没有任何办法了吗？当然不是，这里还有一个关键字：`protected`

这个关键字也可以起到保护的作用，但是却允许子类访问

所以我们可以改成这样：
``` Java
class Goods {
    protected String name;
    protected String type;
    protected double price;
    ... // 省略内容
}
```
在修改之后，我们便可以让子类Food正常的使用父类Goods的属性啦

子类Food的代码如下：
``` Java
class Food extends Goods{
    private int shelfLife;

    public Food(String name,double price,int shelfLife){
        super(name,price);
        this.type = "食物";
        this.shelfLife = shelfLife;
    }

    @Override
    public void showGoods(){
        System.out.println("商品：" + name + " 类型：" + type + " 价格：" + price + " 保质期：" + shelfLife);
    }
}
```
这里可能有人会产生这样的疑问了，诶，这里的`this.type = "食物";`是为什么

首先，在Goods绑定参数时括号内只有两个参数，这也就意味着会向外收取两个参数对应的值

而这里不能忘记的一点是，在大类Goods里面，有一个属性是被我们写死的：`this.type = "其他";`这里也就意味着，我们并不需要对外接受这个属性的值

但是Food是继承了Goods的属性的（如果使用private关键字就不会继承了），所以Food同样拥有这个属性`type`，而我们想要修改这个属性，只需要重新指定一下就行
 
## 多态
接下来将讲一下多态的内容

在完成子类的有关内容后，就要对新的商品进行初始化了

你发现你的商品大类都是Goods，而其他的类都是其子类，所以在创建商品的时候你选择了一种相对简洁的做法：

> 下面的例子创建了一个新的子类Drink，第三个参数500为容量，同样的，这也是Goods的一个子类
``` Java
public static void main(String[] args) {
    Goods water = new Drink("矿泉水", 2, 500);
    Goods bread = new Food("面包", 3, 5);
}
```
为什么要使用这种形式呢？

一方面是因为这样会更加简洁，如果使用这样：

``` Java
public static void main(String[] args) {
    Drink water = new Drink("矿泉水", 2, 500);
    Food bread = new Food("面包", 3, 5);
}
```
虽说也不会报错，但是，假设你将来想要让其他人管理商店，一眼看去是不知道这两个类是Goods的子类的

所以，使用第一种写法，会让人更加清楚的知道什么类可以使用什么方法

---
## 结语
在忙完初始化商品之后，你总算把商店开起来了，为了让更多人可以享受到这样的便利，你决定把自己的代码分享出来：
``` Java
public class NewShop {
    public static void main(String[] args) {
        Goods water = new Drink("矿泉水", 2,500);
        Goods bread = new Food("面包", 3, 5);
        water.showGoods();
        water.setPrice(3);
        water.buyGoods();
        System.out.println("=========== 分割商品 ===========");
        bread.showGoods();
        bread.buyGoods();
    }
}

class Goods {
    protected String name;
    protected String type;
    protected double price;

    public Goods(String name, double price) {
        this.price = price;
        this.name = name;
        this.type = "其他";
    }

    public void showGoods(){
        System.out.println("商品：" + name + " 类型：" + type + " 价格：" + price);
    }

    public void buyGoods(){
        System.out.println("商品：" + name + "成功购买");
    }

    public void setPrice(double newPrice){
        this.price = newPrice;
        System.out.println("商品" + name + "的新价格为： " + price);
    }
}

class Food extends Goods{
    private int shelfLife;

    public Food(String name,double price,int shelfLife){
        super(name,price);
        this.type = "食物";
        this.shelfLife = shelfLife;
    }

    @Override
    public void showGoods(){
        System.out.println("商品：" + name + " 类型：" + type + " 价格：" + price + " 保质期：" + shelfLife);
    }
}

class Drink extends Goods{
    private int volume;

    public Drink(String name,double price,int volume){
        super(name,price);
        this.type = "饮料";
        this.volume = volume;
    }

    @Override
    public void showGoods(){
        System.out.println("商品：" + name + " 类型：" + type + " 价格：" + price + " 容量：" + volume + "mL");
    }
}

// 输出：
// 商品：矿泉水 类型：饮料 价格：2.0 容量：500mL
// 商品矿泉水的新价格为： 3.0
// 商品：矿泉水成功购买
// =========== 分割商品 ===========
// 商品：面包 类型：食物 价格：3.0 保质期：5
// 商品：面包成功购买
```