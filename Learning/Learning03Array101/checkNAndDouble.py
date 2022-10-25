"""
Given an array arr of integers, check if there exists two integers N and M such that N is the double of M ( i.e. N = 2 * M).

More formally check if there exists two indices i and j such that :

i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]
 

Example 1:

Input: arr = [10,2,5,3]
Output: true
Explanation: N = 10 is the double of M = 5,that is, 10 = 2 * 5.
Example 2:

Input: arr = [7,1,14,11]
Output: true
Explanation: N = 14 is the double of M = 7,that is, 14 = 2 * 7.
Example 3:

Input: arr = [3,1,7,11]
Output: false
Explanation: In this case does not exist N and M, such that N = 2 * M.
 

Constraints:

2 <= arr.length <= 500
-10^3 <= arr[i] <= 10^3
"""
from collections import defaultdict
from typing import List


class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        lookup = defaultdict(bool)
        for i in arr:
            if lookup[i*2]:
                print(f"i*2 {i*2}")
                return True
            if i%2 == 0 and lookup[i//2]:
                print(f"i//2 {i//2}")
                return True
            else:
                lookup[i] = True 
                # lookup[i*2] = True 
                # if i%2 == 0:
                #     lookup[i//2] = True
        return False

s = Solution()
print(f"s is {s.checkIfExist([4,-7,11,4,18])}")