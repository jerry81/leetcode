/*

231. Power of Two
Solved
Easy
Topics
Companies
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.



Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1
Example 2:

Input: n = 16
Output: true
Explanation: 24 = 16
Example 3:

Input: n = 3
Output: false


Constraints:

-231 <= n <= 231 - 1


Follow up: Could you solve it without loops/recursion?
Seen this question in a real interview before?
1/4
Yes
No
Accepted
1.1M
Submissions
2.4M
Acceptance Rate
46.7%

*/

impl Solution {
  pub fn is_power_of_two(n: i32) -> bool {
    let two = 2;
    for i in 0..32 {
      let mut x = two.pow(i);
      if x > n { return false; }
      if x == n { return true; }
    }
    false
  }
}