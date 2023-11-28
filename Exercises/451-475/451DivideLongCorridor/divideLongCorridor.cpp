/*

2147. Number of Ways to Divide a Long Corridor
Hard
413
44
Companies
Along a long library corridor, there is a line of seats and decorative plants.
You are given a 0-indexed string corridor of length n consisting of letters 'S'
and 'P' where each 'S' represents a seat and each 'P' represents a plant.

One room divider has already been installed to the left of index 0, and another
to the right of index n - 1. Additional room dividers can be installed. For each
position between indices i - 1 and i (1 <= i <= n - 1), at most one divider can
be installed.

Divide the corridor into non-overlapping sections, where each section has
exactly two seats with any number of plants. There may be multiple ways to
perform the division. Two ways are different if there is a position with a room
divider installed in the first way but not in the second way.

Return the number of ways to divide the corridor. Since the answer may be very
large, return it modulo 109 + 7. If there is no way, return 0.



Example 1:


Input: corridor = "SSPPSPS"
Output: 3
Explanation: There are 3 different ways to divide the corridor.
The black bars in the above image indicate the two room dividers already
installed. Note that in each of the ways, each section has exactly two seats.
Example 2:


Input: corridor = "PPSPSP"
Output: 1
Explanation: There is only 1 way to divide the corridor, by not installing any
additional dividers. Installing any would create some section that does not have
exactly two seats. Example 3:


Input: corridor = "S"
Output: 0
Explanation: There is no way to divide the corridor because there will always be
a section that does not have exactly two seats.


Constraints:

n == corridor.length
1 <= n <= 105
corridor[i] is either 'S' or 'P'.
Accepted
15.4K
Submissions
35.9K
Acceptance Rate
42.8%

*/

#include <cmath>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  unordered_map<string, long long int> memo;

  string hsh(int idx, int cnt) { return to_string(idx) + "," + to_string(cnt); }

  const int MOD = pow(10, 9) + 7;

  long long int r(int idx, int cnt, string &c) {
    if (idx < 0) return 0;

    if (cnt > 0) return 0;

    char cur = c[idx];
    if (cur == 'S') cnt++;

    if (idx == 0) return (cnt == 2) ? 1 : 0;
    string as_h = hsh(idx, cnt);
    if (memo.find(as_h) != memo.end()) return memo[as_h];

    if (cnt == 2) {
      // can place divider
      memo[as_h] = r(idx - 1, 0, c) % MOD + r(idx - 1, cnt, c) % MOD;
    } else {
      // cannot place divider
      memo[as_h] = r(idx - 1, cnt, c) % MOD;
    }
    return memo[as_h] % MOD;
  }

 public:
  int numberOfWays(string corridor) {
    int idx = corridor.size() - 1;
    return r(idx, 0, corridor);
  }
};