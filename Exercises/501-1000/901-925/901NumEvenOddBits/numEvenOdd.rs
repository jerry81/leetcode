/*
2595. Number of Even and Odd Bits
Easy
Topics
Companies
Hint
You are given a positive integer n.

Let even denote the number of even indices in the binary representation of n with value 1.

Let odd denote the number of odd indices in the binary representation of n with value 1.

Note that bits are indexed from right to left in the binary representation of a number.

Return the array [even, odd].



Example 1:

Input: n = 50

Output: [1,2]

Explanation:

The binary representation of 50 is 110010.

It contains 1 on indices 1, 4, and 5.

Example 2:

Input: n = 2

Output: [0,1]

Explanation:

The binary representation of 2 is 10.

It contains 1 only on index 1.



Constraints:

1 <= n <= 1000
Seen this question in a real interview before?
1/5
Yes
No
Accepted
46.5K
Submissions
63.4K
Acceptance Rate
73.4%
*/

impl Solution {
  pub fn even_odd_bit(n: i32) -> Vec<i32> {
    let binary_string = format!("{:b}", number);

    let mut even = 0;
    let mut odd = 0;
    let mut e = true;
    for c in binary_string.chars() {
      if c == '1' {
        if e { even +=1 } else { odd += 1; }
      }
    }
    vec![even,odd];
  }
}