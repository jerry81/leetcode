/*

2328. Number of Increasing Paths in a Grid
Hard
868
21
Companies
You are given an m x n integer matrix grid, where you can move from a cell to any adjacent cell in all 4 directions.

Return the number of strictly increasing paths in the grid such that you can start from any cell and end at any cell. Since the answer may be very large, return it modulo 109 + 7.

Two paths are considered different if they do not have exactly the same sequence of visited cells.



Example 1:


Input: grid = [[1,1],[3,4]]
Output: 8
Explanation: The strictly increasing paths are:
- Paths with length 1: [1], [1], [3], [4].
- Paths with length 2: [1 -> 3], [1 -> 4], [3 -> 4].
- Paths with length 3: [1 -> 3 -> 4].
The total number of paths is 4 + 3 + 1 = 8.
Example 2:

Input: grid = [[1],[2]]
Output: 3
Explanation: The strictly increasing paths are:
- Paths with length 1: [1], [2].
- Paths with length 2: [1 -> 2].
The total number of paths is 2 + 1 = 3.


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 1000
1 <= m * n <= 105
1 <= grid[i][j] <= 105
Accepted
21.8K
Submissions
42.9K
Acceptance Rate
50.8%

*/

#include <vector>

using namespace std;

class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
      // get islands
    }
};

/*
1 1
3 4

- relevant items
1-3-4 - 3 + 2 + 1 = 6
1-4 - 1+1 - can't count this "4" twice
1,3,4,1
1-3, 3-4, 1-4
1-3-4


3 4
1 1

3 4
1 3 4
1 4
*/
