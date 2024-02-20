/*

1009. Complement of Base 10 Integer
Easy
2.2K
108
Companies
The complement of an integer is the integer you get when you flip all the 0's to
1's and all the 1's to 0's in its binary representation.

For example, The integer 5 is "101" in binary and its complement is "010" which
is the integer 2. Given an integer n, return its complement.



Example 1:

Input: n = 5
Output: 2
Explanation: 5 is "101" in binary, with complement "010" in binary, which is 2
in base-10. Example 2:

Input: n = 7
Output: 0
Explanation: 7 is "111" in binary, with complement "000" in binary, which is 0
in base-10. Example 3:

Input: n = 10
Output: 5
Explanation: 10 is "1010" in binary, with complement "0101" in binary, which is
5 in base-10.


Constraints:

0 <= n < 109


Note: This question is the same as 476:
https://leetcode.com/problems/number-complement/

Accepted
208.5K
Submissions
342.6K
Acceptance Rate
60.8%

*/

#include <bitset>
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  int bitwiseComplement(int n) {
    string as_s = bitset<32>(n).to_string();
    // trim
    size_t nonZeroIndex = as_s.find_first_not_of('0');
    if (nonZeroIndex != std::string::npos) {
      as_s = as_s.substr(nonZeroIndex);
    } else {
      as_s = "0";  // If the entire string is zeros, return a single '0'.
    }
    for (int i = 0; i < as_s.size(); ++i) {
      as_s[i] = as_s[i] == '0'?'1':'0';
    }
    int andBack = bitset<32>(as_s).to_ulong();
    return andBack;
  }
};