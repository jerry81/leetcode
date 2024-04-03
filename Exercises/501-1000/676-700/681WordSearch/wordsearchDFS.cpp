#include <vector>

using namespace std;

class Solution {
  const vector<pair<int, int>> N = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  bool r(int idx, int y, int x, vector<vector<bool>> vis,
         vector<vector<char>>& board, string& word, int& h, int& w) {
    if (y < 0 || x < 0 || y >= h, || x >= w) return false;
  }

 public:
  bool exist(vector<vector<char>>& board, string word) {
    int h = board.size();
    int w = board[0].size();
    vector<vector<bool>> empty_vis(h, vector<bool>(w));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (board[i][j] != word[0]) continue;

        if (r(0, i, j, empty_vis, board, word, h, w)) return true;
      }
    }
    return false;
  }
};