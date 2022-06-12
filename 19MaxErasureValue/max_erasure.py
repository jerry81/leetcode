from typing import List

class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        # sliding window/catepillar with prefix sums 
        psums = [nums[0]]
        for i in range(1,len(nums)):
            psums.append(psums[i-1] + nums[i])
        print(f"psums is {psums}")
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
                print(f"csum is {csum} aka {psums[i-1]} - {to_subtract}")
                print(f"updated lookup is {lookup}")
                print(f"updated head is {head}")
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
        print(f"head is {head}")
        last_sum = psums[-1] - psums[head]
        print(f"lastsum {psums[-1]} minus {psums[head+1]}")
        print(f'last_sum {last_sum}')
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