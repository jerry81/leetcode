from collections import defaultdict
from typing import List


class Solution:
    def bfs(self, mat, x,y, memo):
        if memo[y,x] != -1:
            return memo[y,x]
        if mat[y][x] == 0:
            memo[y,x] = 0
            return 0
        next_neighbors = [(y,x)]
        my = len(mat)
        mx = len(mat[0])
        visited = defaultdict(bool)
        visited[y,x] = True 
        count = 0
        while len(next_neighbors) > 0:
          count+=1
          ny,nx = next_neighbors.pop()
          if memo[ny,nx] != -1:
            return count + memo[ny,nx] - 1
          u = ny-1
          d = ny+1 
          l = nx-1
          r = nx+1 
          if u >= 0:
              ui = mat[u][nx]
              if ui == 0:
                memo[y,x] = count
                return count
              elif not visited[u,nx]:
                next_neighbors.append((u,nx))
                visited[u,nx] = True
          if l >= 0:
              li = mat[ny][l] 
              if li == 0:
                memo[y,x] = count
                return count
              elif not visited[ny,l]:
                next_neighbors.append((ny,l))
                visited[ny,l] = True
          if d < my:
              di = mat[d][nx] 
              if di == 0:
                memo[y,x] = count
                return count
              elif not visited[d,nx]:
                next_neighbors.append[(d,nx)]
                visited[d,nx] = True
          if r < mx:
              ri = mat[ny][r] 
              if ri == 0:
                memo[y,x] = count
                return count
              elif not visited[ny,ri]:
                next_neighbors.append[(ny,ri)]
                visited[ny,ri] = True

    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        updated = [[-1]*len(mat) for _ in range(len(mat[0]))]
        memo = defaultdict(lambda: -1)
        for i in range(len(mat)):
            for j in range(len(mat[0])):
                if memo[i,j] != -1:
                    updated[i][j] = memo[i,j] 
                else:
                    updated[i][j] = self.bfs(mat,j,i,memo)

        return updated
        

sol = Solution()

mat = [[0,0,0],[0,1,0],[0,0,0]]
expect = [[0,0,0],[0,1,0],[0,0,0]]
print(f"expect {expect} {sol.updateMatrix(mat)}")

mat = [[0,0,0],[0,1,0],[1,1,1]]
expect = [[0,0,0],[0,1,0],[1,2,1]]
print(f"expect {expect} {sol.updateMatrix(mat)}")

# mini tests
mem = defaultdict(lambda:-1)
print (f"expect 1 is {sol.bfs(mat,1,1,mem)}")
print (f"expect {expect[2][1]} is {sol.bfs(mat,1,2,mem)}")