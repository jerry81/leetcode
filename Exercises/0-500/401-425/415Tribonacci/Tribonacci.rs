/*

1137. N-th Tribonacci Number
Easy
3.9K
172
Companies
The Tribonacci sequence Tn is defined as follows:

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.



Example 1:

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
Example 2:

Input: n = 25
Output: 1389537


Constraints:

0 <= n <= 37
The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.
Accepted
562.5K
Submissions
886K
Acceptance Rate
63.5%

*/

use std::collections::HashMap;

impl Solution {
  pub fn tribonacci(n: i32) -> i32 {
    let mut hm:HashMap<i32,i32> = HashMap::new();

    Solution::r(n,&mut hm)
  }

  fn r(n: i32, hm: &mut HashMap<i32,i32>) -> i32 {

    if n == 0 { return 0; }
    if n == 1 { return 1; }
    if n == 2 { return 1; }

    if let Some(&item) = hm.get(&n) {
      return item;
    }
    let res = Solution::r(n-3, hm) + Solution::r(n-2,hm) + Solution::r(n-1,hm);
    hm.insert(n, res);
    res
  }
}