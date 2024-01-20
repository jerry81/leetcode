/*

907. Sum of Subarray Minimums
Medium
Topics
Companies
Given an array of integers arr, find the sum of min(b), where b ranges over
every (contiguous) subarray of arr. Since the answer may be large, return the
answer modulo 109 + 7.



Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation:
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4],
[3,1,2,4]. Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1. Sum is 17. Example 2:

Input: arr = [11,81,94,43,3]
Output: 444


Constraints:

1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104
Seen this question in a real interview before?
1/4
Yes
No
Accepted
166.8K
Submissions
474.4K
Acceptance Rate
35.2%

*/

#include <cmath>
#include <vector>

using namespace std;

class Solution {
 public:
  int sumSubarrayMins(vector<int>& arr) {
    // feels like a dp problem
    // 00, 01, 02... the mins get smaller
    // one comparison each time
    // 11, 12, 13... - 11 is 01 wihout 0 OR just 11 is the one item.
    int sz = arr.size();
    long long res = 0;
    const int MOD = pow(10, 9) + 7;

    for (int i = 0; i < sz; ++i) {
      long long mn = INT_MAX;
      for (int j = i; j < sz; ++j) {
        mn = min(mn, (long long)arr[j]);
        res += mn;
        res %= MOD;
      }
    }
    return res;
  }
};

// YEP, TLE...