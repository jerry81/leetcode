from collections import defaultdict
from typing import List


class Solution:
    def getMinDist(self,x,y,grid,memo,max_x,max_y,visited=defaultdict(bool),updated=[]):
        if memo[f"{y},{x}"] != -1:
            return memo[f"{y},{x}"]
        if grid[y][x] == 0:
            memo[f"{y},{x}"] = 0
            updated[y][x] = 0
            visited[f"{y},{x}"] = True
            return 0

        compareArr = []
        if x-1 >= 0:
              left = 9999999
              if memo[f"{y},{x-1}"] != -1:
                left = memo[f"{y},{x-1}"]
              elif grid[y][x-1] == 0:
                left = 0
                memo[f"{y},{x-1}"] = 0
                updated[y][x-1] = 0
              elif visited[f"{y},{x-1}"] is None:
                left = self.getMinDist(x-1,y,grid,memo,max_x,max_y, updated = updated)
              visited[f"{y},{x-1}"] = True
              compareArr.append(left)
              
        if y-1 >= 0:
              up = 999999999
              if memo[f"{y-1},{x}"] != -1:
                up = memo[f"{y-1},{x}"]
              elif grid[y-1][x] == 0:
                up = 0
                memo[f"{y-1},{x}"] = 0
                updated[y-1][x] = 0
              elif visited[f"{y-1},{x}"] is None:
                up = self.getMinDist(x,y-1,grid,memo,max_x,max_y, updated = updated)
              visited[f"{y-1},{x}"] = True
              compareArr.append(up)
              
        if x+1 < max_x:
                right = 999999999
                if memo[f"{y},{x+1}"] != -1:
                    right = memo[f"{y},{x+1}"]
                elif grid[y][x+1] == 0:
                    right = 0
                    memo[f"{y},{x+1}"] = 0
                    updated[y][x+1] = 0
                else:
                    right = self.getMinDist(x+1,y,grid,memo,max_x,max_y, updated = updated)
                visited[f"{y},{x+1}"] = True
                compareArr.append(right)
        if y+1 < max_y:
                down = 999999999
                if memo[f"{y+1},{x}"] != -1:
                    down = memo[f"{y+1},{x}"]
                elif grid[y+1][x] == 0:
                    down = 0
                    memo[f"{y+1},{x}"] = 0
                    updated[y+1][x] = 0
                else:
                    down = self.getMinDist(x,y+1,grid,memo,max_x,max_y, updated = updated)
                visited[f"{y+1},{x}"] = True
                compareArr.append(down)

        res = 1 + min(compareArr)
        memo[f"{y},{x}"] = res 
        updated[y][x] = res
        return res 
        
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        max_y = len(mat)
        max_x = len(mat[0])
        updated = [[0]*len(mat[0]) for _ in range(len(mat))] # init 2d matrix 
        memo = defaultdict(lambda: -1)
        for y in range(len(mat)):
            line = mat[y]
            for x in range(len(line)):
                if memo[f"{y},{x}"] == -1:
                    self.getMinDist(x,y,mat,memo,max_x,max_y, updated=updated)
        return updated

sol = Solution()

mat = [[0,0,0],[0,1,0],[0,0,0]]
expect = [[0,0,0],[0,1,0],[0,0,0]]
print(f"expect {expect} {sol.updateMatrix(mat)}")

mat = [[0,0,0],[0,1,0],[1,1,1]]
expect = [[0,0,0],[0,1,0],[1,2,1]]
print(f"expect {expect} {sol.updateMatrix(mat)}")

mat = [[1,0,1,1,0,0,1,0,0,1],\
      [0,1,1,0,1,0,1,0,1,1],\
      [0,0,1,0,1,0,0,1,0,0],\
      [1,0,1,0,1,1,1,1,1,1],\
      [0,1,0,1,1,0,0,0,0,1],\
      [0,0,1,0,1,1,1,0,1,0],\
      [0,1,0,1,0,1,0,0,1,1],\
      [1,0,0,0,1,1,1,1,0,1],\
      [1,1,1,1,1,1,1,0,1,0],\
      [1,1,1,1,0,1,0,0,1,1]]

expect = [[1,0,1,1,0,0,1,0,0,1],\
        [0,1,1,0,1,0,1,0,1,1],\
        [0,0,1,0,1,0,0,1,0,0],\
        [1,0,1,0,1,1,1,1,1,1],\
        [0,1,0,1,1,0,0,0,0,1],\
        [0,0,1,0,1,1,1,0,1,0],\
        [0,1,0,1,0,1,0,0,1,1],\
        [1,0,0,0,1,2,1,1,0,1],\
        [2,1,1,1,1,2,1,0,1,0],\
        [3,2,2,1,0,1,0,0,1,1]]

print(f"expect {expect} {sol.updateMatrix(mat)}")
"""
[[1,0,1,1,0,0,1,0,0,1],
[0,1,1,0,1,0,1,0,1,1],
[0,0,1,0,1,0,0,1,0,0],
[1,0,1,0,1,1,1,1,1,1],
[0,1,0,1,1,0,0,0,0,1],
[0,0,1,0,1,1,1,0,1,0],
[0,1,0,1,0,1,0,0,1,1],
[1,0,0,0,1,2,1,1,0,1],
[2,1,1,1,1,2,1,0,1,0],
[4,3,2,1,0,1,0,0,1,1]]
000
010
111

000
0

000
010
121
"""