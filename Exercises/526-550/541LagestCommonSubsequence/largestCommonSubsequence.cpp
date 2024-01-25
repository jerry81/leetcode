/*


Code
Testcase
Test Result
Test Result
1143. Longest Common Subsequence
Medium
Topics
Companies
Hint
Given two strings text1 and text2, return the length of their longest common
subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string
with some characters (can be none) deleted without changing the relative order
of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both
strings.



Example 1:

Input: text1 = "abcde", text2 = "ace"
Output: 3
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.


Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
899K
Submissions
1.6M
Acceptance Rate
57.6%

*/

#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
  map<pair<int, int>, int> dp;

  int r(string &t1, map<char, vector<int>> m1, map<char, vector<int>> m2, int &s1, int &s2, int idx1, int idx2) {
    if (s1 <= idx1 || s2 <= idx2) return 0;

    if (dp.find({idx1, idx2}) != dp.end()) return dp[{idx1,idx2}];
    char c = t1[idx1];
    int take_cnt = 0;
    // take
    if (m2.find(c) != m2.end()) {
      for (int i = 0; i < m2[c].size(); ++i) {
        if (m2[c][i] >= idx2) {
          take_cnt = 1+r(t1,m1,m2,s1,s2,idx1+1, m2[c][i]);
          break;
        }
      }
    }
    // leave
    int leave_cnt = r(t1,m1,m2,s1,s2,idx1+1, idx2);
    return dp[{idx1,idx2}] = max(take_cnt, leave_cnt);
  }

 public:
  int longestCommonSubsequence(string text1, string text2) {
    int s1 = text1.size();
    int s2 = text2.size();
    map<char, vector<int>> s1_map;
    map<char, vector<int>> s2_map;
    for (int i = 0; i < s1; ++i) {
      s1_map[text1[i]].push_back(i);
    }
    for (int i = 0; i < s2; ++i) {
      s2_map[text2[i]].push_back(i);
    }
    return r(text1, s1_map, s2_map, s1, s2, 0, 0);
  }
};