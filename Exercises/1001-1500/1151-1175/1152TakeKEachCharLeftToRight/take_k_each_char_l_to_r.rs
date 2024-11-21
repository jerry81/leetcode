/*

2516. Take K of Each Character From Left and Right
Medium
Topics
Companies
Hint
You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k. Each minute, you may take either the leftmost character of s, or the rightmost character of s.

Return the minimum number of minutes needed for you to take at least k of each character, or return -1 if it is not possible to take k of each character.



Example 1:

Input: s = "aabaaaacaabc", k = 2
Output: 8
Explanation:
Take three characters from the left of s. You now have two 'a' characters, and one 'b' character.
Take five characters from the right of s. You now have four 'a' characters, two 'b' characters, and two 'c' characters.
A total of 3 + 5 = 8 minutes is needed.
It can be proven that 8 is the minimum number of minutes needed.
Example 2:

Input: s = "a", k = 1
Output: -1
Explanation: It is not possible to take one 'b' or 'c' so return -1.


Constraints:

1 <= s.length <= 105
s consists of only the letters 'a', 'b', and 'c'.
0 <= k <= s.length
Seen this question in a real interview before?
1/5
Yes
No
Accepted
40.1K
Submissions
91.2K
Acceptance Rate
44.0%

*/
impl Solution {
  pub fn take_characters(s: String, k: i32) -> i32 {
      let mut la = None;
      let mut la2 = None;
      let mut lb = None;
      let mut lb2 = None;
      let mut lc = None;
      let mut lc2 = None;
      let n = s.len();

      // Find first and second occurrences from the left
      for (i, c) in s.chars().enumerate() {
          match c {
              'a' => {
                  if la.is_none() {
                      la = Some(i);
                  } else if la2.is_none() {
                      la2 = Some(i);
                  }
              }
              'b' => {
                  if lb.is_none() {
                      lb = Some(i);
                  } else if lb2.is_none() {
                      lb2 = Some(i);
                  }
              }
              'c' => {
                  if lc.is_none() {
                      lc = Some(i);
                  } else if lc2.is_none() {
                      lc2 = Some(i);
                  }
              }
              _ => {}
          }
      }

      // Find first and second occurrences from the right
      let mut ra = None;
      let mut ra2 = None;
      let mut rb = None;
      let mut rb2 = None;
      let mut rc = None;
      let mut rc2 = None;

      for (i, c) in s.chars().rev().enumerate() {
          let idx = n - 1 - i; // Calculate the original index
          match c {
              'a' => {
                  if ra.is_none() {
                      ra = Some(idx);
                  } else if ra2.is_none() {
                      ra2 = Some(idx);
                  }
              }
              'b' => {
                  if rb.is_none() {
                      rb = Some(idx);
                  } else if rb2.is_none() {
                      rb2 = Some(idx);
                  }
              }
              'c' => {
                  if rc.is_none() {
                      rc = Some(idx);
                  } else if rc2.is_none() {
                      rc2 = Some(idx);
                  }
              }
              _ => {}
          }
      }
      if la.is_none() { return -1 }
      if ra.is_none() { return -1 }
      if la2.is_none() { return -1 }
      if ra2.is_none() { return -1 }
      if lb.is_none() { return -1 }
      if rb.is_none() { return -1 }
      if lb2.is_none() { return -1 }
      if rb2.is_none() { return -1 }
      if lc.is_none() { return -1 }
      if rc.is_none() { return -1 }
      if lc2.is_none() { return -1 }
      if rc2.is_none() { return -1 }
      // Calculate the minimum minutes needed
      let mut mina = la2.unwrap().min(n-ra2.unwrap()).min(la.unwrap()+n-ra.unwrap());
      let mut minb = lb2.unwrap().min(n-rb2.unwrap()).min(lb.unwrap()+n-rb.unwrap());
      let mut minc = lc2.unwrap().min(n-rc2.unwrap()).min(lc.unwrap()+n-rc.unwrap());
      mina.max(minb).max(minc) as i32
  }
}