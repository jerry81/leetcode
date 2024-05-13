/*
861. Score After Flipping Matrix
Medium
Topics
Companies
You are given an m x n binary matrix grid.

A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).

Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score after making any number of moves (including zero moves).



Example 1:


Input: grid = [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
Explanation: 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
Example 2:

Input: grid = [[0]]
Output: 1


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 20
grid[i][j] is either 0 or 1.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
60.6K
Submissions
79.1K
Acceptance Rate
76.6%
*/

#include <vector>

using namespace std;

class Solution {
int vecToInt(vector<int> v) {
  int p = 0;
  int sm = 0;
  for (int i = v.size()-1; i >= 0; --i) {
    if (v[i]) sm += pow(2, p);
    p++;
  }
  return sm;
}
public:
    int matrixScore(vector<vector<int>>& grid) {
      // greedy - max left to right
      vector<int> test = {1,0,1};
      cout << "expect 5" << vecToInt(test);
      return 0;
    }
};