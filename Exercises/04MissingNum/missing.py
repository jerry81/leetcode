from typing import List


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        l = len(nums)
        sor = sorted(nums)
        for i in range(l):
            if i != sor[i]:
                return i 
        return l
        
s = Solution()
nums = [3,0,1]
print(f"expect 2 {s.missingNumber(nums)}")

nums = [9,6,4,2,3,5,7,0,1]
print(f"expect 8 {s.missingNumber(nums)}")

nums = [0,1]
print(f"expect 2 {s.missingNumber(nums)}")