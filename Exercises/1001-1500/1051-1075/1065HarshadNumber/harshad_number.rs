/*

3099. Harshad Number
Easy
Topics
Companies
Hint
An integer divisible by the sum of its digits is said to be a Harshad number. You are given an integer x. Return the sum of the digits of x if x is a Harshad number, otherwise, return -1.



Example 1:

Input: x = 18

Output: 9

Explanation:

The sum of digits of x is 9. 18 is divisible by 9. So 18 is a Harshad number and the answer is 9.

Example 2:

Input: x = 23

Output: -1

Explanation:

The sum of digits of x is 5. 23 is not divisible by 5. So 23 is not a Harshad number and the answer is -1.



Constraints:

1 <= x <= 100

Seen this question in a real interview before?
1/5
Yes
No
Accepted
62.8K
Submissions
75.7K
Acceptance Rate
83.0%

*/

impl Solution {
  pub fn sum_of_the_digits_of_harshad_number(x: i32) -> i32 {
    let sm_of_digits:i32 = x.to_string().chars().map(|c| {
      c as u8 - '0' as u8
    }).sum::<u8>() as i32;
    if x % sm_of_digits == 0 {
        sm_of_digits
    } else {
        -1
    }
  }
}

