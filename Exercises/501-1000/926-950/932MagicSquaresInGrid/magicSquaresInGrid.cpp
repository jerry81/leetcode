/*
840. Magic Squares In Grid
Medium
Topics
Companies
A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9
such that each row, column, and both diagonals all have the same sum.

Given a row x col grid of integers, how many 3 x 3 contiguous magic square
subgrids are there?

Note: while a magic square can only contain numbers from 1 to 9, grid may
contain numbers up to 15.



Example 1:


Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
Output: 1
Explanation:
The following subgrid is a 3 x 3 magic square:

while this one is not:

In total, there is only one magic square inside the given grid.
Example 2:

Input: grid = [[8]]
Output: 0


Constraints:

row == grid.length
col == grid[i].length
1 <= row, col <= 10
0 <= grid[i][j] <= 15
Seen this question in a real interview before?
1/5
Yes
No
Accepted
63.1K
Submissions
143.1K
Acceptance Rate
44.1%
*/

#include <vector>

using namespace std;

class Solution {
  vector<vector<int>> buildSums(vector<vector<int>>& grid, int sR, int sC) {
    // called once
  };

  vector<vector<int>> moveRight(vector<vector<int>>& grid, int sR, int sC, vector<vector<int>>& sums) {
  };

  vector<vector<int>> moveDown(vector<vector<int>>& grid, int sR, int sC, vector<vector<int>>& sums) {
  };

  bool isMagic(vector<vector<int>> toCheck) {
    int check_against = toCheck[0][0];
    for (auto v: toCheck) {
      for (int i:v) {
        if (i != check_against) return false;
      }
    }
    return true;
  }

 public:
  int numMagicSquaresInside(vector<vector<int>>& grid) {
    int h = grid.size();
    int w = grid[0].size();  // safe due to constraints
    if (h < 3 || w < 3) return 0;
    int res = 0;
    vector<vector<int>> initDiags = buildSums(grid, 0,0);


    return res;
  }
  // to test
  // 3xhorizontal
  // 3xvertical
  // 4xdiagonal
  // 10 total
  // cache -> vector<vector<int>> h, v, d
  // loop top to bottom
  // r = 0; r < h-2; r++
  // if r > 0 use cached values
  // move left to right
  // c = 0; c < w-2; c++
  // cache 0
  // find magic, stop early
};