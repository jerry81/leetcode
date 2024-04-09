/*

1876. Substrings of Size Three with Distinct Characters
Easy
Topics
Companies
Hint
A string is good if there are no repeated characters.

Given a string s​​​​​, return the number of good substrings of length three in s​​​​​​.

Note that if there are multiple occurrences of the same substring, every occurrence should be counted.

A substring is a contiguous sequence of characters in a string.



Example 1:

Input: s = "xyzzaz"
Output: 1
Explanation: There are 4 substrings of size 3: "xyz", "yzz", "zza", and "zaz".
The only good substring of length 3 is "xyz".
Example 2:

Input: s = "aababcabc"
Output: 4
Explanation: There are 7 substrings of size 3: "aab", "aba", "bab", "abc", "bca", "cab", and "abc".
The good substrings are "abc", "bca", "cab", and "abc".


Constraints:

1 <= s.length <= 100
s​​​​​​ consists of lowercase English letters.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
115.3K
Submissions
157.7K
Acceptance Rate
73.1%

*/

impl Solution {
  pub fn count_good_substrings(s: String) -> i32 {
    // from 0 to len-3
    let sz = s.len();
    if sz < 3 { return 0 }
    let mut res = 0;
    for i in 0..sz-2 {
      if Solution::is_good(s[i..i+3].to_string()) { res+=1; }
    }
    res
  }
  fn is_good(s: String) -> bool {
    let mut lookup = String::new();
    for c in s.chars() {
      if lookup.contains(c) {
        return false
      }

      lookup.push(c);
    }
    true
  }
}