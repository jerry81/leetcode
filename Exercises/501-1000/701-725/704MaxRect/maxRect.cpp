/*


85. Maximal Rectangle
Hard
Topics
Companies
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.



Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = [["0"]]
Output: 0
Example 3:

Input: matrix = [["1"]]
Output: 1


Constraints:

rows == matrix.length
cols == matrix[i].length
1 <= row, cols <= 200
matrix[i][j] is '0' or '1'.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
406.5K
Submissions
857.2K
Acceptance Rate
47.4%

*/

#include <vector>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
      // 2 pass method
      // left to right
      // top to bottom
      int h = matrix.size();
      int w = matrix[0].size();
      vector<vector<int>> ltr(h, vector<int>(w,0));
      vector<vector<int>> areas = ltr;
      for (int i = 0; i < h; ++i) {
        vector<char> cur_row = matrix[i];
        for (int j = 0; j < w; ++j) {
          char val = cur_row[j];
          int left = (i > 0) ? ltr[i][j-1]:0;
          if (val == 0) {
            ltr[i][j] = 0;
          } else {
            ltr[i]j[] = left+1;
          }
        }
      }
      int res = 0;
      for (int j = 0; j < w; ++j) {
        for (int i = 0; i < h; ++i) {
        }
      }
      return res;
    }
};