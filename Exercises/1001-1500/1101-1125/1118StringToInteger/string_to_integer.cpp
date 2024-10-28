/*
8. String to Integer (atoi)
Medium
Topics
Companies
Implement the myAtoi(string s) function, which converts a string to a 32-bit
signed integer.

The algorithm for myAtoi(string s) is as follows:

Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+',
assuming positivity is neither present. Conversion: Read the integer by skipping
leading zeros until a non-digit character is encountered or the end of the
string is reached. If no digits were read, then the result is 0. Rounding: If
the integer is out of the 32-bit signed integer range [-231, 231 - 1], then
round the integer to remain in the range. Specifically, integers less than -231
should be rounded to -231, and integers greater than 231 - 1 should be rounded
to 231 - 1. Return the integer as the final result.



Example 1:

Input: s = "42"

Output: 42

Explanation:

The underlined characters are what is read in and the caret is the current
reader position. Step 1: "42" (no characters read because there is no leading
whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)
           ^
Example 2:

Input: s = " -042"

Output: -42

Explanation:

Step 1: "   -042" (leading whitespace is read and ignored)
            ^
Step 2: "   -042" ('-' is read, so the result should be negative)
             ^
Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)
               ^
Example 3:

Input: s = "1337c0d3"

Output: 1337

Explanation:

Step 1: "1337c0d3" (no characters read because there is no leading whitespace)
         ^
Step 2: "1337c0d3" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "1337c0d3" ("1337" is read in; reading stops because the next character
is a non-digit)
             ^
Example 4:

Input: s = "0-1"

Output: 0

Explanation:

Step 1: "0-1" (no characters read because there is no leading whitespace)
         ^
Step 2: "0-1" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "0-1" ("0" is read in; reading stops because the next character is a
non-digit)
          ^
Example 5:

Input: s = "words and 987"

Output: 0

Explanation:

Reading stops at the first non-digit character 'w'.



Constraints:

0 <= s.length <= 200
s consists of English letters (lower-case and upper-case), digits (0-9), ' ',
'+', '-', and '.'. Seen this question in a real interview before? 1/5 Yes No
Accepted
1.7M
Submissions
9.5M
Acceptance Rate
18.1%
*/

#include <string>
using namespace std;

class Solution {
 public:
  int myAtoi(string s) {
    // trim leading whitespace
    int n = s.size();
    string trimmed = "";
    for (int i = 0; i < n; ++i) {
      if (s[i] != ' ') {
        trimmed = s.substr(i);
        break;
      }
    }

    // step 2: signedness
    bool is_neg = trimmed.size() > 0 && trimmed[0] == '-';
    if (is_neg || trimmed[0] == '+') {
      trimmed = trimmed.substr(1);
    }

    // step 3 convert
    bool non_zero = false;
    string digits;
    for (char c : s) {
      if (isdigit(c)) {
        if (c == '0' && !non_zero) continue;

        digits.push_back(c);
      } else {
        break;
      }
    }
    if (digits.empty()) return 0;

    // oob
    string maxStr = to_string(INT_MAX);
    string minStr = to_string(INT_MIN);
    if (digits.size() == 11) {
      if (minStr < digits) return INT_MIN;
    }
    if (digits.size() == 10) {
      if (digits.front() != '-') {
        if (maxStr < digits) return INT_MAX;
      }
    }
    int res = 0;
    int multiplier = 1;
    reverse(digits.begin(), digits.end());
    for (int i: digits) {
      res+=multiplier*i;
      multiplier*=10;
    }
    return res;
  }
};