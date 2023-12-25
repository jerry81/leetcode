/*

91. Decode Ways
Medium
11K
4.4K
Companies
A message containing letters from A-Z can be encoded into numbers using the
following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back
into letters using the reverse of the mapping above (there may be multiple
ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into
'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.



Example 1:

Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
6). Example 3:

Input: s = "06"
Output: 0
Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is
different from "06").


Constraints:

1 <= s.length <= 100
s contains only digits and may contain leading zero(s).
Accepted
1.1M
Submissions
3.3M
Acceptance Rate
33.8%

*/

#include <string>
#include <vector>

using namespace std;

class Solution {
  vector<vector<int>> memo;
  int r(int idx, int carry, string &s, int &len) {
    if (idx == len) return carry == -1;
    // if (memo[idx][carry] >= 0) return memo[idx][carry];
    char cur = s[idx];
    int as_i = cur - '0';
    if (as_i == 0 && carry == -1) return 0;

    if (as_i > 6 && carry == 2) return 0;

    if (as_i == 1 || as_i == 2 && carry == -1) {
      // use it immediately
      int used = r(idx + 1, -1, s, len);
      int unused = r(idx + 1, as_i, s, len);
      //  memo[idx][carry] = used + unused;
      return used + unused;
    }

    carry = max(0, carry);
    return r(idx + 1, -1, s, len);
    // return memo[idx][carry];
  }

 public:
  int numDecodings(string s) {
    int len = s.size();
    memo.resize(len, vector<int>(4, -1));
    return r(0, -1, s, len);
  }
};