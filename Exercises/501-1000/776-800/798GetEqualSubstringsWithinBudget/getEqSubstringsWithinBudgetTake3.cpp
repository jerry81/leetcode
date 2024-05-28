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
public:
    int equalSubstring(string s, string t, int maxCost) {
      // lengths equal
      // get all costs
      int sz = s.size();
      vector<int> costs(sz,0);
      for (int i = 0; i < sz; ++i) {
        costs[i] = abs((int)s[i]-(int)t[i]);
      }
      // greedy doesn't work b/c we are looking for contiguous
      // dp doesn't work b/c MLE
      // sliding window is the way
      int mx = 0;
      int r = 1;
      int curtotal = 0;
      for (int l = 0; l < sz-1; ++l) {
        curtotal+=costs[l];
        while ((costs[r] + curtotal) <= maxCost) {
          curtotal = costs[r] + curtotal;

          mx = max(mx, (r-l)+1);
          r++;
        }
        curtotal-=costs[l];

      }
      return mx;
    }
};