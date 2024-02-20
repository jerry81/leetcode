/*

892. Surface Area of 3D Shapes
Easy
524
715
Companies
You are given an n x n grid where you have placed some 1 x 1 x 1 cubes. Each
value v = grid[i][j] represents a tower of v cubes placed on top of cell (i, j).

After placing these cubes, you have decided to glue any directly adjacent cubes
to each other, forming several irregular 3D shapes.

Return the total surface area of the resulting shapes.

Note: The bottom face of each shape counts toward its surface area.



Example 1:


Input: grid = [[1,2],[3,4]]
Output: 34
Example 2:


Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
Output: 32
Example 3:


Input: grid = [[2,2,2],[2,1,2],[2,2,2]]
Output: 46


Constraints:

n == grid.length == grid[i].length
1 <= n <= 50
0 <= grid[i][j] <= 50
Accepted
36.5K
Submissions
56.3K
Acceptance Rate
64.8%

*/

#include <vector>

using namespace std;

class Solution {
 public:
  int surfaceArea(vector<vector<int>>& grid) {
    // top, bottom, left, right, front, back
    // missing: donut situations
    // for every block, add surface area.
    // subtract a point for each neighbor
    // top down
    int sz = grid.size();
    int area = 0;
    vector<vector<int>> neigh = {{0,-1},{0,1},{-1,0},{1,0}};
    for (int i = 0; i < sz; ++i) {
      for (int j = 0; j < sz; ++j) {
        int height = grid[i][j];
        area+=4*height;
        if (height > 0) area+=2; // top and bottom
        // remove area covered by neighbors
        for (auto n: neigh) {
          int y = i+n[0];
          int x = j+n[1];
          if (y < 0 || x < 0 || y >= sz || x >= sz) continue;
          int nheight = grid[y][x];
          area-=min(height,nheight);
        }
      }
    }
    return area;
  }
};