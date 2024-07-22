/*

2566. Maximum Difference by Remapping a Digit
Easy
Topics
Companies
Hint
You are given an integer num. You know that Bob will sneakily remap one of the 10 possible digits (0 to 9) to another digit.

Return the difference between the maximum and minimum values Bob can make by remapping exactly one digit in num.

Notes:

When Bob remaps a digit d1 to another digit d2, Bob replaces all occurrences of d1 in num with d2.
Bob can remap a digit to itself, in which case num does not change.
Bob can remap different digits for obtaining minimum and maximum values respectively.
The resulting number after remapping can contain leading zeroes.


Example 1:

Input: num = 11891
Output: 99009
Explanation:
To achieve the maximum value, Bob can remap the digit 1 to the digit 9 to yield 99899.
To achieve the minimum value, Bob can remap the digit 1 to the digit 0, yielding 890.
The difference between these two numbers is 99009.
Example 2:

Input: num = 90
Output: 99
Explanation:
The maximum value that can be returned by the function is 99 (if 0 is replaced by 9) and the minimum value that can be returned by the function is 0 (if 9 is replaced by 0).
Thus, we return 99.


Constraints:

1 <= num <= 108
Seen this question in a real interview before?
1/5
Yes
No
Accepted
25.1K
Submissions
42K
Acceptance Rate
59.9%

*/

impl Solution {
  pub fn min_max_difference(num: i32) -> i32 {
    // logic: remap most significant digit
    // edge case:  most sig is already 0 or 9
    let as_str = num.to_string();
    let sz = as_str.len();
    let mut most_sig_mx = '9';
    for cur in as_str.chars() {;
      if cur != '9' {
        most_sig_mx = cur;
        break
      }
    }
    let mut most_sig_mn = '0';
    for cur in as_str.chars() {;
      if cur != '0' {
        most_sig_mn = cur;
        break
      }
    }
    let mut mxStr: String = as_str.clone().chars().map( |c| {
      if c==most_sig_mx {
        '9'
      } else {
        c
      }
    }).collect();
    let mut mnStr: String = as_str.clone().chars().map( |c| {
      if c==most_sig_mn {
        '0'
      } else {
        c
      }
    }).collect();
    mxStr.parse::<i32>().unwrap() - mnStr.parse::<i32>().unwrap()
  }
}