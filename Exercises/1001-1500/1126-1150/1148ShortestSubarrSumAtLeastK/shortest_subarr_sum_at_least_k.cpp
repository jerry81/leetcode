/*

862. Shortest Subarray with Sum at Least K
Hard
Topics
Companies
Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.

A subarray is a contiguous part of an array.



Example 1:

Input: nums = [1], k = 1
Output: 1
Example 2:

Input: nums = [1,2], k = 4
Output: -1
Example 3:

Input: nums = [2,-1,2], k = 3
Output: 3


Constraints:

1 <= nums.length <= 105
-105 <= nums[i] <= 105
1 <= k <= 109
Seen this question in a real interview before?
1/5
Yes
No
Accepted
111.4K
Submissions
417.5K
Acceptance Rate
26.7%

*/

#include <vector>
#include <queue>

using namespace std;


class Solution {
  struct ComparePQ {
    bool operator()(pair<int,int> a, pair<int,int> b) { return a.first < b.first; }
  };
public:
    int shortestSubarray(vector<int>& nums, int k) {
      int n = nums.size();
      priority_queue<pair<int,int>, vector<pair<int,int>>, ComparePQ> pq;
      int cursum = 0;
      int res = INT_MAX;
      for (int i = 0; i < n; ++i) {
        cursum+=nums[i];
        pq.push({cursum, i});
        if (cursum >= k) res = min(res, i+1);

        while (cursum-pq.top().first >= k) {
          res = min(res, i - pq.top().second + 1);
          pq.pop();
        }
      }
      return res;
    }
};

// brute force:
// test every subarr
// two loops
// start and end pos

// possible improvement two pointer
// dp
// prefix sums (for fast subarr lookup )
// so if i were to pinpoint subarray[1..1]
// prefix_sums[1] - prefix_sums[0]
// ps[2] = [0..2]
// ps[1] = [0..1]
// ps[2] - ps[1] = [2..2]
// ps[2]-ps[0] = 1..2