/*


2652. Sum Multiples
Easy
Topics
Companies
Hint
Given a positive integer n, find the sum of all integers in the range [1, n] inclusive that are divisible by 3, 5, or 7.

Return an integer denoting the sum of all numbers in the given range satisfying the constraint.



Example 1:

Input: n = 7
Output: 21
Explanation: Numbers in the range [1, 7] that are divisible by 3, 5, or 7 are 3, 5, 6, 7. The sum of these numbers is 21.
Example 2:

Input: n = 10
Output: 40
Explanation: Numbers in the range [1, 10] that are divisible by 3, 5, or 7 are 3, 5, 6, 7, 9, 10. The sum of these numbers is 40.
Example 3:

Input: n = 9
Output: 30
Explanation: Numbers in the range [1, 9] that are divisible by 3, 5, or 7 are 3, 5, 6, 7, 9. The sum of these numbers is 30.


Constraints:

1 <= n <= 103
Seen this question in a real interview before?
1/5
Yes
No
Accepted
110.6K
Submissions
129.2K
Acceptance Rate
85.6%

*/
impl Solution {
  pub fn sum_of_multiples(n: i32) -> i32 {
      let mut res = 0;
      for i in 3..=n {
          if i % 3 == 0 {
              res+= i as i32;
              continue
          }
          if i % 5 == 0 {
              res+= i as i32;
              continue
          }
          if i % 7 == 0 {
              res+= i as i32;
              continue
          }
      }
      res
  }
}