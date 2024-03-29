/*

1281. Subtract the Product and Sum of Digits of an Integer
Easy
Topics
Companies
Hint
Given an integer number n, return the difference between the product of its digits and the sum of its digits.


Example 1:

Input: n = 234
Output: 15
Explanation:
Product of digits = 2 * 3 * 4 = 24
Sum of digits = 2 + 3 + 4 = 9
Result = 24 - 9 = 15
Example 2:

Input: n = 4421
Output: 21
Explanation:
Product of digits = 4 * 4 * 2 * 1 = 32
Sum of digits = 4 + 4 + 2 + 1 = 11
Result = 32 - 11 = 21


Constraints:

1 <= n <= 10^5
Seen this question in a real interview before?
1/4
Yes
No
Accepted
454.8K
Submissions
526.6K
Acceptance Rate
86.4%

*/

impl Solution {
  pub fn subtract_product_and_sum(n: i32) -> i32 {
    let str = n.to_string();
    let mut prod = 1;
    for c in str.chars() {
      prod*=c.to_digit(10).unwrap_or(0) as i32;;
    }
    let mut sm = 0;
    for c in str.chars() {
      let item = c.to_digit(10).unwrap_or(0) as i32;
      sm+=item;
    }
    prod-sm
  }
}