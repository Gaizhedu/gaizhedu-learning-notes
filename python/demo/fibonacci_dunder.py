class Fibonacci:
    def __init__(self,num1,num2):
        self.num1 = num1
        self.num2 = num2
        self.list = []

    def a_func(self,n):
        for _ in range(n):
            self.list.append(self.num1)
            self.num1, self.num2 = self.num2,self.num1+self.num2
        return self.list


    def __add__(self, n):
        return self.a_func(n)

    def __str__(self):
        return f"{self.list}"

a1 = Fibonacci(0,1)
a2 = a1 + 10
print(a2)