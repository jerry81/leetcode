from typing import List


class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        for idx,v in enumerate(nums):
          if idx == 0:
              continue
          else:
              nums[idx] = nums[idx-1] + v
        return nums


s = Solution()
i = [1,2,3,4]
output = [1,3,6,10]
print(f"expect {output} {s.runningSum(i)}")

i = [1,1,1,1,1]
output = [1,2,3,4,5]
print(f"expect {output} {s.runningSum(i)}")

i = [3,1,2,10,1]
output = [3,4,6,16,17]
print(f"expect {output} {s.runningSum(i)}")