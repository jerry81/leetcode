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

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  unordered_map<int, vector<int>> grouped;

 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    int sz = nums.size();
    vector<int> res;
    int mxSz = sz;
    for (int r = 0; r < sz; ++r) {
      for (int d = 0; d <= r; ++d) {
        int cr = r - d;
        vector<int> v = nums[cr];
        mxSz = max(mxSz, (int)v.size());
        if (v.size() <= d) continue;

        res.push_back(nums[cr][d]);
      }
    }
    for (int sc = 1; sc < mxSz; ++sc) {
      int diff = 0;
      for (int sr = sz - 1; sr >= 0; --sr) {
        vector<int> row = nums[sr];
        int curc = diff + sc;
        diff++;
        if (curc >= row.size()) continue;
        res.push_back(nums[sr][curc]);
      }
    }

    return res;
  }
};

// 00 r = 0
// 10 01 r = 1   r-d,d
// 20 11 02 r = 2
// 30 12 21 03
// 31 22 13   3 to 1, 1 to 3
// 32 23  3 to 2, 2 to 3
// 33  3 to 3

/*
1 2 3 4
5 6 7 8
9 0 1 2
3 4 5 6
*/