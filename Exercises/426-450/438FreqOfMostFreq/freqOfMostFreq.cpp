/*

1838. Frequency of the Most Frequent Element
Medium
3.1K
84
Companies
The frequency of an element is the number of times it occurs in an array.

You are given an integer array nums and an integer k. In one operation, you can
choose an index of nums and increment the element at that index by 1.

Return the maximum possible frequency of an element after performing at most k
operations.



Example 1:

Input: nums = [1,2,4], k = 5
Output: 3
Explanation: Increment the first element three times and the second element two
times to make nums = [4,4,4]. 4 has a frequency of 3. Example 2:

Input: nums = [1,4,8,13], k = 5
Output: 2
Explanation: There are multiple optimal solutions:
- Increment the first element three times to make nums = [4,4,8,13]. 4 has a
frequency of 2.
- Increment the second element four times to make nums = [1,8,8,13]. 8 has a
frequency of 2.
- Increment the third element five times to make nums = [1,4,13,13]. 13 has a
frequency of 2. Example 3:

Input: nums = [3,9,6], k = 2
Output: 1


Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105
1 <= k <= 105
Accepted
60.9K
Submissions
150.7K
Acceptance Rate
40.4%

*/

#include <vector>

using namespace std;

class Solution {
 public:
  int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    // brute force - try each
    int res = 0;
    int sz = nums.size();
    if (sz == 1) return 1;
    int accum = 0;
    int rptr = sz - 1;
    int lptr = sz - 1;
    while (lptr >= 0 && rptr > 0) {
      // check how far left lptr can go
      int rv = nums[rptr];
      int nl = lptr - 1;
      int nlv = nums[nl];
      int ops = rv - nlv;
      int nxtAccum = accum + ops;
      if (nxtAccum > k) {
        // lptr reached the end already
        int spread = rptr - lptr;
        res = max(res, spread);
        // must update accum

        rptr--;
        int nrv = nums[rptr];
        int diff = rv - nrv;
        accum -= diff * spread;
        lptr = min(lptr, rptr);
      }
    }

    return res;
  }
};