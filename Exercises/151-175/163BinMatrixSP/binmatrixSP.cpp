/*

1091. Shortest Path in Binary Matrix
Medium
4.8K
186
Companies
Given an n x n binary matrix grid, return the length of the shortest clear path
in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0))
to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are
different and they share an edge or a corner). The length of a clear path is the
number of visited cells of this path.



Example 1:


Input: grid = [[0,1],[1,0]]
Output: 2
Example 2:


Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4
Example 3:

Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1


Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 100
grid[i][j] is 0 or 1
Accepted
310.3K
Submissions
689.7K
Acceptance Rate
45.0%

*/

#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    visited[0][0] = true;
    queue<pair<int, int>> nn;
    nn.push({0, 0});
    int pathLength = 0;
    while (!nn.empty()) {
      pathLength++;
      queue<pair<int, int>> nextn;
      while (!nn.empty()) {
        auto [cy, cx] = nn.front();
        nn.pop();
        if (cy == n - 1 && cx == n - 1) {
          return pathLength;
        }
        int uy = cy - 1;
        int dy = cy + 1;
        int lx = cx - 1;
        int rx = cx + 1;
        // add 8 neighbors!
        if (uy >= 0) {
          if (!visited[uy][cx] && grid[uy][cx] == 0) {
            nextn.push({uy, cx});
            visited[uy][cx] = true;
          }
          // up right
          if (rx < n) {
            if (!visited[uy][rx] && grid[uy][rx] == 0) {
              nextn.push({uy, rx});
              visited[uy][rx] = true;
            }
          }
          // up left
          if (lx >= 0) {
            if (!visited[uy][lx] && grid[uy][lx] == 0) {
              nextn.push({uy, lx});
              visited[uy][lx] = true;
            }
          }
        }

        if (dy < n) {
          if (!visited[dy][cx] && grid[dy][cx] == 0) {
            nextn.push({dy, cx});
            visited[dy][cx] = true;
          }
          // up right
          if (rx < n) {
            if (!visited[dy][rx] && grid[dy][rx] == 0) {
              nextn.push({dy, rx});
              visited[dy][rx] = true;
            }
          }
          // up left
          if (lx >= 0) {
            if (!visited[dy][lx] && grid[dy][lx] == 0) {
              nextn.push({dy, lx});
              visited[dy][lx] = true;
            }
          }
        }

        if (lx >= 0) {
          if (!visited[cy][lx] && grid[cy][lx] == 0) {
            nextn.push({cy, lx});
            visited[cy][lx] = true;
          }
        }

        if (rx < n) {
          if (!visited[cy][rx] && grid[cy][rx] == 0) {
            nextn.push({cy, rx});
            visited[cy][rx] = true;
          }
        }
      }
      nn = nextn;
    }
    return -1;
  }
};