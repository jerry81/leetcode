from collections import defaultdict
from typing import List


class Solution:
    def bfs(self, mat, x,y):
        if mat[y][x] == 0:
            return 0
        next_neighbors = [(y,x)]
        my = len(mat)
        mx = len(mat[0])
        visited = defaultdict(bool)
        visited[y,x] = True 
        count = 0
        while len(next_neighbors) > 0:
          count+=1
          y,x = next_neighbors.pop()
          u = y-1
          d = y+1 
          l = x-1
          r = x+1 
          if u >= 0:
              ui = mat[u][x]
              if ui == 0:
                return count
              elif not visited[u,x]:
                next_neighbors.append((u,x))
                visited[u,x] = True
          if l >= 0:
              li = mat[y][l] 
              if li == 0:
                return count
              elif not visited[y,l]:
                next_neighbors.append((y,l))
                visited[y,l] = True
          if d < my:
              di = mat[d][x] 
              if di == 0:
                return count
              elif not visited[d,x]:
                next_neighbors.append[(d,x)]
                visited[d,x] = True
          if r < mx:
              ri = mat[y][r] 
              if ri == 0:
                return count
              elif not visited[y,ri]:
                next_neighbors.append[(y,ri)]
                visited[y,ri] = True

    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        return 
        

sol = Solution()

mat = [[0,0,0],[0,1,0],[0,0,0]]
expect = [[0,0,0],[0,1,0],[0,0,0]]
print(f"expect {expect} {sol.updateMatrix(mat)}")

mat = [[0,0,0],[0,1,0],[1,1,1]]
expect = [[0,0,0],[0,1,0],[1,2,1]]
print(f"expect {expect} {sol.updateMatrix(mat)}")

# mini tests

print (f"expect 1 is {sol.bfs(mat,1,1)}")
print (f"expect {expect[2][1]} is {sol.bfs(mat,1,2)}")