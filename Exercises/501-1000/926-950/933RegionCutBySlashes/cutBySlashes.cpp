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

#include <queue>
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
    vector<vector<bool>> ret(3 * grid.size(), vector<bool>(3 * grid.size()));
    for (int i = 0; i < grid.size(); ++i) {
      string s = grid[i];
      for (int j = 0; j < s.length(); ++j) {
        char c = s[j];
        vector<vector<bool>> pattern;
        if (c == '/') {
          pattern = FSLASH;
        } else if (c == '\\') {
          pattern = BSLASH;
        } else {
          pattern = SPACE;
        }
        for (int di = 0; di < 3; ++di) {
          for (int dj = 0; dj < 3; ++dj) {
            ret[i * 3 + di][j * 3 + dj] = pattern[di][dj];
          }
        }
      }
    }
    return ret;
  }

  vector<vector<bool>> visited;

  int bfs(int row, int col, vector<vector<bool>> grid, int sz) {
    if (visited.at(row).at(col) || grid.at(row).at(col)) {
      return 0;
    }
    // mark visited
    // neighbors
    queue<pair<int, int>> q;
    pair<int, int> start = {row, col};
    q.push(start);
    while (!q.empty()) {
      auto [row,col] = q.front();
      if (visited.at(row).at(col)) {
        q.pop();
        continue;
      }
      q.pop();
      visited.at(row).at(col) = true;
      // add u l r d
      int ur = row - 1;
      int dr = row + 1;
      int lc = col - 1;
      int rc = col + 1;
      if ((ur >= 0) && (!visited.at(ur).at(col)) &&
         !grid.at(ur).at(col)) q.push({ur,col});

      if ((dr < sz) && (!visited.at(dr).at(col)) &&
          !grid.at(dr).at(col)) q.push({dr,col});

      if ((lc >= 0) && (!visited.at(row).at(lc)) &&
          !grid.at(row).at(lc)) q.push({row,lc});

      if ((rc < sz) && (!visited.at(row).at(rc)) &&
          !grid.at(row).at(rc)) q.push({row,rc});
    }
    return 1;
  }

 public:
  int regionsBySlashes(vector<string>& grid) {
    vector<vector<bool>> expanded = build(grid);
    int sz = expanded.size();
    visited = vector<vector<bool>>(sz, vector<bool>(sz, false));
    int res = 0;

    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            if (!visited[i][j] && !expanded[i][j]) {
                res += bfs(i, j, expanded, sz);
            }
        }
    }
    return res;
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