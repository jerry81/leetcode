/*

2352. Equal Row and Column Pairs
Medium
557
27
Companies
Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj)
such that row ri and column cj are equal.

A row and column pair is considered equal if they contain the same elements in
the same order (i.e., an equal array).



Example 1:


Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
Output: 1
Explanation: There is 1 equal row and column pair:
- (Row 2, Column 1): [2,7,7]
Example 2:


Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
Output: 3
Explanation: There are 3 equal row and column pairs:
- (Row 0, Column 0): [3,1,2,2]
- (Row 2, Column 2): [2,4,2,2]
- (Row 3, Column 2): [2,4,2,2]


Constraints:

n == grid.length == grid[i].length
1 <= n <= 200
1 <= grid[i][j] <= 105
Accepted
42.2K
Submissions
59.6K
Acceptance Rate
70.8%

*/

#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  unordered_map<string, int> rowFreq;

 public:
  int equalPairs(vector<vector<int>>& grid) {
    for (auto a : grid) {
      std::stringstream ss;
      for (int i : a) {
        ss << to_string(i) << ",";
      }

      rowFreq[ss.str()]++;
    }

    int result = 0;
    for (int i = 0; i < grid[0].size(); ++i) {
      stringstream ss;
      for (int j = 0; j < grid.size(); ++j) {
        ss << to_string(grid[j][i]) << ',';
      }
      string cmp = ss.str();
      result += rowFreq[cmp];
    }
    return result;
  }
};

/*

0 1 2 3
1
2
3

row 0 0123

n^2 gives TLE?
*/