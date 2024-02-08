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

using namespace std;
class Solution {

 public:
  int numSquares(int n) {
    int sr = sqrt(n);
    int nsq = sr*sr;
    if (nsq == n) return 1;

    return numSquares(n-nsq);
  }
};

/*
          1
   4              5
9     13     5        14

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

maybe greedy?s
from sqrt to 0

55 ->
6 ->
2 ->
1


*/