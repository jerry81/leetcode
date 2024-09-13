/*

2937. Make Three Strings Equal
Easy
Topics
Companies
Hint
You are given three strings: s1, s2, and s3. In one operation you can choose one of these strings and delete its rightmost character. Note that you cannot completely empty a string.

Return the minimum number of operations required to make the strings equal. If it is impossible to make them equal, return -1.



Example 1:

Input: s1 = "abc", s2 = "abb", s3 = "ab"

Output: 2

Explanation: Deleting the rightmost character from both s1 and s2 will result in three equal strings.

Example 2:

Input: s1 = "dac", s2 = "bac", s3 = "cac"

Output: -1

Explanation: Since the first letters of s1 and s2 differ, they cannot be made equal.



Constraints:

1 <= s1.length, s2.length, s3.length <= 100
s1, s2 and s3 consist only of lowercase English letters.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
29.6K
Submissions
68K
Acceptance Rate
43.5%

*/

// get min length
// step from left to right to min length
// stop when the prefixes don't match
// store the index where you stopped
// tally the items needed to be deleted


impl Solution {
  pub fn find_minimum_operations(s1: String, s2: String, s3: String) -> i32 {
    let min_length = s1.len().min(s2.len()).min(s3.len());
    let mut i = 0;
    while i < min_length {
      if s1.chars().nth(i) != s2.chars().nth(i) || s1.chars().nth(i) != s3.chars().nth(i) {
        break;
      }
      i += 1;
    }
    if i == 0 {
      return -1;
    }
    (s1.len() - i) + (s2.len() - i) + (s3.len() - i) as i32
  }
}
