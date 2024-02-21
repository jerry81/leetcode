/*


201. Bitwise AND of Numbers Range
Medium
Topics
Companies
Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.



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

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
      int res = left;
      for (int i = left+1; i <=right; ++i) {
        res&=i;
      }
      return res;
    }
};