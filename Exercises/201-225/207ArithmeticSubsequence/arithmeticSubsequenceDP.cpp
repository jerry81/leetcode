/*

1027. Longest Arithmetic Subsequence
Medium
3.1K
142
Companies
Given an array nums of integers, return the length of the longest arithmetic
subsequence in nums.

Note that:

A subsequence is an array that can be derived from another array by deleting
some or no elements without changing the order of the remaining elements. A
sequence seq is arithmetic if seq[i + 1] - seq[i] are all the same value (for 0
<= i < seq.length - 1).


Example 1:

Input: nums = [3,6,9,12]
Output: 4
Explanation:  The whole array is an arithmetic sequence with steps of length
= 3. Example 2:

Input: nums = [9,4,7,2,10]
Output: 3
Explanation:  The longest arithmetic subsequence is [4,7,10].
Example 3:

Input: nums = [20,1,15,3,10,5,8]
Output: 4
Explanation:  The longest arithmetic subsequence is [20,15,10,5].


Constraints:

2 <= nums.length <= 1000
0 <= nums[i] <= 500
Accepted
108.7K
Submissions
231.3K
Acceptance Rate
47.0%

*/


#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  vector<unordered_map<int, int>> dp;

 public:
  int longestArithSeqLength(vector<int>& nums) {

    if (nums.empty()) return 0;

    if (nums.size() == 1) return 1;
    int ret = 0;
    dp.resize(nums.size(), unordered_map<int, int>());
    for (int i = 1; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        int right = nums[i];

        int left = nums[j];
        int diff = right - left;
        if (dp[j].find(diff) != dp[j].end()) {
          dp[i][diff] = 1+dp[j][diff];
        } else {
          dp[i][diff] = 2;
        }
        ret = max(ret, dp[i][diff]);
      }
    }

    return ret;
  }
};