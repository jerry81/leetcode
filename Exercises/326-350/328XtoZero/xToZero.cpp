/*

1658. Minimum Operations to Reduce X to Zero
Medium
4.2K
83
Companies
You are given an integer array nums and an integer x. In one operation, you can
either remove the leftmost or the rightmost element from the array nums and
subtract its value from x. Note that this modifies the array for future
operations.

Return the minimum number of operations to reduce x to exactly 0 if it is
possible, otherwise, return -1.



Example 1:

Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x
to zero. Example 2:

Input: nums = [5,6,7,8,9], x = 4
Output: -1
Example 3:

Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the
first two elements (5 operations in total) to reduce x to zero.


Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 104
1 <= x <= 109
Accepted
117.6K
Submissions
310.8K
Acceptance Rate
37.8%

*/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int minOperations(vector<int>& nums, int x) {
    // prefix sums forward
    unordered_map<int, int> index1;
    unordered_map<int, int> index2;

    if (nums.empty()) return -1;
    int n = nums.size();
    int res = INT_MAX;

    vector<int> pf;
    int curSum = 0;
    for (int i = 0; i < n; ++i) {
      curSum += nums[i];
      index1[curSum] = i + 1;  // i+1 ops to get to curSum
      pf.push_back(curSum);
      if (curSum > x) break;
    }
    curSum = 0;
    vector<int> rf;
    for (int i = n - 1; i >= 0; --i) {
      curSum += nums[i];
      rf.push_back(curSum);
      index2[curSum] = n - i;  // i+1 ops to get to curSum
      if (curSum == x) {
        res = min(res, n - i);
        break;
      }
      if (curSum > x) break;

      int diff = x - curSum;
      if (index1.find(diff) != index1.end()) {
        res = max(res, index1[diff] + i + 1);
      }
    }

    for (int i = 0; i < pf.size(); ++i) {
      int cur = pf[i];

      if (cur == x) {
        res = max(res, i + 1);
        break;
      }

      int diff = x - cur;

      if (index2.find(diff) != index2.end()) {
        res = max(res, index2[diff] + i + 1);
      }
    }

    return res < INT_MAX ? res : -1;
  }
};