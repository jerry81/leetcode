/*

343. Integer Break
Medium
4K
380
Companies
Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.



Example 1:

Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
Example 2:

Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.


Constraints:

2 <= n <= 58
Accepted
252.1K
Submissions
441.8K
Acceptance Rate
57.1%

*/

class Solution {
int r(int n) {
  if (n == 2) return 2;

  if (n == 3) return 3;

  int minus3 = n-3;

  if (minus3 > 1) return 3 * r(minus3);

  int minus2 = n-2;

  return 2*r(minus2);
}
public:
    int integerBreak(int n) {
      if (n == 2) return 1;

      if (n == 3) return 2;

      return r(n);
    }
};

/*

10 -> 2 2 2 2 2 -> 3 3 2 2

*/