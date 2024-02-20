/*

34. Find First and Last Position of Element in Sorted Array
Medium
18.8K
452
Companies
Given an array of integers nums sorted in non-decreasing order, find the
starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]


Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
Accepted
1.7M
Submissions
4M
Acceptance Rate
42.7%

*/

#include <vector>

using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> notFound = {-1, -1};
        int n = nums.size(); // new var

        if (n == 0) return notFound;

        int left = lower_bound(nums.begin(), nums.end(), target) - nums.begin(); // same as distance

        if (left == n || nums[left] != target) return notFound; // handles target doesnt exist case
          // lowerbaund is less than or equal to.

        int right = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        // upperbound is strictly greater than

        return {left, right};
    }
};