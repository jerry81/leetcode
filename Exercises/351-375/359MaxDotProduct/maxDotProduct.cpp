/*

1458. Max Dot Product of Two Subsequences
Hard
875
18
Companies
Given two arrays nums1 and nums2.

Return the maximum dot product between non-empty subsequences of nums1 and nums2
with the same length.

A subsequence of a array is a new array which is formed from the original array
by deleting some (can be none) of the characters without disturbing the relative
positions of the remaining characters. (ie, [2,3,5] is a subsequence of
[1,2,3,4,5] while [1,5,3] is not).



Example 1:

Input: nums1 = [2,1,-2,5], nums2 = [3,0,-6]
Output: 18
Explanation: Take subsequence [2,-2] from nums1 and subsequence [3,-6] from
nums2. Their dot product is (2*3 + (-2)*(-6)) = 18. Example 2:

Input: nums1 = [3,-2], nums2 = [2,-6,7]
Output: 21
Explanation: Take subsequence [3] from nums1 and subsequence [7] from nums2.
Their dot product is (3*7) = 21.
Example 3:

Input: nums1 = [-1,-1], nums2 = [1,1]
Output: -1
Explanation: Take subsequence [-1] from nums1 and subsequence [1] from nums2.
Their dot product is -1.


Constraints:

1 <= nums1.length, nums2.length <= 500
-1000 <= nums1[i], nums2[i] <= 1000
Accepted
25.4K
Submissions
50.7K
Acceptance Rate
50.2%

*/

#include <vector>

using namespace std;

class Solution {
  vector<vector<int>> memo;
  int r(int i1, int i2, vector<int>& nums1, vector<int>& nums2) {}

 public:
  int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    // dp try all subsequences?
    // greedy?
    int mx1 = *max_element(nums1.begin(), nums1.end());
    int mn1 = *min_element(nums1.begin(), nums1.end());
    int mx2 = *max_element(nums2.begin(), nums2.end());
    int mn2 = *min_element(nums2.begin(), nums2.end());
    if (mx1 < 0 && mn2 > 0) return mx1 * mn2;

    if (mx2 < 0 && mn1 > 0) return mx2 * mn1;

    return r(0,0,nums1,nums2);
  }
};