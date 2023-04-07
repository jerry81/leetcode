/*

1020. Number of Enclaves
Medium
2.6K
47
Companies
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1
represents a land cell.

A move consists of walking from one land cell to another adjacent
(4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the
boundary of the grid in any number of moves.



Example 1:


Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not
enclosed because its on the boundary. Example 2:


Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid[i][j] is either 0 or 1.

*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
  bool* visited;
  int height;
  int width;
  vector<vector<int>> orig;
  struct Point {
    int x;
    int y;
    Point(int x, int y) : x(x), y(y){};
  };

  bool isDone(Point p) { return visited[p.y * height + p.x]; }

  void visit(Point p) { visited[p.y * height + p.x] = true; }

  int bfs(Point start) {
    if (isDone(start)) return 0;

    queue<Point> remain;
    remain.push(start);
    visit(start);
    int count = 0;
    bool canExit = false;
    while (!remain.empty()) {
      Point cur = remain.front();
      int cx = cur.x;
      int cy = cur.y;
      if (orig[cy][cx] == 1) count++;
      remain.pop();
      if (cx <= 0) canExit = true;

      if (cy <= 0) canExit = true;

      if (cx >= (width - 1)) canExit = true;

      if (cy >= (height - 1)) canExit = true;

      int lx = cx - 1;
      int rx = cx + 1;
      int uy = cy - 1;
      int dy = cy + 1;
      Point lp = Point(lx,cy);
      Point rp = Point(rx,cy);
      Point up = Point(cx,uy);
      Point dp = Point(cx,dy);
      if (lx >= 0 && !isDone(lp)) {
        remain.push(lp);
        visit(lp);
      }

      if (rx < width && !isDone(rp)) {
        remain.push(rp);
        visit(rp);
      }

      if (uy >= 0 && !isDone(up)) {
        remain.push(up);
        visit(up);
      }

      if (dy >= 0 && !isDone(dp)) {
        remain.push(dp);
        visit(dp);
      }
    }

    if (canExit) return 0;

    return count;
  }

 public:
  int numEnclaves(vector<vector<int>>& grid) {
    orig = grid;
    height = (int)grid.size();
    int m = (int)grid[0].size();
    width = m;
    visited = new bool[height * m];
    memset(visited, false, sizeof(visited));
    int total = 0;
    for (int i = 0; i < height; ++i) {
      for (int j = 0; j < width: ++j) {
            Point p = Point(j,i);
            total += bfs(p);
      }

    }
    return total;
  }
};

/*

this is a bfs islands problem.
additional check for if node of island is on edge

*/