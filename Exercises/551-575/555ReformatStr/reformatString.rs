/*

1417. Reformat The String
Easy
Topics
Companies
Hint
You are given an alphanumeric string s. (Alphanumeric string is a string consisting of lowercase English letters and digits).

You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. That is, no two adjacent characters have the same type.

Return the reformatted string or return an empty string if it is impossible to reformat the string.



Example 1:

Input: s = "a0b1c2"
Output: "0a1b2c"
Explanation: No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.
Example 2:

Input: s = "leetcode"
Output: ""
Explanation: "leetcode" has only characters so we cannot separate them by digits.
Example 3:

Input: s = "1229857369"
Output: ""
Explanation: "1229857369" has only digits so we cannot separate them by characters.


Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters and/or digits.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
55.5K
Submissions
104.2K
Acceptance Rate
53.2%

*/
impl Solution {
  pub fn reformat(s: String) -> String {
      let mut dig: Vec<char> = Vec::new();
      let mut alphas: Vec<char> = Vec::new();

      for c in s.chars() {
        if c.is_digit(10) {
          /*
            what is char.is_digit(i32)'s usage?
            c you are checking
            arg is base, (0 for any)
          */
          dig.push(c);
        } else {
          alphas.push(c);
        }
      }
      let mut ret :Vec<char> = Vec::new();
      if (dig.len() as i32 - alphas.len() as i32).abs() > 2 {
        "".to_string()
      } else if (dig.len() == 0 && alphas.len() > 1) {
        "".to_string()
      } else if (alphas.len() == 0 && dig.len() > 1) {
        "".to_string()

      } else {
        let mut i1 = 0;
        let mut i2 = 0;
        let mut alpha = false;
        if dig.len() > alphas.len() {
          loop {
              if (i1 >= alphas.len() && i2 >= dig.len()) {
                break;
              }
              if alpha {
                ret.push(alphas[i1]);
                i1+=1;
              } else {
                ret.push(dig[i2]);
                i2+=1;
              }
              alpha = !alpha;
          }
        } else {
          alpha = true;
          loop {
            if (i1 >= alphas.len() && i2 >= dig.len()) {
              break;
            }
            if alpha {
              ret.push(alphas[i1]);
              i1+=1;
            } else {
              ret.push(dig[i2]);
              i2+=1;
            }
            alpha = !alpha;
          }
        }
        ret.iter().collect()
      }

  }
}