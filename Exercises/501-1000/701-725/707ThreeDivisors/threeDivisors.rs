/*

1952. Three Divisors
Easy
Topics
Companies
Hint
Given an integer n, return true if n has exactly three positive divisors. Otherwise, return false.

An integer m is a divisor of n if there exists an integer k such that n = k * m.



Example 1:

Input: n = 2
Output: false
Explantion: 2 has only two divisors: 1 and 2.
Example 2:

Input: n = 4
Output: true
Explantion: 4 has three divisors: 1, 2, and 4.


Constraints:

1 <= n <= 104
Seen this question in a real interview before?
1/5
Yes
No
Accepted
65.1K
Submissions
107.7K
Acceptance Rate
60.5%

*/
impl Solution {
  pub fn is_three(n: i32) -> bool {
    let uplim = (n as f64).sqrt() as i32;
    let mut found = false;
    for i in 2..=uplim {
        if n%i == 0 {
          if found { return false; }
          found = true;
        }
    }
    found
  }
}