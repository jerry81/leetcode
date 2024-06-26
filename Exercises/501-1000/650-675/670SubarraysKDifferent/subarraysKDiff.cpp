/*


992. Subarrays with K Different Integers
Hard
Topics
Companies
Given an integer array nums and an integer k, return the number of good
subarrays of nums.

A good array is an array where the number of different integers in that array is
exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.



Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1],
[1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2] Example 2:

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3],
[2,1,3], [1,3,4].


Constraints:

1 <= nums.length <= 2 * 104
1 <= nums[i], k <= nums.length
Seen this question in a real interview before?
1/4
Yes
No
Accepted
146.6K
Submissions
247.2K
Acceptance Rate
59.3%

*/

#include <unordered_map>
#include <vector>

using namespace std;

// Essence: Figuring out The venn diagramm stuff (that items with exactly K distinct
// are the set of items with less than k minus minus the items with less than k-1);
class Solution {
 public:
  int subarraysWithKDistinct(vector<int>& nums, int k) {
    unordered_map<int, int> cur;
    int sz = nums.size();
    int uptok = 0;
    int starti = 0;
    int endi = 0;

    while (starti < sz && endi < sz) {
      cur[nums[endi]]++;

      while (cur.size() > k) {
        cur[nums[starti]]--;
        if (cur[nums[starti]] == 0) cur.erase(nums[starti]);
        starti++;
      }
      uptok += (endi - starti + 1);
      endi++;
    }

    int notinclk = 0;
    starti = 0;
    endi = 0;
    int k2 = k-1;
    cur.clear();
    while (starti < sz && endi < sz) {
      cur[nums[endi]]++;
      while (cur.size() > k2) {
        cur[nums[starti]]--;
        if (cur[nums[starti]] == 0) cur.erase(nums[starti]);
        starti++;
      }
      notinclk += (endi - starti + 1);
      endi++;
    }


    return uptok - notinclk;
  }
};