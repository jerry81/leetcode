/*

959. Regions Cut By Slashes
Medium
Topics
Companies
An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a
'/', '\', or blank space ' '. These characters divide the square into contiguous
regions.

Given the grid grid represented as a string array, return the number of regions.

Note that backslash characters are escaped, so a '\' is represented as '\\'.



Example 1:


Input: grid = [" /","/ "]
Output: 2
Example 2:


Input: grid = [" /","  "]
Output: 1
Example 3:


Input: grid = ["/\\","\\/"]
Output: 5
Explanation: Recall that because \ characters are escaped, "\\/" refers to \/,
and "/\\" refers to /\.


Constraints:

n == grid.length == grid[i].length
1 <= n <= 30
grid[i][j] is either '/', '\', or ' '.
Accepted
58.2K
Submissions
82.3K
Acceptance Rate
70.7%

*/

#include <string>
#include <vector>

using namespace std;

class Solution {
  const vector<vector<bool>> FSLASH = {
      {false, false, true}, {false, true, false}, {true, false, false}};
  const vector<vector<bool>> BSLASH = {
      {true, false, false}, {false, true, false}, {false, false, true}};
  const vector<vector<bool>> SPACE = {
      {false, false, false}, {false, false, false}, {false, false, false}};

  vector<vector<bool>> build(vector<string>& grid) {
    vector<vector<bool>> ret;
    for (string s: grid) {
      vector<vector<bool>> currow = {{},{},{}};
      for (char c: s) {
        switch (c) {
          case '/': {
            for (int i = 0; i < 3; ++i) currow[i].insert(currow[i].end(), FSLASH[i].begin(), FSLASH[i].end());

            break;

          } case '\\': {
for (int i = 0; i < 3; ++i) currow[i].insert(currow[i].end(), BSLASH[i].begin(), BSLASH[i].end());

            break;
          } default: {
          for (int i = 0; i < 3; ++i) currow[i].insert(currow[i].end(), SPACE[i].begin(), SPACE[i].end());
          }
        }
      }
    }
  };

 public:
  int regionsBySlashes(vector<string>& grid) {
    vector<vector<bool>> expanded = build(grid);
    for (auto row: expanded) {
      cout << endl;
      for (auto v:row) {
        cout << v << ",";
      }
    }
    return 0;
  }
};

// better approach
// expand to 3x3 grids
/*
       1        100
/ ->  1    \ -> 100
     1          001

*/
// turn it into bfs islands problem

// wrong approach!
// so cover the example cases
// single slash reaching borders
// slash not reaching a border
// multiple slashes reaching borders, one enclosed section
// another case
// polygon touching same side