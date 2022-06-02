from typing import List


class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        yl = len(matrix)
        xl = len(matrix[0])
        transposed = [ [0]*yl for _ in range(xl)]
        print(f"transposed is {transposed}")
        for y,i in enumerate(matrix):
            for x,j in enumerate(i):
                print(f"y is {y} x is {x}")
                transposed[x][y] = j
        return transposed
            

s = Solution()
matrix = [[1,2,3],[4,5,6],[7,8,9]]
expected = [[1,4,7],[2,5,8],[3,6,9]]
print(f"expect {expected} {s.transpose(matrix)}")

matrix = [[1,2,3],[4,5,6]]
expected = [[1,4],[2,5],[3,6]]
print(f"expect {expected} {s.transpose(matrix)}")