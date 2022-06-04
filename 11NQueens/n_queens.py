from typing import List

class Solution:
    def place_queen(self, matrix, y, x):
        l = len(matrix)
        cp = matrix.copy()
        cp[y][x] = 'Q'
        for off in range(l):
          if off != x:
            cp[y][off] = 'x'

          if off != y:
            cp[off][x] = 'x'

          # diagonal
          if off == 0: 
              continue

          if (off+x) < l and (off+y) < l:
              cp[off+y][off+x] = 'x'
          
          if (x-off) >= 0 and (y-off) >= 0:
              cp[y-off][x-off] = 'x'
          
          # reverse diag

          if (off+x) < l and (y-off) >= 0:
              cp[y-off][x+off] = 'x'

          if (x-off) >= 0 and (y+off) < l:
              cp[y+off][x-off] = 'x'
        return cp

    def solveNQueens(self, n: int) -> List[List[str]]:
        matrix = [['.'] * n for _ in range(n)]
        print(f"matrix is {matrix}")
        return [['Q']]

s = Solution()
print(f"expect [['Q']] {s.solveNQueens(1)}")

print(f"place queen test: ")
mat = [['.']*3 for _ in range(3)]
print(f"result {s.place_queen(mat, 0,0)}")

print(f"place queen test: ")
mat = [['.']*4 for _ in range(4)]
print(f"result {s.place_queen(mat, 0,0)}")