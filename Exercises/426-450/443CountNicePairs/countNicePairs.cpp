/*

1814. Count Nice Pairs in an Array
Medium
868
38
Companies
You are given an array nums that consists of non-negative integers. Let us
define rev(x) as the reverse of the non-negative integer x. For example,
rev(123) = 321, and rev(120) = 21. A pair of indices (i, j) is nice if it
satisfies all of the following conditions:

0 <= i < j < nums.length
nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
Return the number of nice pairs of indices. Since that number can be too large,
return it modulo 109 + 7.



Example 1:

Input: nums = [42,11,1,97]
Output: 2
Explanation: The two pairs are:
 - (0,3) : 42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121.
 - (1,2) : 11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12.
Example 2:

Input: nums = [13,10,35,24,76]
Output: 4


Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109
Accepted
30.5K
Submissions
71.4K
Acceptance Rate
42.6%

*/

#include <cmath>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int countNicePairs(vector<int>& nums) {
    vector<int> revs;
    for (int n : nums) {
      string asS = to_string(n);
      reverse(asS.begin(), asS.end());
      int backToInt = stoi(asS);
      revs.push_back(backToInt);
    }
    long long int resL = 0;
    const int MOD = pow(10, 9) + 7;
    int sz = nums.size();
    for (int i = 0; i < sz - 1; ++i) {
      for (int j = i + 1; j < sz; ++j) {
        int add1 = revs[i] + nums[j];
        int add2 = revs[j] + nums[i];
        if (add1 == add2) {
          resL++;
          resL %= MOD;
        }
      }
    }

    // binary search for nice pairs
    return resL;
  }
};