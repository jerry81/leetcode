/*

974. Subarray Sums Divisible by K
Medium
Topics
Companies
Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.



Example 1:

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
Example 2:

Input: nums = [5], k = 9
Output: 0


Constraints:

1 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
2 <= k <= 104
Seen this question in a real interview before?
1/5
Yes
No
Accepted
314.2K
Submissions
569.1K
Acceptance Rate
55.2%

*/

#include <vector>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
      // contiguous, 2 ptr
      int sz = nums.size();
      vector<int> prefix_sums;
      int sum = 0;
      for (int i: nums) {
        sum+=i;
        prefix_sums.push_back(sum);
      }
      int res = 0;
      for (int i = -1; i < sz-1; ++i) {
        for (int j = i+1; j < sz; ++j) {
          int left = i < 0?0: prefix_sums[i];
          if ((left-prefix_sums[j])%k == 0) res+=1;
        }
      }
      return res;
    }
};