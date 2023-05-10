/*

59. Spiral Matrix II
Medium
5.1K
216
Companies
Given a positive integer n, generate an n x n matrix filled with elements from 1
to n2 in spiral order.



Example 1:


Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
Example 2:

Input: n = 1
Output: [[1]]


Constraints:

1 <= n <= 20
Accepted
449.1K
Submissions
659.7K
Acceptance Rate
68.1%

*/

#include <vector>

using namespace std;

class Solution {
  vector<vector<int>> init(int n) {
    vector<vector<int>> mat;
    for (int i = 0; i < n; ++i) {
      vector<int> row;
      for (int j = 0; j < n; ++j) {
        row.push_back(0);
      }
      mat.push_back(row);
    }
  }

 public:
  vector<vector<int>> generateMatrix(int n) {
    // init the matrix
    vector<vector<int>> ret = init(n);
    // reuse yesterday's code
      int maxX = n;
      int minX = 0;
      int maxY = n;
      int minY = 0;
      int total = n*n;
      int curx = 0;
      int cury = 0;
      int count = 0;
      int direction = 0;
      while (count < total) {
        ret[cury][curx] = count+1;
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
          if (curx-1 >= minX) {
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
