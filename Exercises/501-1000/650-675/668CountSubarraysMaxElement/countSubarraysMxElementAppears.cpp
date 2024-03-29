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
  unordered_map<int, int> freq;

 public:
  long long countSubarrays(vector<int>& nums, int k) {
    // map to get max.
    int mx = -1;
    int mxCnt = 0;
    for (int i : nums) {
      freq[i]++;
      if (freq[i] > mxCnt) {
        mxCnt = freq[i];
        mx = i;
      }
    }
    // get indexes where max appears
    vector<int> indexes;
    int sz = nums.size();
    for (int i = 0; i < sz; ++i) {
      if (nums[i] == mx) indexes.push_back(i);
    }

    long long res = 0;
    int ptr1 = 0;
    int ptr2 = 0;


    return res;
  }
};