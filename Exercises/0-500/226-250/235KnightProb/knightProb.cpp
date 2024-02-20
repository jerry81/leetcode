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
#include <cmath>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
class Solution {
  vector<pair<int, int>> moves = {{2, 1},  {2, -1},  {1, 2},  {1, -2},
                                  {-2, 1}, {-2, -1}, {-1, 2}, {-1, -2}};
  vector<vector<double>> probabilities;

 public:
  double knightProbability(int n, int k, int row, int column) {
    double inCount = 0;
    probabilities.resize(n, vector<double>(n, 0));
    probabilities[row][column] = 1;
    if (k == 0) return 1;

    int moveCount = 0;
    double ret = 0;
    while (moveCount < k) {
      moveCount++;
      vector<vector<double>> nextProbs(n, vector<double>(n, 0));
      for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
          for (auto move : moves) {
            long long nextRow = r + move.first;
            long long nextcol = c + move.second;
            if (nextRow >= 0 && nextcol >= 0) {
              if (nextRow < n && nextcol < n) {
                nextProbs[r][c] += (probabilities[nextRow][nextcol] / 8.0);
              }
            }
          }
        }
      }
      probabilities = nextProbs;
    }

    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < n; ++c) {
        ret += probabilities[r][c];
      }
    }

    return ret;
  }
};
/*

OOPS
missed the line moves "until it it has moved off the board"

but now we have mem limit exceeded.  which makes this an optimization problem
at its core.

*/