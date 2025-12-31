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
接下来是<html lang="zh-CN">

这个的作用是声明页面的语言，此处`zh-CN`为中文