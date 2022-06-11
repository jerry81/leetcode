from typing import List


class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        prefix_sums = [nums[0]]
        for y in range(1,len(nums)):
            prefix_sums.append(nums[y] + prefix_sums[y-1])
        print(f"ps is {prefix_sums}")
        rev = nums[::-1]
        r_prefix_sums = [rev[0]]
        for y in range(1,len(nums)):
            r_prefix_sums.append(rev[y] + r_prefix_sums[y-1])
        print(f"rps is {r_prefix_sums}")
        return

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