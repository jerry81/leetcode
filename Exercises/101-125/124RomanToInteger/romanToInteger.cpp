/*

13. Roman to Integer
Easy
10.2K
592
Companies
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and
M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together.
12 is written as XII, which is simply X + II. The number 27 is written as XXVII,
which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right.
However, the numeral for four is not IIII. Instead, the number four is written
as IV. Because the one is before the five we subtract it making four. The same
principle applies to the number nine, which is written as IX. There are six
instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.



Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.


Constraints:

1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].
Accepted
2.6M
Submissions
4.5M
Acceptance Rate
58.6%

*/

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int romanToInt(string s) {
    vector<int> i_tries = {1000, 900, 500, 400, 100, 90, 50,
                           40,   10,  9,   5,   4,   1};
    vector<string> s_tries = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                              "XL", "X",  "IX", "V",  "IV", "I"};
    int res = 0;
    for (int i = 0; i < s.size(); ++i) {
      char cur = s[i];
      if (cur == 'M') {
        res += 1000;
      } else if (cur == 'D') {
        res += 500;
      } else if (cur == 'C') {
        int next = i + 1;
        if (next >= s.size()) {
          res += 100;
          continue;
        }

        char nextc = s[next];
        if (nextc == 'M') {
          res += 900;
          i += 1;
        } else if (nextc == 'D') {
          res += 400;
          i += 1;
        } else {
          res += 100;
        }
      } else if (cur == 'L') {
        res += 50;
      } else if (cur == 'X') {
        int next = i + 1;
        if (next >= s.size()) {
          res += 10;
          continue;
        }

        char nextc = s[next];
        if (nextc == 'C') {
          res+=90;
          i+=1;
        } else if (nextc == 'L') {
          res+=40;
          i+=1;
        } else {
          res+=10;
        }
      } else if (cur=='V') {
        res+=5;
      } else { // 'I'
        int next = i + 1;
        if (next >= s.size()) {
          res += 1;
          continue;
        }

        char nextc = s[next];
        if (nextc == 'X') {
          res+=9;
          i+=1;
        } else if (nextc == 'V') {
          res+=4;
          i+=1;
        } else {
          res+=1;
        }
      }
    }
    return ret;
  }
};

/*

attempt 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1
          M,   CM,  D,   CD,  C,  XC, L,  XL, X, IX, V, IV, I

oops, i wrote int to roman.
*/