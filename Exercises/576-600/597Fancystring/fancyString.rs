/*

1957. Delete Characters to Make Fancy String
Easy
Topics
Companies
Hint
A fancy string is a string where no three consecutive characters are equal.

Given a string s, delete the minimum possible number of characters from s to make it fancy.

Return the final string after the deletion. It can be shown that the answer will always be unique.



Example 1:

Input: s = "leeetcode"
Output: "leetcode"
Explanation:
Remove an 'e' from the first group of 'e's to create "leetcode".
No three consecutive characters are equal, so return "leetcode".
Example 2:

Input: s = "aaabaaaa"
Output: "aabaa"
Explanation:
Remove an 'a' from the first group of 'a's to create "aabaaaa".
Remove two 'a's from the second group of 'a's to create "aabaa".
No three consecutive characters are equal, so return "aabaa".
Example 3:

Input: s = "aab"
Output: "aab"
Explanation: No three consecutive characters are equal, so return "aab".


Constraints:

1 <= s.length <= 105
s consists only of lowercase English letters.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
34.1K
Submissions
59.3K
Acceptance Rate
57.6%

*/

impl Solution {
  pub fn make_fancy_string(s: String) -> String {
    let mut res:Vec<char> = Vec::new();
    let mut cur = '?';
    let mut cnt = 0;
    for c in s.chars() {
      if c == cur {
        cnt+=1;
        if cnt < 3 {
          continue
        }
      }
      cur = c;
      res.push(c);
    }
    res.iter().collect()
  }
}