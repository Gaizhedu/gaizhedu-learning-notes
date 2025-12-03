# I/O操作

这份笔记将介绍有关Java中的一些I/O操作

在写这份笔记之前，我们需要了解一下自己的工作目录

``` Java
System.out.println(System.getProperty("user.dir"));
```

使用上面这个语句便可以获得自己当前的工作目录，这一点很重要

## 读取文件
首先先从读取文件开始，我们这里通过一个例子来逐步讲解

``` Java
try (BufferedReader br = new BufferedReader(
        new InputStreamReader(
                new FileInputStream("src/test.txt")
        ))){
    String reading;
    while ((reading = br.readLine()) != null) {
        System.out.println(reading);
    }
}
```
这里使用了一个`try-with-resource`语句，作用是在使用完文件后不需要自己手动关闭文件

如果不选择`try-with-resource`，则需要这么写：

``` Java
BufferedReader br = new BufferedReader(
        new InputStreamReader(
                new FileInputStream("src/test.txt")
        ));
String reading;
while ((reading = br.readLine()) != null) {
    System.out.println(reading);
}
br.close();
```

在上面的例子中，我们读取了一个文件，并将这个文件的每一行逐一打印了出来

在这其中有一些需要介绍的东西，例如`BufferedReader`、`InputStreamReader`、`FileInputStream`、`readLine()`，接下来逐一开始介绍

### FileInputStream
首先是最基本的**FileInputStream**

这个方法的作用很简单，以字节的形式读取本地文件，读取范围为0~255，读取完成的时候返回 **-1**

举一个例子：
``` Java
try (FileInputStream fis = new FileInputStream("src/test.txt")) {
    int reading;
    while ((reading = fis.read()) != -1) {
        System.out.println(reading);
    }
}
// 输出(片段)：
// 233
// 155
// 170
// 229
// 156
// 176
```

可以看到，这里输出了一些编码

上面虽然我们输出了一些内容，但那些内容我们**完全看不懂**，需要转换成我们可以看懂的内容

这时候便可以介绍下一个实现类了