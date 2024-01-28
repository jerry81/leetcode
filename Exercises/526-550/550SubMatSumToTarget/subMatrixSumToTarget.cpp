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
    // for each item
    int h = matrix.size();
    int w = matrix[0].size();
    int res = 0;

    vector<vector<int>> prefix_forward;
    // vector<vector<int>> prefix_backward;
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
    for (auto v: prefix_forward) {
    cout << endl;
      for (auto w: v) {
        cout << w << ",";
      }
    }
    for (int ys = 0; ys < h; ++ys) {
      for (int xs = 0; xs < w; ++xs) {
        if (ys == 0 && xs == 0) continue;

        for (int ye = ys; ye < h; ++ye) {
          for (int xe = xs; xe < w; ++xe) {
            // submatrix from ys, xs to ye, xe
            int sub1 = xe > 0 ? prefix_forward[ye][xe-1] : 0;
            int sub2 = ye > 0 ? prefix_forward[ye-1][xe] : 0;
            int add = xe >0 && ye > 0 ? prefix_forward[ye-1][xe-1] : 0;
            int cur = prefix_forward[ye][xe] - sub1 - sub2 + add;
            if (cur == target) res++;
          }
        }
      }
    }

    return 1;
  }
};

/*

0,1,1,
1,3,4,
1,4,5,

*/

/*
  this covers 9 matrixes all submatrixes with 0,0
  for 0,1
  we have 0,1 by itself (0,1) - (0,0)
  0,1 to 0,2 (0,2) - (0,0)
  0,1 to 1,1 (1,1) - (1,0)
  0,1 to 1,2 (1,2) - (1,0)
  0,1 to 2,1 (2,1) - (2,0)
  0,1 to 2,2 (2,2) - (2,0)

0,1,1,
1,3,4,
1,4,5,

  starting from 1,1
  1,1 -> 1,1 - 1,0 - 0,1 + 0,0
  1,1 to 1,2 -> 1,2 - 0,2 - 1,0 + 0,0
  1,1 to 2,1 -> 2,1 - 2,0 - 0,1 + 0,0
  1,1 to 2,2 -> 2,2 - 2,0 - 0,2 + 0,0

0,1,1,
1,3,4,
1,4,5,

starting from 1,0
1,0 by itself 1,0 - 0,0
1,0 to 1,1 -> 1,1 - 0,1
1,0 to 2,0 -> 2,0 - 0,0
1,0 to 1,2 -> 1,2 - 0,2

starting from 2,0
2,0 by itself is 2,0 - 1,0
2,0 to 2,1 -> 2,1 - 1,1
2,0 to 2,2 -> 2,2 - 1,2
*/