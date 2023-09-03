/*

746. Min Cost Climbing Stairs
Easy
10.1K
1.6K
Companies
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.



Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.


Constraints:

2 <= cost.length <= 1000
0 <= cost[i] <= 999
Accepted
903K
Submissions
1.4M
Acceptance Rate
64.0%

*/

#include <vector>

using namespace std;

class Solution {
  vector<int> dp;
  int r(int idx, vector<int>& cost, int &n) {
    if (idx >= n) return 0;

    if (idx >= 0 && dp[idx] > -1) return dp[idx];
    int curCost = idx > -1 ? cost[idx] : 0;
    if (idx < 0) return min(r(idx+1, cost, n), r(idx+2, cost, n));
    dp[idx] = curCost + min(r(idx+1, cost, n), r(idx+2, cost, n));
    return dp[idx];
  }
public:
    int minCostClimbingStairs(vector<int>& cost) {
      int n = cost.size();
      dp.resize(n, -1);
      dp[n-1] = cost[n-1];
      dp[n-2] = cost[n-2];
      return r(-1, cost, n);
    }
};