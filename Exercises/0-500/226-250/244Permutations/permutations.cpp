/*

46. Permutations
Medium
16.7K
268
Companies
Given an array nums of distinct integers, return all the possible permutations.
You can return the answer in any order.



Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]


Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
Accepted
1.7M
Submissions
2.2M
Acceptance Rate
76.4%

*/

#include <vector>

using namespace std;

class Solution {
  vector<vector<int>> res;
  void dfs(vector<int> cur, vector<int> remain) {
    if (remain.empty()) res.push_back(cur);

    for (int i = 0; i < remain.size(); ++i) {
      vector<int> cpy = remain;
      vector<int> cpy2 = cur;
      cpy2.push_back(cpy[i]);
      cpy.erase(cpy.begin() + i);
      dfs(cpy2, cpy);
    }
  }

 public:
  vector<vector<int>> permute(vector<int>& nums) {
    dfs({}, nums);
    return res;
  }
};

/*

012
021
102
120
201
210

0123 pivot at size-2 ?
0132 swap from size-1 to pivot
0213 pivot moves back - swap pivot and size-1 and reverse
0231 swap size-1 and size-2 (loop to pivot)
0312 swap & reverse
0321
1023
1032
1203
1230
1302
1320

OR

dfs

[0]
[01] [02] [03]
[012] [013]
[0123]
[1]
*/