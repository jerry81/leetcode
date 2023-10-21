/*

1425. Constrained Subsequence Sum
Hard
1.3K
65
Companies
Given an integer array nums and an integer k, return the maximum sum of a
non-empty subsequence of that array such that for every two consecutive integers
in the subsequence, nums[i] and nums[j], where i < j, the condition j - i <= k
is satisfied.

A subsequence of an array is obtained by deleting some number of elements (can
be zero) from the array, leaving the remaining elements in their original order.



Example 1:

Input: nums = [10,2,-10,5,20], k = 2
Output: 37
Explanation: The subsequence is [10, 2, 5, 20].
Example 2:

Input: nums = [-1,-2,-3], k = 1
Output: -1
Explanation: The subsequence must be non-empty, so we choose the largest number.
Example 3:

Input: nums = [10,-2,-10,-5,20], k = 2
Output: 23
Explanation: The subsequence is [10, -2, -5, 20].


Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
Accepted
32.1K
Submissions
64.1K
Acceptance Rate
50.0%

*/

#include <vector>

using namespace std;

class Solution {
  vector<int> memo;
  int r(bool started, int i /* index */, vector<int> &nums, int &k, int &sz) {
    if (i >= sz) return INT_MIN;

    if (memo[i] > INT_MIN) return memo[i];

    if (started) {
      int mx = INT_MIN;
      for (int j = 0; j <= k; ++j) {
        int cur = j + i;
        int take = nums[j] + r(true, cur + 1, nums, k, sz);
        mx = max(take, mx);
      }
      memo[i] = mx;
    } else {
      int take = nums[i] + r(true, i + 1, nums, k, sz);
      int leave = r(false, i + 1, nums, k, sz);
      memo[i] = max(take, leave);
    }
    return memo[i];
  }

 public:
  int constrainedSubsetSum(vector<int> &nums, int k) {
    int sz = nums.size();
    memo.resize(sz, INT_MIN);
    return r(false, 0, nums, k, sz);
    // dp + recursion
  }
};