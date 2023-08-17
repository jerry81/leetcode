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

  vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    queue<pair<int,int>> neighbors;
    int h = mat.size();
    int w = mat[0].size();
    vector<vector<int>> res(h, vector<int>(w, 0));
    unordered_map<string, bool> visited;
    for (int y = 0; y < mat.size(); ++y) {
      for (int x = 0; x < mat[0].size(); ++x) {
        if (mat[y][x] == 0) {
          neighbors.push({y,x});
          visited[hsh(y,x)] = true;
        }
      }
    }

    int dst = 0;
    while (!neighbors.empty()) {
      queue<pair<int,int>> nn;
      while (!neighbors.empty()) {
        auto [cy,cx] = neighbors.front();
        neighbors.pop();
        res[cy][cx] = dst;
        for (auto a: dirs) {
          int ny = a[0] + cy;
          int nx = a[1] + cx;
          string asHsh = hsh(ny,nx);
          if (visited[asHsh]) continue;
          if (ny < 0) continue;

          if (ny >= h) continue;

          if (nx < 0) continue;

          if (nx >= w) continue;

          nn.push({ny,nx});

          visited[asHsh] = true;
        }
      }
      dst++;
      neighbors = nn;
    }

    return res;
  }
};