"""
Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.



Example 1:


Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]
Example 2:

Input: mat = [[1,2],[3,4]]
Output: [1,2,3,4]


Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
-105 <= mat[i][j] <= 105
"""

from typing import List


class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        up = True
        returned = []
        cy=0
        cx=0
        ly = len(mat)
        if ly == 0:
          return []
        lx = len(mat[0])
        while len(returned) < (ly*lx):
          if up:
            while cy >= 0 and cx < lx:
              n = mat[cy][cx]
              returned.append(n)
              cy-=1
              cx+=1
            up = not up
            if cy < 0: cy+=1 # step back
            if cx >= lx: cx-=1
          else:
            while cy < ly and cx >= 0:
              n = mat[cy][cx]
              returned.append(n)
              cy+=1
              cx-=1
            up = not up
            if cy >= ly: cy-=1
            if cx < 0: cx+=1
        return returned
