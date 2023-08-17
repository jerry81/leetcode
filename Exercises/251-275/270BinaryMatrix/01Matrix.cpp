/*

542. 01 Matrix
Medium
8.1K
363
Companies
Given an m x n binary matrix mat, return the distance of the nearest 0 for each
cell.

The distance between two adjacent cells is 1.



Example 1:


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
Example 2:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]


Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
mat[i][j] is either 0 or 1.
There is at least one 0 in mat.
Accepted
438.6K
Submissions
944.7K
Acceptance Rate
46.4%

*/

#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;
class Solution {
  string hsh(int y, int x) { return to_string(y) + "," + to_string(x); }

 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    queue<pair<int,int>> neighbors;
    int h = mat.size();
    int w = mat[0].size();
    vector<vector<int>> res(h, vector<int>(w, 0));

    for (int y = 0; y < mat.size(); ++y) {
      for (int x = 0; x < mat[0].size(); ++x) {
        if (mat[y][x] == 0) {
          res[y][x] = 0;
          neighbors.push({y,x});
        }
      }
    }

    while (!neighbors.empty()) {
      queue<pair<int,int>> nn;
      while (!neighbors.empty()) {

      }
    }

    return res;
  }
};