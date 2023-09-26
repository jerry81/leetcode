/*

316. Remove Duplicate Letters
Medium
7.3K
466
Companies
Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is
the smallest in lexicographical order
 among all possible results.



Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"


Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.


Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

Accepted
245K
Submissions
534.6K
Acceptance Rate
45.8%

*/

#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution {
map<char, vector<int>> lookups;
public:
    string removeDuplicateLetters(string s) {
      for (int i = 0; i < s.size(); ++i) {
        lookups[s[i]].push_back(i);
      }
      string res = "";
      for (auto [a, v]: lookups) {
      }
      return res;
    }
};