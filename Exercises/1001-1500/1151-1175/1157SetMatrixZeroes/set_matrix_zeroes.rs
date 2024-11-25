/*

73. Set Matrix Zeroes
Medium
Topics
Companies
Hint
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.



Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]


Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1


Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

Seen this question in a real interview before?
1/5
Yes
No
Accepted
1.7M
Submissions
2.9M
Acceptance Rate
58.0%

*/

impl Solution {
  pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
    // note all 0s
    let mut z: Vec<(usize,usize)> = vec![];
    let h = matrix.len();
    let w = matrix[0].len();
    for i in 0..h {
      for j in 0..w {
        if matrix[i][j] == 0 {
          z.push((i,j));
        }
      }
    }
    for (y,x) in z {
      for i in 0..w {
        matrix[y][i] = 0;
      }
      for i in 0..h {
        matrix[i][x] = 0;
      }
    }
  }
}