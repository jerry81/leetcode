/*

3163. String Compression III
Medium
Topics
Companies
Hint
Given a string word, compress it using the following algorithm:

Begin with an empty string comp. While word is not empty, use the following operation:
Remove a maximum length prefix of word made of a single character c repeating at most 9 times.
Append the length of the prefix followed by c to comp.
Return the string comp.



Example 1:

Input: word = "abcde"

Output: "1a1b1c1d1e"

Explanation:

Initially, comp = "". Apply the operation 5 times, choosing "a", "b", "c", "d", and "e" as the prefix in each operation.

For each prefix, append "1" followed by the character to comp.

Example 2:

Input: word = "aaaaaaaaaaaaaabb"

Output: "9a5a2b"

Explanation:

Initially, comp = "". Apply the operation 3 times, choosing "aaaaaaaaa", "aaaaa", and "bb" as the prefix in each operation.

For prefix "aaaaaaaaa", append "9" followed by "a" to comp.
For prefix "aaaaa", append "5" followed by "a" to comp.
For prefix "bb", append "2" followed by "b" to comp.


Constraints:

1 <= word.length <= 2 * 105
word consists only of lowercase English letters.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
50K
Submissions
84.9K
Acceptance Rate
58.8%

*/

impl Solution {
  pub fn compressed_string(word: String) -> String {
    let mut v_res: Vec<char> = vec![];
    let mut cur_c: char = '?';
    let mut cur_cnt: u8 = 0;
    for c in word.chars() {
      if cur_c == c {
        cur_cnt += 1;
      } else {
        v_res.push((cur_cnt+'0' as u8) as char);
        v_res.push(cur_c);
        cur_c = c;
        cur_cnt = 1;
      }
      if cur_cnt == 9 {
        v_res.push('9' as char);
        v_res.push(cur_c);
        cur_cnt = 0;
      }
    }
    v_res.push((cur_cnt+'0' as u8) as char);
    v_res.push(cur_c);
    v_res = v_res[2..].to_vec();
    v_res.into_iter().collect()
  }
}