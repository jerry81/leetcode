/*

2710. Remove Trailing Zeros From a String
Easy
Topics
Companies
Hint
Given a positive integer num represented as a string, return the integer num without trailing zeros as a string.



Example 1:

Input: num = "51230100"
Output: "512301"
Explanation: Integer "51230100" has 2 trailing zeros, we remove them and return integer "512301".
Example 2:

Input: num = "123"
Output: "123"
Explanation: Integer "123" has no trailing zeros, we return integer "123".


Constraints:

1 <= num.length <= 1000
num consists of only digits.
num doesn't have any leading zeros.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
66.8K
Submissions
84.7K
Acceptance Rate
78.9%

*/

impl Solution {
  pub fn remove_trailing_zeros(num: String) -> String {

    let mut idx = num.len()-1;

    while idx >= 0 {
      if num.chars().nth(idx).unwrap() != '0' {
        break
      }
      idx-=1;
    }
    num[..=idx].to_string()
  }
}