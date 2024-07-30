/*

1653. Minimum Deletions to Make String Balanced
Medium
Topics
Companies
Hint
You are given a string s consisting only of characters 'a' and 'b'​​​​.

You can delete any number of characters in s to make s balanced. s is balanced
if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]=
'a'.

Return the minimum number of deletions needed to make s balanced.



Example 1:

Input: s = "aababbab"
Output: 2
Explanation: You can either:
Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"),
or Delete the characters at 0-indexed positions 3 and 6 ("aababbab" ->
"aabbbb"). Example 2:

Input: s = "bbaaaaabb"
Output: 2
Explanation: The only solution is to delete the first two characters.


Constraints:

1 <= s.length <= 105
s[i] is 'a' or 'b'​​.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
44K
Submissions
74.6K
Acceptance Rate
58.9%

*/

#include <string>
#include <vector>

using namespace std;

class Solution {
  // gets index of searched item
  int bsearch(vector<int> &sorted, int tgt, bool or_greater) {
    int sz = sorted.size();
    int hi = sz - 1;
    int low = 0;
    while (hi > low) {
      int cur = (hi + low) / 2;
      if (cur == tgt) return cur;

      if (cur > tgt) {
        low = cur + 1;
      } else {
        hi = cur - 1;
      }
    }
    return low;
  };

 public:
  int minimumDeletions(string s) {
    vector<int> a;
    vector<int> b;
    int sz = s.size();
    for (int i = 0; i < sz; ++i) {
      if (s[i] == 'a') {
        a.push_back(i);
        cout << "a: " << i << endl;
      } else {
        b.push_back(i);
        cout << "b: " << i << endl;
      }
    }
    // test bsearch
    cout << "finding 2 in a" << bsearch(a, 2, false) << endl;
    cout << "finding 2 in b" << bsearch(b, 2, false) << endl;

    return 0;
  }
};