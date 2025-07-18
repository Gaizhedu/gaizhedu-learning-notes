# f-字符串
f-字符串（f-string）是语法糖的一种，用来代替原有的.format，具体如下：

``` Python
a = "结果为2
# 未使用f-字符串
print("1+1={}".format(a))

# 使用f-字符串
print(f"1+1={a}")
```
以上两者的输出结果相同，但使用f-字符串会更加简便

如果出现多个变量，语法糖的效果会**更加显著**

例如：
``` Python
a = "月季"
b = "牡丹"
c = "兰花"
# 未使用f-字符串
print("本店有以下花进行售卖：{}的价格是2块一束,{}的价格是3块一束{}的价格是10块一束".format(a,b,c))

# 使用f-字符串
print(f"本店有以下花进行售卖：{a}的价格是2块一束,{b}的价格是3块一束{c}的价格是10块一束")
```
从以上例子可以看到，当出现同时出现多个变量时，使用**f-字符串**会使得代码更加清晰，更加容易阅读

此外，f-string的格式化与`.format()`一致，
``` Python
a_f = 123.456
a_i = 123456
print(f"{a_f}是一个浮点数，{a_i}是一个整数，{a_f:{.1}f}精确到小数点后一位，{a_i:e}是科学计数法，{a_i:b}是{a_i}的二进制数")

# 输出：123.456是一个浮点数，123456是一个整数，123.5精确到小数点后一位，1.234560e+05是科学计数法，11110001001000000是123456的二进制数
```

其他用法与`.format()`均一致，相当于将`.format()`括号内的变量放进了**花括号{}** 里面

---
时间：2025年7月8日