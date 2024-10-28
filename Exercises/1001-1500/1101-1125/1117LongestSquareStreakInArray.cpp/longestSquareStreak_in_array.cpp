/*
2501. Longest Square Streak in an Array
Medium
Topics
Companies
Hint
You are given an integer array nums. A subsequence of nums is called a square streak if:

The length of the subsequence is at least 2, and
after sorting the subsequence, each element (except the first element) is the square of the previous number.
Return the length of the longest square streak in nums, or return -1 if there is no square streak.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.



Example 1:

Input: nums = [4,3,6,16,8,2]
Output: 3
Explanation: Choose the subsequence [4,16,2]. After sorting it, it becomes [2,4,16].
- 4 = 2 * 2.
- 16 = 4 * 4.
Therefore, [4,16,2] is a square streak.
It can be shown that every subsequence of length 4 is not a square streak.
Example 2:

Input: nums = [2,3,5,6,7]
Output: -1
Explanation: There is no square streak in nums so return -1.


Constraints:

2 <= nums.length <= 105
2 <= nums[i] <= 105
Seen this question in a real interview before?
1/5
Yes
No
Accepted
35.7K
Submissions
81.1K
Acceptance Rate
44.0%
*/


#include <vector>

using namespace std;

class Solution {
int MAX_ROOT = sqrt(100000) + 1;
public:
    int longestSquareStreak(vector<int>& nums) {
      vector<bool> lookup(100001, false);
      for (int n: nums) {
        lookup[n] = true;
      }
      vector<int> sorted = nums;
      sort(sorted.begin(), sorted.end());
      int longest = -1;
      for (int i: sorted) {
        int base = i;
        int pw = 1;
        while (MAX_ROOT > base && lookup[pow(base,2)]) {
          pw+=1;
          base = pow(base,2);
        }
        longest = max(longest, pw);
      }
      return longest > 1 ? longest : -1;
    }
};