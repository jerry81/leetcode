"""
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:




Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]


Constraints:

1 <= numRows <= 30
"""

from typing import List


class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        pascal = []
        for i in range(numRows):
          nextRow = [0]*(i+1)
          if i == 0:
            pascal.append([1])
            continue
          # init row with all zeros
          # row length is i+1
          prevRow = pascal[i-1]
          for j in range(len(prevRow)):
            item = prevRow[j]
            nextRow[j] += item
            nextRow[j+1] += item
          pascal.append(nextRow)
        return pascal