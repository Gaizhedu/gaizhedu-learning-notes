# 基础内容
> 这篇笔记将介绍HTML中的基础内容

## 基础框架
HTML的基础框架如下：

``` HTML
<!DOCTYPE html>
<html lang="zh-CN">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>页面标题</title>
</head>
<body>

</body>
</html>
```

首先介绍第一行`<!DOCTYPE html>`

这个的作用是声明文档类型，此处声明为HTML，如果没有这一行，或者是使用了错误的DOCTYPE，那么浏览器可能会出现一些问题

后面的`html`不分大小写，这个声明需要写在文件的最顶部的位置

---
接下来是`<html lang="zh-CN">`

这个的作用是声明页面的语言，此处`zh-CN`为中文


### head
`<head>`标签的作用是用于包含页面的元数据，也就是关于页面的内容，这部分内容用户**不会直接看到**

``` HTML
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>页面标题</title>
</head>
```

---
接下来是两个meta的标签

其中第一个`<meta charset="UTF-8">`意为设置编码为UTF-8，而第二个代表设置页面的尺寸和缩放

`<meta name="viewport">`，指明设定的窗口为控制视口，

而`content="width=device-width, initial-scale=1.0"`则是对该视口的具体设置

`width=device-width`为将该视口的宽度等同于设备屏幕宽度

`initial-scale=1.0`代表页面初始加载时缩放比例，此处为1.0

在`<head>`标签内有一个`<title>`标签，用于设置任务栏上面的标题

除此之外，如果需要设置任务栏显示的图标，可以在`<head>`标签内加上这一句

``` HTML
<link rel="icon" href="favicon.ico" type="image/x-icon">
```
其中`link`标签可以在当前文档和外部资源间建立连接，而属性`rel`为指明后面的资源是什么类型，此处`icon`为图标。后面的`href`为该资源的**相对链接**，此处为`favicon.ico`，说明与该文档是同一目录下，`type`用于声明文件的文件格式，`image/x-icon`为icon文件的文件格式

> PNG为type="image/png"
> SVG为type="image/svg+xml"

### body
`body`标签用于存放这个页面可以看到的内容

首先我们需要认识一些基本的页面元素

`<h1> ~ <h6>`，这个元素的作用是声明标题，其中`h1`最大，`h6`最小
``` HTMl
<h1>主标题</h1>
<h2>副标题<h2>
```

`<p>`代表段落文字，如：
``` HTML
<p>这是一段文字</p>
```

`<a>`代表超链接，后面加上`href`元素代表链接指向的地址

``` HTML
<a href="https://example.com">超链接例子</a>
```

`<img>`代表图片，可以通过添加`scr`属性来指明资源的地址，`alt`属性用于描述图片，如果当资源不存在时会显示该文字，`title`属性用于指明鼠标指针移动到该图片时显示的文字

`<ul>`和`<ol>`均代表列表，但是`<ul>`代表有序列表，而`<ol>`代表无序列表

``` HTML
<ul>
  <li>Apple</li>
  <li>Banana</li>
</ul>
<ol>
  <li>星期一</li>
  <li>星期二</li>
</ol>
```

每个列表的元素需要使用`<li>`标签来包围