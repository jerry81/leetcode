/*


1289. Minimum Falling Path Sum II
Hard
Topics
Companies
Hint
Given an n x n integer matrix grid, return the minimum sum of a falling path with non-zero shifts.

A falling path with non-zero shifts is a choice of exactly one element from each row of grid such that no two elements chosen in adjacent rows are in the same column.



Example 1:


Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
Output: 13
Explanation:
The possible falling paths are:
[1,5,9], [1,5,7], [1,6,7], [1,6,8],
[2,4,8], [2,4,9], [2,6,7], [2,6,8],
[3,4,8], [3,4,9], [3,5,7], [3,5,9]
The falling path with the smallest sum is [1,5,7], so the answer is 13.
Example 2:

Input: grid = [[7]]
Output: 7


Constraints:

n == grid.length == grid[i].length
1 <= n <= 200
-99 <= grid[i][j] <= 99
Seen this question in a real interview before?
1/5
Yes
No
Accepted
74.5K
Submissions
122.8K
Acceptance Rate
60.7%

*/

#include <vector>

using namespace std;

class Solution {
vector<vector<int>> memo;
int r(int col, int row, vector<vector<int>>& grid, int& sz) {
  if (row == sz-1) return grid[row][col];
  if (memo[row][col] != INT_MIN) return memo[row][col];
  int mn = INT_MAX;
  for (int i = 0; i < sz; ++i) {
    if (i == col) continue;
    int nr = row+1;
    int added = row == 0 ? 0 : grid[row][i];
    mn = min(mn, added + r(i, nr, grid, sz));
  }
  memo[row][col] = mn;
  return mn;
}
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
      // brute force, sort rows times
      int res = INT_MAX;
      int h = grid.size();
      int w = grid[0].size();

      memo.resize(h, vector<int>(w,INT_MIN));
      for (int i = 0; i < w; ++i) {
        res = min(res, r(i, 0, grid, h));
      }
      return res;
    }
};