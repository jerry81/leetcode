/*

1903. Largest Odd Number in String
Easy
1.3K
84
Companies
You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

A substring is a contiguous sequence of characters within a string.



Example 1:

Input: num = "52"
Output: "5"
Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
Example 2:

Input: num = "4206"
Output: ""
Explanation: There are no odd numbers in "4206".
Example 3:

Input: num = "35427"
Output: "35427"
Explanation: "35427" is already an odd number.


Constraints:

1 <= num.length <= 105
num only consists of digits and does not contain any leading zeros.
Accepted
109.2K
Submissions
183.6K
Acceptance Rate
59.5%

*/

impl Solution {
    pub fn largest_odd_number(num: String) -> String {
      let mut res = String::new();
      let mut fl = false;
      for c in num.chars().rev() {
        let cur = c.to_digit(10).unwrap();
        let is_odd = cur % 2 == 1;
        if !fl && is_odd { fl = true; }
        if fl { res.push(c) }
      }
      res.chars().rev().collect()
    }
}