/*

2639. Find the Width of Columns of a Grid
Easy
Topics
Companies
Hint
You are given a 0-indexed m x n integer matrix grid. The width of a column is the maximum length of its integers.

For example, if grid = [[-10], [3], [12]], the width of the only column is 3 since -10 is of length 3.
Return an integer array ans of size n where ans[i] is the width of the ith column.

The length of an integer x with len digits is equal to len if x is non-negative, and len + 1 otherwise.



Example 1:

Input: grid = [[1],[22],[333]]
Output: [3]
Explanation: In the 0th column, 333 is of length 3.
Example 2:

Input: grid = [[-15,1,3],[15,7,12],[5,6,-2]]
Output: [3,1,2]
Explanation:
In the 0th column, only -15 is of length 3.
In the 1st column, all integers are of length 1.
In the 2nd column, both 12 and -2 are of length 2.


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100
-109 <= grid[r][c] <= 109
Seen this question in a real interview before?
1/5
Yes
No
Accepted
27.7K
Submissions
41K
Acceptance Rate
67.7%

*/

impl Solution {
  pub fn find_column_width(grid: Vec<Vec<i32>>) -> Vec<i32> {
    let h = grid.len();
    let w = grid[0].len();
    let mut res: Vec<i32> = vec![0;w];
    for i in 0..w {
      for j in 0..h {
        let cur = grid[j][i].to_string().len() as i32;
        res[i] = res[i].max(cur);
      }
    }
    res
  }
}