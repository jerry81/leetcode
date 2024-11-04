/*

36. Valid Sudoku
Medium
Topics
Companies
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.


Example 1:


Input: board =
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:

Input: board =
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.


Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit 1-9 or '.'.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
1.7M
Submissions
2.8M
Acceptance Rate
60.9%

*/

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      // rows
      unordered_set<int> rows;
      unordered_set<int> cols;
      for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
          if (rows.find(board[i][j]) != rows.end()) {
            return false;
          }
          rows.insert(board[i][j]);
          if (cols.find(board[j][i]) != cols.end()) {
            return false;
          }
          cols.insert(board[j][i]);
        }
      }
      for (int sr = 0; sr < 3; ++sr) {
        for (int sc = 0; sc < 3; ++sc) {
          int start_r = sr*3;
          int start_c = sc*3;
          unordered_set<int> cur_square;
          for (int dr = 0; dr < 3; ++dr) {
            for (int dc = 0; dc < 3; ++dc) {
              int cur_item = board[start_r+dr][start_c+dc];
              if (cur_square.find(cur_item)!=cur_square.end()) return false;
              cur_square.insert(cur_item);
            }
          }
        }
      }

      return true;
    }
};