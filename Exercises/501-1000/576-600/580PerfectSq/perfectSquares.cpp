/*

279. Perfect Squares
Solved
Medium
Topics
Companies
Given an integer n, return the least number of perfect square numbers that sum
to n.

A perfect square is an integer that is the square of an integer; in other words,
it is the product of some integer with itself. For example, 1, 4, 9, and 16 are
perfect squares while 3 and 11 are not.



Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.


Constraints:

1 <= n <= 104
Seen this question in a real interview before?
1/4
Yes
No
Accepted
756.2K
Submissions
1.4M
Acceptance Rate
53.7%

*/

#include <cmath>
#include <vector>

using namespace std;
class Solution {
  vector<int> dp;
  int r(int cur) {
    if (cur <= 0) return 0;
    if (dp[cur] >= 0) return dp[cur];
    int sr = sqrt(cur);
    int res = INT_MAX;
    for (int i = sr; i >= 1; --i) {
      int nsq = i * i;
      if (nsq == cur) {
        res = 1;
        break;
      }
      res = min(res, 1+r(cur-nsq));
    }

    return dp[cur] = res;
  }

 public:
  int numSquares(int n) {
    dp.resize(10001, -1);
    return r(n);
  }
};


/*
              1
         4              5
    9       13      5          14
  16  25  13   29 5
25
1 - 1
4 - 1
5 - 2
9 - 1
10 - 1
13 - 2
14 - 3
16 - 1
17 - 2
20 - 2
21 - 3
25 - 1 (16+9, 5+5+5+5+5), etc
problem: not counting dups
- 4 4 4 = 12
- 9 1 1 1 = 12
- for extreme case 10000
- 9999
- 99 * 99


maybe greedy?s
from sqrt to 0

55 ->
6 ->
2 ->
1


*/