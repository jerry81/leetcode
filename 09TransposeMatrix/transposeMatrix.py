from typing import List


class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        return 

s = Solution()
matrix = [[1,2,3],[4,5,6],[7,8,9]]
expected = [[1,4,7],[2,5,8],[3,6,9]]
print(f"expect {expected} {s.transpose(matrix)}")

matrix = [[1,2,3],[4,5,6]]
expected = [[1,4],[2,5],[3,6]]
print(f"expect {expected} {s.transpose(matrix)}")