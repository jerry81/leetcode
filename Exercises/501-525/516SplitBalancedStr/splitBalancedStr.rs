/*

1221. Split a String in Balanced Strings
Easy
Topics
Companies
Hint
Balanced strings are those that have an equal quantity of 'L' and 'R' characters.

Given a balanced string s, split it into some number of substrings such that:

Each substring is balanced.
Return the maximum number of balanced strings you can obtain.



Example 1:

Input: s = "RLRRLLRLRL"
Output: 4
Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.
Example 2:

Input: s = "RLRRRLLRLL"
Output: 2
Explanation: s can be split into "RL", "RRRLLRLL", each substring contains same number of 'L' and 'R'.
Note that s cannot be split into "RL", "RR", "RL", "LR", "LL", because the 2nd and 5th substrings are not balanced.
Example 3:

Input: s = "LLLLRRRR"
Output: 1
Explanation: s can be split into "LLLLRRRR".


Constraints:

2 <= s.length <= 1000
s[i] is either 'L' or 'R'.
s is a balanced string.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
283.4K
Submissions
330.3K
Acceptance Rate
85.8%

*/

impl Solution {
  pub fn balanced_string_split(s: String) -> i32 {
    let mut l = 0;
    let mut r = 0;
    let mut res = 0;
    for c in s.chars() {
      if c == 'L' {
        l+=1;
      } else {
        r+=1;
      }
      if l==r {
        res+=1;
        l = 0;
        r = 0;
      }
      res
    }
  }
}