/*

2009. Minimum Number of Operations to Make Array Continuous
Hard
839
8
Companies
You are given an integer array nums. In one operation, you can replace any
element in nums with any integer.

nums is considered continuous if both of the following conditions are fulfilled:

All elements in nums are unique.
The difference between the maximum element and the minimum element in nums
equals nums.length - 1. For example, nums = [4, 2, 5, 3] is continuous, but nums
= [1, 2, 3, 5, 6] is not continuous.

Return the minimum number of operations to make nums continuous.



Example 1:

Input: nums = [4,2,5,3]
Output: 0
Explanation: nums is already continuous.
Example 2:

Input: nums = [1,2,3,5,6]
Output: 1
Explanation: One possible solution is to change the last element to 4.
The resulting array is [1,2,3,5,4], which is continuous.
Example 3:

Input: nums = [1,10,100,1000]
Output: 3
Explanation: One possible solution is to:
- Change the second element to 2.
- Change the third element to 3.
- Change the fourth element to 4.
The resulting array is [1,2,3,4], which is continuous.


Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
Accepted
13.3K
Submissions
29K
Acceptance Rate
45.9%

*/

#include <vector>

using namespace std;

class Solution {
 public:
  int minOperations(vector<int>& nums) {
    int s = nums.size();
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    int res = INT_MAX;
    for (int i: nums) {
      int ops = s;
      int mx = i + s - 1;
      auto a = lower_bound(nums.begin(), nums.end(), mx);
      ops -= (a-nums.begin());
      res = min(res,ops);
    }

    return res;
  }
};