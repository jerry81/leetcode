/*

456. 132 Pattern
Medium
6.1K
339
Companies
Given an array of n integers nums, a 132 pattern is a subsequence of three
integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k]
< nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.



Example 1:

Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.
Example 2:

Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
Example 3:

Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3,
0] and [-1, 2, 0].


Constraints:

n == nums.length
1 <= n <= 2 * 105
-109 <= nums[i] <= 109
Accepted
185.2K
Submissions
569.9K
Acceptance Rate
32.5%

*/

#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool find132pattern(vector<int>& nums) {
    // subsequence problem
    int s = nums.size();
    vector<int> mins;
    set<int> searchable;
    int curmin = INT_MAX;
    for (int i = 0; i < s; ++i) {
      int cur = nums[i];
      curmin = min(curmin, cur);
      mins.push_back(curmin);
    }
    for (int i = s - 1; i > 0; --i) {
      int prev = mins[i - 1];
      int cur = nums[i];

      searchable.insert(cur);

      if (prev >= cur) continue;

      auto pos = lower_bound(searchable.begin(), searchable.end(), cur);
            if (pos == searchable.begin()) continue;

            pos--;

            if (*pos < cur && prev < *pos) return true;




    }
    return false;
  }
};