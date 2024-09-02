/*

2843. Count Symmetric Integers
Easy
Topics
Companies
Hint
You are given two positive integers low and high.

An integer x consisting of 2 * n digits is symmetric if the sum of the first n digits of x is equal to the sum of the last n digits of x. Numbers with an odd number of digits are never symmetric.

Return the number of symmetric integers in the range [low, high].



Example 1:

Input: low = 1, high = 100
Output: 9
Explanation: There are 9 symmetric integers between 1 and 100: 11, 22, 33, 44, 55, 66, 77, 88, and 99.
Example 2:

Input: low = 1200, high = 1230
Output: 4
Explanation: There are 4 symmetric integers between 1200 and 1230: 1203, 1212, 1221, and 1230.


Constraints:

1 <= low <= high <= 104
Seen this question in a real interview before?
1/5
Yes
No
Accepted
47.5K
Submissions
63.7K
Acceptance Rate
74.6%

*/

impl Solution {
  pub fn count_symmetric_integers(low: i32, high: i32) -> i32 {
    let mut res = 0;
    for i in low..=high {
      let n = i.to_string().len();
      if n % 2 == 1 { continue }
      let half = n/2;
      let mut fh = 0;
      let mut sh = 0;
      let as_s = (i as i32).to_string();
      for idx in 0..half {
        fh+=(as_s.to_string().chars().nth(idx).unwrap() as u8 - '0' as u8) as i32;
      }
      for idx in half..n {
        sh+=(as_s.to_string().chars().nth(idx).unwrap() as u8 - '0' as u8) as i32;
      }
      if fh == sh { res+=1; }
    }
    res
  }
}