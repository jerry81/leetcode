/*

1318. Minimum Flips to Make a OR b Equal to c
Medium
735
52
Companies
Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation.



Example 1:



Input: a = 2, b = 6, c = 5
Output: 3
Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)
Example 2:

Input: a = 4, b = 2, c = 7
Output: 1
Example 3:

Input: a = 1, b = 2, c = 3
Output: 0


Constraints:

1 <= a <= 10^9
1 <= b <= 10^9
1 <= c <= 10^9
Accepted
37K
Submissions
54.6K
Acceptance Rate
67.7%

1318. Minimum Flips to Make a OR b Equal to c
Medium
735
52
Companies
Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation.



Example 1:



Input: a = 2, b = 6, c = 5
Output: 3
Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)
Example 2:

Input: a = 4, b = 2, c = 7
Output: 1
Example 3:

Input: a = 1, b = 2, c = 3
Output: 0


Constraints:

1 <= a <= 10^9
1 <= b <= 10^9
1 <= c <= 10^9
Accepted
37K
Submissions
54.6K
Acceptance Rate
67.7%

*/

using namespace std;
#include <string>
#include <bitset>

class Solution {
string getBString(int inp) {
  return bitset<sizeof(int) * 8>(inp).to_string();
}
public:
    int minFlips(int a, int b, int c) {
      // convert a,b,c to bstrings
      int res = 0;
      string as = getBString(a);
      string bs = getBString(b);
      string cs = getBString(c);
      for (int i = 0; i < as.size(); ++i) {
        bool ab = as[i] == '1';
        bool bb = bs[i] == '1';
        bool cb = cs[i] == '1';
        if (cb) {
          if (!ab && !bb) res++;
        } else {
          if (ab) res++;

          if (bb) res++;
        }
      }
      return res;
    }
};
