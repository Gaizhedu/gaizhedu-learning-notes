# 快速排序
排序的方法有很多，在之前已经介绍了[冒泡排序](bubble_sort.md)这种排序方法

冒泡排序虽然代码比较简单，但由于存在双循环的原因，其时间复杂度达到了O(n$^$2)

接下来来讲一个新的排序方法**快速排序**

通过一个例子来说明具体的用法：

``` Python
def a_func(lst):
    tmp = [0] * len(lst)

    def body(lst_m):
        nonlocal tmp_ptr, lst_ptr
        n = len(lst_m) - 1
        if n == 0:
            tmp[tmp_ptr] = lst_m[0]
            tmp_ptr += 1
            return None
        elif not lst_m:
            return None
        lst_l, lst_r = [], []
        for i in range(1, n + 1):
            if lst_m[0] >= lst_m[i]:
                lst_l.append(lst_m[i])
            else:
                lst_r.append(lst_m[i])
        body(lst_l)
        tmp[tmp_ptr] = lst_m[0]
        tmp_ptr += 1
        body(lst_r)
        return tmp

    tmp_ptr, lst_ptr = 0, 0
    return body(lst)


arr = [5, 3, 4, 2, 8, 9, 10, 1, 7, 6]
print(a_func(arr))

```