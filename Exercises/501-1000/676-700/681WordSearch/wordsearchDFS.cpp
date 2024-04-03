#include <vector>
#include <unordered_map>

using namespace std;

/*
  Gist:  to improve performance, instead of copying a visited array or the board, modify the board inline and then
  if the path fails backtrack by undoing the modification to the board.
*/

class Solution {
  const vector<pair<int, int>> N = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  bool r(int y, int x, string word,
         vector<vector<char>>& board, int& h, int& w) {
    if (word.empty()) return true;

    if (word.front() != board[y][x]) return false;

    word.erase(0,1);

    if (word.empty()) return true;

    char tmp = board[y][x];
    board[y][x] = '0';  // This is a backtracking technique.
    for (auto [dy,dx]:N) {
      int ny = y+dy;
      int nx = x+dx;

      if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;

      if (word[0] != board[ny][nx]) continue;



      if (r(ny,nx,word, board,h,w)) return true;
    }
    board[y][x] = tmp; // TIL: not even having to use a "visited" map
    return false;
  }

 public:
  bool exist(vector<vector<char>>& board, string word) {
    // perf edge cases

    int h = board.size();
    int w = board[0].size();
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (board[i][j] != word[0]) continue;

        if (r(i, j, word, board, h, w)) return true;
      }
    }
    return false;
  }
};