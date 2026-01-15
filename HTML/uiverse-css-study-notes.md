# CSS笔记
这份笔记主要记录`uiverse.io`里面那些有用的实际元素，并分析是如何实现的，其CSS中各个元素分别是什么作用

## new-shrimp-32
原地址：[new-shrimp-32](https://uiverse.io/e-coders/new-shrimp-32)

``` CSS
button {
 appearance: none;
 background-color: transparent;
 border: 0.125em solid #1A1A1A;
 border-radius: 0.9375em;
 box-sizing: border-box;
 color: #3B3B3B;
 cursor: pointer;
 display: inline-block;
 font-family: Roobert,-apple-system,BlinkMacSystemFont,"Segoe UI",Helvetica,Arial,sans-serif,"Apple Color Emoji","Segoe UI Emoji","Segoe UI Symbol";
 font-size: 16px;
 font-weight: 600;
 line-height: normal;
 margin: 0;
 min-height: 3.75em;
 min-width: 0;
 outline: none;
 padding: 1em 2.3em;
 text-align: center;
 text-decoration: none;
 transition: all 300ms cubic-bezier(.23, 1, 0.32, 1);
 user-select: none;
 -webkit-user-select: none;
 touch-action: manipulation;
 will-change: transform;
}

button:disabled {
 pointer-events: none;
}

button:hover {
 color: #fff;
 background-color: #1A1A1A;
 box-shadow: rgba(0, 0, 0, 0.25) 0 8px 15px;
 transform: translateY(-2px);
}

button:active {
 box-shadow: none;
 transform: translateY(0);
}
```

### 介绍
`appearance`的作用是：控制元素默认外观的样式是否应用，一般用于表单控件（例如这里的button）

这个属性可以让元素看起来像原生UI控件

`background-color: transparent;`，`background-color`用于设置背景颜色，此处为`transparent`，也就是透明的效果

`border`和`border-radius`均为设置边框的作用，`border-radius`为设置边框圆角半径

`box-sizing: border-box;`此处设定了一个盒模型，这个盒模型与默认的盒模型（content-box）不太一样，在传统的盒模型中，如果该盒模型尺寸为20px，边框为1px，那么总的大小为(20 + 1 x 2)px，此时如果想要精准设定尺寸为20px就会显得不太方便

那么`border-box`又是怎么样呢？这个盒模型会将总的大小设置为规定的尺寸，也就是说，如果想要为20px的大小，那么就算有边框，总尺寸依旧为20px

`cursor: pointer;`的作用是，当鼠标光标放到该元素上时，将显示为手的光标（注意，有该属性并不意味着可以点击！）

`display: inline-block;`的作用是让其有`block`和`inline`的特点

`block`独占一行，可以设置行高，`inline`不可换行，但是不能设置行高

`inline-block`则为不换行，并且可以设置行高

一般用于设定导航栏中

`margin: 0`意味着该元素与其他元素之间的间隔为0，有四个子属性，可以分别设置：`margin-top`（上），`margin-right`（右），`margin-bottom`（下），`margin-left`（左）

`min-height: 3.75em;`和`min-width: 0;`的作用均为设置最小的大小

`padding: 1em 2.3em;`意味着元素内边距的大小

第一个`1em`为上下内边距，第二个`2.3em`为左右内边距

`text-align: center;`的作用是让文本位于元素的中间位置

`text-decoration: none;`的作用是移除文字的装饰线

什么是装饰线，简单来说就是下划线，上划线，以及链接中用于注明的蓝色线条

``` CSS
 transition: all 300ms cubic-bezier(.23, 1, 0.32, 1);
```
在上面定义了transition属性的内容，实际内容为控制所有动画时间为300ms，并且速度为贝塞尔曲线

`user-select: none;`的作用是禁止用户选中元素的文本，常见的用处是提升用户的体验

`-webkit-user-select: none;`是一种兼容性的写法，用于那些基于`Webkit`的浏览器，等价于`user-select: none;`

`touch-action: manipulation;`的作用主要用于移动设备上

此处的作用是说明该元素只支持点击，拖拽等基本操作

`will-change: transform;`的作用是告诉浏览器将要启动`transform`变化，让其提前做好准备

接下来来到`disabled`选择器的内容

`pointer-events`的作用是完全禁用鼠标或者触摸的效果

接下来是`hover`的内容，这里指的是当鼠标光标位于元素上时的事情

从这里可以看到，此处改变了文字颜色为`#ffffff`，并且将背景色改为`#1A1A1A`，同时添加了一个阴影，以及将坐标平移

此处的变化不是一瞬间完成的，变化的时间与上文的`transition`属性有很大相关

接下来是`active`的内容，这一部分内容代表当前按钮被按下时的操作，此处将阴影取消，并且将原先的移动改为0，与默认一致

通过这样的操作来形成按钮按下的视觉效果