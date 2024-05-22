/*
2180. Count Integers With Even Digit Sum
Easy
Topics
Companies
Hint
Given a positive integer num, return the number of positive integers less than or equal to num whose digit sums are even.

The digit sum of a positive integer is the sum of all its digits.



Example 1:

Input: num = 4
Output: 2
Explanation:
The only integers less than or equal to 4 whose digit sums are even are 2 and 4.
Example 2:

Input: num = 30
Output: 14
Explanation:
The 14 integers less than or equal to 30 whose digit sums are even are
2, 4, 6, 8, 11, 13, 15, 17, 19, 20, 22, 24, 26, and 28.


Constraints:

1 <= num <= 1000
Seen this question in a real interview before?
1/5
Yes
No
Accepted
59.4K
Submissions
88.8K
Acceptance Rate
66.9%
*/

impl Solution {
  fun sm_even(num: i32) -> bool {
    let as_s = num.to_string();
    let mut sm = 0;
    for c in as_s.chars() {
      sm += c as i32 - '0' as i32;
    }
    sm % 2 == 0
  }
  pub fn count_even(num: i32) -> i32 {
    let res = 0;
    for i in 1..=num {
      if Solution::sm_even(i) { res+=1 }
    }
    res
  }
}