/*

172. Factorial Trailing Zeroes
Medium
Topics
Companies
Given an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.



Example 1:

Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Example 3:

Input: n = 0
Output: 0


Constraints:

0 <= n <= 104


Follow up: Could you write a solution that works in logarithmic time complexity?

Seen this question in a real interview before?
1/5
Yes
No
Accepted
529K
Submissions
1.2M
Acceptance Rate
44.4%
*/

impl Solution {
  fn long_mult(n1: Vec<i32>, n2: Vec<i32>) -> Vec<i32> {
    vec![]
  }
  fn fact(n:i32) -> Vec<i32> {
    vec![1]
  }
  fn cnt(v:Vec<i32>) -> i32 {
    let mut res = 0;
    for i in (0..v.len()).rev() {
      if v[i] != 0 {
        break;
      }
      res+=1;
    }
    res
  }
  pub fn trailing_zeroes(n: i32) -> i32 {
    // must do long multiplication
    Solution::cnt(Solution::fact(n))
  }
}