import sys
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

sol = Solution()

mat = [[0,0,0],[0,1,0],[0,0,0]]
expect = [[0,0,0],[0,1,0],[0,0,0]]
print(f"expect {expect} {sol.updateMatrix(mat)}")

mat = [[0,0,0],[0,1,0],[1,1,1]]
expect = [[0,0,0],[0,1,0],[1,2,1]]
print(f"expect {expect} {sol.updateMatrix(mat)}")

mat = [[1,1,0,0,1,0,0,1,1,0],[1,0,0,1,0,1,1,1,1,1],[1,1,1,0,0,1,1,1,1,0],[0,1,1,1,0,1,1,1,1,1],[0,0,1,1,1,1,1,1,1,0],[1,1,1,1,1,1,0,1,1,1],[0,1,1,1,1,1,1,0,0,1],[1,1,1,1,1,0,0,1,1,1],[0,1,0,1,1,0,1,1,1,1],[1,1,1,0,1,0,1,1,1,1]]
expect = "something good"
print(f"expect {expect} {sol.updateMatrix(mat)}")

"""
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) 
            return matrix;
        int cols = matrix[0].size();
        vector<vector<int>> dist(rows, vector<int> (cols, INT_MAX - 100000));

        //First pass: check for left and top
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                } else {
                    if (i > 0)
                        dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                    if (j > 0)
                        dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
                }
            }
        }

        //Second pass: check for bottom and right
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                if (i < rows - 1)
                    dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                if (j < cols - 1)
                    dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
            }
        }
        return dist;
    }
};
"""