/*

48. Rotate Image
Medium
Topics
Companies
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.



Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Example 2:


Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]


Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000
Seen this question in a real interview before?
1/5
Yes
No
Accepted
2M
Submissions
2.6M
Acceptance Rate
76.3%

*/

impl Solution {
  pub fn rotate(matrix: &mut Vec<Vec<i32>>) {
    // outside in
    let n = matrix.len();
    for i in 0..n/2 {
      // work the row
      for j in 0..(n-i-1) {
        let mut x = i+j;
        let mut y = i;
        let mut tmp = matrix[i][j];
        for k in 0..4 {
          let nx = n - 1 - y;
          let ny = x;
          let nxt = matrix[ny][nx];
          println!("replace {},{}:{} with {},{}:{}", ny, nx, matrix[ny][nx], y,x,tmp);
          matrix[ny][nx] = tmp;
          tmp = nxt;
          y = ny;
          x = nx;
        }
      }
    }

  }
}

// formula for 90deg transform (i,j) = (j,N-i-1)