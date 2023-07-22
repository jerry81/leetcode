/*

688. Knight Probability in Chessboard
Medium
2.8K
371
Companies
On an n x n chessboard, a knight starts at the cell (row, column) and attempts
to make exactly k moves. The rows and columns are 0-indexed, so the top-left
cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).

A chess knight has eight possible moves it can make, as illustrated below. Each
move is two cells in a cardinal direction, then one cell in an orthogonal
direction.


Each time the knight is to move, it chooses one of eight possible moves
uniformly at random (even if the piece would go off the chessboard) and moves
there.

The knight continues moving until it has made exactly k moves or has moved off
the chessboard.

Return the probability that the knight remains on the board after it has stopped
moving.



Example 1:

Input: n = 3, k = 2, row = 0, column = 0
Output: 0.06250
Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on
the board. From each of those positions, there are also two moves that will keep
the knight on the board. The total probability the knight stays on the board is
0.0625. Example 2:

Input: n = 1, k = 0, row = 0, column = 0
Output: 1.00000

*/

using namespace std;
#include <queue>
#include <utility>
#include <vector>
#include <cmath>

class Solution {
  vector<pair<int, int>> moves = {{2, 1},  {2, -1},  {1, 2},  {1, -2},
                                  {-2, 1}, {-2, -1}, {-1, 2}, {-1, -2}};

 public:
  double knightProbability(int n, int k, int row, int column) {
    double inCount = 0;
    queue<pair<int, int>> curMoves;
    curMoves.push({row, column});
    int moveCount = 0;
    while (moveCount < k) {
      queue<pair<int, int>> nextMoves;
      moveCount++;
      while (!curMoves.empty()) {
        pair<int, int> curMove = curMoves.front();
        curMoves.pop();
        for (auto move : moves) {
          long long nextRow = curMove.first + move.first;
          long long nextcol = curMove.second + move.second;
          if (nextRow >= 0 && nextcol >= 0) {
            if (nextRow < n && nextcol < n) {
              nextMoves.push(
                  {curMove.first + move.first, curMove.second + move.second});
            }
          }
        }
      }
      curMoves = nextMoves;
    }
    double sz = curMoves.size();
    while (!curMoves.empty()) {
      auto point = curMoves.front();
      if (point.first >= 0 && point.second >= 0) {
        if (point.first < n && point.second < n) {
          inCount++;
        }
      }
      curMoves.pop();
    }
    return inCount / (double)pow(8,k);
  }
};

/*

OOPS
missed the line moves "until it it has moved off the board"
*/