/*

3090. Maximum Length Substring With Two Occurrences
Easy
Topics
Companies
Hint
Given a string s, return the maximum length of a
substring
 such that it contains at most two occurrences of each character.


Example 1:

Input: s = "bcbbbcba"

Output: 4

Explanation:

The following substring has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".
Example 2:

Input: s = "aaaa"

Output: 2

Explanation:

The following substring has a length of 2 and contains at most two occurrences of each character: "aaaa".


Constraints:

2 <= s.length <= 100
s consists only of lowercase English letters.

Seen this question in a real interview before?
1/5
Yes
No
Accepted
41.3K
Submissions
64.5K
Acceptance Rate
64.0%

*/
use std::collections::HashMap;

impl Solution {
  pub fn maximum_length_substring(s: String) -> i32 {
    let mut res = 0;
    let n = s.len();
    for i in 0..n-1 {
      for j in i+1..n {
        let substr = s[i..j];
        let mut hm:HashMap<char,i32> = HashMap::new();
        let mut safe = true;
        for c in substr.chars() {
          *hm.entry(c).or_insert(0)+=1;
          if hm.entry(c).or_insert(0) > 2 {
            safe = false;
            break;
          }
        }
        if safe {
          res = res.max((j-i) as i32);
        }
      }
    }
  }
}