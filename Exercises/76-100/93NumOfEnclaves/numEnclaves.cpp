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
  bool *visited;
  int height;
  struct Point {
    int x;
    int y;
    Point(int x, int y) : x(x), y(y){};
  };

  bool isDone(Point p) {
    return visited[p.y*height + p.x];
  }

  void visit(Point p) {
    visited[p.y*height + p.x] = true;
  }

  int bfs(Point start) {
    cout << "expect 1 " << isDone(start) << endl;
    queue<Point> remain;
    remain.push(start);
    if (isDone(start)) return 0;
    while (!remain.empty()) {
    }
  }

 public:
  int numEnclaves(vector<vector<int>>& grid) {
    height = (int)grid.size();
    int m = (int)grid[0].size();
    visited = new bool[height*m];
    memset(visited, false, sizeof(visited));
    Point test = Point(0,0);
    cout << "testing expect 0: " << isDone(test) << endl;
    Point p = Point(0,0);
    visit(p);
    bfs(p);
    return 0;
  }
};

/*

this is a bfs islands problem.
additional check for if node of island is on edge

*/