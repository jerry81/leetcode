from typing import List


class Solution:
     def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        rows = len(mat)
        if (rows == 0):
            return mat
        cols = len(mat[0])
        updated = [[sys.maxsize] * cols for _ in range(rows)]
        for i in range(rows):
            for j in range(cols):
                if mat[i][j] == 0:
                    updated[i][j] = 0
                else:
                    if i > 0:
                        updated[i][j] = min(updated[i-1][j] + 1, updated[i][j])
                    if j > 0:
                        updated[i][j] = min(updated[i][j-1] + 1, updated[i][j])
        for y in range(rows):
            for x in range(cols):
                i = rows - y - 1
                j = cols - x - 1
                if i < (rows - 1):
                    updated[i][j] = min(updated[i][j], 1 + updated[i+1][j])
                if j < (cols - 1):
                    updated[i][j] = min(updated[i][j], 1 + updated[i][j+1])
        return updated
    
     def orangesRotting(self, grid: List[List[int]]) -> int:
        updated = self.updateMatrix(grid)
        print(f"updated is {updated}")

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
