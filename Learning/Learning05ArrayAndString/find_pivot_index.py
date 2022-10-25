"""
Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.



Example 1:

Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11
Example 2:

Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.
Example 3:

Input: nums = [2,1,-1]
Output: 0
Explanation:
The pivot index is 0.
Left sum = 0 (no elements to the left of index 0)
Right sum = nums[1] + nums[2] = 1 + -1 = 0


Constraints:

1 <= nums.length <= 104
-1000 <= nums[i] <= 1000
"""

from typing import List


class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
      # edge cases
      # prefix sums left to right
      leftps = []
      s = 0
      for n in nums:
        s += n
        leftps.append(s)

      rightps = []
      s = 0
      for n in nums[::-1]:
        s += n
        rightps.append(s)
      rightps = rightps[::-1]

      # prefix sums right to left
      # step i left to right comparing left[i-1] and right[i+1]
      # edge case - i==0, i == len-1
      for i in range(len(nums)):
        left = 0
        right = 0
        if i > 0:
          left = leftps[i-1]
        if i < len(nums) - 1:
          right = rightps[i+1]
        if left == right:
          return i

      return -1

      """
      official solution: only loops once (if you don't count sum function)
class Solution(object):
    def pivotIndex(self, nums):
        S = sum(nums)
        leftsum = 0
        for i, x in enumerate(nums):
            if leftsum == (S - leftsum - x):
                return i
            leftsum += x
        return -1
      """