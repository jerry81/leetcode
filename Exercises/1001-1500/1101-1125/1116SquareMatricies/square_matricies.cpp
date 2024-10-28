/*

1277. Count Square Submatrices with All Ones
Medium
Topics
Companies
Hint
Given a m * n matrix of ones and zeros, return how many square submatrices have
all ones.



Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation:
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix =
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation:
There are 6 squares of side 1.
There is 1 square of side 2.
Total number of squares = 6 + 1 = 7.


Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1
Seen this question in a real interview before?
1/5
Yes
No
Accepted
247.3K
Submissions
325.2K
Acceptance Rate
76.0%

*/

#include <vector>

using namespace std;
class Solution {
 public:
  int countSquares(vector<vector<int>>& matrix) {
    int height = matrix.size();
    int width = matrix[0].size();
    int res = 0;
    vector<vector<int>> dp(height, vector<int>(width, 0));

    for (int r = 0; r < height; r++) {
      for (int c = 0; c < width; c++) {
        if (matrix[r][c] == 1) {
          if (r == 0 || c == 0) {
            dp[r][c] = 1; // First row or column
          } else {
            dp[r][c] = min({dp[r - 1][c], dp[r][c - 1], dp[r - 1][c - 1]}) + 1; // DP relation
          }
          res += dp[r][c]; // Add the size of the square ending at (r, c) to the result
        }
      }
    }
    return res;
  }
};