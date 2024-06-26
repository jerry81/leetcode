/*


2133. Check if Every Row and Column Contains All Numbers
Easy
Topics
Companies
Hint
An n x n matrix is valid if every row and every column contains all the integers from 1 to n (inclusive).

Given an n x n integer matrix matrix, return true if the matrix is valid. Otherwise, return false.



Example 1:


Input: matrix = [[1,2,3],[3,1,2],[2,3,1]]
Output: true
Explanation: In this case, n = 3, and every row and column contains the numbers 1, 2, and 3.
Hence, we return true.
Example 2:


Input: matrix = [[1,1,1],[1,2,3],[1,2,3]]
Output: false
Explanation: In this case, n = 3, but the first row and the first column do not contain the numbers 2 or 3.
Hence, we return false.


Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 100
1 <= matrix[i][j] <= n
Seen this question in a real interview before?
1/5
Yes
No
Accepted
71.1K
Submissions
137.3K
Acceptance Rate
51.8%

*/

use std::collections::HashSet;

impl Solution {
  pub fn check_valid(matrix: Vec<Vec<i32>>) -> bool {
    let n = matrix.len();

    // brute
    for i in 0..n {
      let mut hs:HashSet<i32> = HashSet::new();
      for j in 0..n {
        hs.insert(matrix[i][j]);
      }
      if hs.len() != n { return false; }
    }

    for i in 0..n {
      let mut hs:HashSet<i32> = HashSet::new();
      for j in 0..n {
        hs.insert(matrix[j][i]);
      }
      if hs.len() != n { return false; }
    }

    true
  }
}