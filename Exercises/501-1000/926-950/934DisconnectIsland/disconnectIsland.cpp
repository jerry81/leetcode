/*

1568. Minimum Number of Days to Disconnect Island
Hard
Topics
Companies
Hint
You are given an m x n binary grid grid where 1 represents land and 0 represents
water. An island is a maximal 4-directionally (horizontal or vertical) connected
group of 1's.

The grid is said to be connected if we have exactly one island, otherwise is
said disconnected.

In one day, we are allowed to change any single land cell (1) into a water cell
(0).

Return the minimum number of days to disconnect the grid.



Example 1:


Input: grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]

Output: 2
Explanation: We need at least 2 days to get a disconnected grid.
Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.
Example 2:


Input: grid = [[1,1]]
Output: 2
Explanation: Grid of full water is also disconnected ([[1,1]] -> [[0,0]]), 0
islands.


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 30
grid[i][j] is either 0 or 1.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
18.5K
Submissions
39.2K
Acceptance Rate
47.3%

*/

#include <queue>
#include <set>
#include <vector>

using namespace std;

class Solution {
  vector<pair<int, int>> DIR = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
  set<pair<int, int>> lands;
  int countIslands(vector<vector<int>> grid) {
    int h = grid.size();
    int w = grid[0].size();
    int res = 0;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (grid[i][j] == 1) {
          lands.insert({i, j});
          // flood fill
          queue<pair<int, int>> q;
          q.push({i, j});
          res += 1;
          while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            grid[i][j] = 0;
            for (auto [dy, dx] : DIR) {
              int ny = dy + r;
              int nx = dx + c;
              if (ny >= 0 && ny < h && nx >= 0 && nx < w) {
                if (grid[ny][nx] == 1) {
                  lands.insert({ny, nx});
                  q.push({ny, nx});
                  grid[ny][nx] = 0;
                }
              }
            }
          }
        }
      }
    }
    return res;
  }

 public:
  int minDays(vector<vector<int>>& grid) {
    // brute force - exponential complexity (full game tree) so no
    // logic approach: find thinnest cross-section (constant 2) - hard
    // identify mum of islands with flood fill
    // check every cell, if land encountered, floodfill with water
    int islands = countIslands(grid);
    if (islands == 0 || islands > 1) return 0;

    // need another check
    // brute check if changing one land to water satsfies

    for (auto [y, x] : lands) {
      grid[y][x] = 0;
      int islands = countIslands(grid);
      if (islands == 0 || islands > 1) return 1;

      grid[y][x] = 1;
    }
    return 2;
  }
};