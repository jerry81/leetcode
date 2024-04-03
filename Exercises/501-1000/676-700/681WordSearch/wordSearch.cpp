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
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    // bfs
    vector<vector<int>> NEIGHBORS = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int r = board.size();
    int c = board[0].size();
    char start_letter = word[0];
    for (int cur_r = 0; cur_r < r; ++cur_r) {
      for (int cur_c = 0; cur_c < c; ++cur_c) {
        if (board[r][c] == start_letter) {
          set<pair<int, int>> visited;
          queue<pair<int, int>> q;
          q.push({cur_r, cur_c});
          while (!q.empty()) {
            queue<pair<int,int>> nq;
            while (!q.empty()) {
             pair<int,int> popped = q.front();
             visited.insert(popped);
             auto [y,x] = popped;
              q.pop();
            }
            for (vector<int> neigh: NEIGHBORS) {
            }
          }
        }
      }
    }
    return true;
  }
};