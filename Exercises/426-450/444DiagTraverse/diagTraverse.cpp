/*

1424. Diagonal Traverse II
Medium
1.1K
92
Companies
Given a 2D integer array nums, return all elements of nums in diagonal order as
shown in the below images.



Example 1:


Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,4,2,7,5,3,8,6,9]
Example 2:


Input: nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
Output: [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]


Constraints:

1 <= nums.length <= 105
1 <= nums[i].length <= 105
1 <= sum(nums[i].length) <= 105
1 <= nums[i][j] <= 105
Accepted
55K
Submissions
107.4K
Acceptance Rate
51.2%

*/

#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    int sz = nums.size();
    vector<int> res;
    for (int r = 0; r < sz; ++r) {
      for (int d = 0; d <= r; ++d) {
        int cr = r - d;
        vector<int> v = nums[cr];
        if (v.size() <= d) continue;

        res.push_back(nums[cr][d]);
      }
    }
    return res;
  }
};

// 00 r = 0
// 10 01 r = 1   r-d,d
//
// 20 11 02 r = 2
// 21 12
// 22