/*

1420. Build Array Where You Can Find The Maximum Exactly K Comparisons
Hard
517
12
Companies
You are given three integers n, m and k. Consider the following algorithm to
find the maximum element of an array of positive integers:


You should build the array arr which has the following properties:

arr has exactly n integers.
1 <= arr[i] <= m where (0 <= i < n).
After applying the mentioned algorithm to arr, the value search_cost is equal to
k. Return the number of ways to build the array arr under the mentioned
conditions. As the answer may grow large, the answer must be computed modulo 109
+ 7.



Example 1:

Input: n = 2, m = 3, k = 1
Output: 6
Explanation: The possible arrays are [1, 1], [2, 1], [2, 2], [3, 1], [3, 2] [3,
3] Example 2:

Input: n = 5, m = 2, k = 3
Output: 0
Explanation: There are no possible arrays that satisify the mentioned
conditions. Example 3:

Input: n = 9, m = 1, k = 1
Output: 1
Explanation: The only possible array is [1, 1, 1, 1, 1, 1, 1, 1, 1]


Constraints:

1 <= n <= 50
1 <= m <= 100
0 <= k <= n
Accepted
12.3K
Submissions
19.7K
Acceptance Rate
62.4%

*/

#include <vector>
#include <cmath>

using namespace std;

class Solution {
  int MOD = pow(10,9) + 7;
  vector<vector<vector<long long int>>> memo;
  long long int r(int idx, int cmax, int rem, int &sz, int &mx) {
    if (sz < idx) return 0;

    if (idx == sz) return rem == 0 ? 1 : 0;

    if (rem < 0) return 0;

    if (rem > 0 && mx < cmax) return 0;

    if (memo[idx][cmax][rem] >= 0) return memo[idx][cmax][rem];

    long long int choices = cmax * r(idx + 1, cmax, rem, sz, mx);

    choices %= MOD;

    long long int incrChoices = 0;

    for (int i = cmax+1; i <= mx; ++i) {
      incrChoices += r(idx+1, i, rem-1, sz, mx);
      incrChoices %= MOD;
    }

    memo[idx][cmax][rem] = incrChoices+choices % MOD;

    // for a range
    // idx -

    return memo[idx][cmax][rem];
  }

 public:
  int numOfArrays(int n, int m, int k) {  // size, max, tgtcost
    // cost increases when item > curmax
    memo.resize(n, vector<vector<long long int>>(m + 1, vector<long long int>(k + 1, -1)));

    if (k > m) return 0;

    return r(0, 0, k, n, m);
  }
};