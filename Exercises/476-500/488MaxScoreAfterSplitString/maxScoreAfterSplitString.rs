/*
1422. Maximum Score After Splitting a String
Easy
988
45
Companies
Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).

The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.



Example 1:

Input: s = "011101"
Output: 5
Explanation:
All possible ways of splitting s into two non-empty substrings are:
left = "0" and right = "11101", score = 1 + 4 = 5
left = "01" and right = "1101", score = 1 + 3 = 4
left = "011" and right = "101", score = 1 + 2 = 3
left = "0111" and right = "01", score = 1 + 1 = 2
left = "01110" and right = "1", score = 2 + 1 = 3
Example 2:

Input: s = "00111"
Output: 5
Explanation: When left = "00" and right = "111", we get the maximum score = 2 + 3 = 5
Example 3:

Input: s = "1111"
Output: 3


Constraints:

2 <= s.length <= 500
The string s consists of characters '0' and '1' only.
Accepted
86.2K
Submissions
142.6K
Acceptance Rate
60.4%
*/


impl Solution {
  pub fn max_score(s: String) -> i32 {
    // prefix sums
    let mut zeroes_ps:Vec<i32> = vec![];
    let mut ones_ps:Vec<i32> = vec![];
    let mut zc = 0;
    let mut oc = 0;
    for c in s.chars() {
      if c == '0' {
        zc+=1;
      } else {
        oc+=1;
      }
      zeroes_ps.push(zc);
      ones_ps.push(oc);
    }
    let mut max_score = 0;
    for i in 0..s.len()-1 {
      let score = zeroes_ps[i] + oc - ones_ps[i];
      if score > max_score { max_score = score; }
    }
    max_score
  }
}