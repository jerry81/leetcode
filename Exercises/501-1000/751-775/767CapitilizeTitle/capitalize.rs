/*
2129. Capitalize the Title
Easy
Topics
Companies
Hint
You are given a string title consisting of one or more words separated by a single space, where each word consists of English letters. Capitalize the string by changing the capitalization of each word such that:

If the length of the word is 1 or 2 letters, change all letters to lowercase.
Otherwise, change the first letter to uppercase and the remaining letters to lowercase.
Return the capitalized title.



Example 1:

Input: title = "capiTalIze tHe titLe"
Output: "Capitalize The Title"
Explanation:
Since all the words have a length of at least 3, the first letter of each word is uppercase, and the remaining letters are lowercase.
Example 2:

Input: title = "First leTTeR of EACH Word"
Output: "First Letter of Each Word"
Explanation:
The word "of" has length 2, so it is all lowercase.
The remaining words have a length of at least 3, so the first letter of each remaining word is uppercase, and the remaining letters are lowercase.
Example 3:

Input: title = "i lOve leetcode"
Output: "i Love Leetcode"
Explanation:
The word "i" has length 1, so it is lowercase.
The remaining words have a length of at least 3, so the first letter of each remaining word is uppercase, and the remaining letters are lowercase.


Constraints:

1 <= title.length <= 100
title consists of words separated by a single space without any leading or trailing spaces.
Each word consists of uppercase and lowercase English letters and is non-empty.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
61.3K
Submissions
95.6K
Acceptance Rate
64.1%
*/

impl Solution {
  pub fn capitalize_title(title: String) -> String {
    let mut res: String = String::new();

    for tok in title.split(" ") {
      let mut builder:String = String::new();
      println!("tok is {}", tok);
      if tok.len() <=2 {
        for c in tok.chars() {
          builder.push(c.to_lowercase().next().unwrap()); // TIL: uppercase
        }
      } else {
        let mut f = true;
        for c in tok.chars() {
          let mut to_add =  c.to_lowercase().next().unwrap();
          if f {
            to_add = c.to_uppercase().next().unwrap();

            f = false;
          }
          builder.push(to_add);
        }
      }
      res += &builder;
      res += " ";
    }
    res.pop();
    res
  }
}