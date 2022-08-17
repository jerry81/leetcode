"""
Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.



Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0


Constraints:

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 104


Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).
"""

from re import S
from typing import List


class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        # answer is CONTIGUOUS!
        # find max subarray
          # prefix sums
          # [2,3,1,2,4,3]
          # [2,5,6,8,12,15]
          # target 7
          # 7, so 3
          # 9 - 2 still 3
          # 13 - 6 still 3
          # 16 - 7 9 still 3
          # 16 - 9 = 7 2
        prefix = []
        for i in nums:
          if len(prefix) == 0:
            prefix.append(i)
          else:
            prefix.append(prefix[-1] + i)

        print(f"prefixes are {prefix}")

        ptr2 = None
        mn=len(nums)+1
        if len(nums) == 0: return 0

        if len(nums) == 1:
          return 0 if nums[0] < target else 1

        for ptr1 in range(len(nums)):
          item = prefix[ptr1]

          while True:
            # move ptr2 until diff is < target
            nxt = ptr2
            if nxt is not None:
                nxt += 1
            else:
                nxt = 0
            nextdiff = item - prefix[nxt]
            if nextdiff < target:
              break
            else:
              ptr2 = nxt

            print(f"diff is now {diff}")

          diff = 0
          if ptr2 is None:
            diff = item
          else:
            diff = item - prefix[ptr2]
          i_diff = (ptr1 - ptr2) if ptr2 is not None else (ptr1+1)
          if diff >= target and i_diff < mn:
            print(f"setting mn ptr is {ptr1}")
            mn = i_diff

        return 0 if mn > len(nums) else mn


"""
FAIL CASE FOR NEXT SESSION

Input:
15
[1,2,3,4,5]
Output:
4
Expected:
5
Stdout:
prefixes are [1, 3, 6, 10, 15]
diff is now 14
"""