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

