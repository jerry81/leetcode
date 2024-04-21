/*

2000. Reverse Prefix of Word
Easy
Topics
Companies
Hint
Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the index of the first occurrence of ch (inclusive). If the character ch does not exist in word, do nothing.

For example, if word = "abcdefd" and ch = "d", then you should reverse the segment that starts at 0 and ends at 3 (inclusive). The resulting string will be "dcbaefd".
Return the resulting string.



Example 1:

Input: word = "abcdefd", ch = "d"
Output: "dcbaefd"
Explanation: The first occurrence of "d" is at index 3.
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "dcbaefd".
Example 2:

Input: word = "xyxzxe", ch = "z"
Output: "zxyxxe"
Explanation: The first and only occurrence of "z" is at index 3.
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "zxyxxe".
Example 3:

Input: word = "abcd", ch = "z"
Output: "abcd"
Explanation: "z" does not exist in word.
You should not do any reverse operation, the resulting string is "abcd".


Constraints:

1 <= word.length <= 250
word consists of lowercase English letters.
ch is a lowercase English letter.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
103.5K
Submissions
128K
Acceptance Rate
80.9%

*/

impl Solution {
  pub fn reverse_prefix(word: String, ch: char) -> String {
    let mut idx: i32 = -1;
    let mut cidx = 0;
    for c in word.chars() {
      if c == ch {
        idx = cidx as i32;
        break
      }
      cidx+=1;
    }

    if idx < 0 { return word; }
    let mut slice = &word[0..=idx as usize];
    let mut pref: String = slice.chars().rev().collect();
    pref += &word[(idx+1) as usize..].to_string();
    pref
  }
}