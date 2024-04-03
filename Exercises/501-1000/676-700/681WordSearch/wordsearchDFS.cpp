#include <vector>

using namespace std;


class Solution {
  const vector<pair<int, int>> N = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  bool r(int y, int x, vector<vector<bool>> vis, string word,
         vector<vector<char>>& board, int& h, int& w) {
    if (word.empty()) return true;

    if (word.front() != board[y][x]) return false;

    word.erase(0,1);

    if (word.empty()) return true;

    for (auto [dy,dx]:N) {
      int ny = y+dy;
      int nx = x+dx;

      if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;

      if (vis[ny][nx]) continue;

      vector<vector<bool>> cpy = vis;

      cpy[ny][nx] = true;

      if (r(ny,nx,cpy,word, board,h,w)) return true;
    }
    return false;
  }

 public:
  bool exist(vector<vector<char>>& board, string word) {
    int h = board.size();
    int w = board[0].size();
    vector<vector<bool>> empty_vis(h, vector<bool>(w));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (board[i][j] != word[0]) continue;

        vector<vector<bool>> cpy = empty_vis;
        cpy[i][j] = true;
        if (r(i, j, cpy, word, board, h, w)) return true;
      }
    }
    return false;
  }
};