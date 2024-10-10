/*

3174. Clear Digits
Easy
Topics
Companies
Hint
You are given a string s.

Your task is to remove all digits by doing this operation repeatedly:

Delete the first digit and the closest non-digit character to its left.
Return the resulting string after removing all digits.



Example 1:

Input: s = "abc"

Output: "abc"

Explanation:

There is no digit in the string.

Example 2:

Input: s = "cb34"

Output: ""

Explanation:

First, we apply the operation on s[2], and s becomes "c4".

Then we apply the operation on s[1], and s becomes "".



Constraints:

1 <= s.length <= 100
s consists only of lowercase English letters and digits.
The input is generated such that it is possible to delete all digits.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
53.9K
Submissions
73.5K
Acceptance Rate
73.2%


*/

impl Solution {
  pub fn clear_digits(s: String) -> String {
    let mut res = String::new();
    let mut num_count = 0;
    for c in s.chars().rev() {
      if c.is_digit(10) {
        num_count+=1;
      } else {
        if num_count == 0 {
          res.push(c);
        } else {
          num_count-=1;
        }
      }
    }
    res.chars().rev().collect()
  }
}