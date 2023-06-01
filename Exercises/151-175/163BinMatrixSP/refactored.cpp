
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    if (grid[0][0] == 1) return -1;

    visited[0][0] = true;
    queue<pair<int, int>> q;
    q.push({0, 0});
    int pathLength = 0;

    vector<pair<int, int>> directions = { // refactor - do the [].foreach thing
      {0, 1},  // right
      {0, -1}, // left
      {1, 0},  // down
      {-1, 0}, // up
      {1, 1},  // down-right
      {1, -1}, // down-left
      {-1, 1}, // up-right
      {-1, -1} // up-left
    };

    while (!q.empty()) {
      pathLength++;
      queue<pair<int, int>> nextq;
      while (!q.empty()) {
        auto [cy, cx] = q.front();
        q.pop();
        if (cy == n - 1 && cx == n - 1 && grid[cy][cx] == 0) {
          return pathLength;
        }

        for (const auto& dir : directions) { // the refactor
          int ny = cy + dir.first;
          int nx = cx + dir.second;

          if (ny >= 0 && ny < n && nx >= 0 && nx < n && !visited[ny][nx] && grid[ny][nx] == 0) { // all the checks on one line
            nextq.push({ny, nx});
            visited[ny][nx] = true;
          }
        }
      }
      q = nextq;
    }

    return -1;
  }
};