/*

463. Island Perimeter
Easy
5.7K
281
Companies
You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.



Example 1:


Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.
Example 2:

Input: grid = [[1]]
Output: 4
Example 3:

Input: grid = [[1,0]]
Output: 4


Constraints:

row == grid.length
col == grid[i].length
1 <= row, col <= 100
grid[i][j] is 0 or 1.
There is exactly one island in grid.
Accepted
440.4K
Submissions
631.4K
Acceptance Rate
69.7%

*/

#include <vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
      vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
      int tally = 0;
      for (int i = 0; i < grid.size(); ++i) {
        vector<int> row = grid[i];
        for (int j = 0; j < row.size(); ++j) {
          if (grid[i][j] == 1) {
            for (auto a: dirs) {
              int ny = i+a[0];
              int nx = j+a[1];
              if (ny >= grid.size() || ny < 0) {
                tally++;
              } else {
                if (grid[ny][nx] == 0) tally++;
              }
            }
          }
        }
      }
      return tally;
    }
};