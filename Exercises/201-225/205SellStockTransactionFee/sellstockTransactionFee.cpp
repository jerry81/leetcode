/*

714. Best Time to Buy and Sell Stock with Transaction Fee
Medium
5.6K
143
Companies
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Example 2:

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6


Constraints:

1 <= prices.length <= 5 * 104
1 <= prices[i] < 5 * 104
0 <= fee < 5 * 104
Accepted
242.4K
Submissions
367.5K
Acceptance Rate
66.0%

*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
vector<unordered_map<int,int>> dp;
int r(vector<int>& p, int fee, int idx, int held) {
  if (dp[idx].find(held) != dp[idx].end()) return dp[idx][held];
  if (idx >= p.size()-1) {
    if (held == 0) {
      dp[idx][0] = 0;
      return 0;
    }
    dp[idx][held] = p[idx]-held-fee;
    return dp[idx][held];
  }
}
public:
    int maxProfit(vector<int>& prices, int fee) {
      dp.resize(prices.size(), unordered_map<int,int>());
      return r(prices, fee, 0, 0);
    }
};

/*

analyze example
Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8

size = 6
dp = { 0: {}, 1: {}, 2: {}, 3:{}, 4:{}, 5:{} }
dp(0,0) = max(dp(1,prices[0]), dp(1,0))
dp(1,prices[0]) = max(profit+dp(2,0), dp(2,prices[0]))
dp(1,0) = max(dp(2,0), dp()
..
dp(5,x) = x<= 0 -> 0;  x>= 0 -> (prices[5] - x) - fee

transaction is buy and sell combination

dp with params: idx, held

held -1 is nothing held

next dp has choices
if -1 (buy or dont buy)
if >= 1 (sell or dont sell)
*/