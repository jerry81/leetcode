/*
1905. Count Sub Islands
Medium
Topics
Companies
Hint
You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.

An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.

Return the number of islands in grid2 that are considered sub-islands.



Example 1:


Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
Output: 3
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.
Example 2:


Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
Output: 2
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are two sub-islands.


Constraints:

m == grid1.length == grid2.length
n == grid1[i].length == grid2[i].length
1 <= m, n <= 500
grid1[i][j] and grid2[i][j] are either 0 or 1.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
104.5K
Submissions
153.2K
Acceptance Rate
68.2%
*/

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
      int h = grid1.size();
      int w = grid1[0].size();
      const vector<pair<int,int>> NEIGH = {
        {-1,0},{1,0},
        {0,-1},{0,1}
      };

      vector<vector<pair<int,int>>> islands;
      int res = 0;

      vector<vector<bool>> visited(h, vector<bool>(w, false));

      // for each square in grid 2
      for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
          // bfs if not visited and 1
          if (visited[y][x]) continue;

          if (grid2[y][x] == 0) continue;

          queue<pair<int,int>> q;
          q.push({y,x});
          visited[y][x] = true;
          vector<pair<int,int>> currentIsland;

          while (!q.empty()) {
            auto [cy,cx] = q.front();
            q.pop();
            if (visited[cy][cx]) continue;

            visited[cy][cx] = true;
            currentIsland.push_back({y,x});
            for (auto [dy,dx]: NEIGH) {
              int ny = dy+cy;
              int nx = dx+cx;

              if (ny < h && ny >= 0 && nx < w && nx >= 0 && !visited[ny][nx]) queue.push({ny,nx});
            }
          }
        }
      }

      return res;
    }
};

// bfs to find islands on island 2.

// island 1 is just a lookup table