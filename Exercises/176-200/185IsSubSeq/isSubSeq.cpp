/*

392. Is Subsequence
Easy
7.5K
421
Companies
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).



Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false


Constraints:

0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.


Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 109, and you want to check one by one to see if t has its subsequence. In this scenario, how would you change your code?
Accepted
871.6K
Submissions
1.8M
Acceptance Rate
47.4%

*/

#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
      if (s.empty()) return true;
      // use recursion
      char f = s[0];
      size_t pos = t.find(f);
      if (pos == string::npos) return false;

      return isSubsequence(s.substr(1), t.substr(pos+1));
    }
};