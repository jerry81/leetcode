/*

441. Arranging Coins
Easy
3.4K
1.2K
Companies
You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.

Given the integer n, return the number of complete rows of the staircase you will build.



Example 1:


Input: n = 5
Output: 2
Explanation: Because the 3rd row is incomplete, we return 2.
Example 2:


Input: n = 8
Output: 3
Explanation: Because the 4th row is incomplete, we return 3.


Constraints:

1 <= n <= 231 - 1
Accepted
363.9K
Submissions
786.4K
Acceptance Rate
46.3%

*/

#include <cmath>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
      long long x = (-1 + sqrt(1 + 8*(long long)n)) / 2;
      long long x2 = (-1 - sqrt(1 + 8*(long long)n)) / 2;
      return max(x,x2);
    }
};

// so each row is has
// i coins where i is increasing from 1 to x
// sum series
// (x * (x + 1)) / 2 = n
// 2n = x^2+x
// 8 expect 3
// 1 + 2 + 3 = 6
// 8 = (x * x+1) / 2
// 16 = (x^2 + x)
// quadratic formula
// or binary search guesses at x