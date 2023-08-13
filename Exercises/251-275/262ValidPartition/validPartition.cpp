/*

2369. Check if There is a Valid Partition For The Array
Medium
600
108
Companies
You are given a 0-indexed integer array nums. You have to partition the array
into one or more contiguous subarrays.

We call a partition of the array valid if each of the obtained subarrays
satisfies one of the following conditions:

The subarray consists of exactly 2 equal elements. For example, the subarray
[2,2] is good. The subarray consists of exactly 3 equal elements. For example,
the subarray [4,4,4] is good. The subarray consists of exactly 3 consecutive
increasing elements, that is, the difference between adjacent elements is 1. For
example, the subarray [3,4,5] is good, but the subarray [1,3,5] is not. Return
true if the array has at least one valid partition. Otherwise, return false.



Example 1:

Input: nums = [4,4,4,5,6]
Output: true
Explanation: The array can be partitioned into the subarrays [4,4] and [4,5,6].
This partition is valid, so we return true.
Example 2:

Input: nums = [1,1,1,2]
Output: false
Explanation: There is no valid partition for this array.


Constraints:

2 <= nums.length <= 105
1 <= nums[i] <= 106
Accepted
22.2K
Submissions
53.4K
Acceptance Rate
41.6%

*/

#include <vector>

using namespace std;

class Solution {
  bool r(vector<int>& nums, int idx, vector<int>& dp, int& n) {
    if (dp[idx] >= 0) return (bool)dp[idx];
    if (idx >= n-2) return false;
    if (idx == n-3) { // last pair
      dp[idx] = (nums[idx] == nums[idx+1]) ? 1 : 0;
      return dp[idx];
    }
    if (idx == n-4) { // last triplet
      bool allSame = nums[idx] == nums[idx+1] && nums[idx] == nums[idx+2];
      bool consecutive = (nums[idx] == (nums[idx+1] - 1)) && (nums[idx] == (nums[idx+2] - 2));
      dp[idx] = allSame || consecutive;
      return dp[idx];
    }

    bool ret = false;
    if (nums[idx] == nums[idx+1]) ret = ret || r(nums, idx+2, dp, n);


    if (nums[idx] == nums[idx+1] && nums[idx] == nums[idx+2]) ret = ret || r(nums, idx+3, dp, n);

    if ((nums[idx] == (nums[idx+1] - 1)) && ((nums[idx] == (nums[idx+2] - 2)))) ret = ret || r(nums,idx+3, dp, n);
    dp[idx] = ret;
    return ret;
  }

 public:
  bool validPartition(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, -1);
    return r(nums, 0, dp, n);
  }
};

// rules - 2 of a kind
// 3 of a kind
// 3 straight
// rules are recurrence
// end case is empty, single element, 2 elements, 3 elements
// dfs + dp
// dp on index