/*
1326. Minimum Number of Taps to Open to Water a Garden
Hard
2.1K
127
Companies
There is a one-dimensional garden on the x-axis. The garden starts at the point 0 and ends at the point n. (i.e The length of the garden is n).

There are n + 1 taps located at points [0, 1, ..., n] in the garden.

Given an integer n and an integer array ranges of length n + 1 where ranges[i] (0-indexed) means the i-th tap can water the area [i - ranges[i], i + ranges[i]] if it was open.

Return the minimum number of taps that should be open to water the whole garden, If the garden cannot be watered return -1.



Example 1:


Input: n = 5, ranges = [3,4,1,1,0,0]
Output: 1
Explanation: The tap at point 0 can cover the interval [-3,3]
The tap at point 1 can cover the interval [-3,5]
The tap at point 2 can cover the interval [1,3]
The tap at point 3 can cover the interval [2,4]
The tap at point 4 can cover the interval [4,4]
The tap at point 5 can cover the interval [5,5]
Opening Only the second tap will water the whole garden [0,5]
Example 2:

Input: n = 3, ranges = [0,0,0,0]
Output: -1
Explanation: Even if you activate all the four taps you cannot water the whole garden.


Constraints:

1 <= n <= 104
ranges.length == n + 1
0 <= ranges[i] <= 100
Accepted
74.7K
Submissions
156.6K
Acceptance Rate
47.7%
*/

#include <vector>

using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
      vector<int> maxEnds(n+1);
      int curMax = -1;
      for (int i = 0; i <= n; ++i) {
        curMax = max(curMax,ranges[i] + i);
        maxEnds[i] = curMax;
      }
      int count, cur, nxt = 0;
      for (int i = 0; i <= n; ++i) {
        int reach = maxEnds[i];
        if (i > nxt) return -1;
        if (i > cur) {
          count++;
          cur = reach;
        }

        nxt = max(nxt,reach);
      }
      return count;
    }
};

/*

brute force - check all combos of sprinklers using knapsack

optimization knapsack with dp

straight to editorial

official 1 - DP
  - representation - taps needed to water from position 0 to i
official 2 - greedy
  - take largest spanning taps?
  - build

*/