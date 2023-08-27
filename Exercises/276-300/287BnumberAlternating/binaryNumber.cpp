/*

693. Binary Number with Alternating Bits
Easy
1.3K
110
Companies
Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.



Example 1:

Input: n = 5
Output: true
Explanation: The binary representation of 5 is: 101
Example 2:

Input: n = 7
Output: false
Explanation: The binary representation of 7 is: 111.
Example 3:

Input: n = 11
Output: false
Explanation: The binary representation of 11 is: 1011.


Constraints:

1 <= n <= 231 - 1
Accepted
120K
Submissions
194.1K
Acceptance Rate
61.8%

*/


class Solution {
public:
    bool hasAlternatingBits(int n) {
      bool started = false;
      bool cur = false;
      while (n != 0) {
        int half = n/2;
        int r = n%2;
        if (!started) cur = r;
        started = true;
        if (cur == !!r) return false;
        cur = r;
        n = half;
      }
      return true;
    }
};