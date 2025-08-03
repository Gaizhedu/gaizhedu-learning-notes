# 佩尔数列的多种实现方法

## 使用**for语句**
``` Python
a = [0,1]  
list_per = []  
for _ in range(10):  
    list_per.append(a[0])  
    a[0],a[1] = a[1],a[1] * 2 + a[0]  
print(list_per)
```

### 更简洁的版本
``` Python
a = [0,1]
for _ in range(10):
    a.append(a[-1] * 2 + a[-2])
print(a)
```

## 使用装饰器
``` Python
def pell(func):
    def wrapper(a, b):
        seq = []
        for _ in range(10):
            seq.append(a)
            result = func(a, b)
            a, b = b, result
        return seq

    return wrapper


@pell
def a_func(a, b):
    return b * 2 + a


print(a_func(0, 1))


```

## 使用递归函数
``` Python
def pell_list(a, b, n):

    def wrapper(j, k, c, seq):
        if c == n:
            return seq
        seq.append(j)
        j, k = k, k * 2 + j
        c += 1
        return wrapper(j, k, c, seq)

    return wrapper(a, b, 0, [])


print(pell_list(0, 1, 10))


```

## 使用魔术方法
``` Python
class Pell:
    def __init__(self,a,b):
        self.num1 = a
        self.num2 = b


    def __add__(self, all_count):
        a,b = self.num1,self.num2
        seq = []
        for _ in range(all_count):
            seq.append(a)
            a,b = b,b * 2 + a
        return seq


a2 = Pell(0,1)
a3 = a2 + 10
print(a3)

```

## 使用生成器
``` Python
def pell(a, b, n):
    for _ in range(n):
        yield a
        a, b = b, b * 2 + a


print(list(pell(0, 1, 10)))

```