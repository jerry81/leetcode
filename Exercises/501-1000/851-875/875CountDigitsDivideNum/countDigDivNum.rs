/*

2520. Count the Digits That Divide a Number
Easy
Topics
Companies
Hint
Given an integer num, return the number of digits in num that divide num.

An integer val divides nums if nums % val == 0.



Example 1:

Input: num = 7
Output: 1
Explanation: 7 divides itself, hence the answer is 1.
Example 2:

Input: num = 121
Output: 2
Explanation: 121 is divisible by 1, but not 2. Since 1 occurs twice as a digit, we return 2.
Example 3:

Input: num = 1248
Output: 4
Explanation: 1248 is divisible by all of its digits, hence the answer is 4.


Constraints:

1 <= num <= 109
num does not contain 0 as one of its digits.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
84.1K
Submissions
99.5K
Acceptance Rate
84.6%

*/

impl Solution {
  pub fn count_digits(num: i32) -> i32 {
    // num to string
    let s = num.to_string();
    s.chars()
    .fold(0,
      |sm, c| if num % ((c as u8 - '0' as u8) as i32) == 0 { sm+1 } else { sm }
    )
  }
}