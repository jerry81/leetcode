from typing import List

class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        # sliding window/catepillar with prefix sums 
        psums = [nums[0]]
        for i in range(1,len(nums)):
            psums.append(psums[i-1] + nums[i])
        msum = 0
        lookup = {}
        head = -1
        for i in range(len(nums)):
            try:
                idx = lookup[nums[i]] # duplicate 
                to_subtract = 0 if head == -1 else psums[head+1]
                csum = psums[i-1] - to_subtract # current sum
                head = idx
                lookup =  dict(filter(lambda elem: elem[1] > idx, lookup.items()))
                lookup[nums[i]] = i
                if csum > msum:
                    msum = csum 
                    # a sum from start to end is 
                    # prefix sums end - prefix sums start 
                    # e.g. given prefix sums
                    # [4,6,10,15,21] 
                    # sum of nums[1:] is psums[4] - psums[0] 
                    # newDict = dict(filter(lambda elem: elem[0] % 2 == 0, dictOfNames.items()))
            except:
                lookup[nums[i]] = i
        # also check final sum 
        last_sum = psums[-1] - psums[head] if head > -1 else psums[-1]
        return max([msum,last_sum]) 
    
    def maximumUniqueSubarrayBRUTE(self, nums: List[int]) -> int:
        # brute force - find all unique subarrays
        max = 0
        for head in range(len(nums)):
            for tail in range(head+1, len(nums)+1):
                sub = nums[head:tail]
                if len(list(set(sub))) == len(sub): # uniqueness check
                    csum = sum(sub)
                    if csum > max:
                        max = csum
        return max 

sol = Solution()

nums = [4,2,4,5,6]
# prefix sums?
# [4,6,10,15,21]
# 21 - 4 = 17 - prefix sums useful, yes 
# 4 2 = 6  lookup 4,2
# 6 4 10  - 4 = 6 lookup 4, 2
# 5 11
# 6 17
Output = 17
print(f"expect {Output} is {sol.maximumUniqueSubarray(nums)}")

nums = [5,2,1,2,5,2,1,2,5]
# 5 2 1 lookup 5,2,1 sum 8
# 2 1 2 -> 1 2 lookup 1,2 
# 1,2,5 
# 5,2,1
Output = 8
print(f"expect {Output} is {sol.maximumUniqueSubarray(nums)}")

nums = [10000]
Output = 10000
print(f"expect {Output} is {sol.maximumUniqueSubarray(nums)}")

nums = [558,508,782,32,187,103,370,607,619,267,984,10]
Output = 5027
print(f"expect {Output} is {sol.maximumUniqueSubarray(nums)}")
