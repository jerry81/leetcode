/*

1043. Partition Array for Maximum Sum
Medium
Topics
Companies
Hint
Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.



Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]
Example 2:

Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83
Example 3:

Input: arr = [1], k = 1
Output: 1


Constraints:

1 <= arr.length <= 500
0 <= arr[i] <= 109
1 <= k <= arr.length
Seen this question in a real interview before?
1/4
Yes
No
Accepted
93.8K
Submissions
129.1K
Acceptance Rate
72.6%

*/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
vector<int> dp;
int r(int idx, vector<int>& arr, int &k, int &sz) {
  if (idx >= sz) return 0;

  if (dp[idx] >= 0) return dp[idx];

  int mx = arr[idx];
  int cur_sum = arr[idx];
  int cur_mx = arr[idx] + r(idx+1, arr, k, sz);
  for (int i = 1; i < k; ++i) {
    if (i+idx >= sz) break;

    mx = max(mx,arr[idx+i]);
    cur_sum = (i+1)*mx;
    cur_mx = max(cur_mx,cur_sum+r(idx+i+1,arr,k,sz));
  }
  return dp[idx] = cur_mx;
}
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
      dp.resize(501,-1);
      int sz = arr.size();
      return r(0,arr,k,sz);
    }
};