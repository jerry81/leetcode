/*

942. DI String Match
Easy
2.3K
942
Companies
A permutation perm of n + 1 integers of all the integers in the range [0, n] can
be represented as a string s of length n where:

s[i] == 'I' if perm[i] < perm[i + 1], and
s[i] == 'D' if perm[i] > perm[i + 1].
Given a string s, reconstruct the permutation perm and return it. If there are
multiple valid permutations perm, return any of them.



Example 1:

Input: s = "IDID"
Output: [0,4,1,3,2]
Example 2:

Input: s = "III"
Output: [0,1,2,3]
Example 3:

Input: s = "DDI"
Output: [3,2,0,1]


Constraints:

1 <= s.length <= 105
s[i] is either 'I' or 'D'.
Accepted
141.9K
Submissions
182K
Acceptance Rate
77.9%

*/

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> diStringMatch(string s) {
    int sz = s.size();
    int mn = 0;
    int cur = 0;
    int mx = 0;
    vector<int> tmp = {0};
    vector<int> res;
    for (char c : s) {
      if (c == 'D') {
        mn--;
        tmp.push_back(mn);
      } else {
        mx++;
        tmp.push_back(mx);
      }
    }

    int diff = abs(mn);
    if (diff > 0) {
      for (int i : tmp) {
        i += diff;
        res.push_back(i);
      }
    } else {
      return tmp;
    }
    return res;
  }
};