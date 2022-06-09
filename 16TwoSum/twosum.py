from typing import List

class Solution:
    def binary(self, sorted, target):
        # should return idx 
        cur_i = len(sorted) // 2
        cur = None
        while cur != target:
          cur = sorted[cur_i]
          if cur < target:
              cur_i = (len(sorted) + cur_i) // 2
          else: 
              cur_i = cur_i // 2
        return cur_i 

    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        accum = None
        as_set = list(set(numbers))
        while accum != target:
            for i1 in range(len(numbers)):
                accum = numbers[i1]
                if accum > target:
                    break
                for i2 in range(i1+1,len(numbers)):
                  accum = numbers[i1] + numbers[i2]
                  if accum > target:
                      break 
                  if accum == target:
                      print(f"returning ")
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

numbers = [0,0,3,4]
target = 0
Output = [1,2]
print(f"expect {Output} {sol.twoSum(numbers, target)}")

# broken performance test case - lots of duplicates and target towards end of array 

# new plan
# convert to set to find unique values
# find two unique values (allowing repeat) that sum up to target
# binary search to find first value 
  # if both needed values are the same
    # check left and right of the index and see if they are a repeat
  # else binary search second value 