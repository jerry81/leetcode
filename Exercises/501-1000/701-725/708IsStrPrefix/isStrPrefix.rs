/*

1961. Check If String Is a Prefix of Array
Easy
Topics
Companies
Hint
Given a string s and an array of strings words, determine whether s is a prefix string of words.

A string s is a prefix string of words if s can be made by concatenating the first k strings in words for some positive k no larger than words.length.

Return true if s is a prefix string of words, or false otherwise.



Example 1:

Input: s = "iloveleetcode", words = ["i","love","leetcode","apples"]
Output: true
Explanation:
s can be made by concatenating "i", "love", and "leetcode" together.
Example 2:

Input: s = "iloveleetcode", words = ["apples","i","love","leetcode"]
Output: false
Explanation:
It is impossible to make s using a prefix of arr.


Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 20
1 <= s.length <= 1000
words[i] and s consist of only lowercase English letters.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
49.8K
Submissions
94.3K
Acceptance Rate
52.8%

*/

impl Solution {
  pub fn is_prefix_string(s: String, words: Vec<String>) -> bool {
    let mut s_c = s.clone();
    let mut words_c = words.clone();
    while !s_c.is_empty() {
      if words_c.is_empty() { return false }

      let f = words_c.first().unwrap();
      if s_c.starts_with(f) {
        s_c = s_c[f.len()..].to_string();
        words_c.remove(0);
      } else {
        return false;
      }
    }
    true
  }
}