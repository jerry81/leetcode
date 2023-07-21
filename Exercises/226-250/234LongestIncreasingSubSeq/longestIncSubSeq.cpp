/*

Premium
4

avatar
673. Number of Longest Increasing Subsequence
Medium
5.5K
226
Companies
Given an integer array nums, return the number of longest increasing
subsequences.

Notice that the sequence has to be strictly increasing.



Example 1:

Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3,
5, 7]. Example 2:

Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of the longest increasing subsequence is 1, and there
are 5 increasing subsequences of length 1, so output 5.


Constraints:

1 <= nums.length <= 2000
-106 <= nums[i] <= 106
Accepted
167.8K
Submissions
374.5K
Acceptance Rate
44.8%

*/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  unordered_map<int, int> lookup;
  int r(vector<int>& nums, int idx, int last) {
    if (idx < 0) return 0;
    if (lookup.find(idx) != lookup.end()) return lookup[idx];
    if (idx >= nums.size()-1) return 1;
    int cur = nums[idx];
    if (cur < last) {
      // take or leave
      lookup[idx] = max()
    } else {
    }
  }

 public:
  int findNumberOfLIS(vector<int>& nums) {
    int ret = 1;
    int mx = 0;
    for (int i = nums.size()-1; i >= 0; --i) {
      int maxIS = r(nums, i);
      if (maxIS > mx) {
        mx = maxIS;
        ret = 1;
      }
      if (maxIS == mx) {
        ret++;
      }
    }
    return ret;
  }
};

// increasing subsequence from i
// memoize the results?
// brute force each index