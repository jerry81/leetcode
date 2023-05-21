class Solution {
  std::vector<std::pair<int, int>> island1;
  std::vector<std::pair<int, int>> island2;
  std::vector<std::vector<bool>> visited;

  void bfs(bool isFirst, int y, int x, std::vector<std::vector<int>>& grid) {
    std::queue<std::pair<int, int>> nn;
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

  void makeIslands(std::vector<std::vector<int>>& grid) {
    bool firstIslandFound = false;
    int numRows = grid.size();
    int numCols = grid[0].size();

    visited = std::vector<std::vector<bool>>(numRows, std::vector<bool>(numCols, false));

    for (int i = 0; i < numRows; ++i) {
      for (int j = 0; j < numCols; ++j) {
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
    for (auto pr : island1) {
      for (auto pr2 : island2) {
        int dist = abs(pr.first - pr2.first) + abs(pr.second - pr2.second);
        mn = std::min(dist-1, mn);
      }
    }
    return mn;
  }

public:
  int shortestBridge(std::vector<std::vector<int>>& grid) {
    int numRows = grid.size();
    int numCols = grid[0].size();

    makeIslands(grid);
    return getMinDist();
  }
};