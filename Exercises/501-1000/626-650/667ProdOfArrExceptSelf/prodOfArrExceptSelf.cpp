/*

238. Product of Array Except Self
Medium
Topics
Companies
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.



Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]


Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.


Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)

Seen this question in a real interview before?
1/4
Yes
No
Accepted
2.4M
Submissions
3.6M
Acceptance Rate
65.5%

*/

#include <vector>

using namespace std;

class Solution {
vector<int> zeroidx;
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      long long int totalProd = 1;
      long long int nonZeroProd = 1;
      for (int i: nums) {

        if (i == 0) {
          zeroidx.push_back(i);
        } else {
          nonZeroProd*=i;
        }
        totalProd *= i;
      }
      vector<int> res;
      bool multiplez = zeroidx.size() > 0;
      for (int i: nums) {
        if (i == 0) {
          if (multiplez) {
            res.push_back(0);
          } else {
            res.push_back(nonZeroProd);
          }
        } else {
          res.push_back( totalProd/i);
        }
      }
      return res;

    }
};