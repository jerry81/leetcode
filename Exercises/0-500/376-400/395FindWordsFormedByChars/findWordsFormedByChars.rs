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

      *freq.entry(c).or_insert(0) += 1; // handle the key not exist case // rust doesn't have ++??
    }
    let mut res: i32 = 0;

    for s in words {
      let mut cpy = freq.clone();
      let mut found = true;

      for c in s.chars() {
        if let Some(entry) = cpy.get_mut(&c) { // this is rust pattern matching
          /*
            cpy.get_mut(&c) - get a mut reference to value associated with char c in the cpy hashmap
            result Some(&mut i32) or None
          */
          if *entry > 0 {
            *entry -= 1;
          } else {
            found = false;
            break;
          }
        } else {
          found = false;
          break;
        }
      }

      if found {
        res+=s.len() as i32;
      }
    }
    res // TIL: no semicolon
  }
}