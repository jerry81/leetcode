/*

1486. XOR Operation in an Array
Easy
Topics
Companies
Hint
You are given an integer n and an integer start.

Define an array nums where nums[i] = start + 2 * i (0-indexed) and n == nums.length.

Return the bitwise XOR of all elements of nums.



Example 1:

Input: n = 5, start = 0
Output: 8
Explanation: Array nums is equal to [0, 2, 4, 6, 8] where (0 ^ 2 ^ 4 ^ 6 ^ 8) = 8.
Where "^" corresponds to bitwise XOR operator.
Example 2:

Input: n = 4, start = 3
Output: 8
Explanation: Array nums is equal to [3, 5, 7, 9] where (3 ^ 5 ^ 7 ^ 9) = 8.


Constraints:

1 <= n <= 1000
0 <= start <= 1000
n == nums.length
Seen this question in a real interview before?
1/4
Yes
No
Accepted
181.2K
Submissions
212K
Acceptance Rate
85.5%

*/

impl Solution {
  pub fn xor_operation(n: i32, start: i32) -> i32 {
    let mut cur = start;
    let mut res = start;
    for i in 1..n {
      cur+=2;
      res^=cur;
    }
    res
  }
}