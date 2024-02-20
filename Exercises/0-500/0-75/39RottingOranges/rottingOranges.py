from collections import defaultdict
import sys
from typing import List


class Solution:
     def bfs(self, mat, x,y, memo):
        if memo[y,x] != -1:
            return memo[y,x]
        if mat[y][x] == 2:
            memo[y,x] = 0
            return 0
        if mat[y][x] == 0:
            memo[y,x] = None
            return None
        next_neighbors = [(y,x)]
        my = len(mat)
        mx = len(mat[0])
        visited = defaultdict(bool)
        visited[y,x] = True 
        count = 0
        while len(next_neighbors) > 0:
          new_neighbors = []
          count+=1
          for n in next_neighbors:
            ny,nx = n
            # if memo[ny,nx] != -1:
            #   return 1 + memo[ny,nx]
            u = ny-1
            d = ny+1 
            l = nx-1
            r = nx+1
            memoized = []
            if memo[ny,nx] != -1:
                memoized.append(memo[ny,nx])
            if u >= 0:
                ui = mat[u][nx]
                if ui == 2:
                  memo[y,x] = count
                  return count
                elif not visited[u,nx] and ui == 1:
                  new_neighbors.append((u,nx))
                  visited[u,nx] = True
            if l >= 0:
                li = mat[ny][l] 
                if li == 2:
                  memo[y,x] = count
                  return count
                elif not visited[ny,l] and li == 1:
                  new_neighbors.append((ny,l))
                  visited[ny,l] = True
            if d < my:
                di = mat[d][nx] 
                if di == 2:
                  memo[y,x] = count
                  return count
                elif not visited[d,nx] and di == 1:
                  new_neighbors.append((d,nx))
                  visited[d,nx] = True
            if r < mx:
                ri = mat[ny][r] 
                if ri == 2:
                  memo[y,x] = count
                  return count
                elif not visited[ny,r] and ri == 1:
                  new_neighbors.append((ny,r))
                  visited[ny,r] = True
          if len(memoized) > 0:
            memo[y,x] = min(memoized) + 1
            return min(memoized) + 1
          next_neighbors = new_neighbors
    
     def orangesRotting(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        if (rows == 0):
            return grid
        cols = len(grid[0])
        maxO = 0
        for r in range(rows):
            for c in range(cols):
                b = self.bfs(grid,c,r,defaultdict(lambda:-1))
                if grid[r][c] == 1 and b is None:
                    return -1
                if grid[r][c] == 1 and maxO < b:
                    maxO = b 
        return maxO

sol = Solution()
grid = [[2,1,1],[1,1,0],[0,1,1]]
expect = 4
print(f"expect {expect} {sol.orangesRotting(grid)}")

grid = [[2,1,1],[0,1,1],[1,0,1]]
expect = -1
print(f"expect {expect} {sol.orangesRotting(grid)}")


grid = [[0,2]]
expect = 0
print(f"expect {expect} {sol.orangesRotting(grid)}")
