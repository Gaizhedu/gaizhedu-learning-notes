# DIP
DIP指的是依赖倒置原则，属于SOLID原则中的一个内容

其核心为：高层模块不应依赖于低层模块，两者都应依赖于抽象。抽象不应依赖于细节，而细节应依赖于抽象

当然，正常人是看不懂这玩意到底想表达什么的

没关系，让我们通过一个实际的例子来说明

``` Java
public class Dip {
    public static void main(String[] args) {
        CaptchaGenerate captchaGenerate = new CaptchaGenerate();
        System.out.println("你生成的验证码为："+captchaGenerate.generate());
    }
}

class CaptchaGenerate{
    public String generate(){
        Random randomGenerate = new Random();

        StringBuilder captcha = new StringBuilder();
        for (int i = 0 ; i < 5;++i){
            int isLowerOrUpper = randomGenerate.nextInt(0,3);
            if (isLowerOrUpper == 0){
                captcha.append((char)randomGenerate.nextInt('a','z' + 1));
            }
            else if (isLowerOrUpper == 1){
                captcha.append((char)randomGenerate.nextInt('A','Z' + 1));
            }
            else {
                captcha.append((char)randomGenerate.nextInt('0','9' + 1));
            }
        }
        return String.format(captcha.toString());
    }
}
```

很明显，这个生成验证码的例子就不满足依赖倒置原则，为什么这么说呢？

首先我们回顾一下依赖倒置原则的内容是什么：**高层模块不应依赖于低层模块**

而这里是这样的

高层模块`main`通过new创建了一个叫做`CaptchaGenerate`的对象，之后通过这个对象来调用这个类的内容

这就导致了什么

假设我们需要增加新的功能，那么我就必须修改这里的内容

这里便不满足依赖导致原则的内容，并且这样也不太方便

那么我们要怎么办呢？

那么这个时候我们可以新增一个接口，而后将高层模块和低层模块都依赖于这个接口，形成依赖倒置

举个具体例子，我们可以这样写：

``` Java
import java.util.Random;

public class Dip {
    public static void main(String[] args) {
        Captcha captchaGenerate = new CaptchaGenerate();
        System.out.println("你生成的验证码为：" + captchaGenerate.generate(5));
    }
}

interface Captcha{
    String generate(int length);
}

class CaptchaGenerate implements Captcha{

    @Override
    public String generate(int length){
        Random randomGenerate = new Random();

        StringBuilder captcha = new StringBuilder();
        for (int i = 0 ; i < length;++i){
            int isLowerOrUpper = randomGenerate.nextInt(0,3);
            if (isLowerOrUpper == 0){
                captcha.append((char)randomGenerate.nextInt('a','z' + 1));
            }
            else if (isLowerOrUpper == 1){
                captcha.append((char)randomGenerate.nextInt('A','Z' + 1));
            }
            else {
                captcha.append((char)randomGenerate.nextInt('0','9' + 1));
            }
        }
        return String.format(captcha.toString());
    }
}
```

在这个改进的程序中，我们使用到了一个接口：`captcha`，并且在高层模块中，我们使用到了这个接口来创建对象

这样做有什么好处呢？

假设我们需要新增一个功能，这个功能为新创建一个只有小写字母的验证码，那么我们就可以新建一个类，之后在这个类里面重写一个新的`generate`方法即可，并不需要修改其他的东西

``` Java
class CaptchaGenerateLower implements Captcha{
    @Override
    public String generate(int length) {
        Random randomGenerate = new Random();

        StringBuilder captcha = new StringBuilder();
        for (int i = 0 ; i < length;++i){
            captcha.append((char)randomGenerate.nextInt('a','z' + 1));
        }
        return String.format(captcha.toString());
    }
}
```

在这里我们新了一个只生成小写字母验证码的方法`CaptchaGenerateLower`，这个方法的特点是，与上文的`CaptchaGenerate`一致，只接入接口并且重写方法

那么在我们需要在高层模块使用的时候，便可以这样写：
``` Java
public class Dip {
    public static void main(String[] args) {
        Captcha captchaGenerate = new CaptchaGenerate();
        System.out.println("你生成的验证码为：" + captchaGenerate.generate(5));

        captchaGenerate = new CaptchaGenerateLower();
        System.out.println("你生成的验证码为：" + captchaGenerate.generate(5));
    }
}
```

在这里我们对变量`captchaGenerate`重新赋值，将其赋值为新建对象

通过使用这种方法，我们只需要对变量重新赋值，不需要对高层模块的任何原有东西进行修改

---
最后完整代码如下：
``` Java
import java.util.Random;

public class Dip {
    public static void main(String[] args) {
        Captcha captchaGenerate = new CaptchaGenerate();
        System.out.println("你生成的验证码为：" + captchaGenerate.generate(5));

        captchaGenerate = new CaptchaGenerateLower();
        System.out.println("你生成的验证码为：" + captchaGenerate.generate(5));
    }
}

interface Captcha{
    String generate(int length);
}

class CaptchaGenerate implements Captcha{

    @Override
    public String generate(int length){
        Random randomGenerate = new Random();

        StringBuilder captcha = new StringBuilder();
        for (int i = 0 ; i < length;++i){
            int isLowerOrUpper = randomGenerate.nextInt(0,3);
            if (isLowerOrUpper == 0){
                captcha.append((char)randomGenerate.nextInt('a','z' + 1));
            }
            else if (isLowerOrUpper == 1){
                captcha.append((char)randomGenerate.nextInt('A','Z' + 1));
            }
            else {
                captcha.append((char)randomGenerate.nextInt('0','9' + 1));
            }
        }
        return String.format(captcha.toString());
    }
}

class CaptchaGenerateLower implements Captcha{
    @Override
    public String generate(int length) {
        Random randomGenerate = new Random();

        StringBuilder captcha = new StringBuilder();
        for (int i = 0 ; i < length;++i){
            captcha.append((char)randomGenerate.nextInt('a','z' + 1));
        }
        return String.format(captcha.toString());
    }
}

//输出：
//你生成的验证码为：t9p2O
//你生成的验证码为：poyot
```