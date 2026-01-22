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

总体上来说，这个元素是一个按钮的类型，边框大小为固定，不会随着边框粗细来调整大小

## tidy-pig-67
原地址：[tidy-pig-67](https://uiverse.io/LightAndy1/tidy-pig-67)

``` HTML
<div class="group">
  <svg viewBox="0 0 24 24" aria-hidden="true" class="search-icon">
    <g>
      <path
        d="M21.53 20.47l-3.66-3.66C19.195 15.24 20 13.214 20 11c0-4.97-4.03-9-9-9s-9 4.03-9 9 4.03 9 9 9c2.215 0 4.24-.804 5.808-2.13l3.66 3.66c.147.146.34.22.53.22s.385-.073.53-.22c.295-.293.295-.767.002-1.06zM3.5 11c0-4.135 3.365-7.5 7.5-7.5s7.5 3.365 7.5 7.5-3.365 7.5-7.5 7.5-7.5-3.365-7.5-7.5z"
      ></path>
    </g>
  </svg>

  <input
    id="query"
    class="input"
    type="search"
    placeholder="Search..."
    name="searchbar"
  />
</div>
```

``` CSS
.group {
  display: flex;
  line-height: 28px;
  align-items: center;
  position: relative;
  max-width: 190px;
}

.input {
  font-family: "Montserrat", sans-serif;
  width: 100%;
  height: 45px;
  padding-left: 2.5rem;
  box-shadow: 0 0 0 1.5px #2b2c37, 0 0 25px -17px #000;
  border: 0;
  border-radius: 12px;
  background-color: #16171d;
  outline: none;
  color: #bdbecb;
  transition: all 0.25s cubic-bezier(0.19, 1, 0.22, 1);
  cursor: text;
  z-index: 0;
}

.input::placeholder {
  color: #bdbecb;
}

.input:hover {
  box-shadow: 0 0 0 2.5px #2f303d, 0px 0px 25px -15px #000;
}

.input:active {
  transform: scale(0.95);
}

.input:focus {
  box-shadow: 0 0 0 2.5px #2f303d;
}

.search-icon {
  position: absolute;
  left: 1rem;
  fill: #bdbecb;
  width: 1rem;
  height: 1rem;
  pointer-events: none;
  z-index: 1;
}
```

### 介绍
首先先从HTML部分看起

可以看到这里有一个标签为：`svg`，意味着下面的那部分画出了一个形状，此处为放大镜

接下来看到CSS

首先第一个`group`，`display: flex;`将元素设置为一个块级的弹性盒子容器，`line-height`设置了行高，`align-items: center;`对齐容器内的所有子元素在交叉轴上的位置，`position: relative;`将元素间的位置设定为相对位置，`max-width: 190px;`设置元素的最大宽度为190像素

接下来是input的内容，此处为输入框内的输入内容，用于显示输入的文字

此处部分属性在之前的button中已经有说明，这里只会补充部分内容

`cursor: text;`，上文的按钮为`cursor: pointer;`，这里的`text`则代表当光标放在该元素上时，变为可以输入文本的光标样式，这里来提醒用户可以输入

`z-index: 0;`的意思是控制定位元素的层叠顺序，数字越大，那么元素在视觉就越靠前，默认的值为0

需要注意的一点是，如果`position`为`static`，那么这个属性无效

接下来是`transform: scale(0.95);`

此处的scale(0.95)意为将原先的尺寸缩小至原本大小的0.95倍

可以通过这个效果来模拟按动按钮的效果

接下来是`search-icon`中的`pointer-events: none;`，意思是禁用鼠标的交互事件