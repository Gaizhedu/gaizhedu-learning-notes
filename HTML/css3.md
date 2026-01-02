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