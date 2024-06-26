/*
995. Minimum Number of K Consecutive Bit Flips
Hard
Topics
Companies
You are given a binary array nums and an integer k.

A k-bit flip is choosing a subarray of length k from nums and simultaneously
changing every 0 in the subarray to 1, and every 1 in the subarray to 0.

Return the minimum number of k-bit flips required so that there is no 0 in the
array. If it is not possible, return -1.

A subarray is a contiguous part of an array.



Example 1:

Input: nums = [0,1,0], k = 1
Output: 2
Explanation: Flip nums[0], then flip nums[2].
Example 2:

Input: nums = [1,1,0], k = 2
Output: -1
Explanation: No matter how we flip subarrays of size 2, we cannot make the array
become [1,1,1]. Example 3:

Input: nums = [0,0,0,1,0,1,1,0], k = 3
Output: 3
Explanation:
Flip nums[0],nums[1],nums[2]: nums becomes [1,1,1,1,0,1,1,0]
Flip nums[4],nums[5],nums[6]: nums becomes [1,1,1,1,1,0,0,0]
Flip nums[5],nums[6],nums[7]: nums becomes [1,1,1,1,1,1,1,1]


Constraints:

1 <= nums.length <= 105
1 <= k <= nums.length
Seen this question in a real interview before?
1/5
Yes
No
Accepted
40.5K
Submissions
76.4K
Acceptance Rate
53.0%
*/

#include <vector>

using namespace std;

class Solution {
  int r(vector<int>& nums, int k) {
    for (int i : nums) {
      cout << i << endl;
    }
    if (nums.empty()) return 0;  // end case 1

    // end case 2 - k exceeds size
    if (k > nums.size()) return -1;

    // get first index that is 1 and flip

    int new_start = 0;
    while (new_start < k) {
      if (nums[new_start] == 1) break;

      new_start++;
    }
    for (int i = new_start; i < k; ++i) {
      nums[i] = nums[i] == 1 ? 0 : 1;
      if (nums[i] == 1) new_start+=1;
    }

    cout << "post" << endl;
    for (int i : nums) {
      cout << i << endl;
    }
    nums = vector<int>(nums.begin() + new_start, nums.end());
    int res = r(nums, k);
    if (res < 0) return res;
    return 1 + r(nums, k);
  };

 public:
  int minKBitFlips(vector<int>& nums, int k) {
    int cnt = 0;
    for (int i : nums) {
      if (i == 1) cnt++;
    }
    return r(nums, k);
  }
};
// recursive greedy?