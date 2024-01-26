/*

576. Out of Boundary Paths
Medium
Topics
Companies
Hint
There is an m x n grid with a ball. The ball is initially at the position
[startRow, startColumn]. You are allowed to move the ball to one of the four
adjacent cells in the grid (possibly out of the grid crossing the grid
boundary). You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the number
of paths to move the ball out of the grid boundary. Since the answer can be very
large, return it modulo 109 + 7.



Example 1:


Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6
Example 2:


Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
Output: 12


Constraints:

1 <= m, n <= 50
0 <= maxMove <= 50
0 <= startRow < m
0 <= startColumn < n
Seen this question in a real interview before?
1/4
Yes
No
Accepted
128.3K
Submissions
287.2K
Acceptance Rate
44.7%

*/

#include <vector>

using namespace std;

class Solution {
  const int MOD = 10e9 + 7;
  vector<vector<int>> dp;
  const vector<vector<int>> NEIGHBORS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  int r(int y, int x, int movesLeft, int &h, int &w) {
    if (movesLeft <= 0) return 0;

    if (y >= h || x >= w) return 0;

    if (y < 0 || x < 0) return 0;

    if (dp[y][x] >= 0) return dp[y][x];

    long long int total = 0;
    for (auto v: NEIGHBORS) {
      int dy = v[0];
      int dx = v[1];
      int ny = dy+y;
      int nx = dx+x;
      if (ny >= h || nx >= w || ny < 0 || nx < 0) {
        total+=1;
      } else {
        total+=r(ny,nx,movesLeft-1,h,w);
      }
    }
    return dp[y][x] = total;
  }

 public:
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    dp.resize(m + 1, vector<int>(n + 1, -1));
    return r(startRow, startColumn, maxMove, m, n);
  }
};