/*

3110. Score of a String
Easy
Topics
Companies
Hint
You are given a string s. The score of a string is defined as the sum of the absolute difference between the ASCII values of adjacent characters.

Return the score of s.



Example 1:

Input: s = "hello"

Output: 13

Explanation:

The ASCII values of the characters in s are: 'h' = 104, 'e' = 101, 'l' = 108, 'o' = 111. So, the score of s would be |104 - 101| + |101 - 108| + |108 - 108| + |108 - 111| = 3 + 7 + 0 + 3 = 13.

Example 2:

Input: s = "zaz"

Output: 50

Explanation:

The ASCII values of the characters in s are: 'z' = 122, 'a' = 97. So, the score of s would be |122 - 97| + |97 - 122| = 25 + 25 = 50.



Constraints:

2 <= s.length <= 100
s consists only of lowercase English letters.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
65.2K
Submissions
70.5K
Acceptance Rate
92.4%

*/

impl Solution {
  pub fn score_of_string(s: String) -> i32 {
    let mut r = 0;
    let sz = s.len();
    for i in 0..sz-1 {
     let cur = s.chars().nth(i).unwrap() as i32;
     let nxt = s.chars().nth(i+1).unwrap() as i32; // yes this is ok
     let diff = (cur-nxt).abs();
     r+=diff;
    }
    r
  }
}