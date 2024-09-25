/*

3083. Existence of a Substring in a String and Its Reverse
Easy
Topics
Companies
Hint
Given a string s, find any
substring
 of length 2 which is also present in the reverse of s.

Return true if such a substring exists, and false otherwise.



Example 1:

Input: s = "leetcode"

Output: true

Explanation: Substring "ee" is of length 2 which is also present in reverse(s) == "edocteel".

Example 2:

Input: s = "abcba"

Output: true

Explanation: All of the substrings of length 2 "ab", "bc", "cb", "ba" are also present in reverse(s) == "abcba".

Example 3:

Input: s = "abcd"

Output: false

Explanation: There is no substring of length 2 in s, which is also present in the reverse of s.



Constraints:

1 <= s.length <= 100
s consists only of lowercase English letters.

Seen this question in a real interview before?
1/5
Yes
No
Accepted
45.1K
Submissions
68.1K
Acceptance Rate
66.3%

*/

use std::collections::HashSet;

impl Solution {
  pub fn is_substring_present(s: String) -> bool {
    let rev: String = s.chars().rev().collect(); // instead of Vec<char>.reverse()
    let hs: HashSet<_> = s.chars().collect::<Vec<_>>().windows(2).map(|pr| pr.iter().collect::<String>()).collect();
    rev.chars().collect::<Vec<_>>().windows(2).any(|r_v| hs.contains(&r_v.iter().collect::<String>())) // TIL: any returns a bool looks for 1 true
  }
}