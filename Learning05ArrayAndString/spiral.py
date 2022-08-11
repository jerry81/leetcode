"""
Given an m x n matrix, return all elements of the matrix in spiral order.



Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]


Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
"""

from typing import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
      if len(matrix) == 0:
        return []
      flattened = []
      direction = 'R'
      curx = 0
      cury = 0
      mx = len(matrix[0]) - 1
      my = len(matrix) - 1
      mnx = 0
      mny = 0
      targetLen = len(matrix) * len(matrix[0])
      while len(flattened) < targetLen:
        flattened.append(matrix[cury][curx])
        if direction == 'R':
          if (curx+1) <= mx:
            curx+=1
            continue
          else:
            mx-=1
            direction = 'D'
            cury+=1
            continue
        if direction == 'D':
          if (cury+1) <= my:
            cury+=1
            continue
          else:
            my-=1
            direction = 'L'
            curx-=1
            continue
        if direction == 'L':
          if (curx-1) >= mnx:
            curx-=1
            continue
          else:
            mnx+=1
            direction = 'U'
            cury-=1
            continue
        if direction == 'U':
          if (cury-1) >= mny:
            cury-=1
            continue
          else:
            mny+=1
            direction = 'R'
            curx+=1
      return flattened


"""
[1,2,3,6,9,8,7,4,1]
Expected answer
[1,2,3,6,9,8,7,4,5]
"""