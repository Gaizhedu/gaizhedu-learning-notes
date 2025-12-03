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

### InputStreamReader
这个方法的签名如下：
``` Java
public InputStreamReader(InputStream in, Charset cs)
```
其中第一个代表传入的内容，第二个代表用什么方式解码

我们以之前的内容为例子：

``` Java
try (InputStreamReader isr = new InputStreamReader(new FileInputStream("src/test.txt"), StandardCharsets.UTF_8)) {
    int reading;
    while ((reading = isr.read()) != -1) {
        System.out.println(reading);
    }
}

// 输出：
// 38634
// 22320
// 29190
// 35010
// 65292
// 21943
```
诶，这里为什么输出还是无意义的数字呢？实际上这里输出的内容为Unicode的十进制码

那我们要怎么转换成中文呢？有两种方法，第一种方法为通过强制转换来转换：

``` Java
try (InputStreamReader isr = new InputStreamReader(new FileInputStream("src/test.txt"), StandardCharsets.UTF_8)) {
    int reading;
    while ((reading = isr.read()) != -1) {
        // 从int转换为char
        System.out.println((char)reading);
    }
}

// 输出（片段）：
// 雪
// 地
// 爆
// 裂
// ，
// 喷
// 出
// 整
// 片
// 沸
// 腾
// 的
// 海
// 。
```

或者是：
``` Java
try (InputStreamReader isr = new InputStreamReader(new FileInputStream("src/test.txt"), StandardCharsets.UTF_8)) {
    int reading;
    char[] buffer = new char[1024];
    while ((reading = isr.read(buffer)) != -1) {
        // 从int转换为char
        System.out.println(new String(buffer,0,reading));
    }
}

// 输出：
// 雪地爆裂，喷出整片沸腾的海。
// 海水未落，已在空中凝成千座尖锐高山，刺穿星空。
// 星群碎裂，残光拧成一道炽白银河，横劈山体。
// 山崩时没有声音，只涌出深黑的雪，覆盖了海的源头。
// 银河骤然倒卷，把自己塞进一粒冰晶——
// 冰晶坠入虚空，炸成一片静止的海，
// 而雪，正从海底升起，烧穿天顶。
```
这种写法是什么意思呢？

首先新建一个长度1024字符的char数组，之后`isr.read(buffer)`，代表每次读入1024个字符

这样的好处是可以一次性读取多个字符，如果是`isr.read()`，那么一次读取一个字符就太慢了

接下来是`new String(buffer,0,reading)`，代表创建一个新的字符串，字符串内容为buffer的内容，读取顺序从0开始读取，从reading结束

由于我们这里这段文字的长度小于1024，所以会直接读取一整段，如果大于1024，那么会分为多次进行读取

我们可以通过这个例子来说明读取多次的效果：
``` Java
try (InputStreamReader isr = new InputStreamReader(new FileInputStream("src/test.txt"), StandardCharsets.UTF_8)) {
    int reading;
    char[] buffer = new char[50];
    while ((reading = isr.read(buffer)) != -1) {
        // 从int转换为char
        System.out.println(new String(buffer,0,reading));
        System.out.println(reading);
    }
}

// 输出：
// 雪地爆裂，喷出整片沸腾的海。
// 海水未落，已在空中凝成千座尖锐高山，刺穿星空。
// 星群碎裂，残光拧成
// 50
// 一道炽白银河，横劈山体。
// 山崩时没有声音，只涌出深黑的雪，覆盖了海的源头。
// 银河骤然倒卷，把自己
// 50
// 塞进一粒冰晶——
// 冰晶坠入虚空，炸成一片静止的海，
// 而雪，正从海底升起，烧穿天顶。
// 43
```
可以看到，这里每读取50个字符便停止，之后进入下一次的读取

那么第二种方法是什么呢？

### BufferedReader
第二种方法是使用BufferedReader

这个方法有两种签名：

``` Java
public BufferedReader(Reader in)

public BufferedReader(Reader in, int sz)
```

BufferedReader是一个自带char数组的缓冲类（默认大小为8192）

如果想要修改默认大小，可以选择带有两个参数的签名，并修改第二个参数的大小

接下来给出一个实际的例子：

``` Java
try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("src/test.txt"), StandardCharsets.UTF_8))) {
    String reading;
    while ((reading = br.readLine()) != null) {
        System.out.println(reading);
    }
}
// 输出：
// 雪地爆裂，喷出整片沸腾的海。
// 海水未落，已在空中凝成千座尖锐高山，刺穿星空。
// 星群碎裂，残光拧成一道炽白银河，横劈山体。
// 山崩时没有声音，只涌出深黑的雪，覆盖了海的源头。
// 银河骤然倒卷，把自己塞进一粒冰晶——
// 冰晶坠入虚空，炸成一片静止的海，
// 而雪，正从海底升起，烧穿天顶。
```
这里使用了`BufferedReader`特有的一个方法：`readLine()`

作用为读取一行文本，不包括行终止符（例如\n或者\r\n）

不过需要注意的一点是，如果读取的时候遇到了空白行，那么会显示空白内容，而不是`null`

由于readLine并不会保留换行符，如果想要保留这些符号，得使用read(char[])来处理

至此，有关读取文件的部分已经完成