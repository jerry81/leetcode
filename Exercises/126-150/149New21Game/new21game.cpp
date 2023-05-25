/*

837. New 21 Game
Medium
1.3K
880
Companies
Alice plays the following game, loosely based on the card game "21".

Alice starts with 0 points and draws numbers while she has less than k points. During each draw, she gains an integer number of points randomly from the range [1, maxPts], where maxPts is an integer. Each draw is independent and the outcomes have equal probabilities.

Alice stops drawing numbers when she gets k or more points.

Return the probability that Alice has n or fewer points.

Answers within 10-5 of the actual answer are considered accepted.



Example 1:

Input: n = 10, k = 1, maxPts = 10
Output: 1.00000
Explanation: Alice gets a single card, then stops.
Example 2:

Input: n = 6, k = 1, maxPts = 10
Output: 0.60000
Explanation: Alice gets a single card, then stops.
In 6 out of 10 possibilities, she is at or below 6 points.
Example 3:

Input: n = 21, k = 17, maxPts = 10
Output: 0.73278


Constraints:

0 <= k <= n <= 104
1 <= maxPts <= 104
Accepted
40.1K
Submissions
105.3K
Acceptance Rate
38.1%

*/
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
vector<double> dp;
public:
    double new21Game(int n, int k, int maxPts) {
      dp[0] = 1;
      double prob = (double)(1.0/(double)maxPts);
      double ret = 0.0;
      double sum = 0.0;
      for (int i = 1; i <= n; ++i) {
        // add head, subtract tail
        int head = i-1;
        int tail = i-maxPts;
        if (tail >= 0) {
          sum-=dp[tail];
        }
        sum+= dp[head];
        dp[i] = sum*prob;
      }
      return dp[n];
    }
};

/*

naive

- brute force train a probability

- tried it, TLE.

- need a mathematical approximation O(1) solution

- official solution is DP
- probability to draw one card out of max is p
- dp[x] represents probability to get to x points
- base case dp[0] is 1 - no draws always gets 0
- look for recurrence
- dp[1] = p
- dp[2] = p(dp[1]) + p
- dp[max] = p(dp[1]) + p(dp[2]) ... p(dp[max-1])
- simplify
- dp[max] = p(dp[1] + ..... dp[max-1]);

- then work out
- k = 2, n = 2, maxPoints = 10

dp[0] = 1
dp[1] = dp[0]/10
dp[1] = 1/10
dp[2] = dp[1]/10 + dp[0]/10
dp[2] = 1/10 + (1/10)(1/10) = 11/100 <-- checks out
dp[3] = (dp[2] + dp[1] + dp[0]) / 10 = (1+ 1/10 + 11/100) / 10 = (121/1000) checks out
dp[4] = (dp[3] + dp[2] + dp[1]+dp[0]) / 10
*/

