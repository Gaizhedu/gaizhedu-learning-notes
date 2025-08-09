# 大O表示法
大O表示法是算法中用于描述算法复杂度的一个数学符号，用于表示算法执行时间随着输入增长的趋势

大O表示法关注在最坏情况下算法效率的上限，利用这一特点，可以帮助我们比较不同算法的效率，从而得出最优的算法

## 时间复杂度
接下来介绍一下常见的时间复杂度

### 常数时间
常数时间指的是`O(1)`

这个时间复杂度的特点是算法执行的时间不随规模的变化而变化，一般为固定的运行方式：

``` Python
l = [1, 2, 3, 4, 5]
print(l[0])

```
在上面这个例子中，`l[0]`的时间复杂度便为`O(1)`，因为无论列表`l`的长度为多少，`l[0]`运行时间始终不变，所以为`O(1)`

### 对数时间
对数时间指的是`O(log n)`

这个的运算时间会随着n的增大而增大，其增长特点是对数增长（一般来说是以2为底的对数）

常见的例子有二分法，比如说一个长度为100的数列，要在其中找到30这个数，用一般的方法需要找30次

而使用二分法就只需要7次即可找到：

``` Python
def two_p(low, high, guess):
    if low > high or guess > high or guess < low:
        print("数据输入错误")
        return None
    steps = 1
    while True:
        middle = int((high + low) / 2)
        if middle == guess:
            break
        elif middle > guess:
            steps += 1
            high = middle - 1
        else:
            steps += 1
            low = middle + 1
    return steps


high_1 = 100
low_1 = 1
guess_1 = 30

print(two_p(low_1, high_1, guess_1))

# 输出：7
```
在上面这个例子中，由于最大值为`100`，那么**最大需要7次**才能找到（2 ^ 7 = 128）

### 线性时间
线性时间是指`O(n)`

这个时间复杂度的特点是时间与输入n成正比，换言之就是n越大，要求的时间也就越多

``` Python
l = range(1,100)
target = 20

for i in l:
    if i == target:
        print(f"目标数为：{i}")

# 输出：目标数为：20
```
在上面这个例子中，由于查找目标数需要遍历整个列表，这就导致了如果n越大，所需要的时间也就越多

符合线性时间的标准，所以时间复杂度为`O(n)`

### 线性对数时间
线性对数时间指的是`O (n log n)`

常见的场景为分治策略

接下来举一个例子来说明，这里用到的例子为**归并排序**
``` Python

```

### 平方时间
平方时间指的是O(n$^2$)

特点是执行时间与n成正比，一般会在嵌套循环的时候出现

接下来举一个冒泡排序的例子
``` Python
def bub(acc):
    n = len(acc) - 1
    a_list = acc
    for i in range(n):
        for o in range(n - i):
            if a_list[o] > a_list[o + 1]:
                a_list[o], a_list[o + 1] = a_list[o + 1], a_list[o]
    return a_list


ra_list = [4, 3, 5, 2, 6, 1]
print(bub(ra_list))
```

这里由于执行次数为：`(n - 1) + (n - 2) + (n - 3) ...`

表现为一个等差数列，其求和便存在n$^2$，所以时间复杂度为O(n$^2$)（(n$^2$ + n) / 2）

### 指数时间
指数时间的时间复杂度的表示方式为：O(2$^n$)

特点是运行时间随着n呈指数增长，所以一旦n变大，其运行效率便会变得**极低**

``` Python
def pell(n):
    if n <= 1:
        return 1
    return pell(n - 1) * 2 + pell(n - 2)


print(pell(10))

```
在上面这个例子中，由于每运行一次都会再次执行两次`pell()`——直到n为1

所以这里的时间复杂度为O(2$^n$)