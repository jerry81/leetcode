/*

1269. Number of Ways to Stay in the Same Place After Some Steps
Hard
772
42
Companies
You have a pointer at index 0 in an array of size arrLen. At each step, you can
move 1 position to the left, 1 position to the right in the array, or stay in
the same place (The pointer should not be placed outside the array at any time).

Given two integers steps and arrLen, return the number of ways such that your
pointer is still at index 0 after exactly steps steps. Since the answer may be
too large, return it modulo 109 + 7.



Example 1:

Input: steps = 3, arrLen = 2
Output: 4
Explanation: There are 4 differents ways to stay at index 0 after 3 steps.
Right, Left, Stay
Stay, Right, Left
Right, Stay, Left
Stay, Stay, Stay
Example 2:

Input: steps = 2, arrLen = 4
Output: 2
Explanation: There are 2 differents ways to stay at index 0 after 2 steps
Right, Left
Stay, Stay
Example 3:

Input: steps = 4, arrLen = 2
Output: 8


Constraints:

1 <= steps <= 500
1 <= arrLen <= 106
Accepted
35.9K
Submissions
81.6K
Acceptance Rate
44.0%

*/

#include <cmath>
#include <vector>

using namespace std;

class Solution {
  const int MOD = pow(10, 9) + 7;
  vector<vector<int>> memo;
  int r(int steps, int idx, int &l) {
    if (idx < 0) return 0;

    if (idx >= l) return 0;

    if (steps < 0) return 0;

    if (memo[steps][idx] >= 0) return memo[steps][idx];

    if (idx == 0) {
      if (steps > 0) return 0;

      return 1;
    }

    memo[steps][idx] =
        (r(steps - 1, idx, l) % MOD + r(steps - 1, idx - 1, l) % MOD +
         r(steps - 1, idx + 1, l) % MOD) %
        MOD;
    return memo[steps][idx];
  }

 public:
  int numWays(int steps, int arrLen) {
    // recursion
    memo.resize(steps, vector<int>(arrLen, -1));
    return r(steps, 0, arrLen);
  }
};