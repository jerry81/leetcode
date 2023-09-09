/*
766. Toeplitz Matrix
Easy
3.4K
156
Companies
Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return
false.

A matrix is Toeplitz if every diagonal from top-left to bottom-right has the
same elements.



Example 1:


Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
Output: true
Explanation:
In the above grid, the diagonals are:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
In each diagonal all elements are the same, so the answer is True.
Example 2:


Input: matrix = [[1,2],[2,2]]
Output: false
Explanation:
The diagonal "[1, 2]" has different elements.


Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 20
0 <= matrix[i][j] <= 99


Follow up:

What if the matrix is stored on disk, and the memory is limited such that you
can only load at most one row of the matrix into the memory at once? What if the
matrix is so large that you can only load up a partial row into the memory at
once? Accepted 286.8K Submissions 419.2K Acceptance Rate 68.4%
*/

#include <vector>

using namespace std;

class Solution {
 public:
  bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    int h = matrix.size();
    int w = matrix[0].size();
    for (int y = 0; y < h; ++y) {
      int match = matrix[y][0];
      int x = 0;
      int y2 = y;
      while (x < w && y2 < h) {
        if (matrix[y2][x] != match) return false;
        x++;
        y2++;
      }
    }
    for (int x = 0; x < w; ++x) {
      int match = matrix[0][x];
      int y = 0;
      int x2 = x;
      while (x2 < w && y < h) {
        if (matrix[y][x2] != match) return false;
        x2++;
        y++;
      }
    }
    return true;
  }
};