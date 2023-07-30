/*

808. Soup Servings
Medium
405
1.2K
Companies
There are two types of soup: type A and type B. Initially, we have n ml of each type of soup. There are four kinds of operations:

Serve 100 ml of soup A and 0 ml of soup B,
Serve 75 ml of soup A and 25 ml of soup B,
Serve 50 ml of soup A and 50 ml of soup B, and
Serve 25 ml of soup A and 75 ml of soup B.
When we serve some soup, we give it to someone, and we no longer have it. Each turn, we will choose from the four operations with an equal probability 0.25. If the remaining volume of soup is not enough to complete the operation, we will serve as much as possible. We stop once we no longer have some quantity of both types of soup.

Note that we do not have an operation where all 100 ml's of soup B are used first.

Return the probability that soup A will be empty first, plus half the probability that A and B become empty at the same time. Answers within 10-5 of the actual answer will be accepted.



Example 1:

Input: n = 50
Output: 0.62500
Explanation: If we choose the first two operations, A will become empty first.
For the third operation, A and B will become empty at the same time.
For the fourth operation, B will become empty first.
So the total probability of A becoming empty first plus half the probability that A and B become empty at the same time, is 0.25 * (1 + 1 + 0.5 + 0) = 0.625.
Example 2:

Input: n = 100
Output: 0.71875


Constraints:

0 <= n <= 109
Accepted
23.7K
Submissions
50.7K
Acceptance Rate
46.7%

*/
#include <cmath>
#include <vector>

using namespace std;

class Solution {
vector<vector<double>> dp;
double r(int left, int right) {
  if (dp[left][right] >= 0) return dp[left][right];

  if (left <= 0 && right >= 0) {
    dp[left][right] = 1.0;
    return 1.0;
  }
  if (left <= 0 && right <= 0) {
    dp[left][right] = .5;
    return .5;
  }
  if (left >= 0 && right <= 0) {
    dp[left][right] = 0.0;
    return 0.0;
  }
  dp[left][right] = (r(left-4, right - 0) + r(left-3, right-1) + r(left-2, right-2), r(left-1, right-3)) / 4.0;
  return dp[left][right];
}
public:
    double soupServings(int n) {
      int totalServings = ceil(n / 25);
      dp.resize(totalServings, vector<double>(totalServings, -1.0));
      return r(totalServings, totalServings);
    }
};

/*

ref:
100 0
75 25
50 50
25 75
work out

n = 100
expect 0.71875
AA
AB
AC
AD
BA
BB
BC
BD .5
CA
CB
CC .5
CD 0
DA
DB .5
DC 0
DD 0

but number of turns is not always even

n = 51
expect - 0.65625
2 rolls needed
AX
BX
CA - 0
CB - 0
CC - .5
CD - 1
DX - 4

*/