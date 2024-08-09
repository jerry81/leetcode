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
// 2,0 1,1 0,2
class Solution {
  vector<vector<int>> buildSums(vector<vector<int>>& grid, int sR, int sC) {
    // called once
    vector<int> rows;
    vector<int> cols;
    int diagSum = 0;
    int diagSum2 = 0;
    for (int i = 0; i < 3; ++i) {
      int rowSum = 0;
      int colSum = 0;
      diagSum += grid[sR + i][sC + i];
      diagSum2 += grid[sR + i][sC + 2 - i];
      for (int j = 0; j < 3; ++j) {
        rowSum += grid[sR + i][sC + j];
        colSum += grid[sR + j][sC + i];
      }
      rows.push_back(rowSum);
      cols.push_back(colSum);
    }

    return {rows, cols, {diagSum, diagSum2}};
  };

  vector<vector<int>> moveRight(vector<vector<int>>& grid, int sR, int sC,
                                vector<vector<int>>& sums) {
    // so there is a whole new column.  dequeue the vertical first
    vector<vector<int>> ret = sums;
    // diags need recalculation
    ret.pop_back();
    ret[1].erase(ret[1].begin());
    // add another column
    int newVert = 0;
    for (int i = sR; i < sR + 3; ++i) newVert += grid[i][sC];

    ret[1].push_back(newVert);

    // all 3 horizontals get changed
    // subtract sC-3 and add sC
    int diagSum1 = 0;
    int diagSum2 = 0;
    for (int i = 0; i < 3; ++i) {
      ret[0][sC - 3] -= grid[sR + i][sC - 3] + grid[sR + i][sC];
      diagSum1 += grid[sR + i][sC + i - 2];
      diagSum2 += grid[sR + i][sC + i];
    }
    ret.push_back({diagSum1, diagSum2});
    // diags need recalculation
    return ret;
  };

  vector<vector<int>> moveDown(vector<vector<int>>& grid, int sR,
                               vector<vector<int>>& sums) {
    return {};
  };

  bool isMagic(vector<vector<int>> toCheck) {
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
    vector<vector<int>> initSums = buildSums(grid, 0, 0);
    vector<vector<int>> currentSums = initSums;
    // test init
    for (auto a : currentSums) {
      cout << "printing" << endl;
      for (auto b : a) {
        cout << b << ",";
      }
      cout << endl;
    }
    for (int r = 0; r < h - 2; ++r) {
      for (int c = 1; c < w - 2; ++c) {
        if (isMagic(currentSums)) ++res;

        currentSums = moveRight(grid, r, c, currentSums);
        cout << "moved right" << endl;
        for (auto a : currentSums) {
          cout << "printing" << endl;
          for (auto b : a) {
            cout << b << ",";
          }
          cout << endl;
        }
      }
      auto temp = moveDown(grid, r, initSums);
      initSums = temp;  // just in case there are concurrent modification issues
                        // or something
    }

    return res;
  }
};