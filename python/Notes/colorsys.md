# colorsys
colorsys是Python中的一个模块，其作用为实现各类颜色之间的转换

其方法在`__all__`中展现：
``` Python
__all__ = ["rgb_to_yiq","yiq_to_rgb","rgb_to_hls","hls_to_rgb","rgb_to_hsv","hsv_to_rgb"]
```

接下来先展示各个方法的源代码以及如何使用

## rgb_to_yiq(r, g, b)
``` Python
def rgb_to_yiq(r, g, b):
    y = 0.30*r + 0.59*g + 0.11*b
    i = 0.74*(r-y) - 0.27*(b-y)
    q = 0.48*(r-y) + 0.41*(b-y)
    return (y, i, q)
```
实际运行：

``` Python
import colorsys

print(colorsys.rgb_to_yiq(100/255,100/255,100/255))

# 输出：(0.39215686274509803, 0.0, 0.0)
```
需要注意的一点是，这里方法内数的范围为**0~1**

### 源码分析
首先可以看到，这个方法定义了三个参数，分别对应三原色

而后面的计算部分是一个简单的计算，作用是通过一定的运算规律，将RGB转换成YIQ

最后返回的结果是对应的YIQ颜色

## def yiq_to_rgb(y, i, q)
``` Python
def yiq_to_rgb(y, i, q):
    # r = y + (0.27*q + 0.41*i) / (0.74*0.41 + 0.27*0.48)
    # b = y + (0.74*q - 0.48*i) / (0.74*0.41 + 0.27*0.48)
    # g = y - (0.30*(r-y) + 0.11*(b-y)) / 0.59

    r = y + 0.9468822170900693*i + 0.6235565819861433*q
    g = y - 0.27478764629897834*i - 0.6356910791873801*q
    b = y - 1.1085450346420322*i + 1.7090069284064666*q

    if r < 0.0:
        r = 0.0
    if g < 0.0:
        g = 0.0
    if b < 0.0:
        b = 0.0
    if r > 1.0:
        r = 1.0
    if g > 1.0:
        g = 1.0
    if b > 1.0:
        b = 1.0
    return (r, g, b)
```
实际应用：
``` Python
import colorsys

print(colorsys.yiq_to_rgb(100/255,100/255,100/255))

# 输出：(1.0, 0.035106382162212374, 0.627632115201739)
```

### 源码分析
这个方法的计算还是相对来说比较简单的，不同于上面的RGB，这里在末尾处还多了一个判断是否超过范围的

## def rgb_to_hls(r, g, b)
``` Python
    maxc = max(r, g, b)
    minc = min(r, g, b)
    sumc = (maxc+minc)
    rangec = (maxc-minc)
    l = sumc/2.0
    if minc == maxc:
        return 0.0, l, 0.0
    if l <= 0.5:
        s = rangec / sumc
    else:
        s = rangec / (2.0-maxc-minc)  # Not always 2.0-sumc: gh-106498.
    rc = (maxc-r) / rangec
    gc = (maxc-g) / rangec
    bc = (maxc-b) / rangec
    if r == maxc:
        h = bc-gc
    elif g == maxc:
        h = 2.0+rc-bc
    else:
        h = 4.0+gc-rc
    h = (h/6.0) % 1.0
    return h, l, s
```
实际应用如下：
``` Python
import colorsys

print(colorsys.rgb_to_hls(20/255,30/255,40/255))

# 输出：(0.5833333333333334, 0.11764705882352941, 0.3333333333333333)
```
首先先说明一下转换的原理：

HLS分别对应的是**色相（Hue）、明度（Lightness）、饱和度（Saturation）**

---
首先从最简单的讲起：明度

首先先要获取RGB三个数中的最大值，记为`Max`

还要获取最小值，记为`Min`

而明度的计算公式就是**最大值加最小值的和除以二**

实际代码如下：
``` Python
maxc = max(r, g, b)
minc = min(r, g, b)
sumc = (maxc+minc)
l = sumc/2.0
```

---
接下来是饱和度

首先要先看看这个颜色是否为灰度

灰度的特征是**最大值等于最小值**，也就是`Max == Min`

如果出现这种状况，则**饱和度为0**

如果不为灰度的话，还需要看明度的情况

如果明度>=0.5

那么此时的饱和度的计算方式为：`最大值 - 最小值 / 最大值 + 最小值`

反之则为`最大值 - 最小值/2 - 最大值 - 最小值`

这里对应的代码部分为：
``` Python
    if l <= 0.5:
        s = rangec / sumc
    else:
        s = rangec / (2.0-maxc-minc)
```

另外最大值等于最小值的情况，将合并到下面的色相部分来讲

---
接下来是色相

与饱和度相同，如果最大值与最小值相等，则**色相为0**

如果最大值不等于最小值的话

则根据最大值来进行运算

如果最大值为R：

色相则为：60° * ((G - B)/(最大值 - 最小值)除以6的余数)

如果最大值为G：

色相则为：60° * ((B - R)/(最大值 - 最小值) + 2)

如果最大值为B：

色相则为：60° * ((R - G)/(最大值 - 最小值) + 4)

相应的代码为：
``` Python
rc = (maxc-r) / rangec
gc = (maxc-g) / rangec
bc = (maxc-b) / rangec
if r == maxc:
    h = bc-gc
elif g == maxc:
    h = 2.0+rc-bc
else:
    h = 4.0+gc-rc
h = (h/6.0) % 1.0
```
这里`rc`、`gc`、`bc`可以看到分别是对不同值的处理

而后面的判断最大值之后的操作，在化简之后可以发现`maxc`被消除

而在最后面的`h = (h/6.0) % 1.0`中

`(h/6.0)`对应的是`60°`，而后面的`% 1.0`的作用是限制最后h的范围在`**[0,1)**`中

