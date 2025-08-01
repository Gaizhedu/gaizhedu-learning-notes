def hexadecimal(n):
    if n == 0:
        return "000000"

    def re_check():
        for i in range(0,6 - len(l)):
            l.insert(0,"0")
        return ''.join(l)

    l = []
    c = ["0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f"]
    def to_hexadecimal(num):
        while num > 0:
            l.insert(0,c[num % 16])
            num //= 16
        return re_check()
    return to_hexadecimal(n)

print(hexadecimal(2845934))