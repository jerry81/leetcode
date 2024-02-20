/*

931. Minimum Falling Path Sum
Medium

5846

142

Add to List

Share
Given an n x n array of integers matrix, return the minimum sum of any falling
path through matrix.

A falling path starts at any element in the first row and chooses the element in
the next row that is either directly below or diagonally left/right.
Specifically, the next element from position (row, col) will be (row + 1, col -
1), (row + 1, col), or (row + 1, col + 1).



Example 1:


Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
Example 2:


Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.


Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100
Accepted
351,145
Submissions
541,487

*/

#include <vector>

using namespace std;

class Solution {
 public:
  int minFallingPathSum(vector<vector<int>>& matrix) {
    int h = matrix.size();
    int w = matrix[0].size();
    vector<vector<int>> grid = matrix;
    for (int i = h - 2; i >= 0; --i) {
      vector<int> row = grid[i];
      vector<int> next_row = grid[i + 1];
      for (int j = 0; j < w; ++j) {
        int mn = next_row[j];
        if (j > 0) mn = min(next_row[j - 1], mn);

        if (j < (w - 1)) mn = min(next_row[j + 1], mn);

        grid[i][j] += mn;
      }
    }
    int mn = INT_MAX;
    for (int i: grid[0]) {
      mn = min(mn, i);
    }
    return mn;
  }
};