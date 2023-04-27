/*

319. Bulb Switcher
Medium
1.4K
2.1K
Companies
There are n bulbs that are initially off. You first turn on all the bulbs, then
you turn off every second bulb.

On the third round, you toggle every third bulb (turning on if it's off or
turning off if it's on). For the ith round, you toggle every i bulb. For the nth
round, you only toggle the last bulb.

Return the number of bulbs that are on after n rounds.



Example 1:


Input: n = 3
Output: 1
Explanation: At first, the three bulbs are [off, off, off].
After the first round, the three bulbs are [on, on, on].
After the second round, the three bulbs are [on, off, on].
After the third round, the three bulbs are [on, off, off].
So you should return 1 because there is only one bulb is on.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 1


Constraints:

0 <= n <= 109
Accepted
139.9K
Submissions
283.8K
Acceptance Rate
49.3%

*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
 public:
  int bulbSwitch(int n) {
    if (n == 0) return 0;

    if (n == 1) return 1;

    vector<bool> switches;
    for (int i = 0; i < n; ++i) {
      switches.push_back(true);
    }
    int count = n;

    for (int i = 2; i <= n; ++i) {
      int start = i-1;
      while (start < n) {
        switches[start] = !switches[start];

        if (switches[start]) {
          count++;
        } else {
          count--;
        }
        start+=i;
      }
    }
    return count;
  }
};

int main() {
  Solution s;
  int prev = 0;
  for (int i = 1; i < 100; ++i) {
    int cur = s.bulbSwitch(i);
    if (cur != prev) {
      cerr << "changed at " << i << " count is " << cur << endl;
      prev = cur;
    }
  }
};

// naive - do the loop
// leet - solve it mathematically
/*

  n = 300
  expected 17
  output 73


  1 3 5 7
  2 5 8
  3 7 11

  TLE on 10000000
*/

// by feeding numbers found that the solution is
// sqrt(n)'s floor