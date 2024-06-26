/*

131. Palindrome Partitioning
Medium
Topics
Companies
Given a string s, partition s such that every
substring
 of the partition is a
palindrome
. Return all possible palindrome partitioning of s.



Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]


Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
808.2K
Submissions
1.2M
Acceptance Rate
67.8%

*/

#include <string>
#include <vector>

using namespace std;


class Solution {
  bool is_p(string s) {
    int sz = s.size();
    if (sz == 1) return true;

    int l = 0;
    int r = sz - 1;
    while (l < r) {
      if (s[l] != s[r]) return false;

      l++;
      r--;
    }
    return true;
  }

  vector<vector<string>> res;

  void r(vector<string> cur, int idx, string &s, int sz) {
    if (idx >= sz) {

      if (!cur.empty()) res.push_back(cur);

      return;
    }

    // try substrings starting from idx
    int rem = sz - idx;
    for (int i = 1; i <= rem; ++i) {
      string subs = s.substr(idx, i);
      if (!is_p(subs)) continue;

      vector<string> cpy = cur;
      cpy.push_back(subs);
      r(cpy, idx+i, s, sz);
    }
  }

 public:
  vector<vector<string>> partition(string s) {
    int sz = s.size();
    r({}, 0, s, sz);
    return res;
  }
};