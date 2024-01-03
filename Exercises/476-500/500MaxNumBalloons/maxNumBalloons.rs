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

impl Solution {
  pub fn max_number_of_balloons(text: String) -> i32 {
      let mut res = 0;
      for c in text.chars() {
        match c { // TIL: match syntax (switch)
          'b' | 'a' | 'l' | 'o' | 'n' => {
            println!("matched {}", c);
          }
          _ => {
            println!("nope");
          }
        }

      }
      res
  }
}