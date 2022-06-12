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
            # print(f"lookup is {lookup}")
            try:
                idx = lookup[nums[i]] # duplicate 
                to_subtract = 0 if head == -1 else psums[head]
                csum = psums[i-1] - to_subtract # current sum
                head = idx
                # number of items in lookup at this point is i - idx 
                
                la = list(lookup.items())
                la = la[(i-idx+1):]
                la.append((nums[i], i))
                lookup = dict(la) # this is an N operation 
                # slice instead of filter much faster
                # lookup[nums[i]] = i
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

nums = [449,154,934,526,429,732,784,909,884,805,635,660,742,209,742,272,669,449,766,904,698,434,280,332,876,200,333,464,12,437,269,355,622,903,262,691,768,894,929,628,867,844,208,384,644,511,908,792,56,872,275,598,633,502,894,999,788,394,309,950,159,178,403,110,670,234,119,953,267,634,330,410,137,805,317,470,563,900,545,308,531,428,526,593,638,651,320,874,810,666,180,521,452,131,201,915,502,765,17,577,821,731,925,953,111,305,705,162,994,425,17,140,700,475,772,385,922,159,840,367,276,635,696,70,744,804,63,448,435,242,507,764,373,314,140,825,34,383,151,602,745]
Output = 30934
print(f"expect {Output} is {sol.maximumUniqueSubarray(nums)}")
nums = [10000,1,10000,1,1,1,1,1,1]
Output = 10001
print(f"expect {Output} is {sol.maximumUniqueSubarray(nums)}")

# print(f"expect {Output} is {sol.maximumUniqueSubarray(nums)}")
# print(f"len is {len(nums)}")

# psums = [nums[0]]
# for i in range(1,len(nums)):
#     psums.append(psums[i-1] + nums[i])
# print(f"prefix sums are {psums}")