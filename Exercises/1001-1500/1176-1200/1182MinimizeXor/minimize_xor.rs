/*

2429. Minimize XOR
Medium
Topics
Companies
Hint
Given two positive integers num1 and num2, find the positive integer x such that:

x has the same number of set bits as num2, and
The value x XOR num1 is minimal.
Note that XOR is the bitwise XOR operation.

Return the integer x. The test cases are generated such that x is uniquely determined.

The number of set bits of an integer is the number of 1's in its binary representation.



Example 1:

Input: num1 = 3, num2 = 5
Output: 3
Explanation:
The binary representations of num1 and num2 are 0011 and 0101, respectively.
The integer 3 has the same number of set bits as num2, and the value 3 XOR 3 = 0 is minimal.
Example 2:

Input: num1 = 1, num2 = 12
Output: 3
Explanation:
The binary representations of num1 and num2 are 0001 and 1100, respectively.
The integer 3 has the same number of set bits as num2, and the value 3 XOR 1 = 2 is minimal.


Constraints:

1 <= num1, num2 <= 109
Seen this question in a real interview before?
1/5
Yes
No
Accepted
33.8K
Submissions
68.4K
Acceptance Rate
49.5%

*/

impl Solution {
  pub fn minimize_xor(num1: i32, num2: i32) -> i32 {
    // worst case a billion ops
    let one_count: u32 = num2.count_ones();
    let mut min_total = i32::MAX;
    let mut res = -1;
    for i in 0..=num1 {
      if i.count_ones() != one_count {
        continue
      } else {
        let mut op_res = num1 ^ i;
        if min_total > op_res {
          res = i;
          min_total = op_res;
        }
      }
    }
    res
  }
}

/*
3, 5

011, 101
// set bits same as 101
so try 011, 101, 110, etc
// pattern to this?
1001, 1010, 1100
3, 5, 6, 8, 10, 12

0001
1100
*/
