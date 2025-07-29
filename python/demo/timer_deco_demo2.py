import functools
import time

def timer(func):
    @functools.wraps(func)
    def wrapper(*args,**kwargs):
        start_time = time.time()
        result = func(*args,**kwargs)
        end_time = time.time()
        print(f"程序 {func.__name__} 的运行时间为{end_time - start_time:.6f}s")
        return result
    return wrapper


@timer
def test2(n=1000000):
    time.sleep(0.3)
    return sum(i**2 for i in range(n))

print(test2())

# 输出：程序 test2 的运行时间为0.364591s
# 333332833333500000