# CSS3
这篇文档将介绍CSS3的各个属性

## color
`color`的作用是设置文字颜色

基本语法如下：
``` HTML
<h1 style="color: #333333">Hello World!</h1>
```

这个属性带有可以被继承，例如：
``` HTML
<div id="wrapper" style="color: #AACAFE">
    <h1>Hello World!</h1>
    <p>This is my first website</p>
</div>
```
上面的例子中，由于继承，使得下面的两段文字颜色都变成指定的颜色

如果想要指定更改颜色，可以在指定的标签内重写：
``` HTML
<div id="wrapper" style="color: #99CAFE">
    <h1 style="color: #55CAFE;">Hello World!</h1>
    <p>This is my first website</p>
</div>
```

这个标签不仅支持十六进制，还支持通过单词等多种形式来表示颜色

所有的可用颜色可以在这里找到：[W3School](https://www.w3schools.com/colors/colors_names.asp)

使用的方法很简单，只需要把原来的`color="十六进制"`改为`colotr="代表颜色的单词"`即可

``` HTML
<div id="wrapper" style="color: paleturquoise">
  <h1 style="color: #55CAFE;">Hello World!</h1>
  <p>This is my first website</p>
</div>
```

除了使用单词，还可以使用不同的格式，如RGB
``` HTML
<div id="wrapper" style="color: paleturquoise">
  <h1 style="color: RGB(111,111,111);">Hello World!</h1>
  <p>This is my first website</p>
</div>
```

## font-family
`font-family`的作用是设定显示的字体组，如果某文字无法以A字体显示，那么会自动尝试之后的字体

``` CSS
body{
  font-family: Arial, Helvetica, sans-serif;
}
```
上面的三个字体是最为常用的字体，也是比较推荐的默认设置

## font-size
`font-size`的作用是设置字体的大小

``` CSS
#wrapper p {
  font-size: 1.5rem;
}
```
此处的作用是将该段落的字体大小设置为`1.5rem`

`rem`的意思是全局的`fort-size`（默认为16px），此处为1.5为的默认大小

### 预设关键字
除了使用一些单位，还可以通过一些预设的关键字来精准调控字体大小

例如`x-large`、`xx-large`、`x-small`

如果想要使用默认值，则可以使用`medium`

## font-weight
`font-weight`的作用是设置字体的粗细

这个属性有以下关键字可选`normal`、`bold`、`bolder`、`lighter`

或者更加建议的是直接使用数值

常见的数值为：400（默认），700（粗体），300（细体）

``` CSS
#wrapper p {
  font-weight: 200;
}
```
在上面这个例子便将字体的粗细设置成200

## font-style
这个属性的作用是设置字体为斜体

仅能通过设置关键字来调整是否为斜体，一般默认为`normal`（无斜体）

斜体有两种方式，一种是直接使用字体文件自带的斜体格式：`italic`，还有一种是直接将字体倾斜的斜体：`oblique`

``` CSS
#wrapper h1 {
  font-style: italic;
}
```

## text-align
`text-align`的作用是设置文本的对齐方法，使用的模式为关键字

比较常用的关键字有`left`、`right`、`center`、`justify`

默认为`left`，代表向左对齐，适用于一些常规的文字

`right`可以用于导航栏等样式，`center`则为水平居中对齐，`justify`为两端对齐

如果想要设定默认的话可以使用`start`，这个的作用是设定对齐方向是当前书写方向的起始边

同理`end`则设定为当前书写方向的结束边

## text-decoration
`text-decoration`的作用是设置文本的各种线，例如删除线，下划线，上划线等

使用的格式如下：
``` CSS
text-decoration: 线的类型 线的样式 线的颜色;
```

一些常见的关键字如下：

线的类型：`none`默认，无线条，`underline`下划线，`overline`上划线，`line-through`上划线

线的样式：`solid`实线，`double`双线，`dotted`点线，`dashed`虚线，`wavy`波浪线

第三个线的颜色同上文的`color`标签，可以使用十六进制，或者是RGB等关键字

举一个具体例子：

``` CSS
#wrapper .sentence {
  color: #99CAFE;
  font-size: 20px;
  font-weight: 600;
  text-decoration: underline overline solid #90CCCC ;
}
```
在上面这个例子中，我们设定了该文本的下划线为上划线和下划线两种形式，并且均为实线类型，颜色为`#90CCCC`

此外，如果不想这样直接设置，也可以分别设置其子属性：

``` CSS
#wrapper .sentence {
  color: #99CAFE;
  font-size: 20px;
  font-weight: 600;
  text-decoration-line: underline overline;
  text-decoration-style: solid;
  text-decoration-color: #90CCCC;
}
```
分别设置子属性可以使得操作更加精细

## text-transform
`text-transform`属性的作用是设置文本的大小写，可以通过不同的关键字来设定不同的类型

常见的关键字有`capitalize`（首字母大写），`uppercase`（全部大写），`lowercase`（全部小写）

默认为`none`

需要注意的点是，设置这个属性后并不会影响原文本，只是渲染上发生了改变，原文本并不会发生改变

``` CSS
#wrapper h1 {
  color: #767676;
  text-align: center;
  font-style: italic;
  text-transform: uppercase;
}
```

## line-height
`line-height`的作用是调整行与行之间的间隔，调整时可以通过多种方式调整

需要特别注意的一点是，调整行高不仅影响文字上下间距，还影响了行框的高度

``` CSS
#wrapper p {
  font-size: 1.25rem;
  text-align: left;
  line-height: 1.2;
}
```
在上面的例子中，我们将行高设置为1.2，也就是`font-size`的1.2倍

## letter-spacing
`letter-spacing`的作用是调整这段文字中各个字符之间的间隔

这个参数可以设置为整数，也可以为负数，如果为负数则可以实现文本重叠的效果

``` CSS
#wrapper .sentence2{
  letter-spacing: 20px;
}
```
上面的例子设置文本间隔为20像素（实际上很宽了）

## word-spacing
`word-spacing`的作用是调整单词与单词之间的间隔，分割的标准为空格

也就是说，该属性影响的是句子中有空格的部分

可以理解为这个属性会调整空格的长度

``` CSS
#wrapper .sentence2{
  color: #99CAFE;
  word-spacing: 16px;
}
```
上面的例子中我们将两个由空格分割的单词之间的间隔的大小设定为16px

## white-space
`white-space`属性的作用是设定HTML对于空格的默认处理

这里需要先介绍一下HTML对与空格的处理

在默认情况下，HTML对于空格的处理如下：

> 将连续的空白字符折叠为一个空格，并忽略行首行尾的空白

使用这个属性可以忽略这些限制

例如：`pre-wrap`关键字是保留原状并且允许自动换行，如果不想要自动换行可以使用`pre`关键字

接下来给出更多的关键字：`pre-line`将多个空格合并为一个，但是保留换行符（默认不保留），并且允许自动换行

`nowrap`的作用是与默认(normal)类似，不过取消了自动换行的功能，这一特性可以用于显示一些一行表达的文字

`break-spaces`是一个较为新的关键字，可以保留所有的空白字符，并且必要的时候可以换行（行尾连续空格），与`pre-wrap`的区别在此

``` CSS
#wrapper .sentence2{
  color: #99CAFE;
  white-space: pre-wrap;
}
``` 

## text-indent
`text-indent`的作用为控制首行缩进，让第一行文本向右偏移一段距离

允许使用负值，如果为负值则向左偏移

``` CSS
#wrapper p {
  text-indent: 2em;
}
```

需要注意的一点是，`text-indent`只作用于块级元素的**第一行文本**，对于内嵌元素是无效的

## text-shadow
`text-shadow`的作用是给文本添加文字阴影

格式如下
``` CSS
text-shadow: h-offset v-offset blur-radius color;
```
`h-offset`代表该阴影的水平偏移量，如果为0意味着在水平方向上与原来的文本是重叠的

`v-offset`代表该阴影的垂直偏移量，如果为0意味着在垂直方向上与原来的文本是重叠的

`blur-radius`代表该阴影的模糊半径，数值越大越模糊，该参数可选填，默认为0

`color`代表该阴影的颜色，该参数选填，默认继承`currentColor`

其中`h-offset`和`v-offset`为必填项

这个参数支持多重阴影：
``` CSS
h1 {
  text-shadow:
    0 0 5px white,
    0 0 10px yellow,
    0 0 15px orange;
}
```

## width / height
`width`和`height`代表盒模型的宽和高

通过设置这两个属性可以控制盒元素的大小

其基本语法如下：

``` CSS
width: length | percentage | auto | min-content | max-content | fit-content |
```

其中，`length`代表当前元素的长度，可以使用绝对长度或者是相对长度

`percentage`代表相对于包含块的宽度或高度

`min-content`和`max-content`代表元素可能最大尺寸

`fit-content`代表根据可用空间自适应，不超过指定的值，也不小于所需最小值