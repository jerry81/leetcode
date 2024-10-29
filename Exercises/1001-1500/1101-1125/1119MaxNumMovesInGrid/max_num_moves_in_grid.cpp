/*

2684. Maximum Number of Moves in a Grid
Medium
Topics
Companies
Hint
You are given a 0-indexed m x n matrix grid consisting of positive integers.

You can start at any cell in the first column of the matrix, and traverse the
grid in the following way:

From a cell (row, col), you can move to any of the cells: (row - 1, col + 1),
(row, col + 1) and (row + 1, col + 1) such that the value of the cell you move
to, should be strictly bigger than the value of the current cell. Return the
maximum number of moves that you can perform.



Example 1:


Input: grid = [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]
Output: 3
Explanation: We can start at the cell (0, 0) and make the following moves:
- (0, 0) -> (0, 1).
- (0, 1) -> (1, 2).
- (1, 2) -> (2, 3).
It can be shown that it is the maximum number of moves that can be made.
Example 2:


Input: grid = [[3,2,4],[2,1,9],[1,1,7]]
Output: 0
Explanation: Starting from any cell in the first column we cannot perform any
moves.


Constraints:

m == grid.length
n == grid[i].length
2 <= m, n <= 1000
4 <= m * n <= 105
1 <= grid[i][j] <= 106
Seen this question in a real interview before?
1/5
Yes
No
Accepted
31.2K
Submissions
63.8K
Acceptance Rate
49.0%

*/

#include <queue>
#include <vector>

using namespace std;

class Solution {
  const vector<pair<int, int>> MOVES = {{-1, 1}, {0, 1}, {1, 1}};

  int dfs(int cr, int cc, int depth, vector<vector<int>>& grid,
          vector<vector<int>>& dp) {
    if (dp[cr][cc] > -1) {
      dp[cr][cc];
    }
  }

 public:
  int maxMoves(vector<vector<int>>& grid) {
    // dp
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> memo = vector<vector<int>>(n, vector<int>(m, -1));

    int res = 0;
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < m; ++c) {
        res = max(res, dfs(r, c, 0, grid, memo));
      }
    }
    return res;
  }
};