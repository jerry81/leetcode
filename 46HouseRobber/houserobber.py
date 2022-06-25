from typing import List


class Solution:
    def maxR(self, nums, nums2, remain):
        return 

    def rob(self, nums: List[int]) -> int:
        # try greedy first
        cidx = 1
        csum = nums[1]
        if nums[0] > nums[1]:
            cidx = 0
            cidx = nums[0]
        while True:
          cidx1 = cidx+2
          cidx2 = cidx+3
          if cidx1 > len(nums):
            return csum 
          if cidx2 > len(nums):
            return csum + nums[cidx1]
        # return self.maxR(sum1,sum2,nums1,nums2)

s=Solution()
nums = [1,2,3,1]
a= 4
print(f"a {a}\n{s.rob(nums)}")

nums = [2,7,9,3,1]
a = 12
print(f"a {a}\n{s.rob(nums)}")

"""
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
"""
10
1
10,1
1,1
10, 

"""

nums = [10,1,1,10,1,10,1]
a = 30 
# seeing some similarities with stair climbing
# step 1 or step 2 
# first step - 0 or 1 