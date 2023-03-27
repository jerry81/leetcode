/*

64. Minimum Path Sum
Medium
9.8K
127
Companies
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.



Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 100
Accepted
870.3K
Submissions
1.4M
Acceptance Rate
61.3%

*/

#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;


class Solution {
struct Point {
  int x = -1;
  int y = -1;
  string to_hash() {
    return y+","+x;
  }
};
vector<vector<int>> dists;
vector<vector<int>> original;
int w;
int h;
void pathBFS() {
  unordered_map<string, bool> visited; // is it needed?
  Point root;
  root.x = 0;
  root.y = 0;
  queue<Point> neighbors;
  neighbors.push(root);
  while (!neighbors.empty()) {
    Point cur = neighbors.front();
    neighbors.pop();
    int curx = cur.x;
    int cury = cur.y;
    int lx = curx - 1;
    int rx = curx + 1;
    int uy = cury - 1;
    int dy = cury + 1;
    int left = 0;
    if (lx >= 0) left = original[cury][lx];
    int top = 0;
    if (uy >= 0) top = original[uy][curx];
    int minp = min(left,top);
    dists[cury][curx] = original[cury][curx] + minp;
    if (rx < w) {
      Point right;
      right.x = rx;
      right.y = cury;
      neighbors.push(right);
    }
    if (dy < h) {
      Point down;
      down.x = curx;
      down.y = dy;
      neighbors.push(down);
    }
  }
}
public:
    int minPathSum(vector<vector<int>>& grid) {
      h = grid.size();
      w = grid[0].size();
      for (auto y: grid) {
        vector<int> row;
        for (auto x: y) {
          row.push_back(-1);
        }
        dists.push_back(row);
      }
      pathBFS();
      return dists[h-1][w-1];
    }
};

/*

greedy out because of example 1
comprehensive checking

this is DFS and dfs fails with this scheme
use bfs instead
*/