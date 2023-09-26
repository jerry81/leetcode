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

struct CWithI {
  char c;
  int i;
};
class Solution {
map<char, vector<int>> lookups;

vector<CWithI> res;

void r(char c, int lastIdx, vector<CWithI> cur, int &sz) {

  if (cur.size() == sz) res = cur;

  if (c > 'z') return;

  vector<int> v = lookups[c];
  for (int i: v) {
    if (i > lastIdx) {
      vector<CWithI> tmp = cur;
      CWithI ci;
      ci.i = i;
      ci.c = c;
      tmp.push_back(ci);
      r(c+1, i, tmp, sz);
    }
  }
}
public:
    string removeDuplicateLetters(string s) {
      for (int i = 0; i < s.size(); ++i) {
        lookups[s[i]].push_back(i);
      }
      int sz = lookups.size();
      r('a', -1, {}, sz);
      for (CWithI ci: res) {
        cout << "c is " << ci.c << " i is " << ci.i << endl;
      }
      return "";
    }
};