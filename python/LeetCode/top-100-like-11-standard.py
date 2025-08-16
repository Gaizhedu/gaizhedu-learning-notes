def max_rainwater(height):
    left_ptr, right_ptr = 0, len(height) - 1
    max_water = 0
    while left_ptr < right_ptr:
        water_square = min(height[left_ptr], height[right_ptr]) * (right_ptr - left_ptr)
        if height[left_ptr] > height[right_ptr]:
            right_ptr -= 1
        else:
            left_ptr += 1
        if water_square >= max_water:
            max_water = water_square
    return max_water


arr = [1,8,6,2,5,4,8,3,7]
print(max_rainwater(arr))