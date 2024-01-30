/*

1446. Consecutive Characters
Easy
Topics
Companies
Hint
The power of the string is the maximum length of a non-empty substring that contains only one unique character.

Given a string s, return the power of s.



Example 1:

Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.
Example 2:

Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.


Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
157.9K
Submissions
261.1K
Acceptance Rate
60.5%

*/

impl Solution {
  pub fn max_power(s: String) -> i32 {
    let mut cur = '?';
    let mut cnt = 1;
    let mut mx = 0;
    for c in s.chars() {

      if c == cur {
        cnt+=1;
        mx = mx.max(cnt);
      } else {
        cnt = 1;
        cur = c;
      }
    }
    mx
  }
}