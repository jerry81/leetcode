from typing import List
class Solution:
    def getNext(self, nums):
        # 1,2,3 -> 1,3,2
        for i in range(len(nums)-1, 1, -1):
            if nums[i-1] < nums[i]:
              print(f"swap! {nums[i-1]} and {nums[i]}")
        return 

    def permute(self, nums: List[int]) -> List[List[int]]:
        return 



sol = Solution()
print(f"getNext([1,2,3]) is {sol.getNext([1,2,3])}")
nums = [1,2,3]
ex = [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
print(f"expect {ex}\n{sol.permute(nums)}")

nums = [0,1]
ex = [[0,1],[1,0]]
print(f"expect {ex}\n{sol.permute(nums)}")

nums = [1]
ex = [[1]]
print(f"expect {ex}\n{sol.permute(nums)}")

nums = [1,2,3,4]
ex = [[1,2,3,4],[1,2,4,3],[1,3,2,4],[1,3,4,2],[1,4,2,3],[1,4,3,2],\
    [2,1,3,4],[2,1,4,3],[2,3,1,4],[2,3,4,1],[2,4,1,3],[2,4,3,1],\
    [3,1,2,4],[3,1,4,2],[3,2,1,4],[3,2,4,1],[3,4,1,2],[3,4,2,1],\
    [4,1,2,3],[4,1,3,2],[4,2,1,3],[4,2,3,1],[4,3,1,2],[4,3,2,1]]
print(f"expect {ex}\n{sol.permute(nums)}")

arr1 = [1,2,3]
arr2 = [1,2,3]
print(f"equals test {arr1==arr2}")
arr3 = [3,2,1]
print(f"equals test {arr1==arr3}")
