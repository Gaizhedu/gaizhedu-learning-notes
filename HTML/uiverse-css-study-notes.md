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