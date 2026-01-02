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
