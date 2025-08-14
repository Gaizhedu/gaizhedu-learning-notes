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
        for i in range(1,n + 1):
            if lst_m[0] >= lst_m[i]:
                lst_l.append(lst_m[i])
            else:
                lst_r.append(lst_m[i])
        body(lst_l)
        tmp[tmp_ptr] = lst_m[0]
        tmp_ptr += 1
        body(lst_r)
        return tmp

    tmp_ptr,lst_ptr = 0,0
    return body(lst)


arr = [5,3,4,2,8,9,10,1,7,6]
print(a_func(arr))
