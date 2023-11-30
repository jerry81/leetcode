/*

1611. Minimum One Bit Operations to Make Integers Zero
Hard
477
433
Companies
Given an integer n, you must transform it into 0 using the following operations
any number of times:

Change the rightmost (0th) bit in the binary representation of n.
Change the ith bit in the binary representation of n if the (i-1)th bit is set
to 1 and the (i-2)th through 0th bits are set to 0. Return the minimum number of
operations to transform n into 0.



Example 1:

Input: n = 3
Output: 2
Explanation: The binary representation of 3 is "11".
"11" -> "01" with the 2nd operation since the 0th bit is 1.
"01" -> "00" with the 1st operation.
Example 2:

Input: n = 6
Output: 4
Explanation: The binary representation of 6 is "110".
"110" -> "010" with the 2nd operation since the 1st bit is 1 and 0th through 0th
bits are 0. "010" -> "011" with the 1st operation. "011" -> "001" with the 2nd
operation since the 0th bit is 1. "001" -> "000" with the 1st operation.


Constraints:

0 <= n <= 109
Accepted
17.3K
Submissions
26.5K
Acceptance Rate
65.5%

*/

#include <bitset>
#include <string>
#include <cmath>

using namespace std;

class Solution {

 public:
  int minimumOneBitOperations(int n) {
    if (n == 0) return 0;

    std::string binaryString = std::bitset<32>(n).to_string();
    size_t firstOne = binaryString.find('1');
    binaryString = binaryString.substr(firstOne);
    int sz = binaryString.size();
    int accum = 0;
    for (int i = sz-1; i >= 0; i--) {
      int exponent = sz-i;
      char c = binaryString[i];
      if (c == '1') {
        accum = pow(2, exponent) - 1 - accum;
      }
    }
    return accum;
  }
};