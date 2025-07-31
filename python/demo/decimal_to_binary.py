def binary(m):
    if m == 0:
        return ["0"]
    def a_func(n,l):
        if n % 2 == 0:
            l.insert(0,"0")
            return a_func(n//2,l)
        elif n == 1:
            l.insert(0,"1")
            return l
        else:
            l.insert(0,"1")
            return a_func((n-1)//2,l)
    return a_func(m,[])

print(binary(200))