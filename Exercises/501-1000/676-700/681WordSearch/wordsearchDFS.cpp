#include <vector>
#include <unordered_map>

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
    // perf edge cases
    unordered_map<char, int> freq;
    for (vector<char> v : board) {
      for (char c : v) {
        if (freq.find(c) == freq.end()) {
          freq[c] = 1;
        } else {
          freq[c] += 1;
        }
      }
    }
    unordered_map<char, int> freq2;
    for (char c : word) {
      if (freq2.find(c) == freq.end()) {
        freq2[c] = 1;
      } else {
        freq2[c] += 1;
      }
    }

    for (auto [k,v]: freq2) {
      if (freq.find(k) == freq.end()) return false;

      if (freq[k] < v) return false;
    }


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