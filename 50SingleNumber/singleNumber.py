from collections import defaultdict
from typing import List

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        res = 0
        for i in nums:
            res ^= i 
        return res 

    def singleNumberBF(self, nums: List[int]) -> int:
        fmap = defaultdict(lambda: 0)
        for i in nums:
            fmap[i] +=1
        as_tlist = list(fmap.items())
        filtered = list(filter(lambda x: x[1] == 1, as_tlist))
        return filtered[0][0]

s = Solution()
nums = [2,2,1]
a = 1
print(f"a is {a}\ns is {s.singleNumber(nums)}")

print(4^0)
print(4^1)
print(5^2)
print(7^1)
print(6^2) # wow!
nums = [4,1,2,1,2]
a = 4
print(f"a is {a}\ns is {s.singleNumber(nums)}")

nums = [1]
a = 1
print(f"a is {a}\ns is {s.singleNumber(nums)}")
