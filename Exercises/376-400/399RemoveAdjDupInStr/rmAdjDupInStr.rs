/*

1047. Remove All Adjacent Duplicates In String
Easy
6.3K
236
Companies
You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.



Example 1:

Input: s = "abbaca"
Output: "ca"
Explanation:
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
Example 2:

Input: s = "azxxzy"
Output: "ay"


Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
Accepted
497.9K
Submissions
720.9K
Acceptance Rate
69.1%

*/

impl Solution {
  fn try_remove(s: String) -> String {
    let mut newv = Vec::new();
    for c in s.chars() {
      if newv.len() <= 0 {
        newv.push(c);
      } else {
        if newv.back() == c {
          newv.pop();
        } else {
          newv.push(c);
        }
      }
    }
    let ret: String = newv.into_iter().collect();
    ret
  }
  pub fn remove_duplicates(s: String) -> String {
    let str = Solution::try_remove(s);
    str
  }
}