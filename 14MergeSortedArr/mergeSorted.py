from typing import List


class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """

s = Solution()
nums1 = [1,2,3,0,0,0]
m = 3
nums2 = [2,5,6]
n = 3
s.merge(nums1, m, nums2, n)
print(f"expect [1,2,2,3,5,6] {nums1}")

nums1 = [1]
m = 1
nums2 = []
n = 0
s.merge(nums1, m, nums2, n)
print(f"expect [1] {nums1}")

nums1 = []
m = 0
nums2 = [1]
n = 1
s.merge(nums1, m, nums2, n)
print(f"expect [1] {nums1}")