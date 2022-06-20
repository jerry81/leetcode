from collections import defaultdict
from typing import List

class Solution:
    def floodFillArea(self, visited, image: List[List[int]], sr: int, sc: int, color: int = 1) -> int:
        area = 1
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
                  area+=1
                  visited[y-1,x] = True 
          if y+1 < len(image):
              if image[y+1][x] == oldcolor and not visited[y+1,x]:
                  neighbors.append((y+1,x))
                  area+=1
                  visited[y+1,x] = True 
          if x-1 >= 0:
              if image[y][x-1] == oldcolor and not visited[y,x-1]:
                  neighbors.append((y,x-1))
                  area+=1
                  visited[y,x-1] = True 
          if x+1 < len(image[0]):
              if image[y][x+1] == oldcolor and not visited[y,x+1]:
                  neighbors.append((y,x+1))
                  area+=1
                  visited[y,x+1] = True 
        return area

    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        visited = defaultdict(bool)
        largest = 0
        for i in range(len(grid)):
            row = grid[i]
            for j in range(len(row)):
              if row[j] == 1 and not visited[(i,j)]:
                area = self.floodFillArea(visited,grid,i,j)
                if area > largest:
                    largest = area 
                
        # for every coordinate of the grid
        # if it is unvisited land (1) run a flood fill on it - counting the number of nodes visited 
        return largest

sol = Solution()

grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
expect = 6
print(f"expect {expect} {sol.maxAreaOfIsland(grid)}")

grid = [[0,0,0,0,0,0,0,0]]
expect = 0
print(f"expect {expect} {sol.maxAreaOfIsland(grid)}")

