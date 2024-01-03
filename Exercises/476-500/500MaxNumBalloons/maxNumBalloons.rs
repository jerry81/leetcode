/*

1189. Maximum Number of Balloons
Easy
1.6K
93
Companies
Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.



Example 1:



Input: text = "nlaebolko"
Output: 1
Example 2:



Input: text = "loonbalxballpoon"
Output: 2
Example 3:

Input: text = "leetcode"
Output: 0


Constraints:

1 <= text.length <= 104
text consists of lower case English letters only.
Accepted
180.5K
Submissions
300.6K
Acceptance Rate
60.1%

*/

use std::collections::HashMap;

impl Solution {
  pub fn max_number_of_balloons(text: String) -> i32 {
      let mut hm: HashMap<char, i32> = HashMap::new();
      let mut res = 0;
      for c in text.chars() {
        match c { // TIL: match syntax (switch)
          'b' | 'a' | 'l' | 'o' | 'n' => {
            // 2 o, 2 l
            *hm.entry(c).or_insert(0)+=1;
            println!("matched {}", c);
          }
          _ => {
            println!("nope");
          }
        }
      }
      while true {
        if let Some(&value) = hm.get('b') {
          if value < 1 { break; }
          *hm.entry('b').or_insert(0) -= 1;
        } else {
          break;
        }
        if let Some(&value) = hm.get('a') {
          if value < 1 { break; }

          *hm.entry('a').or_insert(0) -= 1;

        } else {
          break;
        }
        if let Some(&value) = hm.get('l') {
          if value < 2 { break; }

          *hm.entry('l').or_insert(0) -= 2;

        } else {
          break;
        }
        if let Some(&value) = hm.get('o') {
          if value < 2 { break; }

          *hm.entry('o').or_insert(0) -= 2;

        } else {
          break;
        }
        if let Some(&value) = hm.get('n') {
          if value < 1 { break; }

          *hm.entry('n').or_insert(0) -= 1;

        } else {
          break;
        }
        res+=1;
      }
      res
  }
}