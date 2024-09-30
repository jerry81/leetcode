/*

3142. Check if Grid Satisfies Conditions
Easy
Topics
Companies
Hint
You are given a 2D matrix grid of size m x n. You need to check if each cell grid[i][j] is:

Equal to the cell below it, i.e. grid[i][j] == grid[i + 1][j] (if it exists).
Different from the cell to its right, i.e. grid[i][j] != grid[i][j + 1] (if it exists).
Return true if all the cells satisfy these conditions, otherwise, return false.



Example 1:

Input: grid = [[1,0,2],[1,0,2]]

Output: true

Explanation:



All the cells in the grid satisfy the conditions.

Example 2:

Input: grid = [[1,1,1],[0,0,0]]

Output: false

Explanation:



All cells in the first row are equal.

Example 3:

Input: grid = [[1],[2],[3]]

Output: false

Explanation:



Cells in the first column have different values.



Constraints:

1 <= n, m <= 10
0 <= grid[i][j] <= 9
Seen this question in a real interview before?
1/5
Yes
No
Accepted
33.3K
Submissions
76.4K
Acceptance Rate
43.6%

*/

impl Solution {
  pub fn satisfies_conditions(grid: Vec<Vec<i32>>) -> bool {
    let h = grid.len();
    let w = grid[0].len();
    for r in 0..h {
      for c in 0..w {
        if r != h-1 {
          if grid[r][c] != grid[r+1][c] {
            return false;
          }
        }
        if c != w-1 {
          if grid[r][c] == grid[r][c+1] {
            return false;
          }
        }
      }
    }
    true
  }
}