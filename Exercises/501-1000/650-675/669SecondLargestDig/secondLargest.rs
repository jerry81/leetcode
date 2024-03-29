/*

1796. Second Largest Digit in a String
Easy
Topics
Companies
Hint
Given an alphanumeric string s, return the second largest numerical digit that appears in s, or -1 if it does not exist.

An alphanumeric string is a string consisting of lowercase English letters and digits.



Example 1:

Input: s = "dfa12321afd"
Output: 2
Explanation: The digits that appear in s are [1, 2, 3]. The second largest digit is 2.
Example 2:

Input: s = "abc1111"
Output: -1
Explanation: The digits that appear in s are [1]. There is no second largest digit.


Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters and/or digits.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
53.7K
Submissions
107.2K
Acceptance Rate
50.1%


*/

impl Solution {
  pub fn second_highest(s: String) -> i32 {
    // maintain list of digits
    let mut digs: Vec<i32> = Vec::new();
    for c in s.chars() {
      if c.is_digit(10) { // TIL (review) must include the base
        digs.push(c as i32 - '0' as i32);
      }
    }
    if digs.len() < 2 { return -1 }
    digs.sort_by(|a, b| b.cmp(a)); // sort in reverse order
    let mut mx = digs[0];
    for i in digs {
      if i != mx {
        return i
      }
    }
    -1
  }
}