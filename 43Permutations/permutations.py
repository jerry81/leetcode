from typing import List
class Solution:
    def getNext(self, nums):
        # 2,5,6,4 expect 2,6,4,5
        #1,3,4,2 expect 1,4,2,3
        # 2 vs 4
        # 2 vs 3
        # 2 vs 1
        # vs 
        # 2 vs 4
        # 4 vs 3
        # swap 
        # 1,3,2
        # 1,3,2
        # 2,1,3
        for pivot in range(len(nums)-2,-1,-1):
          for i in range(len(nums)-1, pivot, -1):
            # 2,1,0
                  if nums[pivot] < nums[i]:
                    nums[i],nums[pivot] = nums[pivot],nums[i]
                    subs = nums[pivot+1:]
                    nums[pivot+1:] = subs[::-1]
                    return nums
        return None

    def permute(self, nums: List[int]) -> List[List[int]]:
        nextres = nums.copy()
        nextres.sort()
        print(f"starting is {nextres}")
        res = []
        while nextres is not None:
          curRes = nextres.copy()
          res.append(curRes)
          nextres = self.getNext(nextres)
        return res



sol = Solution()
print(f"getNext([1,2,3]) is {sol.getNext([1,2,3])}")
print(f"getNext([1,3,2]) is {sol.getNext([1,3,2])}")
print(f"getNext[2,5,6,4] is {sol.getNext([2,5,6,4])}")

print(f"getNext[1,3,4,2] is {sol.getNext([1,3,4,2])}")

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
print(f"expect 24 {len(sol.permute(nums))}")

nums = [5,4,6,2]
ex = 24
print(f"expect {ex}\n{len(sol.permute(nums))}")

nums = [0,1,-1]
ex = [[1]]
print(f"expect something reasonable\n{sol.permute(nums)}")

arr1 = [1,2,3]
arr2 = [1,2,3]
print(f"equals test {arr1==arr2}")
arr3 = [3,2,1]
print(f"equals test {arr1==arr3}")
