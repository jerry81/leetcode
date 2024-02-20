from collections import defaultdict
from typing import List

class Solution:
    def rob(self, nums: List[int]) -> int:
        # edge cases
        if len(nums) == 1:
            return nums[0]
        if len(nums) == 0:
            return 0
        if len(nums) == 2:
            return max(nums[0], nums[1])
        # main loop 
        memo = defaultdict(lambda: 0)
        memo[0] = nums[0]
        memo[1] = nums[1]
        for i in range(2, len(nums)):
          memo[i] = max(nums[i] + memo[i-3], nums[i] + memo[i-2], memo[i-1])
        return max(list(memo.values()))

    def robGreedy(self, nums: List[int]) -> int:
        # try greedy first
        cidx = 1
        csum = nums[1]
        if nums[0] > nums[1]:
            cidx = 0
            csum = nums[0]
        while True:
          cidx1 = cidx+2
          cidx2 = cidx+3
          if cidx1 >= len(nums):
            return csum 
          if cidx2 >= len(nums):
            return csum + nums[cidx1]
          if nums[cidx1] > nums[cidx2]:
            csum += nums[cidx1]
            cidx = cidx1
          else:
            csum += nums[cidx2]
            cidx = cidx2 
        # return self.maxR(sum1,sum2,nums1,nums2)

s=Solution()
nums = [1,2,3,1]
a= 4
print(f"a {a}\n{s.rob(nums)}")

nums = [2,7,9,3,1]
a = 12
print(f"a {a}\n{s.rob(nums)}")

"""
memoize max at every idx?
max[0] = 1
max[1] = max(nums[1], max[0]) = 2
max[2] is max(max[0] + nums[2], max[1]) = max(4, 2) = 4
max[3] is max(nums[3] + max[1, max[2])] = max(3, 4) = 4
2,9,1
7,3
2,3
7,3
"""

nums = [1,2,3,1,2,7,9,3,1]
a = 16
print(f"a {a}\n{s.rob(nums)}")
"""
1,3,2,9,1  = 16
2,1,7,3,1 = 14
"""

nums = [10,1,1,10,1,1,10]
a = 30
print(f"a {a}\n{s.rob(nums)}")
"""
10
1
10,1
1,1
10, 

"""

nums = [10,1,1,10,1,10,1]
a = 30 
print(f"a {a}\n{s.rob(nums)}")
# seeing some similarities with stair climbing
# step 1 or step 2 
# first step - 0 or 1 

nums = [2,1,1,2]
a = 4
print(f"a {a}\n{s.rob(nums)}")