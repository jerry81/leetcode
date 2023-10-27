/*

5. Longest Palindromic Substring
Medium
27.5K
1.6K
Companies
Given a string s, return the longest
palindromic

substring
 in s.



Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"


Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
Accepted
2.7M
Submissions
8.1M
Acceptance Rate
32.9%

*/

#include <string>

using namespace std;

class Solution {
  pair<int, int> check(int ptr1, int ptr2, string &s, int &sz) {
    while (true) {
      int nxt1 = ptr1 - 1;
      int nxt2 = ptr2 + 1;
      if (nxt1 < 0 || nxt2 >= sz) return {ptr1, ptr2};

      if (s[nxt1] != s[nxt2]) return {ptr1, ptr2};

      ptr1 = nxt1;
      ptr2 = nxt2;
    }
    return {-1, -1};
  }

 public:
  string longestPalindrome(string s) {
    int sz = s.size();
    if (sz == 1) return s;

    string res = "";
    int mxsz = 0;
    int ptr1 = 0;
    for (int ptr1 = 0; ptr1 < sz - 1; ++ptr1) {
      for (int i : {1, 2}) {
        int ptr2 = ptr1 + i;
        if (s[ptr1] != s[ptr2]) continue;
        pair<int, int> pr = check(ptr1, ptr2, s, sz);
        int cursz = pr.second - pr.first + 1;
        if (cursz > mxsz) {
          mxsz = cursz;
          res = s.substr(pr.first, mxsz);
        }
      }
    }
    // one more case
    if (mxsz < 2) {
      if (s[sz - 2] == s[sz - 1]) return s.substr(sz - 2, 2);
    }
    return res;
  }
};

/*
some kind of 2 ptr
check adjacent and off by 1 cases
*/