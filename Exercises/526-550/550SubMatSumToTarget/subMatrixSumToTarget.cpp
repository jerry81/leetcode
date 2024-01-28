/*

1074. Number of Submatrices That Sum to Target
Hard
Topics
Companies
Hint
Given a matrix and a target, return the number of non-empty submatrices that sum
to target.

A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <=
x2 and y1 <= y <= y2.

Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they
have some coordinate that is different: for example, if x1 != x1'.



Example 1:


Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
Output: 4
Explanation: The four 1x1 submatrices that only contain 0.
Example 2:

Input: matrix = [[1,-1],[-1,1]], target = 0
Output: 5
Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2
submatrix. Example 3:

Input: matrix = [[904]], target = 0
Output: 0


Constraints:

1 <= matrix.length <= 100
1 <= matrix[0].length <= 100
-1000 <= matrix[i] <= 1000
-10^8 <= target <= 10^8
Seen this question in a real interview before?
1/4
Yes
No
Accepted
98K
Submissions
139K
Acceptance Rate
70.5%

*/
#include <map>
#include <vector>

using namespace std;
class Solution {
  map<tuple<int, int, int, int>, int> sums;

  int r(int sy, int sx, int ey, int ex, int& target) {}

 public:
  int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    // for each item
    int h = matrix.size();
    int w = matrix[0].size();
    int sum = 0;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; ++j) {
        sum += r(i, j, i, j, target);
      }
    }
    return sum;
  }
};

// vector<vector<int>> prefix_forward;
// vector<vector<int>> prefix_backward;
// for (vector<int> v : matrix) {
//   vector<int> cur;
//   int sm = 0;
//   for (int i : v) {
//     sm += i;
//     cur.push_back(sm);
//   }
//   prefix_forward.push_back(cur);
// }
// for (vector<int> v : matrix) {
//   int sm = 0;
//   vector<int> vc = v;
//   vector<int> cur;
//   reverse(vc.begin(), vc.end());
//   for (int i : vc) {
//     sm += i;
//     cur.push_back(sm);
//     prefix_backward.push_back(cur);
//   }
// }