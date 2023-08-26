/*

646. Maximum Length of Pair Chain
Medium
3.4K
118
Companies
You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and
lefti < righti.

A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be
formed in this fashion.

Return the length longest chain which can be formed.

You do not need to use up all the given intervals. You can select pairs in any
order.



Example 1:

Input: pairs = [[1,2],[2,3],[3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4].
Example 2:

Input: pairs = [[1,2],[7,8],[4,5]]
Output: 3
Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].


Constraints:

n == pairs.length
1 <= n <= 1000
-1000 <= lefti < righti <= 1000
Accepted
157.2K
Submissions
272.8K
Acceptance Rate
57.6%

*/

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  vector<int> dp;

  int r(int idx, vector<vector<int>> &sorted, int &n) {
    if (idx >= n) return 0;

    if (dp[idx] != 0) return dp[idx];

    dp[idx] = 1;

    // take it or leave it
    vector<int> cur = sorted[idx];
    for (int j = idx + 1; j < n; ++j) {
      if (cur[1] < sorted[j][0]) {
        dp[idx] = max(dp[idx], 1+r(j,sorted,n));
      }
    }

    return dp[idx];
  }

 public:
  int findLongestChain(vector<vector<int>> &pairs) {
    vector<vector<int>> sorted = pairs;
    int n = sorted.size();
    dp.resize(n);
    sort(sorted.begin(), sorted.end());
    int res = 0;
    for (int i = 0; i < n; ++i) {
      res = max(res, r(i, sorted, n));
    }
    return res;
  }
};
// sort pairs
// dp + recursion