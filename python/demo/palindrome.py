def palindrome(lst):
    left_ptr, right_ptr = 0, len(lst) - 1
    while left_ptr < right_ptr:
        if lst[left_ptr] != lst[right_ptr]:
            return False
        left_ptr += 1
        right_ptr -= 1
    return True


arr = [1, 2, 3, 3, 2, 1]
print("是回文" if palindrome(arr) else "不是回文")
