def fibonacci(j,k,p):
    l = []
    def list_1(a,b,c):
        if c == 0:
            return l
        else:
            l.append(a)
            return list_1(b,a+b,c-1)
    return list_1(j,k,p)

print(fibonacci(0,1,10))