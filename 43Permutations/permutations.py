from typing import List
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        return 

sol = Solution()
nums = [1,2,3]
ex = [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
print(f"expect {ex}\n{sol.permute(nums)}")

nums = [0,1]
ex = [[0,1],[1,0]]
print(f"expect {ex}\n{sol.permute(nums)}")

nums = [1]
ex = [[1]]
print(f"expect {ex}\n{sol.permute(nums)}")