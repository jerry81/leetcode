/*

2366. Minimum Replacements to Sort the Array
Hard
552
17
Companies
You are given a 0-indexed integer array nums. In one operation you can replace
any element of the array with any two elements that sum to it.

For example, consider nums = [5,6,7]. In one operation, we can replace nums[1]
with 2 and 4 and convert nums to [5,2,4,7]. Return the minimum number of
operations to make an array that is sorted in non-decreasing order.



Example 1:

Input: nums = [3,9,3]
Output: 2
Explanation: Here are the steps to sort the array in non-decreasing order:
- From [3,9,3], replace the 9 with 3 and 6 so the array becomes [3,3,6,3]
- From [3,3,6,3], replace the 6 with 3 and 3 so the array becomes [3,3,3,3,3]
There are 2 steps to sort the array in non-decreasing order. Therefore, we
return 2.

Example 2:

Input: nums = [1,2,3,4,5]
Output: 0
Explanation: The array is already in non-decreasing order. Therefore, we return
0.


Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
Accepted
13.2K
Submissions
30.1K
Acceptance Rate
43.7%


*/

#include <cmath>
#include <vector>

using namespace std;

class Solution {
 public:
  long long minimumReplacement(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return 0;  // edge case

    long long count = 0;
    int curMax = nums[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      int cur = nums[i];
      if (cur > curMax) {
        int divisions = ceil((double)cur / (double)curMax);
        count += (divisions - 1);
        curMax = divisions;
      } else {
        curMax = cur;
      }
    }
    return count;
  }
};
/*

brainstorm

iterate and find where rule breaks
note previous item and succeeding item
dp recursion to find possible replacements
3,9,3
3,[3,6] [4,5]
3,3,6,3   3,3,4,5,3
3,3,[2,4] no [3,3] yes          3,3,[1,3] [2,2] x stop early

official

greedy
go in REVERSE
because going forwards you may retroactively affect sorting of previously
traversed items how to chop greedily? max the leftmost and rightmost item after
breaking with hard constraint being <= right item e.g. right item 3, current 7
7/3 = 2.x
-> 3 items, highest 3, smallest 2 - doesn't matter which is which - 2 operations
wow ingenious - they fudge the calculation to optimize



*/