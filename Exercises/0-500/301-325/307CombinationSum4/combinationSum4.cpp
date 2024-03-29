/*

377. Combination Sum IV
Medium
6.2K
596
Companies
Given an array of distinct integers nums and a target integer target, return the
number of possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.



Example 1:

Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
Example 2:

Input: nums = [9], target = 3
Output: 0


Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 1000
All the elements of nums are unique.
1 <= target <= 1000


Follow up: What if negative numbers are allowed in the given array? How does it
change the problem? What limitation we need to add to the question to allow
negative numbers?

Accepted
386.8K
Submissions
737K
Acceptance Rate
52.5%

*/

#include <vector>

using namespace std;

class Solution {
  int r(int remaining, vector<int>& dp, vector<int>& sorted) {
    long long count = 0;
    for (int i : sorted) {
      if (i == remaining) count += 1;

      if (i > remaining) break;

      long long lookup = dp[remaining - i];
      long long add = lookup >= 0 ? lookup : r(remaining - i, dp, sorted);
      count += add;
    }
    return count;
  }

 public:
  int combinationSum4(vector<int>& nums, int target) {
    // analysis
    // dp + recursion probably
    // base case - options > than target then return 0
    // sort to optimize breaking out
    vector<int> sorted = nums;
    vector<int> dp(target + 1, -1);
    sort(sorted.begin(), sorted.end());
    for (int i = 1; i <= target; ++i)
      if (dp[i] < 0) dp[i] = r(i, dp, sorted);
    return dp[target];
  }
};