/*
1208. Get Equal Substrings Within Budget
Medium
Topics
Companies
Hint
You are given two strings s and t of the same length and an integer maxCost.

You want to change s to t. Changing the ith character of s to ith character of t costs |s[i] - t[i]| (i.e., the absolute difference between the ASCII values of the characters).

Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of t with a cost less than or equal to maxCost. If there is no substring from s that can be changed to its corresponding substring from t, return 0.



Example 1:

Input: s = "abcd", t = "bcdf", maxCost = 3
Output: 3
Explanation: "abc" of s can change to "bcd".
That costs 3, so the maximum length is 3.
Example 2:

Input: s = "abcd", t = "cdef", maxCost = 3
Output: 1
Explanation: Each character in s costs 2 to change to character in t,  so the maximum length is 1.
Example 3:

Input: s = "abcd", t = "acde", maxCost = 0
Output: 1
Explanation: You cannot make any change, so the maximum length is 1.


Constraints:

1 <= s.length <= 105
t.length == s.length
0 <= maxCost <= 106
s and t consist of only lowercase English letters.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
64.4K
Submissions
121.6K
Acceptance Rate
53.0%
*/

#include <string>
#include <vector>

using namespace std;

class Solution {
vector<vector<int>> memo;
int r(int idx, vector<int> &costs, int budget) {

  if (idx>=costs.size()) return 0;

  if (costs[idx] > budget) return 0;

  if (memo[idx][budget] > -1) return memo[idx][budget];

  return memo[idx][budget] = 1 + r(idx+1, costs, budget-costs[idx]);
}
public:
    int equalSubstring(string s, string t, int maxCost) {
      // lengths equal
      // get all costs
      int sz = s.size();
      memo.resize(sz, vector<int>(maxCost+1, -1));
      vector<int> costs(sz,0);
      for (int i = 0; i < sz; ++i) {
        costs[i] = abs((int)s[i]-(int)t[i]);
      }
      // greedy won't work because the substring must be contiguous
      // must do dp
      int mx = 0;
      for (int i = 0; i < sz; ++i) {
        mx = max(mx, r(i,costs,maxCost));
      }
      return mx;
    }
};