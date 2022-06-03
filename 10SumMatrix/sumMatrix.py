from typing import List


class NumMatrix:

    
    def __init__(self, matrix: List[List[int]]):
        self.matrix = matrix
        self.memo = {}
    
    def make_key(self,row1,col1,row2,col2):
      return f"{row1},{col1},{row2},{col2}"

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        key = self.make_key(row1,col1,row2,col2)
        lines = self.matrix[row1:(row2+1)]
        tot = 0
        try:
          tot = self.memo[key]
          return tot
        except:
          for l in lines:
              tot += sum(l[col1:(col2+1)])
          self.memo[key] = tot
          return tot

nm = NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]])
print(f"nm.matrix is {nm.matrix}")
out1 = nm.sumRegion(2, 1, 4, 3); 
print(f"expect 8 {out1}")
# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)