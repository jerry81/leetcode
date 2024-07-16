/*

2544. Alternating Digit Sum
Easy
Topics
Companies
Hint
You are given a positive integer n. Each digit of n has a sign according to the following rules:

The most significant digit is assigned a positive sign.
Each other digit has an opposite sign to its adjacent digits.
Return the sum of all digits with their corresponding sign.



Example 1:

Input: n = 521
Output: 4
Explanation: (+5) + (-2) + (+1) = 4.
Example 2:

Input: n = 111
Output: 1
Explanation: (+1) + (-1) + (+1) = 1.
Example 3:

Input: n = 886996
Output: 0
Explanation: (+8) + (-8) + (+6) + (-9) + (+9) + (-6) = 0.


Constraints:

1 <= n <= 109


Seen this question in a real interview before?
1/5
Yes
No
Accepted
60.9K
Submissions
89.3K
Acceptance Rate
68.2%

*/

impl Solution {
  pub fn alternate_digit_sum(n: i32) -> i32 {
    let (res, _) = n.to_string().chars().fold(
      (0,true), |(sm, pos), cur_char| {
        let mut addend = (cur_char as u8 - '0' as u8) as i32;
        if !pos { addend *= -1; }
        (sm+addend, !pos)
      }
    );
    res
  }
}