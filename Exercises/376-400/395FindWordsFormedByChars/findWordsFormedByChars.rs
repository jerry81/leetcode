/*

1160. Find Words That Can Be Formed by Characters
Easy
1.4K
152
Companies
You are given an array of strings words and a string chars.

A string is good if it can be formed by characters from chars (each character can only be used once).

Return the sum of lengths of all good strings in words.



Example 1:

Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
Example 2:

Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation: The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.


Constraints:

1 <= words.length <= 1000
1 <= words[i].length, chars.length <= 100
words[i] and chars consist of lowercase English letters.
Accepted
155.4K
Submissions
231.5K
Acceptance Rate
67.1%

*/

use std::collections::HashMap; // LC runtime wants this

impl Solution {
  pub fn count_characters(words: Vec<String>, chars: String) -> i32 {
    let mut freq:HashMap<char, i32> = HashMap::new();
    for c in chars.chars() {
      let entry = freq.entry(c);
      *entry.or_insert(0) += 1; // handle the key not exist case // rust doesn't have ++??
    }
    let mut res: i32 = 0;
    for s in words {
      let cpy = freq.clone();
      for c in s.chars() {
        let entry = cpy.entry(c);
        if *entry.or_insert(0) <= 0 {
          break;
        }
        *entry--;
        res+=s.len();
      }
    }
    res // TIL: no semicolon
  }
}