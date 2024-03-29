/*

1935. Maximum Number of Words You Can Type
Easy
Topics
Companies
Hint
There is a malfunctioning keyboard where some letter keys do not work. All other keys on the keyboard work properly.

Given a string text of words separated by a single space (no leading or trailing spaces) and a string brokenLetters of all distinct letter keys that are broken, return the number of words in text you can fully type using this keyboard.



Example 1:

Input: text = "hello world", brokenLetters = "ad"
Output: 1
Explanation: We cannot type "world" because the 'd' key is broken.
Example 2:

Input: text = "leet code", brokenLetters = "lt"
Output: 1
Explanation: We cannot type "leet" because the 'l' and 't' keys are broken.
Example 3:

Input: text = "leet code", brokenLetters = "e"
Output: 0
Explanation: We cannot type either word because the 'e' key is broken.


Constraints:

1 <= text.length <= 104
0 <= brokenLetters.length <= 26
text consists of words separated by a single space without any leading or trailing spaces.
Each word only consists of lowercase English letters.
brokenLetters consists of distinct lowercase English letters.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
54.1K
Submissions
74.5K
Acceptance Rate
72.6%

*/

impl Solution {
  pub fn can_be_typed_words(text: String, broken_letters: String) -> i32 {
    let spl_iter: Vec<&str> = text.split(' ').collect();
    let mut res = spl_iter.len();
    for s in spl_iter {
      for c in s.chars() {
          if broken_letters.contains(c) {
              res-=1;
              break;
          }
      }
    }
    res as i32
  }
}