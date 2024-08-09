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
#include <unordered_set>

using namespace std;
// 2,0 1,1 0,2
class Solution {
  vector<vector<int>> buildSums(vector<vector<int>>& grid, int sR, int sC) {
    // called once
    vector<int> rows;
    vector<int> cols;
    unordered_set<int> checksum;
    int diagSum = 0;
    int diagSum2 = 0;
    for (int i = 0; i < 3; ++i) {
      int rowSum = 0;
      int colSum = 0;

      diagSum += grid[sR + i][sC + i];
      diagSum2 += grid[sR + i][sC + 2 - i];
      for (int j = 0; j < 3; ++j) {
        int rawNum = grid[sR+i][sC+j];
        auto [_,dup] = checksum.insert(rawNum);

        if (!dup || rawNum > 9 ) return {};

        rowSum += grid[sR + i][sC + j];
        colSum += grid[sR + j][sC + i];
      }
      rows.push_back(rowSum);
      cols.push_back(colSum);
    }

    return {rows, cols, {diagSum, diagSum2}};
  };

  bool isMagic(vector<vector<int>> toCheck) {
    if (toCheck.empty()) return false;
    for (auto v : toCheck) {
      for (int i : v) {
        if (i != 15) return false;
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

    for (int r = 0; r < h - 2; ++r) {
      for (int c = 0; c < w - 2; ++c) {
        if (isMagic(buildSums(grid, r, c))) ++res;
      }
    }

    return res;
  }
};