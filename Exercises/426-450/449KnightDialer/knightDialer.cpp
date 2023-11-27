/*
935. Knight Dialer
Medium
2.2K
396
Companies
The chess knight has a unique movement, it may move two squares vertically and
one square horizontally, or two squares horizontally and one square vertically
(with both forming the shape of an L). The possible movements of chess knight
are shown in this diagaram:

A chess knight can move as indicated in the chess diagram below:


We have a chess knight and a phone pad as shown below, the knight can only stand
on a numeric cell (i.e. blue cell).


Given an integer n, return how many distinct phone numbers of length n we can
dial.

You are allowed to place the knight on any numeric cell initially and then you
should perform n - 1 jumps to dial a number of length n. All jumps should be
valid knight jumps.

As the answer may be very large, return the answer modulo 109 + 7.



Example 1:

Input: n = 1
Output: 10
Explanation: We need to dial a number of length 1, so placing the knight over
any numeric cell of the 10 cells is sufficient. Example 2:

Input: n = 2
Output: 20
Explanation: All the valid number we can dial are [04, 06, 16, 18, 27, 29, 34,
38, 40, 43, 49, 60, 61, 67, 72, 76, 81, 83, 92, 94] Example 3:

Input: n = 3131
Output: 136006598
Explanation: Please take care of the mod.


Constraints:

1 <= n <= 5000
Accepted
110.1K
Submissions
211.3K
Acceptance Rate
52.1%
*/

#include <cmath>
#include <vector>

using namespace std;

class Solution {
  vector<vector<int>> movemap = {  // idx 0 is number of moves
      {6, 4},                      // 0
      {8, 6},                      // 1
      {7, 9},                      // 2
      {4, 8},                      // 3
      {3, 9, 0},                   // 4
      {},                          // 5
      {1, 7},                      // 6
      {2, 6},                      // 7
      {1, 3},                      // 8
      {4, 2}};

  const int MOD = pow(10, 9) + 7;

  long long int r(int cur, int rem) {
    if (rem == 0) return 1;

    long long int ret = 0;
    vector<int> options = movemap[cur];
    for (int o:options) {
      if (o == 5) {}

      ret+= r(o, rem-1);
      ret%=MOD;
    }
    return ret;
  }

 public:
  int knightDialer(int n) {
    // dp/recursion problem i thinks
    // start on any square
    // handle 10 squares (base case)
    long long int res = 0;
    for (int i = 0; i < 10; ++i) {
      res+=r(i,n-1);
      res%=MOD;
    }
    return res;
  }
};