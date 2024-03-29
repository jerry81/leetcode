/*

121. Best Time to Buy and Sell Stock
Easy
25.3K
796
Companies
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.



Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.


Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104
Accepted
3.3M
Submissions
6.1M
Acceptance Rate
54.3%

*/

#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      // keep vector of min/max
      // start new pair each time there is "drop"
      int curmin = INT_MAX;
      int curmax = 0;
      int maxDiff = 0;
      for (int price: prices) {
        if (curmax < price) curmax = price;

        if (curmin > price) {
          curmin = price;
          curmax = price;
        }

        maxDiff = std::max(maxDiff, (curmax-curmin));
      }
      return maxDiff;
    }
};

/*

[7,1,5,3,6,4]

n,x,d:  7,7,0  1,1,0, 1,4, 3, 1,4
*/