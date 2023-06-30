/*

1970. Last Day Where You Can Still Cross
Hard
677
13
Companies
There is a 1-based binary matrix where 0 represents land and 1 represents water. You are given integers row and col representing the number of rows and columns in the matrix, respectively.

Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. You are given a 1-based 2D array cells, where cells[i] = [ri, ci] represents that on the ith day, the cell on the rith row and cith column (1-based coordinates) will be covered with water (i.e., changed to 1).

You want to find the last day that it is possible to walk from the top to the bottom by only walking on land cells. You can start from any cell in the top row and end at any cell in the bottom row. You can only travel in the four cardinal directions (left, right, up, and down).

Return the last day where it is possible to walk from the top to the bottom by only walking on land cells.



Example 1:


Input: row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
Output: 2
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 2.
Example 2:


Input: row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
Output: 1
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 1.
Example 3:


Input: row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
Output: 3
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 3.


Constraints:

2 <= row, col <= 2 * 104
4 <= row * col <= 2 * 104
cells.length == row * col
1 <= ri <= row
1 <= ci <= col
All the values of cells are unique.
Accepted
13.5K
Submissions
26.3K
Acceptance Rate
51.4%

*/

#include <vector>
#include <queue>

using namespace std;

class Solution {

bool canCross(int day,int row,int col,vector<vector<int>>& cells) {
  vector<vector<int>> g(row, vector<int>(col, 0));
  for (int i = 0; i < day; ++i) {
    auto turnOff = cells[i];
    g[turnOff[0]][turnOff[1]] = 1;
  }
  queue<pair<int,int>> nn;
  for (int i = 0; i < col; ++i) {
    if (g[0][i] == 0) {
      g[0][i] = -1;
      nn.push({0,i});
    }
  }
}
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {

    }
};

// trie?
/*

Input: row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
Output: 3

trie - 0,0  0,1  0,2
       1,0  1,1  1,2
       2,0, 2,1  2,2

       0,0   [0,1, 1,0]
       1,0   [2,0], 1,1]

not brute force, b/c too easy

brute force with binary search
*/