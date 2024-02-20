/*

1027. Longest Arithmetic Subsequence
Medium
3.1K
142
Companies
Given an array nums of integers, return the length of the longest arithmetic
subsequence in nums.

Note that:

A subsequence is an array that can be derived from another array by deleting
some or no elements without changing the order of the remaining elements. A
sequence seq is arithmetic if seq[i + 1] - seq[i] are all the same value (for 0
<= i < seq.length - 1).


Example 1:

Input: nums = [3,6,9,12]
Output: 4
Explanation:  The whole array is an arithmetic sequence with steps of length
= 3. Example 2:

Input: nums = [9,4,7,2,10]
Output: 3
Explanation:  The longest arithmetic subsequence is [4,7,10].
Example 3:

Input: nums = [20,1,15,3,10,5,8]
Output: 4
Explanation:  The longest arithmetic subsequence is [20,15,10,5].


Constraints:

2 <= nums.length <= 1000
0 <= nums[i] <= 500
Accepted
108.7K
Submissions
231.3K
Acceptance Rate
47.0%

*/

#include <vector>

using namespace std;

class Solution {
  vector<vector<int>> lookup;

 public:
  int longestArithSeqLength(vector<int>& nums) {
    if (nums.empty()) return 0;

    if (nums.size() == 1) return 1;

    int res = 2;
    lookup.resize(501, vector<int>(0));
    for (int i = 0; i < nums.size(); ++i) {
      int num = nums[i];
      lookup[num].push_back(i);
    }
    for (int i = 0; i < nums.size() - 1; ++i) {
      for (int j = i+1; j < nums.size(); ++j) {
        int cur = 2;
        int curnum = nums[j];

        int diff = curnum - nums[i];
        int k = j;
        while (k < nums.size()) {
          int expect = curnum + diff;
          if (expect < 0) break;


          if (lookup[expect].empty()) break;

          auto ptr = lower_bound(lookup[expect].begin(), lookup[expect].end(), k+1);


          if (ptr==lookup[expect].end()) break;

          curnum = nums[*ptr];
          ++cur;

          if (cur > res) res = cur;

          k = *ptr;
        }
      }
    }
    return res;
  }
};
