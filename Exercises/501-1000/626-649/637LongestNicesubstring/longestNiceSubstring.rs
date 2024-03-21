/*


1763. Longest Nice Substring
Easy
Topics
Companies
Hint
A string s is nice if, for every letter of the alphabet that s contains, it appears both in uppercase and lowercase. For example, "abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' appear. However, "abA" is not because 'b' appears, but 'B' does not.

Given a string s, return the longest substring of s that is nice. If there are multiple, return the substring of the earliest occurrence. If there are none, return an empty string.



Example 1:

Input: s = "YazaAay"
Output: "aAa"
Explanation: "aAa" is a nice string because 'A/a' is the only letter of the alphabet in s, and both 'A' and 'a' appear.
"aAa" is the longest nice substring.
Example 2:

Input: s = "Bb"
Output: "Bb"
Explanation: "Bb" is a nice string because both 'B' and 'b' appear. The whole string is a substring.
Example 3:

Input: s = "c"
Output: ""
Explanation: There are no nice substrings.


Constraints:

1 <= s.length <= 100
s consists of uppercase and lowercase English letters.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
51.2K
Submissions
84.7K
Acceptance Rate
60.4%

*/
use std::collections::HashSet;
impl Solution {
  pub fn longest_nice_substring(s: String) -> String {
    let mut hs:HashSet<char> = HashSet::new();
    for c in s.chars() {
      hs.insert(c);
    }
    for &c in hs {
      if !hs.contains(c.to_ascii_uppercase()) { return false; }
      if !hs.contains(c.to_ascii_lowercase()) { return false; }
    }
    true
  }
}