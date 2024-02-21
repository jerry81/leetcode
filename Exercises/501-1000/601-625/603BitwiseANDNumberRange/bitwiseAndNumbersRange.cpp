/*


201. Bitwise AND of Numbers Range
Medium
Topics
Companies
Given two integers left and right that represent the range [left, right], return
the bitwise AND of all numbers in this range, inclusive.



Example 1:

Input: left = 5, right = 7
Output: 4
Example 2:

Input: left = 0, right = 0
Output: 0
Example 3:

Input: left = 1, right = 2147483647
Output: 0


Constraints:

0 <= left <= right <= 231 - 1
Seen this question in a real interview before?
1/4
Yes
No
Accepted
284.4K
Submissions
652.7K
Acceptance Rate
43.6%


*/

#include <bitset>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;
class Solution {
 public:
  int rangeBitwiseAnd(int left, int right) {
    string binaryStringL = std::bitset<sizeof(int) * 8>(left).to_string();
    string binaryStringR = std::bitset<sizeof(int) * 8>(right).to_string();
    int idx = 0;
    int first_one_l, first_one_r = -1;
    while (idx < 32 && (first_one_r < 0 || first_one_r < 0)) {
      if (binaryStringL[idx] == '1') first_one_l = idx;
      if (binaryStringR[idx] == '1') first_one_r = idx;

      idx++;
    }

    if (first_one_l != first_one_r) return 0;

    int res = 0;
    for (int i = 31-first_one_l; i >= 0; --i) {
      if (binaryStringL[idx] == '1' && binaryStringR[idx] =='1') {
        res += pow(2,i);
      }
    }

    return res;
  }
};