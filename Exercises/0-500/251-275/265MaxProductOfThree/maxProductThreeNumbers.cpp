/*

628. Maximum Product of Three Numbers
Easy
3.9K
634
Companies
Given an integer array nums, find three numbers whose product is maximum and return the maximum product.



Example 1:

Input: nums = [1,2,3]
Output: 6
Example 2:

Input: nums = [1,2,3,4]
Output: 24
Example 3:

Input: nums = [-1,-2,-3]
Output: -6


Constraints:

3 <= nums.length <= 104
-1000 <= nums[i] <= 1000

*/

#include <vector>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
      int product = 1;
      int product2 = 1;
      sort(nums.begin(), nums.end());
      for (int i = nums.size()-3; i < nums.size(); ++i) {
        product*=nums[i];
      }
      product2 = nums[0] * nums[1] * nums.back();
      return max(product, product2);
    }
};