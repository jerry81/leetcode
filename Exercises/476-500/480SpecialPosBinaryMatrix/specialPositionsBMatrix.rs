/*

1582. Special Positions in a Binary Matrix
Easy
765
28
Companies
Given an m x n binary matrix mat, return the number of special positions in mat.

A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).



Example 1:


Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
Output: 1
Explanation: (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.
Example 2:


Input: mat = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
Explanation: (0, 0), (1, 1) and (2, 2) are special positions.


Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 100
mat[i][j] is either 0 or 1.
Accepted
52.5K
Submissions
79.6K
Acceptance Rate
66.0%

*/

impl Solution {
    pub fn num_special(mat: Vec<Vec<i32>>) -> i32 {
      let mut rows = Vec::new();
      for r in 0..mat.len() {
        let mut cnt = 0;
        for c in 0..mat.len() {
          if mat[r][c] == 1 {
            cnt+=1;
          }
        }
        if cnt == 1 {
          rows.push(r);
        }
      }
      let mut cols = Vec::new();
      for c in 0..mat.len() {
        let mut cnt = 0;
        for r in 0..mat.len() {
          if mat[r][c] == 1 {
            cnt+=1;
          }
        }
        if cnt == 1 {
          cols.push(1);
        } else {
          cols.push(0);
        }
      }
      let mut res = 0;
      for c in 0..mat.len() {
        for r in 0..mat.len() {
          if (cols[c] == 1 && rows[r] == 1) {
            res+=1;
          }
        }
      }
      res
    }
}