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

high_1= 100
low_1 = 1
guess_1 = 4

print(two_p(low_1,high_1,guess_1))