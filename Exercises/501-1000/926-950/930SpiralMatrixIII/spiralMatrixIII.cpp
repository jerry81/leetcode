/*

885. Spiral Matrix III
Medium
Topics
Companies
You start at the cell (rStart, cStart) of an rows x cols grid facing east. The northwest corner is at the first row and column in the grid, and the southeast corner is at the last row and column.

You will walk in a clockwise spiral shape to visit every position in this grid. Whenever you move outside the grid's boundary, we continue our walk outside the grid (but may return to the grid boundary later.). Eventually, we reach all rows * cols spaces of the grid.

Return an array of coordinates representing the positions of the grid in the order you visited them.



Example 1:


Input: rows = 1, cols = 4, rStart = 0, cStart = 0
Output: [[0,0],[0,1],[0,2],[0,3]]
Example 2:


Input: rows = 5, cols = 6, rStart = 1, cStart = 4
Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]


Constraints:

1 <= rows, cols <= 100
0 <= rStart < rows
0 <= cStart < cols
Seen this question in a real interview before?
1/5
Yes
No
Accepted
56.6K
Submissions
74.4K
Acceptance Rate
76.1%

*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
      // brute force
      vector<vector<int>> res;
      int curWidth = 1;
      int dir_counter = 0; // 0123 RDLU

      // analyzing spiral pattern
      // RD 1
      //LLUU 2
      // RRRDDD 3
      // LLLLUUUU 4
      const vector<pair<int,int>> DIR = {{0,1}, {1,0}, {0,-1}, {-1,0}}; // RDLU
      int cur_r = rStart;
      int cur_c = cStart;
      int totalSq = rows*cols;
      res.push_back({rStart,cStart});
      totalSq--;
      while (totalSq > 0) {
        for (int i = 0; i < 2; ++i) {
          auto [dr,dc] = DIR[dir_counter%4];
          for (int j = 0; j < curWidth; j++) {
            int nr = dr+cur_r;
            int nc = dc+cur_c;
            if (nr >=0 && nr < rows) {
              if (nc >=0 && nc < cols) {
                res.push_back({nr,nc});
                totalSq--;
              }
            }
            cur_r = nr;
            cur_c = nc;
          }
          dir_counter++;
        }
        curWidth++;
      }
      return res;
    }
};