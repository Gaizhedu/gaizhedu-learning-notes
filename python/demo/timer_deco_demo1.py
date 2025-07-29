import time
import functools

def timer(func):
    @functools.wraps(func)
    def check(*args, **kwargs):
        start_time = time.time()
        result = func(*args, **kwargs)
        end_time = time.time()
        print(f"函数{func.__name__}的执行时间为：{end_time - start_time:.4f}s")
        return result

    return check


@timer
def test1(a, b):
    time.sleep(0.5)  # 模拟耗时操作
    return a + b


print(test1(3,5))

# 输出：函数test1的执行时间为：0.5001s
# 8