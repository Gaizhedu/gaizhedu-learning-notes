from typing import List

class Solution:
    def count_smaller(self, nums: List[int]) -> List[int]:
        n = len(nums)
        counts = []
        for i in range(n):
            ans = 0
            for o in range(n - i - 1):
                if nums[i] > nums[-o-1]:
                    ans += 1
            counts.append(ans)
        return counts

# 本地测试
if __name__ == "__main__":
    s = Solution()
    print(s.count_smaller([5, 2, 6, 1]))  # 示例