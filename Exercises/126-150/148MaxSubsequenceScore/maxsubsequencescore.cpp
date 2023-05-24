/*

2542. Maximum Subsequence Score
Medium
665
32
Companies
You are given two 0-indexed integer arrays nums1 and nums2 of equal length n and a positive integer k. You must choose a subsequence of indices from nums1 of length k.

For chosen indices i0, i1, ..., ik - 1, your score is defined as:

The sum of the selected elements from nums1 multiplied with the minimum of the selected elements from nums2.
It can defined simply as: (nums1[i0] + nums1[i1] +...+ nums1[ik - 1]) * min(nums2[i0] , nums2[i1], ... ,nums2[ik - 1]).
Return the maximum possible score.

A subsequence of indices of an array is a set that can be derived from the set {0, 1, ..., n-1} by deleting some or no elements.



Example 1:

Input: nums1 = [1,3,3,2], nums2 = [2,1,3,4], k = 3
Output: 12
Explanation:
The four possible subsequence scores are:
- We choose the indices 0, 1, and 2 with score = (1+3+3) * min(2,1,3) = 7.
- We choose the indices 0, 1, and 3 with score = (1+3+2) * min(2,1,4) = 6.
- We choose the indices 0, 2, and 3 with score = (1+3+2) * min(2,3,4) = 12.
- We choose the indices 1, 2, and 3 with score = (3+3+2) * min(1,3,4) = 8.
Therefore, we return the max score, which is 12.
Example 2:

Input: nums1 = [4,2,3,1,1], nums2 = [7,5,10,9,6], k = 1
Output: 30
Explanation:
Choosing index 2 is optimal: nums1[2] * nums2[2] = 3 * 10 = 30 is the maximum possible score.


Constraints:

n == nums1.length == nums2.length
1 <= n <= 105
0 <= nums1[i], nums2[j] <= 105
1 <= k <= n
Accepted
13.4K
Submissions
29.8K
Acceptance Rate
44.9%

*/

#include <vector>
#include <string>
using namespace std;

class Solution {
int _size;
long long _max = 0;
void maxScoreR(vector<int>& nums1, vector<int>& nums2, int k, int curk, long long accum, int mn, int idx) {

  if (curk > k) return;

  if (curk == k) {
    long long prod = accum * mn;
    _max = max(prod, _max);
    return;
  }

  if (idx >= _size) return;

  int cur1 = nums1[idx];
  int cur2 = nums2[idx];
  maxScoreR(nums1, nums2, k, curk+1, accum+cur1, min(mn, cur2), idx+1);
  maxScoreR(nums1, nums2, k, curk, accum, mn, idx+1);
}
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
      _size = nums1.size();
      maxScoreR(nums1, nums2, k, 0, 0, INT_MAX, 0);
      return _max;
    }
};

/*
  recursively knapsack
  stop when the required k or (size-k) met

  i think this will TLE terribly without any memoization

  we can break this down to 2 subproblems

  - maximize sum of nums1
  - maximize min of nums2

  - fail on
  nums1 [93,463,179,2488,619,2006,1561,137,53,1765,2304,1459,1768,450,1938,2054,466,331,670,1830,1550,1534,2164,1280,2277,2312,1509,867,2223,1482,2379,1032,359,1746,966,232,67,1203,2474,944,1740,1775,1799,1156,1982,1416,511,1167,1334,2344]
  nums2 [345,229,976,2086,567,726,1640,2451,1829,77,1631,306,2032,2497,551,2005,2009,1855,1685,729,2498,2204,588,474,693,30,2051,1126,1293,1378,1693,1995,2188,1284,1414,1618,2005,1005,1890,30,895,155,526,682,2454,278,999,1417,1682,995]
  k = 42.
  size just 50
  and this isn't even big case...
  big case would be n = 10^5..
*/