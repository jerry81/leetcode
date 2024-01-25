/*

1380. Lucky Numbers in a Matrix
Easy
Topics
Companies
Hint
Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.



Example 1:

Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 2:

Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 3:

Input: matrix = [[7,8],[1,2]]
Output: [7]
Explanation: 7 is the only lucky number since it is the minimum in its row and the maximum in its column.


Constraints:

m == mat.length
n == mat[i].length
1 <= n, m <= 50
1 <= matrix[i][j] <= 105.
All elements in the matrix are distinct.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
99.7K
Submissions
140.1K
Acceptance Rate
71.2%


*/

impl Solution {
  pub fn lucky_numbers (matrix: Vec<Vec<i32>>) -> Vec<i32> {
    let mut row_mx :Vec<i32> = vec![];
    let mut col_mx :Vec<i32> = vec![];
    let h = matrix.len();
    let w = matrix[0].len();
    for i in 0..h {
      let mut mx = 0;
      let r = matrix[i].clone();
      for j in 0..w {
        mx = mx.max(r[j]);
      }
      row_mx.push(mx);
    }
    for i in 0..w {
      let mut mx = 0;
      for j in 0..h {
        mx = mx.max(matrix[j][i]);
      }
      col_mx.push(mx);
    }
    let mut res : Vec<i32> = vec![];
    for i in 0..h {
      for j in 0..w {
        if matrix[i][j] == col_mx[j] && matrix[i[j] == row_mx[i] {
          res.push(matrix[i][j]);
        }
      }
    }
    res
  }
}