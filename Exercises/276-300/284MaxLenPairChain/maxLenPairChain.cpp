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

#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
  unordered_map<string, int> dp;
  string toHash(int idx, int last) {
    return to_string(idx) + "," + to_string(last);
  }
  static bool ccompare(vector<int> a, vector<int> b) { return a[0] < b[0]; }

  int r(int idx, vector<vector<int>> &sorted, int last, int &n) {

    if (idx >= n) return 0;

    string hsh = toHash(idx, last);

    if (dp.find(hsh) != dp.end()) return dp[hsh];

    // take it or leave it
    vector<int> cur = sorted[idx];
    if (cur[0] <= last) {
      dp[hsh] = r(idx + 1, sorted, last, n);
    } else {
      dp[hsh] = max(r(idx + 1, sorted, last,n), 1 + r(idx + 1, sorted, cur[1],n));
    }
    return dp[hsh];
  }

 public:
  int findLongestChain(vector<vector<int>>& pairs) {
    vector<vector<int>> sorted = pairs;
    int n = sorted.size();
    sort(sorted.begin(), sorted.end(), ccompare);
    return r(0, sorted, -1001, n);
  }
};
// sort pairs
// dp + recursion