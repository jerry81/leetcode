
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

  bool isDone(Point p) {
    return visited[(p.y * width) + p.x]; }

  void visit(Point p) { visited[(p.y * width) + p.x] = true; }

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
      if (lx >= 0 && !isDone(lp) && orig[lx][cy]) {
        remain.push(lp);
        visit(lp);
      }

      if (rx < width && !isDone(rp) && orig[rx][cy]) {
        remain.push(rp);
        visit(rp);
      }

      if (uy >= 0 && !isDone(up) && orig[cx][uy]) {
        remain.push(up);
        visit(up);
      }

      if (dy < height && !isDone(dp) && orig[cx][dy]) {
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
    int totaldim = height*width;

    visited = new bool[totaldim];
    memset(visited, false, totaldim);
    int total = 0;
    for (int i = 1; i < height-1; ++i) {
      for (int j = 1; j < width-1; ++j) {
            if (!orig[i][j]) continue;
            Point p = Point(j,i);
            total += bfs(p);
      }

    }
    return total;
  }
};