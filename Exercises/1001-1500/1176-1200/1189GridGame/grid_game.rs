/*

2017. Grid Game
Medium
Topics
Companies
Hint
You are given a 0-indexed 2D array grid of size 2 x n, where grid[r][c] represents the number of points at position (r, c) on the matrix. Two robots are playing a game on this matrix.

Both robots initially start at (0, 0) and want to reach (1, n-1). Each robot may only move to the right ((r, c) to (r, c + 1)) or down ((r, c) to (r + 1, c)).

At the start of the game, the first robot moves from (0, 0) to (1, n-1), collecting all the points from the cells on its path. For all cells (r, c) traversed on the path, grid[r][c] is set to 0. Then, the second robot moves from (0, 0) to (1, n-1), collecting the points on its path. Note that their paths may intersect with one another.

The first robot wants to minimize the number of points collected by the second robot. In contrast, the second robot wants to maximize the number of points it collects. If both robots play optimally, return the number of points collected by the second robot.



Example 1:


Input: grid = [[2,5,4],[1,5,1]]
Output: 4
Explanation: The optimal path taken by the first robot is shown in red, and the optimal path taken by the second robot is shown in blue.
The cells visited by the first robot are set to 0.
The second robot will collect 0 + 0 + 4 + 0 = 4 points.
Example 2:


Input: grid = [[3,3,1],[8,5,2]]
Output: 4
Explanation: The optimal path taken by the first robot is shown in red, and the optimal path taken by the second robot is shown in blue.
The cells visited by the first robot are set to 0.
The second robot will collect 0 + 3 + 1 + 0 = 4 points.
Example 3:


Input: grid = [[1,3,1,15],[1,3,3,1]]
Output: 7
Explanation: The optimal path taken by the first robot is shown in red, and the optimal path taken by the second robot is shown in blue.
The cells visited by the first robot are set to 0.
The second robot will collect 0 + 1 + 3 + 3 + 0 = 7 points.


Constraints:

grid.length == 2
n == grid[r].length
1 <= n <= 5 * 104
1 <= grid[r][c] <= 105
Accepted
41.8K
Submissions
80.8K
Acceptance Rate
51.7%

*/

impl Solution {
  pub fn grid_game(grid: Vec<Vec<i32>>) -> i64 {
    let w = grid[0].len();
    let mut psums: Vec<Vec<i64>> = vec![vec![0;w],vec![0;w]];
    psums[0][0] = grid[0][0] as i64;
    psums[1][0] = grid[1][0] as i64;

    for i in 1..w {
      for j in 0..=1 {
        psums[j][i] = grid[j][i] as i64 + psums[j][i-1];
      }

    }
    let mut res = i64::MAX;
    for p1_play in 0..w {
      let interval_start_0: i32 = p1_play as i32 + 1;
      let interval_end_1: i32 = p1_play as i32 - 1;
      if interval_start_0 < w {
        res = res.min(psums[0][w-1] - psums[0][interval_start_0 as usize-1]);
      }
      if interval_end_1 >= 0 {
        res = res.min(psums[1][interval_end_1]);
      })
    }
    res
  }
}

/*
only 2 rows so pick which col to switch
prefix sums
*/
