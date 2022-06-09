from typing import List

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        accum = 0
        while accum != target:
            accum = 0
            for i1 in range(len(numbers)):
                accum = numbers[i1]
                if accum > target:
                    break
                for i2 in range(i1,len(numbers)):
                  accum = numbers[i1] + numbers[i2]
                  if accum > target:
                      break 
                  if accum == target:
                      return [i1+1,i2+1]
        return 

sol = Solution()

numbers = [2,7,11,15]
target = 9
Output = [1,2]
print(f"expect {Output} {sol.twoSum(numbers, target)}")

numbers = [2,3,4]
target = 6
Output = [1,3]
print(f"expect {Output} {sol.twoSum(numbers, target)}")

numbers = [-1,0]
target = -1
Output = [1,2]
print(f"expect {Output} {sol.twoSum(numbers, target)}")