/*

2375. Construct Smallest Number From DI String
Medium
Topics
Companies
Hint
You are given a 0-indexed string pattern of length n consisting of the characters 'I' meaning increasing and 'D' meaning decreasing.

A 0-indexed string num of length n + 1 is created using the following conditions:

num consists of the digits '1' to '9', where each digit is used at most once.
If pattern[i] == 'I', then num[i] < num[i + 1].
If pattern[i] == 'D', then num[i] > num[i + 1].
Return the lexicographically smallest possible string num that meets the conditions.



Example 1:

Input: pattern = "IIIDIDDD"
Output: "123549876"
Explanation:
At indices 0, 1, 2, and 4 we must have that num[i] < num[i+1].
At indices 3, 5, 6, and 7 we must have that num[i] > num[i+1].
Some possible values of num are "245639871", "135749862", and "123849765".
It can be proven that "123549876" is the smallest possible num that meets the conditions.
Note that "123414321" is not possible because the digit '1' is used more than once.
Example 2:

Input: pattern = "DDD"
Output: "4321"
Explanation:
Some possible values of num are "9876", "7321", and "8742".
It can be proven that "4321" is the smallest possible num that meets the conditions.


Constraints:

1 <= pattern.length <= 8
pattern consists of only the letters 'I' and 'D'.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
87.6K
Submissions
105.1K
Acceptance Rate
83.4%

*/

use std::collections::HashSet;

impl Solution {
  fn r(pattern:&str, idx: usize, sz: &usize, used: &mut HashSet<char>, cur:char, res: &mut String) -> bool {
    if idx >= (sz-1) { return true }

    let nxt = pattern.chars().nth(idx).unwrap();
    let cur_as_u8 = cur as u8;
    if nxt == 'D' {
      let mut one_as_u8:u8 = '1' as u8;
      for cand in one_as_u8..cur_as_u8 {
        if used.contains(&(cand as char)) { continue; }

        used.insert(cand as char);
        res.push(cand as char);
        if Solution::r(pattern, idx+1, sz, used, cand as char, res) {
          return true;
        } else {
          res.pop();
          used.remove(&(cand as char));
        }
      }
    } else {
      let mut nine_as_u8:u8 = '9' as u8;
      for cand in cur_as_u8+1..=nine_as_u8 {
        if used.contains(&(cand as char)) { continue; }

        used.insert(cand as char);
        res.push(cand as char);

        if Solution::r(pattern, idx+1, sz, used, cand as char, res) {
          return true;
        } else {
          res.pop();
          used.remove(&(cand as char));
        }
      }
    }

    false
  }
  pub fn smallest_number(pattern: String) -> String {

    let mut res: &mut String = &mut String::new();
    for i in 1..=9 {
      let mut hs: HashSet<char> = HashSet::new();
      let mut c:char = (i as u8 + '0' as u8) as char;
      hs.insert(c);
      res.clear();
      res.push(c);
      if Solution::r(&pattern, 0, &(pattern.len()+1), &mut hs, c, res) {
        return res.to_string()
      }
    }

    String::new()
  }
}