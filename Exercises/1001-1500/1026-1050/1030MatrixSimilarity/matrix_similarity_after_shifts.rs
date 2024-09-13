/*

2946. Matrix Similarity After Cyclic Shifts
Easy
Topics
Companies
Hint
You are given an m x n integer matrix mat and an integer k. The matrix rows are 0-indexed.

The following proccess happens k times:

Even-indexed rows (0, 2, 4, ...) are cyclically shifted to the left.


Odd-indexed rows (1, 3, 5, ...) are cyclically shifted to the right.


Return true if the final modified matrix after k steps is identical to the original matrix, and false otherwise.



Example 1:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 4

Output: false

Explanation:

In each step left shift is applied to rows 0 and 2 (even indices), and right shift to row 1 (odd index).



Example 2:

Input: mat = [[1,2,1,2],[5,5,5,5],[6,3,6,3]], k = 2

Output: true

Explanation:



Example 3:

Input: mat = [[2,2],[2,2]], k = 3

Output: true

Explanation:

As all the values are equal in the matrix, even after performing cyclic shifts the matrix will remain the same.



Constraints:

1 <= mat.length <= 25
1 <= mat[i].length <= 25
1 <= mat[i][j] <= 25
1 <= k <= 50
Seen this question in a real interview before?
1/5
Yes
No
Accepted
23.6K
Submissions
40.4K
Acceptance Rate
58.6%

*/

impl Solution {
  pub fn are_similar(mat: Vec<Vec<i32>>, k: i32) -> bool {
    let m = mat.len();
    let n = mat[0].len();
    let k = k as usize % n; // Normalize k to be within the range of column count

        for i in 0..m {
            for j in 0..n {
                let new_j = if i % 2 == 0 {
                    // Even-indexed rows: left shift
                    (j + n - k) % n
                } else {
                    // Odd-indexed rows: right shift
                    (j + k) % n
                };

                if mat[i][j] != mat[i][new_j] {
                    return false;
                }
            }
        }

        true

  }
}