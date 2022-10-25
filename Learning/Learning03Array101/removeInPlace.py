from typing import List


class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        ptr = 0
        for i in range(len(nums)):
          n = nums[i]
          if n != val:
            nums[ptr] = n
            ptr+=1
        return ptr

s=Solution()
arr = [3,2,2,3]
s.removeElement(arr,3)
print(f"mod is {arr}")