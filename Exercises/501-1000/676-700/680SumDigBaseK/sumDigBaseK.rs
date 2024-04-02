/*
1837. Sum of Digits in Base K
Easy
Topics
Companies
Hint
Given an integer n (in base 10) and a base k, return the sum of the digits of n after converting n from base 10 to base k.

After converting, each digit should be interpreted as a base 10 number, and the sum should be returned in base 10.



Example 1:

Input: n = 34, k = 6
Output: 9
Explanation: 34 (base 10) expressed in base 6 is 54. 5 + 4 = 9.
Example 2:

Input: n = 10, k = 10
Output: 1
Explanation: n is already in base 10. 1 + 0 = 1.


Constraints:

1 <= n <= 100
2 <= k <= 10
Seen this question in a real interview before?
1/4
Yes
No
Accepted
52K
Submissions
67.3K
Acceptance Rate
77.2%

*/

impl Solution {
  pub fn sum_base(n: i32, k: i32) -> i32 {
    // convert
    let mut res = 0;
    let digs: Vec<i32> = vec![];
    loop {
      let mut exponent = 0;
      for i in 0..10 {
        if k.pow(i) > n {
          exponent = i-1;
          break
        }
      }
      let curfact = k.pow(exponent);
      res+=n/curfact;
      n = n%curfact;
    }
    res
    // sum
  }
}

