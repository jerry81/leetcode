"""
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:




Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]
Example 2:

Input: rowIndex = 0
Output: [1]
Example 3:

Input: rowIndex = 1
Output: [1,1]


Constraints:

0 <= rowIndex <= 33


Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?
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
    def getRow(self, rowIndex: int) -> List[int]:
        return self.generate(rowIndex+1)[-1]