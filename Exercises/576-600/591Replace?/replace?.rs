/*
1576. Replace All ?'s to Avoid Consecutive Repeating Characters
Easy
Topics
Companies
Hint
Given a string s containing only lowercase English letters and the '?' character, convert all the '?' characters into lowercase letters such that the final string does not contain any consecutive repeating characters. You cannot modify the non '?' characters.

It is guaranteed that there are no consecutive repeating characters in the given string except for '?'.

Return the final string after all the conversions (possibly zero) have been made. If there is more than one solution, return any of them. It can be shown that an answer is always possible with the given constraints.



Example 1:

Input: s = "?zs"
Output: "azs"
Explanation: There are 25 solutions for this problem. From "azs" to "yzs", all are valid. Only "z" is an invalid modification as the string will consist of consecutive repeating characters in "zzs".
Example 2:

Input: s = "ubv?w"
Output: "ubvaw"
Explanation: There are 24 solutions for this problem. Only "v" and "w" are invalid modifications as the strings will consist of consecutive repeating characters in "ubvvw" and "ubvww".


Constraints:

1 <= s.length <= 100
s consist of lowercase English letters and '?'.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
58.3K
Submissions
124.8K
Acceptance Rate
46.7%
*/

impl Solution {
  pub fn modify_string(s: String) -> String {
    let mut cv:Vec<char> = Vec::new();

    let sz = s.len();
    for idx in 0..sz {
      let cur = s.chars().nth(idx).unwrap();
      if cur != '?' { continue }
      let prev = '?';
      if idx > 0 {
        prev = s.chars().nth(idx-1).unwrap();
      }
      let nxt = '?';
      if idx < (sz-1) {
        nxt = s.chars().nth(idx+1).unwrap();
      }
    }

    "".to_string()
  }
}