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

      // Calculate the minimum minutes needed
      let mut total_minutes = 0;

      for (first, second) in [(la, ra), (lb, rb), (lc, rc)] {
          let first_min = first.map_or(i32::MAX, |f| f as i32 + 1);
          let second_min = second.map_or(i32::MAX, |s| (n - s) as i32 + 1);
          let min_needed = if let (Some(f), Some(s)) = (first, second) {
              (f as i32 + 1).min((n - s) as i32 + 1)
          } else {
              i32::MAX
          };

          total_minutes += min_needed;
      }

      // Check if we can take at least k of each character
      if total_minutes < k {
          -1
      } else {
          total_minutes
      }
  }
}