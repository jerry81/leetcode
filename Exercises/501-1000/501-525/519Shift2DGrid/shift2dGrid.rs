/*

1260. Shift 2D Grid
Easy
Topics
Companies
Hint
Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.

In one shift operation:

Element at grid[i][j] moves to grid[i][j + 1].
Element at grid[i][n - 1] moves to grid[i + 1][0].
Element at grid[m - 1][n - 1] moves to grid[0][0].
Return the 2D grid after applying shift operation k times.



Example 1:


Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
Output: [[9,1,2],[3,4,5],[6,7,8]]
Example 2:


Input: grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
Output: [[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]
Example 3:

Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
Output: [[1,2,3],[4,5,6],[7,8,9]]


Constraints:

m == grid.length
n == grid[i].length
1 <= m <= 50
1 <= n <= 50
-1000 <= grid[i][j] <= 1000
0 <= k <= 100
Seen this question in a real interview before?
1/4
Yes
No
Accepted
102.7K
Submissions
152.6K
Acceptance Rate
67.3%

*/

impl Solution {
  fn get_new_position(orig: Vec<i32>, k: i32, h: i32, w: i32) -> Vec<i32> {
    let mx = h*w;

    let orig_flat = orig[0] * w + orig[1];
    let mut new_flat = orig_flat + k;
    new_flat %= mx;
    let ret = vec![new_flat / w, new_flat % w];
    ret
  }

  pub fn shift_grid(grid: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {
    let h = grid.len();
    let w = grid[0].len();
    let mut res: Vec<Vec<i32>> = vec![vec![0; w]; h];

    for i in 0..h {
      for j in 0..w {
        let orig = vec![i as i32,j as i32];
        let cur = Solution::get_new_position(orig,k,h as i32,w as i32);
        res[cur[0] as usize][cur[1] as usize] = grid[i][j];
      }
    }
    res
  }
}