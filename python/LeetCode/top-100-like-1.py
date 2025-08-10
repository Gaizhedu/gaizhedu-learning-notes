from typing import List

class Solution:
    def count_smaller(self, nums: List[int],target) -> List[int]:
        n = len(nums)
        lst = []
        for i in range(n - 1):
            for o in range(i,n - i + 1):
                if nums[i] + nums[o] == target:
                    lst.append(i)
                    lst.append(o)
                    return lst
        pass

# 本地测试
if __name__ == "__main__":
    s = Solution()
    print(s.count_smaller([3,2,4],6))  # 示例