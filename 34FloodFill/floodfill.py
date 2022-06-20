from collections import defaultdict
from typing import List


class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        visited = defaultdict(bool)
        oldcolor = image[sr][sc]
        visited[sr,sc] = True 
        neighbors = [(sr,sc)]
        while len(neighbors) > 0:
          y,x = neighbors.pop()
          image[y][x] = color
          if y-1 >= 0:
              if image[y-1][x] == oldcolor and not visited[y-1,x]:
                  neighbors.append((y-1,x))
                  visited[y-1,x] = True 
          if y+1 < len(image):
              if image[y+1][x] == oldcolor and not visited[y+1,x]:
                  neighbors.append((y+1,x))
                  visited[y+1,x] = True 
          if x-1 >= 0:
              if image[y][x-1] == oldcolor and not visited[y,x-1]:
                  neighbors.append((y,x-1))
                  visited[y,x-1] = True 
          if x+1 < len(image[0]):
              if image[y][x+1] == oldcolor and not visited[y,x+1]:
                  neighbors.append((y,x+1))
                  visited[y,x+1] = True 
        return image
        


sol = Solution()

image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1
sc = 1
color = 2
expect = [[2,2,2],[2,2,0],[2,0,1]]

print(f"expect {expect} {sol.floodFill(image,sr,sc,color)}")

image = [[0,0,0],[0,0,0]]
sr = 0
sc = 0
color = 0
expect = [[0,0,0],[0,0,0]]
print(f"expect {expect} {sol.floodFill(image,sr,sc,color)}")