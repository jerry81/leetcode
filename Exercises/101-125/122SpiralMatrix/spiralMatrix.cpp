/*

54. Spiral Matrix
Medium
11.5K
1.1K
Companies
Given an m x n matrix, return all elements of the matrix in spiral order.



Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]


Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
Accepted
1M
Submissions
2.3M
Acceptance Rate
45.5%

*/

#include <vector>

using namespace std;

class Solution {
int direction = 0;  // 0R 1D 2L 3U
int total,curw, curh = 0;
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      curw = matrix[0].size();
      curh = matrix.size();
      vector<int> ret;
      int maxX = curw;
      int minX = 0;
      int maxY = curh;
      int minY = 0;
      total = curw*curh;
      int curx = 0;
      int cury = 0;
      int count = 0;
      while (count < total) {
        ret.push_back(matrix[cury][curx]);
        if (direction == 0) {
          if ((curx+1) < maxX) {
            curx+=1;
          } else {
            direction = 1;
            cury+=1;
            maxX--;
          }
        } else if (direction == 1) {
          if ((cury+1) < maxY) {
            cury+=1;
          } else {
            direction = 2;
            curx-=1;
            maxY--;
          }
        } else if (direction == 2) {
          if (curx-1 > minX) {
            curx--;
          } else {
            direction=3;
            cury--;
            minX++;
          }
        } else {
          if (cury-1 > minY) {
            cury--;
          } else {
            direction = 0;
            curx++;
            minY++;
          }
        }
        count++;
      }
      return ret;
    }
};

/*

looking at the indexes of 3x3
00 01 02 12 22 21 20 10 11 done
*/