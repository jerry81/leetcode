/*


79. Word Search
Medium
Topics
Companies
Given an m x n grid of characters board and a string word, return true if word
exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where
adjacent cells are horizontally or vertically neighboring. The same letter cell
may not be used more than once.



Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
"ABCCED" Output: true Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
"SEE" Output: true Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
"ABCB" Output: false


Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.


Follow up: Could you use search pruning to make your solution faster with a
larger board?

Seen this question in a real interview before?
1/4
Yes
No
Accepted
1.5M
Submissions
3.7M
Acceptance Rate
41.6%

*/
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    // bfs
    // edge case (perf)
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
    vector<vector<int>> NEIGHBORS = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int r = board.size();
    int c = board[0].size();
    int word_size = word.size();
    char start_letter = word[0];

    for (int cur_r = 0; cur_r < r; ++cur_r) {
      for (int cur_c = 0; cur_c < c; ++cur_c) {
        int cur_idx = 0;
        if (board[cur_r][cur_c] == start_letter) {
          queue<pair<pair<int, int>, vector<vector<bool>>>> q;
          vector<vector<bool>> path(r, vector<bool>(c));
          path[cur_r][cur_c] = true;
          ;
          q.push({{cur_r, cur_c}, path});
          // int temp1 = cur_r;
          // int temp2 = cur_c;
          while (!q.empty()) {
            queue<pair<pair<int, int>, vector<vector<bool>>>> nq;
            int next_idx = cur_idx + 1;
            while (!q.empty()) {
              pair<pair<int, int>, vector<vector<bool>>> popped = q.front();

              auto [loc, vis] = popped;
              auto [y, x] = loc;
              q.pop();

              if (board[y][x] == word[cur_idx]) {
                vis[y][x] = true;
              } else {
                continue;
              }
              for (vector<int> neigh : NEIGHBORS) {
                int ny = neigh[0] + y;
                int nx = neigh[1] + x;

                if (ny < 0) continue;

                if (nx < 0) continue;

                if (ny >= r) continue;

                if (nx >= c) continue;

                pair<int, int> key = {ny, nx};

                if (vis[ny][nx]) continue;

                if (board[ny][nx] != word[next_idx]) continue;

                nq.push({key, vis});
              }
            }
            q = nq;
            cur_idx++;
          }
        }
        if (cur_idx == word_size) return true;
      }
    }
    return false;
  }
};