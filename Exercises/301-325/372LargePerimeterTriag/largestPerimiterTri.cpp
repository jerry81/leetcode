/*

976. Largest Perimeter Triangle
Easy
2.9K
396
Companies
Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.



Example 1:

Input: nums = [2,1,2]
Output: 5
Explanation: You can form a triangle with three side lengths: 1, 2, and 2.
Example 2:

Input: nums = [1,2,1,10]
Output: 0
Explanation:
You cannot use the side lengths 1, 1, and 2 to form a triangle.
You cannot use the side lengths 1, 1, and 10 to form a triangle.
You cannot use the side lengths 1, 2, and 10 to form a triangle.
As we cannot use any three side lengths to form a triangle of non-zero area, we return 0.


Constraints:

3 <= nums.length <= 104
1 <= nums[i] <= 106
Accepted
218.3K
Submissions
396.5K
Acceptance Rate
55.0%

*/

#include <vector>
using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
      // rule of a triangle
      // a+b > c
      // sort(nums.begin(),nums.end(), greater<int>());
      int res = 0;
      int s = nums.size();
      for (int i = 0; i < s-2; ++i) {
        for (int j = i+1; j < s-1; ++j) {
          for (int k = j+1; k < s-2; ++k) {
            if (nums[i] < nums[j]+nums[k]) {
               res = max(res, nums[i]+nums[j]+nums[k]);
            }
          }
        }
      }
      return res;
    }
};