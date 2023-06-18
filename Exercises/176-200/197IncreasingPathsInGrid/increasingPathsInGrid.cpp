/*

2328. Number of Increasing Paths in a Grid
Hard
868
21
Companies
You are given an m x n integer matrix grid, where you can move from a cell to
any adjacent cell in all 4 directions.

Return the number of strictly increasing paths in the grid such that you can
start from any cell and end at any cell. Since the answer may be very large,
return it modulo 109 + 7.

Two paths are considered different if they do not have exactly the same sequence
of visited cells.



Example 1:


Input: grid = [[1,1],[3,4]]
Output: 8
Explanation: The strictly increasing paths are:
- Paths with length 1: [1], [1], [3], [4].
- Paths with length 2: [1 -> 3], [1 -> 4], [3 -> 4].
- Paths with length 3: [1 -> 3 -> 4].
The total number of paths is 4 + 3 + 1 = 8.
Example 2:

Input: grid = [[1],[2]]
Output: 3
Explanation: The strictly increasing paths are:
- Paths with length 1: [1], [2].
- Paths with length 2: [1 -> 2].
The total number of paths is 2 + 1 = 3.


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 1000
1 <= m * n <= 105
1 <= grid[i][j] <= 105
Accepted
21.8K
Submissions
42.9K
Acceptance Rate
50.8%

*/

#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
  vector<vector<long long>> memo;
  vector<vector<int>> incr = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  long long mod = 1e9 + 7;
  struct gridItem {
    int x = -1;
    int y = -1;
    int val = 0;

    gridItem(int x, int y, int v) : x(x), y(y), val(v) {}
  };
  string hash(int y, int x) {
    string s = to_string(x) + "," + to_string(y);
    return s;
  }
  static bool compareGI(gridItem* a, gridItem* b) {
    return (a->val) < (b->val);
  }
  void bfs(gridItem* gi, vector<vector<int>>& memo, vector<vector<int>>& g) {
    queue<pair<int, int>> neighbors;
    neighbors.push({gi->y, gi->x});
    while (!neighbors.empty()) {
      auto cur = neighbors.front();
      neighbors.pop();
      int toApply = memo[cur.first][cur.second] % mod;
      for (auto diffs : incr) {
        int newy = diffs[0] + cur.first;
        int newx = diffs[1] + cur.second;
        if (newy < 0) continue;
        if (newx < 0) continue;
        if (newy >= memo.size()) continue;
        if (newx >= memo[0].size()) continue;
        if (g[newy][newx] <= g[cur.first][cur.second]) continue;

        memo[newy][newx] += (toApply % mod);
      }
    }
  }

 public:
  int countPaths(vector<vector<int>>& grid) {
    int h = grid.size();
    int w = grid[0].size();
    vector<vector<int>> memo(h, vector<int>(w, 1));
    vector<gridItem*> processed;
    for (int i = 0; i < h; ++i) {
      auto row = grid[i];
      for (int j = 0; j < row.size(); ++j) {
        gridItem* g = new gridItem(j, i, row[j]);
        processed.push_back(g);
      }
    }
    sort(processed.begin(), processed.end(), compareGI);
    long long tally = 0;

    for (gridItem* gi : processed) {
      bfs(gi, memo, grid);
    }
    for (auto a : memo) {
      for (auto b : a) {
        tally += b;
        tally %= mod;
      }
    }
    return tally;
  }
};

// BFS not needed!