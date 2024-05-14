/*

1219. Path with Maximum Gold
Medium
Topics
Companies
Hint
In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

Every time you are located in a cell you will collect all the gold in that cell.
From your position, you can walk one step to the left, right, up, or down.
You can't visit the same cell more than once.
Never visit a cell with 0 gold.
You can start and stop collecting gold from any position in the grid that has some gold.


Example 1:

Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
Output: 24
Explanation:
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Path to get the maximum gold, 9 -> 8 -> 7.
Example 2:

Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
Output: 28
Explanation:
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 15
0 <= grid[i][j] <= 100
There are at most 25 cells containing gold.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
120.7K
Submissions
188.2K
Acceptance Rate
64.1%

*/

#include <vector>
#include <queue>

using namespace std;

class Solution {

int bfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>> &visited, int &h, int &w) {
}
public:
    int getMaximumGold(vector<vector<int>>& grid) {
      int h = grid.size();
      int w = grid[0].size();
      int res = 0;
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          if (grid[i][j] == 0) continue;

          vector<vector<bool>> visited(h, vector<bool>(w, false));
          int cur = bfs(i,j,grid,visited, h,w);
          res = max(res,cur);
        }
      }
      return res;
    }
};