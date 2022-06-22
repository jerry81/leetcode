from typing import List


class Solution:
    def getMinDist(self,x,y,grid,memo,max_x,max_y):
        min = max_x * max_y
        if grid[y][x] == 0:
            memo[f"{y},{x}"] = 0
            return 0 
        

    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        updated = [] # init 2d matrix 
        memo = {} # memoize entire grid 
        return 

sol = Solution()

mat = [[0,0,0],[0,1,0],[0,0,0]]
expect = [[0,0,0],[0,1,0],[0,0,0]]
print(f"expect {expect} {sol.updateMatrix(mat)}")

mat = [[0,0,0],[0,1,0],[1,1,1]]
expect = [[0,0,0],[0,1,0],[1,2,1]]
print(f"expect {expect} {sol.updateMatrix(mat)}")
