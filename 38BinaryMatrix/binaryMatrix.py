from collections import defaultdict
from typing import List


class Solution:
    def getMinDist(self,x,y,grid,memo,max_x,max_y,visited=defaultdict(bool)):
        if grid[y][x] == 0:
            memo[f"{y},{x}"] = 0
            visited[f"{y},{x}"] = True
            return 0

        print(f"grid y x is {y} {x} {grid[y][x]}")
        left = 999999
        right = 999999
        up = 9999999
        down = 9999999
        if x-1 >= 0:
            if not visited[f"{y},{x-1}"]:
              lres = memo[f"{y},{x-1}"] if memo[f"{y},{x-1}"] > -1 else self.getMinDist(x-1,y,grid,memo,max_x,max_y)
              left = 1 + lres
        if y-1 >= 0:
            if not visited[f"{y-1},{x}"]:
              ures = memo[f"{y-1},{x}"] if memo[f"{y-1},{x}"] > -1 else self.getMinDist(x,y-1,grid,memo,max_x,max_y)
              up = 1 + ures
        if x+1 < max_x:
            if not visited[f"{y},{x+1}"]:
              rres = memo[f"{y},{x+1}"] if memo[f"{y},{x+1}"] > -1 else self.getMinDist(x+1,y,grid,memo,max_x,max_y)
              right = 1 + rres
        if y+1 < max_y:
            if not visited[f"{y+1},{x}"]:
              dres = memo[f"{y+1},{x}"] if memo[f"{y+1},{x}"] > -1 else self.getMinDist(x,y+1,grid,memo,max_x,max_y)
              down = 1 + dres
        res = min(left,up,right,down)
        memo[f"{y},{x}"] = res 
        return res 
        
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        max_y = len(mat)
        max_x = len(mat[0])
        updated = [[0]*len(mat) for _ in range(len(mat[0]))] # init 2d matrix 
        memo = defaultdict(lambda: -1)
        for y in range(len(mat)):
            line = mat[y]
            for x in range(len(line)):
                if memo[f"{y},{x}"] == -1:
                    print(f"memo before {memo}")
                    self.getMinDist(x,y,mat,memo,max_x,max_y)
                    print(f"memo after {memo}")
        print(f"updated is {updated}") # memoize entire grid 
        return 

sol = Solution()

mat = [[0,0,0],[0,1,0],[0,0,0]]
expect = [[0,0,0],[0,1,0],[0,0,0]]
print(f"expect {expect} {sol.updateMatrix(mat)}")

mat = [[0,0,0],[0,1,0],[1,1,1]]
expect = [[0,0,0],[0,1,0],[1,2,1]]
print(f"expect {expect} {sol.updateMatrix(mat)}")
