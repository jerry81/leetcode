from typing import List


class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        sol = []
        h1 = 0
        h2 = 0
        if m == 0:
            nums1[:] = nums2.copy() # trick to change the items in list 
            return None

        if n == 0: 
            return 

        while len(sol) < m + n:
            first = nums1[h1]
            if h1 >= m:
                sol.append(nums2[h2])
                h2+=1
            elif h2 >= n:
                sol.append(nums1[h1])
                h1+=1
            elif first > 0 and first <= nums2[h2]:
                sol.append(nums1[h1])
                h1+=1
            else: 
                sol.append(nums2[h2])
                h2+=1
        nums1[:] = sol
            

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

nums1 = [0]
m = 0
nums2 = [1]
n = 1
s.merge(nums1, m, nums2, n)
print(f"expect [1] {nums1}")

nums1 = [2,0]
m = 1
nums2 = [1]
n = 1
s.merge(nums1, m, nums2, n)
print(f"expect [1,2] {nums1}")