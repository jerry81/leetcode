from typing import List


class Solution:
    def getMinDist(self,x,y):
        return 9999
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        return 

sol = Solution()

mat = [[0,0,0],[0,1,0],[0,0,0]]
expect = [[0,0,0],[0,1,0],[0,0,0]]
print(f"expect {expect} {sol.updateMatrix(mat)}")

mat = [[0,0,0],[0,1,0],[1,1,1]]
expect = [[0,0,0],[0,1,0],[1,2,1]]
print(f"expect {expect} {sol.updateMatrix(mat)}")
