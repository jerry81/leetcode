/*


205. Isomorphic Strings
Solved
Easy
Topics
Companies
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.



Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true


Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
1.2M
Submissions
2.6M
Acceptance Rate
43.9%

*/
use std::collections::HashMap;
impl Solution {

  pub fn is_isomorphic(s: String, t: String) -> bool {
    // one of those freq problems.
    let mut hm: HashMap<char,i32> = HashMap::new();
    let mut freq_of_freq: HashMap<i32,i32> = HashMap::new();
    let mut hm2: HashMap<char,i32> = HashMap::new();
    for c in s.chars() {
      *hm.entry(c).or_insert(0)+=1;
    }
    for c in t.chars() {
      *hm2.entry(c).or_insert(0)+=1;
    }
    for (_,v) in &hm {
      *freq_of_freqs.entry(v).or_insert(0)+=1;
    }
    for (_,v) in &hm2 {
      let mut freq = *freq_of_freqs.entry(v).or_insert(-1);
      if freq <= 0 {
        return false;
      } else {
        freq-=1;
        if freq == 0 {
          freq_of_freqs.remove(v);
        }
      }
    }
    freq_of_freqs.is_empty()
  }
}