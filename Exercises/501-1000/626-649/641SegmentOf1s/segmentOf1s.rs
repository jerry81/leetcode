/*


1784. Check if Binary String Has at Most One Segment of Ones
Easy
Topics
Companies
Hint
Given a binary string s ​​​​​without leading zeros, return true​​​ if s contains at most one contiguous segment of ones. Otherwise, return false.



Example 1:

Input: s = "1001"
Output: false
Explanation: The ones do not form a contiguous segment.
Example 2:

Input: s = "110"
Output: true


Constraints:

1 <= s.length <= 100
s[i]​​​​ is either '0' or '1'.
s[0] is '1'.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
41.2K
Submissions
104.8K
Acceptance Rate
39.3%

*/

impl Solution {
  pub fn check_ones_segment(s: String) -> bool {
    let mut endseg = true;
    let mut cnt = 0;
    for c in s.chars() {
      if c == '1' && endseg {
        endseg = false;
        cnt += 1;
        if cnt > 1 {
          return false;
        }
      }
      if c == '0' {
        endseg = true;
      }
    }
    true
  }
}