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
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
    int h = matrix.size();
    int w = matrix[0].size();
    int res = 0;

    vector<vector<int>> prefix_forward;
    for (int idx = 0; idx < matrix.size(); ++idx) {
      vector<int> v = matrix[idx];
      vector<int> cur;
      int sm = 0;
      for (int i = 0; i < v.size(); ++i) {
        sm += v[i];

        int mod = (idx > 0) ? prefix_forward[idx - 1][i] : 0;
        if (sm + mod == target) res++;
        cur.push_back(sm + mod);
      }

      prefix_forward.push_back(cur);
    }
    for (int ys = 0; ys < h; ++ys) {
      for (int xs = 0; xs < w; ++xs) {
        if (ys == 0 && xs == 0) continue;

        for (int ye = ys; ye < h; ++ye) {
          for (int xe = xs; xe < w; ++xe) {
            int sub1 = xs > 0 ? prefix_forward[ye][xs - 1] : 0;
            int sub2 = ys > 0 ? prefix_forward[ys - 1][xe] : 0;
            int add = (xs > 0 && ys > 0) ? prefix_forward[ys - 1][xs - 1] : 0;
            int cur = prefix_forward[ye][xe] - sub1 - sub2 + add;
            if (cur == target) res++;
          }
        }
      }
    }

    return res;
  }
};