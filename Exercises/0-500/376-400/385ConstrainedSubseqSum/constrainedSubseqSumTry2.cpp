/*

1425. Constrained Subsequence Sum
Hard
1.3K
65
Companies
Given an integer array nums and an integer k, return the maximum sum of a
non-empty subsequence of that array such that for every two consecutive integers
in the subsequence, nums[i] and nums[j], where i < j, the condition j - i <= k
is satisfied.

A subsequence of an array is obtained by deleting some number of elements (can
be zero) from the array, leaving the remaining elements in their original order.



Example 1:

Input: nums = [10,2,-10,5,20], k = 2
Output: 37
Explanation: The subsequence is [10, 2, 5, 20].
Example 2:

Input: nums = [-1,-2,-3], k = 1
Output: -1
Explanation: The subsequence must be non-empty, so we choose the largest number.
Example 3:

Input: nums = [10,-2,-10,-5,20], k = 2
Output: 23
Explanation: The subsequence is [10, -2, -5, 20].


Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
Accepted
32.1K
Submissions
64.1K
Acceptance Rate
50.0%

*/

#include <queue>
#include <vector>

using namespace std;

struct State {
  int sum = 0;
  int ridx = 0;
  State(int s, int i) : sum(s), ridx(i){};
};

struct ComparePQ {
  bool operator()(State *a, State *b) { return a->sum < b->sum; }
};

class Solution {
 public:
  int constrainedSubsetSum(vector<int> &nums, int k) {
    int res = nums[0];
    priority_queue<State *, vector<State *>, ComparePQ> pq;
    pq.push(new State(nums[0], 0));
    for (int i = 1; i < nums.size(); ++i) {
      // pop all between i and i-k

      while (pq.top()->ridx < i - k) {
        pq.pop();
      }
      State *tp = pq.top();
      int addend = tp->sum;
      int cur = nums[i];
      if (addend > 0) {
        // use 0 instead
        cur += addend;
      }
      res = max(res, cur);
      pq.push(new State(cur, i));
    }
    return res;
  }
};