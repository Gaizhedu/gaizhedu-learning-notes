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