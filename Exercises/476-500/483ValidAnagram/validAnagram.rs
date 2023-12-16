/*

242. Valid Anagram
Easy
11.1K
353
Companies
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.



Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false


Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.


Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

Accepted
2.9M
Submissions
4.5M
Acceptance Rate
63.5%

*/

use std::collections::HashMap;

impl Solution {
  pub fn is_anagram(s: String, t: String) -> bool {
    let mut hm:HashMap<char,i32> = HashMap::new();

    for c in s.chars() {
      *hm.entry(c).or_insert(0) += 1;
    }

    for c in t.chars() {
      *hm.entry(c).or_insert(-1) -= 1;
    }

    for (key, value) in hm.iter() {
      if *value != 0 {
        return false
      }
    }

    true
  }
}