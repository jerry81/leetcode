/*

2483. Minimum Penalty for a Shop
Medium
408
15
Companies
You are given the customer visit log of a shop represented by a 0-indexed string customers consisting only of characters 'N' and 'Y':

if the ith character is 'Y', it means that customers come at the ith hour
whereas 'N' indicates that no customers come at the ith hour.
If the shop closes at the jth hour (0 <= j <= n), the penalty is calculated as follows:

For every hour when the shop is open and no customers come, the penalty increases by 1.
For every hour when the shop is closed and customers come, the penalty increases by 1.
Return the earliest hour at which the shop must be closed to incur a minimum penalty.

Note that if a shop closes at the jth hour, it means the shop is closed at the hour j.



Example 1:

Input: customers = "YYNY"
Output: 2
Explanation:
- Closing the shop at the 0th hour incurs in 1+1+0+1 = 3 penalty.
- Closing the shop at the 1st hour incurs in 0+1+0+1 = 2 penalty.
- Closing the shop at the 2nd hour incurs in 0+0+0+1 = 1 penalty.
- Closing the shop at the 3rd hour incurs in 0+0+1+1 = 2 penalty.
- Closing the shop at the 4th hour incurs in 0+0+1+0 = 1 penalty.
Closing the shop at 2nd or 4th hour gives a minimum penalty. Since 2 is earlier, the optimal closing time is 2.
Example 2:

Input: customers = "NNNNN"
Output: 0
Explanation: It is best to close the shop at the 0th hour as no customers arrive.
Example 3:

Input: customers = "YYYY"
Output: 4
Explanation: It is best to close the shop at the 4th hour as customers arrive at each hour.


Constraints:

1 <= customers.length <= 105
customers consists only of characters 'Y' and 'N'.
Accepted
20.1K
Submissions
33.3K
Acceptance Rate
60.4%

*/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
      int n = customers.size();
      // prefix sum of Y
      vector<int> yes;
      int accum = 0;
      for (char c: customers) {
        if (c == 'Y') accum++;

        yes.push_back(accum);
      }

      int beginV = yes[n-1];
      int endV = n - yes[n-1];
      int minV;
      int minI;
      if (beginV <= endV) {
        minI = 0;
        minV = beginV;
      } else {
        minI = n;
        minV = endV;
      }

      // handle edges
      // close at 0 - y count
      // total no count
      for (int i = 1; i < n; ++i) {

        int penaltyBefore = i - yes[i-1]; // N count to i
        int penaltyAfter = yes[n-1] - yes[i]; // Y count after i

        int cur = penaltyBefore + penaltyAfter;
        if (customers[i] == 'Y') cur++;

        if (minV > cur || (minV >= cur && minI > i)) {
          minV = cur;
          minI = i;
        }
      }
      return minI;
    }
};