/*

2309. Greatest English Letter in Upper and Lower Case
Easy
Topics
Companies
Hint
Given a string of English letters s, return the greatest English letter which occurs as both a lowercase and uppercase letter in s. The returned letter should be in uppercase. If no such letter exists, return an empty string.

An English letter b is greater than another letter a if b appears after a in the English alphabet.



Example 1:

Input: s = "lEeTcOdE"
Output: "E"
Explanation:
The letter 'E' is the only letter to appear in both lower and upper case.
Example 2:

Input: s = "arRAzFif"
Output: "R"
Explanation:
The letter 'R' is the greatest letter to appear in both lower and upper case.
Note that 'A' and 'F' also appear in both lower and upper case, but 'R' is greater than 'F' or 'A'.
Example 3:

Input: s = "AbCdEfGhIjK"
Output: ""
Explanation:
There is no letter that appears in both lower and upper case.


Constraints:

1 <= s.length <= 1000
s consists of lowercase and uppercase English letters.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
52.8K
Submissions
75.7K
Acceptance Rate
69.7%

*/
use std::collections::HashSet;

impl Solution {
  pub fn greatest_letter(s: String) -> String {
    let mut lowers:HashSet<char> = HashSet::new();
    let mut uppers:HashSet<char> = HashSet::new();
    for c in s.chars() {
      if c.is_lowercase() { lowers.insert(c); }
      if c.is_uppercase() { uppers.insert(c); }
    }
    let mut sorted:Vec<char> = Vec::new();
    for item in lowers {
      let upp = item.to_uppercase().next().unwrap();
      // TIL: to_uppercase returns iter
      if uppers.contains(&upp) { // Review: need a ref
        sorted.push(upp);
      }
    }
    sorted.sort();
    match sorted.last() { // review: using match
      Some(lst) => {
        return lst.to_string()
      }
      _ => { return "".to_string() }
    }
    return "".to_string();
  }
}