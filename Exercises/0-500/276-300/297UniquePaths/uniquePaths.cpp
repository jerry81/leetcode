/*

62. Unique Paths
Medium
15K
404
Companies
There is a robot on an m x n grid. The robot is initially located at the
top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right
corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right
at any point in time.

Given the two integers m and n, return the number of possible unique paths that
the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2
* 109.



Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the
bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down


Constraints:

1 <= m, n <= 100
Accepted
1.5M
Submissions
2.4M
Acceptance Rate
63.1%

*/

#include <vector>

using namespace std;
class Solution {
  vector<vector<int>> dp;
  int r(int &m, int &n, int x, int y) {
    if (x >= m) return 0;

    if (y >= n) return 0;

    if (dp[y][x] > -1) return dp[y][x];

    dp[y][x] = r(m, n, x + 1, y) + r(m, n, x, y + 1);
    return dp[y][x];
  }

 public:
  int uniquePaths(int m, int n) {
    dp.resize(n, vector<int>(m, -1));
    dp[n - 1][m - 1] = 1;
    return r(m, n, 0, 0);
  }
};