/*

934. Shortest Bridge
Medium
3.6K
152
Companies
You are given an n x n binary matrix grid where 1 represents land and 0
represents water.

An island is a 4-directionally connected group of 1's not connected to any other
1's. There are exactly two islands in grid.

You may change 0's to 1's to connect the two islands to form one island.

Return the smallest number of 0's you must flip to connect the two islands.



Example 1:

Input: grid = [[0,1],[1,0]]
Output: 1
Example 2:

Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2
Example 3:

Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1


Constraints:

n == grid.length == grid[i].length
2 <= n <= 100
grid[i][j] is either 0 or 1.
There are exactly two islands in grid.
Accepted
128.3K
Submissions
236K
Acceptance Rate
54.4%

*/

#include <queue>
#include <vector>

using namespace std;

class Solution {
  // step1:
  // get 2 islands first
  // how to represent island
  // just vector of {x,y}
  // then dist from each block in island 1 to each block in island 2
  vector<pair<int, int>> island1;
  vector<pair<int, int>> island2;
  vector<vector<bool>> visited;

  void bfs(bool isFirst, int y, int x,vector<vector<int>>& grid) {
    queue<pair<int, int>> nn;
    nn.push({y, x});
    visited[y][x] = true;
    while (!nn.empty()) {
      auto pr = nn.front();
      nn.pop();
      int nx = pr.second;
      int ny = pr.first;
      if (isFirst) {
        island1.push_back(pr);
      } else {
        island2.push_back(pr);
      }
      int lx = nx - 1;
      int rx = nx + 1;
      int dy = ny + 1;
      int uy = ny - 1;
      if (lx >= 0 && !visited[ny][lx] && grid[ny][lx]) {
        visited[ny][lx] = true;
        nn.push({ny, lx});
      }
      if (rx < visited.size() && !visited[ny][rx] && grid[ny][rx]) {
        visited[ny][rx] = true;
        nn.push({ny, rx});
      }
      if (dy < visited.size() && !visited[dy][nx] && grid[dy][nx]) {
        visited[dy][nx] = true;
        nn.push({dy, nx});
      }
      if (uy >= 0 && !visited[uy][nx] && grid[uy][nx]) {
        visited[uy][nx] = true;
        nn.push({uy, nx});
      }
    }
  }

  void makeIslands(vector<vector<int>>& grid) {
    bool firstIslandFound = false;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid.size(); ++j) {
        if (!grid[i][j]) continue;

        if (!visited[i][j]) {
          bfs(!firstIslandFound, i, j, grid);
          firstIslandFound = true;
        }
      }
    }
  }
  int getMinDist() {
    int mn = INT_MAX;
    for (auto pr:island1) {
      for (auto pr2:island2) {
        int dist = abs(pr.first-pr2.first) + abs(pr.second-pr2.second);
        mn = std::min(dist-1,mn);
      }
    }
    return mn;
  }

 public:
  int shortestBridge(vector<vector<int>>& grid) {
    int s = grid.size();
    vector<vector<bool>> _visited(s, vector<bool>(s, false));
    visited = _visited;
    makeIslands(grid);
    return getMinDist();
  }
};

/*
  01
  10
*/

/*
expect 2
*/
/*
[[0,1,0],[0,0,0],[0,0,1]]

010
000
001

*/

/*
expect 1
[[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
11111
10001
10101
10001
11111

case, expect 1
[[0,0,0,1,1],[0,0,0,1,0],[0,0,0,1,1],[0,0,1,0,1],[0,0,1,1,0]]
00011
00010
00011
00101
00110
*/