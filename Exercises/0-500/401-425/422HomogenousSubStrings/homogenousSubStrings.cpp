/*

1759. Count Number of Homogenous Substrings
Medium
740
46
Companies
Given a string s, return the number of homogenous substrings of s. Since the
answer may be too large, return it modulo 109 + 7.

A string is homogenous if all the characters of the string are the same.

A substring is a contiguous sequence of characters within a string.



Example 1:

Input: s = "abbcccaa"
Output: 13
Explanation: The homogenous substrings are listed as below:
"a"   appears 3 times.
"aa"  appears 1 time.
"b"   appears 2 times.
"bb"  appears 1 time.
"c"   appears 3 times.
"cc"  appears 2 times.
"ccc" appears 1 time.
3 + 1 + 2 + 1 + 3 + 2 + 1 = 13.
Example 2:

Input: s = "xy"
Output: 2
Explanation: The homogenous substrings are "x" and "y".
Example 3:

Input: s = "zzzzz"
Output: 15


Constraints:

1 <= s.length <= 105
s consists of lowercase letters.
Accepted
35.6K
Submissions
68.2K
Acceptance Rate
52.3%

*/

#include <cmath>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  const int MOD = pow(10, 9) + 7;

 public:
  int countHomogenous(string s) {
    long long int tmpres = 1;
    int streak = 1;
    char prev = s[0];
    for (int i = 1; i < s.size(); ++i) {
      int c = s[i];
      if (prev == c) {
        streak++;
        tmpres += streak;
        tmpres %= MOD;
      } else {
        streak = 1;
        tmpres += 1;
        tmpres %= MOD;
      }
      prev = c;
    }
    return tmpres;
  }
};