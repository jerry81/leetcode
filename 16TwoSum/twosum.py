from typing import List

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
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