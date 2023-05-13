/*

2466. Count Ways To Build Good Strings
Medium
1K
90
Companies
Given the integers zero, one, low, and high, we can construct a string by
starting with an empty string, and then at each step perform either of the
following:

Append the character '0' zero times.
Append the character '1' one times.
This can be performed any number of times.

A good string is a string constructed by the above process having a length
between low and high (inclusive).

Return the number of different good strings that can be constructed satisfying
these properties. Since the answer can be large, return it modulo 109 + 7.



Example 1:

Input: low = 3, high = 3, zero = 1, one = 1
Output: 8
Explanation:
One possible valid good string is "011".
It can be constructed as follows: "" -> "0" -> "01" -> "011".
All binary strings from "000" to "111" are good strings in this example.
Example 2:

Input: low = 2, high = 3, zero = 1, one = 2
Output: 5
Explanation: The good strings are "00", "11", "000", "110", and "011".


Constraints:

1 <= low <= high <= 105
1 <= zero, one <= low
Accepted
36.1K
Submissions
67.2K
Acceptance Rate
53.8%

*/

#include <cmath>

using namespace std;

const int MOD = pow(10, 9) + 7;
class Solution {
  int cgs(int z, int o, int cur) {}

 public:
  int countGoodStrings(int low, int high, int zero, int one) {
    long long tot = 0;
    for (int i = low; i < high; ++i) {
      tot += cgs(zero, one, i);
      tot %= MOD;
    }
    return (int)tot;
  }
};

// Input: low = 3, high = 3, zero = 1, one = 1
// Output: 8

// 000
// 001

/*

Input: low = 2, high = 3, zero = 1, one = 2
Output: 5

11
00
011
110
000

0    0
00   0,0
11   1
011  0,1
110  1,0
000  0,0,0
1111 1,1,

for size = 2, 2 0 or 1  1
for size = 3, 3 0, 1 1, 1 0

size 5 -> 5 0, 3 1, 1, 2

00000

00011
11000
01100
00110
01111
11011
11110

size 6 -> 6 0, 4 1, 2 2, 0, 3
000000

4 1 case
110000
011000
001100
000110
000011

2,2 case
111100
110011
001111


111111

similar to staircase problem

official solution uses iterative and recursive with dp

*/
