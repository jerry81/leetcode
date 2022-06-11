from typing import List


class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        candidates = []
        prefix_sums = [nums[0]]
        for y in range(1,len(nums)):
            prefix_sums.append(nums[y] + prefix_sums[y-1])
            
        print(f"ps is {prefix_sums}")
        rev = nums[::-1]
        r_prefix_sums = [rev[0]]
        for y in range(1,len(nums)):
            r_prefix_sums.append(rev[y] + r_prefix_sums[y-1])
            
        print(f"rps is {r_prefix_sums}")
        for l in range(len(nums)):
            a = prefix_sums[l]
            if a == x:
                candidates.append(l+1)
            for r in range(len(nums)):
                b = r_prefix_sums[r]
                if b == x:
                    candidates.append(r+1)
                sum = a+b 
                if sum == x and l+r+2 <= len(nums):
                    candidates.append(l+r+2)
        if len(candidates) == 0:
            return -1
        return min(candidates)

sol = Solution()

nums = [1,1,4,2,3]
x = 5
Output = 2
print(f"expect {Output} {sol.minOperations(nums,x)}")

nums = [5,6,7,8,9]
x = 4
Output = -1
print(f"expect {Output} {sol.minOperations(nums,x)}")

nums = [3,2,20,1,1,3]
x = 10
Output = 5
print(f"expect {Output} {sol.minOperations(nums,x)}")

nums = [1,1]
x = 3
Output = -1
print(f"expect {Output} {sol.minOperations(nums,x)}")

nums = [10,1,1,1,1,1]
x = 5
Output = 5
print(f"expect {Output} {sol.minOperations(nums,x)}")

nums = [2,3,1,1,1]
x = 5
Output = 2
print(f"expect {Output} {sol.minOperations(nums,x)}")
