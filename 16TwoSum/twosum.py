from typing import List

class Solution:
    def binary(self, sorted, target):
        # should return idx 
        hi = len(sorted)
        lo = 0
        cur = None
        limit = 0
        mid = 0
        while cur != target and limit < 5:
          mid = (hi + lo) // 2
          limit += 1
          cur = sorted[mid]
          if cur < target:
              lo = mid 
          else: 
              hi = mid 
        return mid 
    
    def get_values(self, numbers, target):
      accum = None
      while accum != target:
            for i1 in range(len(numbers)):
                accum = numbers[i1]
                if accum > target:
                    break
                for i2 in range(i1,len(numbers)):
                  accum = numbers[i1] + numbers[i2]
                  if accum > target:
                      break 
                  if accum == target:
                      return [numbers[i1],numbers[i2]]

    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        as_set = list(set(numbers))
        as_set.sort()
        values = self.get_values(as_set,target)
        print(f"values is {values}")
        idx1 = self.binary(numbers, values[0])
        if values[0] == values[1]:
            if numbers[idx1-1] == values[0]:
              return [idx1, idx1+1]
            if numbers[idx1+1] == values[0]:
              return [idx1+1,idx1+2]
        idx2 = self.binary(numbers, values[1])
        return [idx1+1,idx2+1]

sol = Solution()

# test dedup 
as_set = list(set([1,1,1,2,2,4,4,5,2,2,3,3]))
print(f"as_set is {as_set}")

# test binary search
numbers = [1,2,3,5,7]
target = 5
Output = 3
print(f"expect {Output} {sol.binary(numbers, target)}")

numbers = [1,2,3,5,7]
target = 7
Output = 4
print(f"expect {Output} {sol.binary(numbers, target)}")

numbers = [1,2,3,5,7]
target = 1
Output = 0
print(f"expect {Output} {sol.binary(numbers, target)}")

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

numbers = [0,0,3,4]
target = 0
Output = [1,2]
print(f"expect {Output} {sol.twoSum(numbers, target)}")

numbers = [12,13,23,28,43,44,59,60,61,68,70,86,88,92,124,125,136,168,173,173,180,199,212,221,227,230,277,282,306,314,316,321,325,328,336,337,363,365,368,370,370,371,375,384,387,394,400,404,414,422,422,427,430,435,457,493,506,527,531,538,541,546,568,583,585,587,650,652,677,691,730,737,740,751,755,764,778,783,785,789,794,803,809,815,847,858,863,863,874,887,896,916,920,926,927,930,933,957,981,997]
target = 542
Output = [24,32]
print(f"expect {Output} {sol.twoSum(numbers, target)}")

# broken performance test case - lots of duplicates and target towards end of array 

# new plan
# convert to set to find unique values
# find two unique values (allowing repeat) that sum up to target
# binary search to find first value 
  # if both needed values are the same
    # check left and right of the index and see if they are a repeat
  # else binary search second value 