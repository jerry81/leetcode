/*

446. Arithmetic Slices II - Subsequence
Hard
2.5K
121
Companies
Given an integer array nums, return the number of all the arithmetic
subsequences of nums.

A sequence of numbers is called arithmetic if it consists of at least three
elements and if the difference between any two consecutive elements is the same.

For example, [1, 3, 5, 7, 9], [7, 7, 7, 7], and [3, -1, -5, -9] are arithmetic
sequences. For example, [1, 1, 2, 5, 7] is not an arithmetic sequence. A
subsequence of an array is a sequence that can be formed by removing some
elements (possibly none) of the array.

For example, [2,5,10] is a subsequence of [1,2,1,2,4,1,5,10].
The test cases are generated so that the answer fits in 32-bit integer.



Example 1:

Input: nums = [2,4,6,8,10]
Output: 7
Explanation: All arithmetic subsequence slices are:
[2,4,6]
[4,6,8]
[6,8,10]
[2,4,6,8]
[4,6,8,10]
[2,4,6,8,10]
[2,6,10]
Example 2:

Input: nums = [7,7,7,7,7]
Output: 16
Explanation: Any subsequence of this array is arithmetic.


Constraints:

1  <= nums.length <= 1000
-231 <= nums[i] <= 231 - 1
Accepted
84K
Submissions
175.2K
Acceptance Rate
47.9%

*/
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    int sz = nums.size();
    vector<unordered_map<long long, int>> memo(sz, unordered_map<long long int, int>());
    int res = 0;
    for (int i = sz - 1; i >= 0; --i) {
      int anchor = nums[i];
      for (int j = i - 1; j >= 0; --j) {
        int comp = nums[j];
        long long diff = (long long)anchor - comp;

        if (memo[i].find(diff) == memo[i].end()) {
          memo[j][diff] += 1;
        } else {
          int prev = memo[i][diff];
          memo[j][diff] += 1 + memo[i][diff];
          res += prev;
        }
      }
    }
    return res;
  }
};