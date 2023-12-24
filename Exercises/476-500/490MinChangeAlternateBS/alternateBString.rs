/*

1758. Minimum Changes To Make Alternating Binary String
Easy
602
21
Companies
You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any '0' to '1' or vice versa.

The string is called alternating if no two adjacent characters are equal. For example, the string "010" is alternating, while the string "0100" is not.

Return the minimum number of operations needed to make s alternating.



Example 1:

Input: s = "0100"
Output: 1
Explanation: If you change the last character to '1', s will be "0101", which is alternating.
Example 2:

Input: s = "10"
Output: 0
Explanation: s is already alternating.
Example 3:

Input: s = "1111"
Output: 2
Explanation: You need two operations to reach "0101" or "1010".


Constraints:

1 <= s.length <= 104
s[i] is either '0' or '1'.
Accepted
40.9K
Submissions
70.1K
Acceptance Rate
58.4%
*/

impl Solution {
  fn tally(s:String, b:bool) -> i32 {
    let mut _b = b;
    let mut _s = s.clone();
    let mut _count = 0;
    for c in _s.chars() {
      if _b {
        if c == '0' {
          _count+=1;
        }
      }
      if !_b {
        if c == '1' {
          _count+=1;
        }
      }
      _b = !_b;
    }
    _count
  }

  pub fn min_operations(s: String) -> i32 {
    let _s = s.clone();
    let _s2 = s.clone();
    std::cmp::min(Solution::tally(_s,false), Solution::tally(_s2,true))
  }
}