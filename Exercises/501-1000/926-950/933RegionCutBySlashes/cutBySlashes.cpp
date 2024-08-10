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
  const vector<vector<bool>> slash = {{false,false,true}, {false,true,false}, {true, false, false}};
  const vector<vector<bool>> bslash = {{true, false, false},{false,true,false},{false,false,true}};

 public:
  int regionsBySlashes(vector<string>& grid) {}
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