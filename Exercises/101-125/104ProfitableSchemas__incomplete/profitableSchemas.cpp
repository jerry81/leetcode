/*

879. Profitable Schemes
Hard
852
76
Companies
There is a group of n members, and a list of various crimes they could commit. The ith crime generates a profit[i] and requires group[i] members to participate in it. If a member participates in one crime, that member can't participate in another crime.

Let's call a profitable scheme any subset of these crimes that generates at least minProfit profit, and the total number of members participating in that subset of crimes is at most n.

Return the number of schemes that can be chosen. Since the answer may be very large, return it modulo 109 + 7.



Example 1:

Input: n = 5, minProfit = 3, group = [2,2], profit = [2,3]
Output: 2
Explanation: To make a profit of at least 3, the group could either commit crimes 0 and 1, or just crime 1.
In total, there are 2 schemes.
Example 2:

Input: n = 10, minProfit = 5, group = [2,3,5], profit = [6,7,8]
Output: 7
Explanation: To make a profit of at least 5, the group could commit any crimes, as long as they commit one.
There are 7 possible schemes: (0), (1), (2), (0,1), (0,2), (1,2), and (0,1,2).


Constraints:

1 <= n <= 100
0 <= minProfit <= 100
1 <= group.length <= 100
1 <= group[i] <= 100
profit.length == group.length
0 <= profit[i] <= 100
Accepted
25.3K
Submissions
57.5K
Acceptance Rate
44.0%

*/

#include <vector>
#include <cmath>
#include <iostream>
#include <unordered_map>

using namespace std;

const static int MOD =  pow(10,9) + 7;

// why this number always shows up https://www.geeksforgeeks.org/modulo-1097-1000000007/
class Solution {
unordered_map<int, unordered_map<int, unordered_map<int, bool>>> lookup;
unordered_map<int, unordered_map<int, unordered_map<int, bool>>> visited;
int _successes = 0;
int _people;
int _minprofit;
int _size;
void buildTree(int idx, int members, int profit) {
  if (idx >= _size) return;

  if (visited[idx][members][profit]) {
    if (lookup[idx][members][profit]) _successes = (_successes+1) % (pow(10,9) + 7);
  } else {
    visited[idx][members][profit]
  }
}
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
      _people = n;
      _minprofit = minProfit;
      _size = group.size();
      buildTree(0,0,0);
      return 0;
    }
};

/*
strat
tree? yes (binary tree)
  no decisions made
2 decisions at each index: take dont take
        t            dt
    t      dt      t     dt
  t    dt t  dt  t   dt t   dt

  at any node if at capacity, then the subtrees counts can be calculated in one turn
- memoization & array are enough

memo keep track of idx 0, 1, ->
*/