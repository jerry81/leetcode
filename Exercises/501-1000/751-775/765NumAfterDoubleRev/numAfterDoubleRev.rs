/*
2119. A Number After a Double Reversal
Easy
Topics
Companies
Hint
Reversing an integer means to reverse all its digits.

For example, reversing 2021 gives 1202. Reversing 12300 gives 321 as the leading zeros are not retained.
Given an integer num, reverse num to get reversed1, then reverse reversed1 to get reversed2. Return true if reversed2 equals num. Otherwise return false.



Example 1:

Input: num = 526
Output: true
Explanation: Reverse num to get 625, then reverse 625 to get 526, which equals num.
Example 2:

Input: num = 1800
Output: false
Explanation: Reverse num to get 81, then reverse 81 to get 18, which does not equal num.
Example 3:

Input: num = 0
Output: true
Explanation: Reverse num to get 0, then reverse 0 to get 0, which equals num.


Constraints:

0 <= num <= 106
Seen this question in a real interview before?
1/5
Yes
No
Accepted
85.1K
Submissions
106.9K
Acceptance Rate
79.6%
*/

impl Solution {
  pub fn is_same_after_reversals(num: i32) -> bool {
    if num < 10 { return true }

    let n_str = num.to_string();

    //let lst = n_str.chars().nth(n_str.len()-1).unwrap();

    // lst != '0'

    n_str.chars().last() != Some('0') // better
  }
}