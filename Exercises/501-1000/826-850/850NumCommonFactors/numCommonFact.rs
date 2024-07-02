/*


2427. Number of Common Factors
Easy
Topics
Companies
Hint
Given two positive integers a and b, return the number of common factors of a and b.

An integer x is a common factor of a and b if x divides both a and b.



Example 1:

Input: a = 12, b = 6
Output: 4
Explanation: The common factors of 12 and 6 are 1, 2, 3, 6.
Example 2:

Input: a = 25, b = 30
Output: 2
Explanation: The common factors of 25 and 30 are 1, 5.


Constraints:

1 <= a, b <= 1000
Seen this question in a real interview before?
1/5
Yes
No
Accepted
86.7K
Submissions
109.8K
Acceptance Rate
79.0%

*/

impl Solution {
  pub fn common_factors(a: i32, b: i32) -> i32 {
    let mn = a.min(b);
    let mut res = 0;
    for i in 1..=mn {
      if a % i == 0 && b % i == 0 { res+=1; }
    }
    res
  }
}