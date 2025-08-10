from typing import List

class Solution:
    def count_smaller(self, nums: List[int]) -> List[int]:
        j,k = 0,0
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[k] = nums[i]
                i += 1
                k += 1
            else:
                nums[k] = nums[i]
                i += 1
                j += 1
        for o in range(j):
            nums[k+o] = 0


# 本地测试
if __name__ == "__main__":
    s = Solution()
    print(s.count_smaller([0,0,0,2,3,4,5]))  # 示例