/*

1248. Count Number of Nice Subarrays
Medium
Topics
Companies
Hint
Given an array of integers nums and an integer k. A continuous subarray is
called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.



Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16


Constraints:

1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length
Seen this question in a real interview before?
1/5
Yes
No
Accepted
184.5K
Submissions
268.4K
Acceptance Rate
68.7%

*/

class Solution {
 public:
  int numberOfSubarrays(vector<int>& nums, int k) {
    // dp
    int sz = nums.size();
    vector<int> prefix;

    int curcount = 0;
    //  vector<vector<int>> memo(sz, vector<int>(sz, -1));
    for (int i = 0; i < sz; ++i) {
      if (nums[i] % 2 == 1) ++curcount;
      prefix.push_back(curcount);
    }
    int left = -1;
    int right = 0;
    int res = 0;
    while (right < sz) {
      int leftcnt = 0;
      if (left >= 0) {
        leftcnt = prefix[left];
      }
      int cur = prefix[right] - leftcnt;
      if (cur == k) res++;
      if (cur > k) {
        left+=1;
      } else  {
        right+=1;
      }
    }

    return res;
  }
};