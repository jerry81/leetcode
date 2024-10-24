/*

7. Reverse Integer
Medium
Topics
Companies
Given a signed 32-bit integer x, return x with its digits reversed. If reversing
x causes the value to go outside the signed 32-bit integer range [-231, 231 -
1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or
unsigned).



Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21


Constraints:

-231 <= x <= 231 - 1
Seen this question in a real interview before?
1/5
Yes
No
Accepted
3.6M
Submissions
12.2M
Acceptance Rate
29.3%

*/

#include <string>
using namespace std;
class Solution {
 public:
  int reverse(int x) {
    // so the challenge is testing out of bounds?
    string as_s = to_string(x);
    if (x < 0) {
      std::reverse(as_s.begin() + 1, as_s.end());
    } else {
      std::reverse(as_s.begin(), as_s.end());
    }
    // max to string
    string maxStr = to_string(INT_MAX);
    string minStr = to_string(INT_MIN);
    if (as_s.size() == 11) {
      if (minStr < as_s) return 0;
    }
    if (as_s.size() == 10) {
      if (as_s.front() != '-') {
        if (maxStr < as_s) return 0;
      }
    }
    return stoi(as_s);
  }
};