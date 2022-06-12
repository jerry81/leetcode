from typing import List

class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        # brute force - find all unique subarrays
        uniques = []
        for head in range(len(nums)):
            for tail in range(head+1, len(nums)+1):
                sub = nums[head:tail]
                if len(list(set(sub))) == len(sub): # uniqueness check
                    uniques.append(sub)
        print(f"uniques are {uniques}")

sol = Solution()

nums = [4,2,4,5,6]
Output = 17
print(f"expect {Output} is {sol.maximumUniqueSubarray(nums)}")

nums = [5,2,1,2,5,2,1,2,5]
Output = 8
print(f"expect {Output} is {sol.maximumUniqueSubarray(nums)}")