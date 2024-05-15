/*

2812. Find the Safest Path in a Grid
Medium
Topics
Companies
Hint
You are given a 0-indexed 2D matrix grid of size n x n, where (r, c) represents:

A cell containing a thief if grid[r][c] = 1
An empty cell if grid[r][c] = 0
You are initially positioned at cell (0, 0). In one move, you can move to any
adjacent cell in the grid, including cells containing thieves.

The safeness factor of a path on the grid is defined as the minimum manhattan
distance from any cell in the path to any thief in the grid.

Return the maximum safeness factor of all paths leading to cell (n - 1, n - 1).

An adjacent cell of cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r
+ 1, c) and (r - 1, c) if it exists.

The Manhattan distance between two cells (a, b) and (x, y) is equal to |a - x| +
|b - y|, where |val| denotes the absolute value of val.



Example 1:


Input: grid = [[1,0,0],[0,0,0],[0,0,1]]
Output: 0
Explanation: All paths from (0, 0) to (n - 1, n - 1) go through the thieves in
cells (0, 0) and (n - 1, n - 1). Example 2:


Input: grid = [[0,0,1],[0,0,0],[0,0,0]]
Output: 2
Explanation: The path depicted in the picture above has a safeness factor of 2
since:
- The closest cell of the path to the thief at cell (0, 2) is cell (0, 0). The
distance between them is | 0 - 0 | + | 0 - 2 | = 2. It can be shown that there
are no other paths with a higher safeness factor. Example 3:


Input: grid = [[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]
Output: 2
Explanation: The path depicted in the picture above has a safeness factor of 2
since:
- The closest cell of the path to the thief at cell (0, 3) is cell (1, 2). The
distance between them is | 0 - 1 | + | 3 - 2 | = 2.
- The closest cell of the path to the thief at cell (3, 0) is cell (3, 2). The
distance between them is | 3 - 3 | + | 0 - 2 | = 2. It can be shown that there
are no other paths with a higher safeness factor.


Constraints:

1 <= grid.length == n <= 400
grid[i].length == n
grid[i][j] is either 0 or 1.
There is at least one thief in the grid.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
21.5K
Submissions
64.8K
Acceptance Rate
33.2%

*/

#include <queue>
#include <vector>

using namespace std;

class Solution {
  const vector<pair<int, int>> NEIGHBORS = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
  int h, w;
  vector<vector<int>> safeness;

  struct ComparePQ {
    vector<vector<int>>& safeness;
    ComparePQ(vector<vector<int>>& s)
        : safeness(s) {}  // use constructor to pass in the struct member
    bool operator()(pair<int, int> a, pair<int, int> b) {
      auto [ay, ax] = a;
      auto [by, bx] = b;
      int sa = safeness[ay][ax];
      int sb = safeness[by][bx];
      return sa < sb;
    }  // this is idiomatic...
  };

 public:
  int maximumSafenessFactor(vector<vector<int>>& grid) {
    // brute force?
    // bfs from each theif to find safeness of grid
    // with caveat.  bfs and start from all theives
    // WRONG -> dfs or bfs to find all paths from 0,0 to sz,sz
    h = grid.size();
    w = grid[0].size();

    safeness = vector<vector<int>>(h, vector<int>(w, INT_MAX));

    queue<pair<int, int>> q;
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (grid[i][j]) {
          q.push({i, j});
          visited[i][j] = true;
        }
      }
    }

    int level = 0;

    // shit, need level order here
    while (!q.empty()) {
      queue<pair<int, int>> nq;
      while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();
        int cur = safeness[y][x];
        safeness[y][x] = min(level, cur);
        for (auto [dy, dx] : NEIGHBORS) {
          int ny = dy + y;
          int nx = dx + x;
          if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;

          if (!visited[ny][nx]) {
            visited[ny][nx] = true;

            nq.push({ny, nx});
          }
        }
      }
      q = nq;
      ++level;
    }

    // CORRECT: dijkstra
    // DIJKSTRA REVIEW
    /*
      1.  djikstra is greedy
      2.  priority queue because we want to pick min/max weight
      3.  stop when you reach the destination
    */
    auto cmp = ComparePQ(safeness); // wow fixes the compile issue
    priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePQ> pq(cmp);
    int res = safeness[0][0];
    pq.push({0,0});
    vector<vector<bool>> processed(h, vector<bool>(w, false));
    while (true) {
      auto [y,x] = pq.top();
      res = min(res, safeness[y][x]);
      if (y == h-1 && x == w-1) {
        break;
      }

      pq.pop();

      if (processed[y][x]) continue;
      processed[y][x] = true;

      for (auto [dy,dx]:NEIGHBORS) {
        int ny = dy + y;
        int nx = dx + x;
        if (ny < 0 || nx < 0) continue;
        if (ny >=h || nx >=w) continue;
        if (processed[ny][nx]) continue;
        pq.push({ny,nx});
      }
    }

    return res;
  }
};