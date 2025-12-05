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

## 写入文件

既然有读取文件，那便有写入文件的操作，接下来将介绍一下写入的部分操作

首先通过一个简单的例子来说明一下：

``` Java
try (FileOutputStream fos = new FileOutputStream("src/test.txt", true)) {
    fos.write("Hello！".getBytes());
} catch (FileNotFoundException e) {
    System.out.println("找不到写入文件");
} finally {
    System.out.println("已完成操作");
}
```

``` Java
try (FileWriter fw = new FileWriter("src/test.txt", true)) {
    fw.write("Hello");
} catch (FileNotFoundException e) {
    System.out.println("找不到写入文件");
} finally {
    System.out.println("已完成操作");
}
```

``` Java
try (BufferedWriter bw = new BufferedWriter(new FileWriter("src/test.txt", true))) {
    bw.write("Hello！");
} catch (FileNotFoundException e) {
    System.out.println("找不到写入文件");
} finally {
    System.out.println("已完成操作");
}
```
上面的三个例子都实现了文件的写入，但是实际有一些不同，接下来将逐一开始介绍

### FileOutputStream
首先是最基本的**FileOutputStream**

这个方法的作用是以字节的形式写入文件，一般用于**图片，音频**这些用字节表示的文件

首先先看签名，由于`FileOutputStream`的重载方法的数量相当多，这里只介绍一些比较常见的

比较常见的有这两个：
``` Java
public FileOutputStream(String name)

public FileOutputStream(String name, boolean append)
```
这两个签名的区别主要在第二个参数上

第二个参数的意思是是否以追加模式写入

什么是追加模式呢？

假设这是我原来的文本内容
``` test.txt
Hello!This is test.
```

如果我选择了追加模式写入，那么会变成这个结果

``` test.txt
Hello!This is test.Hello!
```
但如果我选择没有参数的版本，或者是在第二个参数选择了`false`

那么会是这个结果：

``` test.txt
Hello!
```
可以看到，这里原本的内容不见了，只剩下我们写入的内容了，换言之就是将原本的内容清空，而后将新内容写入

那么我们要怎么写入文件呢？

接下来从例子开始分析：

``` Java
try (FileWriter fw = new FileWriter("src/test.txt", true)) {
    fw.write("Hello");
} catch (FileNotFoundException e) {
    System.out.println("找不到写入文件");
} finally {
    System.out.println("已完成操作");
}
```

可以很明显的看到写入文件使用了`write()`

需要特别注意的一点是，由于`FileOutputStream`写入的内容为字节，所以括号内要填的内容为数字

诶，这里可能有人要问了，为什么上面例子写的是字符串呢？实际上是因为后面加上了`.getBytes()`的原因

这个方法的作用是返回该字符串在当前编码中的编码

在Java10以后，如果没写指定编码，那么会默认为`UTF-8`，相当于下面的这个语句

``` Java
fos.write("Hello！".getBytes(StandardCharsets.UTF_8));
```

如果使用的Java版本小于10，那么则需要加这个语句，但如果大于10，那么可以选择不加

由于这里使用了`try-with-resource`结构，所以是没有`.close()`的

如果不是该结构的话，那么还需要在末尾加一句`.close()`

> FileOutputStream基础部分只需要认识write()和close()即可，
> 其他的一些方法（例如：getChannel()和getFD()）并不在这里的探讨范围

#### 补充点：有关源代码
事实上，我们从源代码中可以发现一些有趣的点：

``` Java
public FileOutputStream(String name) 
    throws FileNotFoundException 
{
    this(name != null ? new File(name) : null, false);
}

public FileOutputStream(String name, boolean append)
    throws FileNotFoundException
{
    this(name != null ? new File(name) : null, append);
}
```
可以看到，这里的两个方法的实现实际上没有太大差别，唯一的一个不同点在三元表达式上

只有一个参数的版本，三元表达式默认为false，而使用两个参数的版本则将这个交由append决定

---
### FileWriter
我们从上面的例子中可以看到，对于日常的文件写入，`FileOutputStream`并不是很方便

为什么说不是很方便呢？假设我们想要写入一个字符串，那么我们需要将这个字符串通过`.getBytes()`来转换成正确的格式，并且如果想要让其正确显示文本，还得考虑编码的问题

**这太麻烦了！**

那么如果我们想要往一个文档里面写入字符串，要怎么办才可以比较轻松呢？

其实很简单，我们可以使用**FileWriter**

``` Java
try (FileWriter fw = new FileWriter("src/test.txt", true)) {
    fw.write("Hello");
} catch (FileNotFoundException e) {
    System.out.println("找不到写入文件");
} finally {
    System.out.println("已完成操作");
}
```

FileWriter的作用是以文本的形式，将对应的字符串或者字符数据写入文件，

简单来说就是可以不用自己转换了！

在Java11以后，FileWriter会自动处理编码（默认为UTF-8）

当然，如果需要，也可以自己设置：

``` Java
FileWriter fw = new FileWriter("src/test.txt", StandardCharsets.UTF_8, true)
```

具体签名如下：
``` Java
FileWriter(String fileName, Charset charset, boolean append)
```

### BufferedWriter
接下来是**BufferedWriter**，这个方法有什么作用呢？

实际上，如果从实现的角度看，这个方法的作用跟`FileWriter`的作用是一样的

那么这个方法有什么作用呢？其实很简单，这个方法多了一个缓冲的作用

这样说可能有点晕晕的，我们不妨举个例子来说明

假设你有一天心潮澎湃，想要使用`FileWriter`把《红楼梦》复制到一个新的文件，假设写入成功，那么会执行多少次IO操作呢？

> 虽然说有人会认为这玩意没缓存，但其实FileWriter底层是有缓存的

答案是差不多200多次，那么我们如果使用BufferedWriter呢？只需要大约90次

这是为什么呢？答案是因为BufferedWriter里面有一个缓存区，默认为8192字节大小

缓存区的意思在之前也提及到了，简单来说就是不同于之前的来一个操作一次，有缓存区是写满才操作一次

这样做的好处是可以大大减少操作次数，提高效率

``` Java
try (BufferedWriter bw = new BufferedWriter(new FileWriter("src/test.txt", true))) {
    bw.write("Hello！");
} catch (FileNotFoundException e) {
    System.out.println("找不到写入文件");
} finally {
    System.out.println("已完成操作");
}
```
这个方法的签名如下：
``` Java
public BufferedWriter(Writer out, int sz)
```
第二个参数代表缓冲区的大小，可以自己设置