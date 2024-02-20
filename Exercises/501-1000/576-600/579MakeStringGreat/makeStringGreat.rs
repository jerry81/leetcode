/*

1544. Make The String Great
Easy
Topics
Companies
Hint
Given a string s of lower and upper case English letters.

A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:

0 <= i <= s.length - 2
s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
To make the string good, you can choose two adjacent characters that make the string bad and remove them. You can keep doing this until the string becomes good.

Return the string after making it good. The answer is guaranteed to be unique under the given constraints.

Notice that an empty string is also good.



Example 1:

Input: s = "leEeetcode"
Output: "leetcode"
Explanation: In the first step, either you choose i = 1 or i = 2, both will result "leEeetcode" to be reduced to "leetcode".
Example 2:

Input: s = "abBAcC"
Output: ""
Explanation: We have many possible scenarios, and all lead to the same answer. For example:
"abBAcC" --> "aAcC" --> "cC" --> ""
"abBAcC" --> "abBA" --> "aA" --> ""
Example 3:

Input: s = "s"
Output: "s"


Constraints:

1 <= s.length <= 100
s contains only lower and upper case English letters.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
161.9K
Submissions
256.7K
Acceptance Rate
63.1%

*/

impl Solution {
  fn r(s:&String) -> String {
    let mut buf = ' ';
    let mut ret = String::new();
    for c in s.chars() {
      if buf == ' ' {
        buf = c;
        continue
      }
      if (c as i32 - buf as i32).abs() == 32 {
        buf = ' ';
      } else {
        ret.push(buf);
        buf = c;
      }
    }
    if buf != ' ' { ret.push(buf); }
    ret
  }
  pub fn make_good(s: String) -> String {
    let cur = Solution::r(&s);
    if cur.len() == s.len() {
        cur
    } else {
        Solution::make_good(cur)
    }
  }
}