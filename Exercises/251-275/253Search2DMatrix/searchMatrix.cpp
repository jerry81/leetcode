/*

74. Search a 2D Matrix
Medium
13.3K
368
Companies
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous
row. Given an integer target, return true if target is in matrix or false
otherwise.

You must write a solution in O(log(m * n)) time complexity.



Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false


Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
Accepted
1.3M
Submissions
2.8M
Acceptance Rate
48.4%

*/

#include <vector>

using namespace std;

class Solution {
  bool bsearch(int tgt, vector<vector<int>>& matrix) {
    int rmin = 0;
    int rmax = matrix.size() - 1;
    int rmid = 0;
    int tgtR = 0;
    while (rmin < rmax) {
      rmid = (rmin + rmax) / 2;
      int midv = matrix[rmid][0];
      if (midv == tgt) return true;
      if (midv > tgt) {
        rmax = rmid - 1;
      }
      if (midv < tgt) {
        tgtR = rmid;
        rmin = rmid + 1;
      }
    }

    vector<int> cand = matrix[tgtR];
    int cmin = 0;
    int cmax = cand.size() - 1;
    int cmid = 0;
    while (cmin < cmax) {
      cmid = (cmin + cmax) / 2;
      int midv = cand[cmid];
      if (midv == tgt) return true;
      if (midv > tgt) {
        cmax = cmid - 1;
      }
      if (midv < tgt) {
        cmin = cmid + 1;
      }
    }
    return false;
  }

 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    return bsearch(target, matrix);
  }
};

// 2 bsearches?
//