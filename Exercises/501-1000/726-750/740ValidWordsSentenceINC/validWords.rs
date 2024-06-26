/*

2047. Number of Valid Words in a Sentence
Easy
Topics
Companies
Hint
A sentence consists of lowercase letters ('a' to 'z'), digits ('0' to '9'), hyphens ('-'), punctuation marks ('!', '.', and ','), and spaces (' ') only. Each sentence can be broken down into one or more tokens separated by one or more spaces ' '.

A token is a valid word if all three of the following are true:

It only contains lowercase letters, hyphens, and/or punctuation (no digits).
There is at most one hyphen '-'. If present, it must be surrounded by lowercase characters ("a-b" is valid, but "-ab" and "ab-" are not valid).
There is at most one punctuation mark. If present, it must be at the end of the token ("ab,", "cd!", and "." are valid, but "a!b" and "c.," are not valid).
Examples of valid words include "a-b.", "afad", "ba-c", "a!", and "!".

Given a string sentence, return the number of valid words in sentence.



Example 1:

Input: sentence = "cat and  dog"
Output: 3
Explanation: The valid words in the sentence are "cat", "and", and "dog".
Example 2:

Input: sentence = "!this  1-s b8d!"
Output: 0
Explanation: There are no valid words in the sentence.
"!this" is invalid because it starts with a punctuation mark.
"1-s" and "b8d" are invalid because they contain digits.
Example 3:

Input: sentence = "alice and  bob are playing stone-game10"
Output: 5
Explanation: The valid words in the sentence are "alice", "and", "bob", "are", and "playing".
"stone-game10" is invalid because it contains digits.


Constraints:

1 <= sentence.length <= 1000
sentence only contains lowercase English letters, digits, ' ', '-', '!', '.', and ','.
There will be at least 1 token.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
28.6K
Submissions
98.5K
Acceptance Rate
29.0%

*/
impl Solution {
  pub fn count_valid_words(sentence: String) -> i32 {
      let mut tk = sentence.split(" ");
      let mut res = 0;
      for t in tk {
          if t.is_empty() { continue }
          let mut valid = true;
          let mut hyphen_count = 0;
          let mut punct_count = 0;
          let mut hyphen_preceeding = false;
          let mut letter_preceeding = false;
          let mut punct_preceeding = false;
          let mut start = true;
          for c in t.chars() {
            let code = c as u8;
            if code >= 'a' as u8 && code <= 'z' as u8 {
              start = false;
              if punct_preceeding { valid = false; break }
              letter_preceeding = true;
              hyphen_preceeding = false;
              punct_preceeding = false;
              continue
            }
            if code == '-' as u8 {
              start = false;
              if punct_preceeding {
                valid = false;
                break
              }
              if !letter_preceeding {
                valid = false;
                break
              }
              hyphen_preceeding = true;
              letter_preceeding = false;
              punct_preceeding = false;
              hyphen_count += 1;
              if hyphen_count > 1 {
                valid = false;
                break
              }
              continue
            }
            if code == '!' as u8 || code == '.' as u8 || code == ',' as u8 {
              if !letter_preceeding && !start {

                valid = false;
                break
              }
              start = false;
              punct_preceeding = true;
              letter_preceeding = false;
              hyphen_preceeding = false;
              punct_count += 1;
              if punct_count > 1 {
                valid = false;
                break
              }
              continue
            }
            valid = false;
            break;
          }
          if valid && !hyphen_preceeding {
            res+=1;
          }
      }
      res
  }
}