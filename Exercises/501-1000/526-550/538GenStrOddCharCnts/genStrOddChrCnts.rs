/*

1374. Generate a String With Characters That Have Odd Counts
Easy
Topics
Companies
Hint
Given an integer n, return a string with n characters such that each character in such string occurs an odd number of times.

The returned string must contain only lowercase English letters. If there are multiples valid strings, return any of them.



Example 1:

Input: n = 4
Output: "pppz"
Explanation: "pppz" is a valid string since the character 'p' occurs three times and the character 'z' occurs once. Note that there are many other valid strings such as "ohhh" and "love".
Example 2:

Input: n = 2
Output: "xy"
Explanation: "xy" is a valid string since the characters 'x' and 'y' occur once. Note that there are many other valid strings such as "ag" and "ur".
Example 3:

Input: n = 7
Output: "holasss"


Constraints:

1 <= n <= 500
Seen this question in a real interview before?
1/4
Yes
No
Accepted
88.7K
Submissions
114.2K
Acceptance Rate
77.6%

*/

impl Solution {
  pub fn generate_the_string(n: i32) -> String {
    let mut cv:Vec<char> = Vec::new();
    let mut n_c = n;
    let mut cur_char = 'a';
    let mut cur_char_cnt = 0;
    while n_c > 0 {
      if (n_c == 1 && cur_char_cnt % 2 == 1) || (n_c == 2 && cur_char_cnt % 2 == 1){

          cur_char = (cur_char as u8 + 1) as char;
          cur_char_cnt = 0;
      }
      cv.push(cur_char);
      cur_char_cnt+=1;
      n_c -=1;
    }
    let res:String = cv.iter().collect();
    res
  }
}