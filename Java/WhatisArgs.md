# String[] args
这份笔记来聊聊main括号后面跟着的`String[] args`到底是什么

## 正文
说得简单粗暴点，这个的意思是代表在使用java语句运行时后面跟着的一些参数

举个例子：
``` Shell
javac WhatisArgs.java
java WhatisArgs 这是后面跟着的参数
```
那么在此时，字符串数组`args`的第一项就是：`这是后面跟着的参数`

是的，就是这么简单粗暴

这里分割项的标准是空格，每出现一个空格就会自动多出一项

---
那么要怎么获取到这些传进来的参数呢？这玩意本质也是个变量，所以像平时使用变量那样就行了

我们来动手写一个例子：
``` Java
public class WhatisArgs {
    public static void main(String[] args) {
        if (args.length == 0){
            System.out.println("没有参数进来");
        }
        else {
            System.out.println("传进参数长度：" + args.length);
            for (int i = 0; i < args.length;++i) {
                System.out.printf("传进参数第%d项为：%s\n", i+1, args[i]);
            }
        }
    }
}
```
在上面这个例子中，我们用`args.length`获取到输入参数的长度，如果长度不为0（为零就是没参数了），那么则将传入的所有项分别打印出来

我们不妨试试看效果：
![](assets\args_1.png)

在上面这个例子中，我们输入了
``` Shell
java WhatisArgs 你好 这有一个空格 所以这句话被分割成几项了
```

相当于传入了后面那些内容

第一项为`你好`

而第二项为`这有一个空格`

第三项为`所以这句话被分割成几项了`

那么想要在一项中包含空格怎么办呢？

很简单，只需要把对应的部分用双引号包起来即可：

![](assets/args_2.png)

从简单的角度出发，这个字符串数组相当于一个外界与程序连接的通道