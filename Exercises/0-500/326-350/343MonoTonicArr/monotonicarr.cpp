/*

896. Monotonic Array
Easy
2.3K
69
Companies
An array is monotonic if it is either monotone increasing or monotone decreasing.

An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].

Given an integer array nums, return true if the given array is monotonic, or false otherwise.



Example 1:

Input: nums = [1,2,2,3]
Output: true
Example 2:

Input: nums = [6,5,4,4]
Output: true
Example 3:

Input: nums = [1,3,2]
Output: false


Constraints:

1 <= nums.length <= 105
-105 <= nums[i] <= 105
Accepted
289.7K
Submissions
492K
Acceptance Rate
58.9%

*/

#include <vector>

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
      bool identified = false;
      bool increasing = false;
      for (int i = 0; i < nums.size()-1; ++i) {
        int cur = nums[i];
        int next = nums[i+1];
        if (next == cur) {
          continue;
        }
        if (next < cur) {
          if (!identified) {
            identified = true;
            continue;
          }

          if (increasing) return false;
        } else {
          if (!identified) {
            identified = true;
            increasing = true;
            continue;
          }

          if (!increasing) return false;
        }
      }
      return true;
    }
};