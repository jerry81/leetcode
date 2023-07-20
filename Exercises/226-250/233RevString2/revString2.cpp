/*

541. Reverse String II
Easy
1.7K
3.3K
Companies
Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.

If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.



Example 1:

Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Example 2:

Input: s = "abcd", k = 2
Output: "bacd"


Constraints:

1 <= s.length <= 104
s consists of only lowercase English letters.
1 <= k <= 104
Accepted
204.2K
Submissions
405.3K
Acceptance Rate
50.4%

*/

#include <string>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
      string ret = "";
      ret.resize(s.size(), ' ');

      for (int i = 0; i < s.size(); ++i) {
        // k == 2
        // 0 1 3 2 4 5 7 6
        // 0 1 2 3 4 5 6 7
        // f   b   f   b
        int base = i/k;
        int rem = i % k;
        if (rem == 0) rem = k;
        bool forwards = base % 2 == 0;
        if (forwards) {
          ret[i] = s[i];
        } else {
          ret[i] = s[base+k-rem];
        }
      }
      return ret;
    }
};