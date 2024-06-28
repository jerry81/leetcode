/*

2413. Smallest Even Multiple
Easy
Topics
Companies
Hint
Given a positive integer n, return the smallest positive integer that is a multiple of both 2 and n.


Example 1:

Input: n = 5
Output: 10
Explanation: The smallest multiple of both 5 and 2 is 10.
Example 2:

Input: n = 6
Output: 6
Explanation: The smallest multiple of both 6 and 2 is 6. Note that a number is a multiple of itself.


Constraints:

1 <= n <= 150
Seen this question in a real interview before?
1/5
Yes
No
Accepted
171.3K
Submissions
195.2K
Acceptance Rate
87.7%

*/

impl Solution {
  pub fn smallest_even_multiple(n: i32) -> i32 {
      if n % 2 == 0 { return n }

      n*2
  }
}