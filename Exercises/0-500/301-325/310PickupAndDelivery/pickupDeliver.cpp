/*
1359. Count All Valid Pickup and Delivery Options
Hard
1.9K
158
Companies
Given n orders, each order consist in pickup and delivery services.

Count all valid pickup/delivery possible sequences such that delivery(i) is
always after of pickup(i).

Since the answer may be too large, return it modulo 10^9 + 7.



Example 1:

Input: n = 1
Output: 1
Explanation: Unique order (P1, D1), Delivery 1 always is after of Pickup 1.
Example 2:

Input: n = 2
Output: 6
Explanation: All possible orders:
(P1,P2,D1,D2), (P1,P2,D2,D1), (P1,D1,P2,D2), (P2,P1,D1,D2), (P2,P1,D2,D1) and
(P2,D2,P1,D1). This is an invalid order (P1,D2,P2,D1) because Pickup 2 is after
of Delivery 2. Example 3:

Input: n = 3
Output: 90


Constraints:

1 <= n <= 500
Accepted
65.1K
Submissions
103.1K
Acceptance Rate
63.1%
*/
#include <cmath>
using namespace std;
class Solution {
 public:
  int countOrders(int n) {
    int MOD = pow(10, 9) + 7;
    long long fact = 1;
    for (int i = 2; i <= 2 * n; ++i) {
      fact *= i;
      if (i % 2 == 0) fact /= 2;
      fact %= MOD;
    }

    return fact;
  }
};

/*

pool - P1,p2,p3,d1,d2,d3
first spot , available p1,p2,p3
p1-> then d1 becomes option, pool p2p3d1d2d3
second spot available p2,p3,d1

*/