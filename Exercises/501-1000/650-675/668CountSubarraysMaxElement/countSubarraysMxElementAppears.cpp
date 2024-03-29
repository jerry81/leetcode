/*


2962. Count Subarrays Where Max Element Appears at Least K Times
Medium
Topics
Companies
You are given an integer array nums and a positive integer k.

Return the number of subarrays where the maximum element of nums appears at
least k times in that subarray.

A subarray is a contiguous sequence of elements within an array.



Example 1:

Input: nums = [1,3,2,3,3], k = 2
Output: 6
Explanation: The subarrays that contain the element 3 at least 2 times are:
[1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3]. Example 2:

Input: nums = [1,4,2,1], k = 3
Output: 0
Explanation: No subarray contains the element 4 at least 3 times.


Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 106
1 <= k <= 105
Seen this question in a real interview before?
1/4
Yes
No
Accepted
41.7K
Submissions
77.4K
Acceptance Rate
53.8%

*/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  long long countSubarrays(vector<int>& nums, int k) {
    // map to get max.
    int mx = *max_element(nums.begin(), nums.end());
    // get indexes where max appears
    vector<int> indexes;
    int sz = nums.size();
    for (int i = 0; i < sz; ++i) {
      if (nums[i] == mx) indexes.push_back(i);
    }

    // for each subarray where enough indexes are included
    // add the possible prefixes

    long long res = 0;
    int firstidx = 0;
    if (indexes.size() < k - 1) return 0;

    int secondidx = k - 1;
    for (int i = 0; i < sz; ++i) {
      if (secondidx >= indexes.size()) break;

      if (i > indexes[firstidx]) {
        firstidx++;
        secondidx++;
        if (secondidx >= indexes.size()) break;
      }

      int range = sz - indexes[secondidx];
      res += range;
    }

    return res;
  }
};