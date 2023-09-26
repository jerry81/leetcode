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
#include <algorithm>
#include <iterator>

using namespace std;

struct CWithI {
  char c;
  int i;
};
class Solution {
map<char, vector<int>> lookups;

vector<CWithI> res;

void r(int lastIdx, vector<CWithI> cur, int &sz, vector<char> keys) {

  if (cur.size() == sz) res = cur;

  if (keys.empty()) return;

  vector<int> v = lookups[c];
  auto uppr = upper_bound(v.begin(), v.end(), lastIdx);
  auto lwr = lower_bound(v.begin(), v.end(), lastIdx);

  if (uppr != v.end()) {
    int nextIdx = distance(v.begin(), uppr);
    r()
  }

  if (lwr != v.end()) {
    int nextIdx = distance(v.begin(), lwr);
  }
}
public:
    string removeDuplicateLetters(string s) {
      for (int i = 0; i < s.size(); ++i) {
        lookups[s[i]].push_back(i);
      }
      int sz = lookups.size();
      vector<char> keys;
      for (auto [k,_]: lookups) {
        keys.push_back(k);
      }
      r(-1, {}, sz, keys);
      return "";
    }
};