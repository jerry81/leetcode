/*

1727. Largest Submatrix With Rearrangements
Medium
1K
32
Companies
You are given a binary matrix matrix of size m x n, and you are allowed to
rearrange the columns of the matrix in any order.

Return the area of the largest submatrix within matrix where every element of
the submatrix is 1 after reordering the columns optimally.



Example 1:


Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]
Output: 4
Explanation: You can rearrange the columns as shown above.
The largest submatrix of 1s, in bold, has an area of 4.
Example 2:


Input: matrix = [[1,0,1,0,1]]
Output: 3
Explanation: You can rearrange the columns as shown above.
The largest submatrix of 1s, in bold, has an area of 3.
Example 3:

Input: matrix = [[1,1,0],[1,0,1]]
Output: 2
Explanation: Notice that you must rearrange entire columns, and there is no way
to make a submatrix of 1s larger than an area of 2.


Constraints:

m == matrix.length
n == matrix[i].length
1 <= m * n <= 105
matrix[i][j] is either 0 or 1.
Accepted
17.5K
Submissions
27.8K
Acceptance Rate
63.0%

*/

#include <vector>

using namespace std;

class Solution {
 public:
  int largestSubmatrix(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> ref(rows, vector<int>(cols, 0));
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        int val = matrix[i][j];
        if (i == 0) {
          ref[i][j] = val;
          continue;
        }
        int prev = i-1;
        ref[i][j] = val ? prev+1 : 0;
      }
    }
    int res = 0;
    for (int i = 0; i < rows; ++i) {
      auto row = ref[i];
      sort(row.begin(), row.end());
      int maxh = 0;
      for (int j = 0; j < cols; ++j) {
        maxh = max(maxh, row[j];
        int area = (j+1) * maxh;
        res = max(area,res);
      }
    }
    return res;
  }
};