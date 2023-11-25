/*

1685. Sum of Absolute Differences in a Sorted Array
Medium
1.2K
35
Companies
You are given an integer array nums sorted in non-decreasing order.

Build and return an integer array result with the same length as nums such that
result[i] is equal to the summation of absolute differences between nums[i] and
all the other elements in the array.

In other words, result[i] is equal to sum(|nums[i]-nums[j]|) where 0 <= j <
nums.length and j != i (0-indexed).



Example 1:

Input: nums = [2,3,5]
Output: [4,3,5]
Explanation: Assuming the arrays are 0-indexed, then
result[0] = |2-2| + |2-3| + |2-5| = 0 + 1 + 3 = 4,
result[1] = |3-2| + |3-3| + |3-5| = 1 + 0 + 2 = 3,
result[2] = |5-2| + |5-3| + |5-5| = 3 + 2 + 0 = 5.
Example 2:

Input: nums = [1,4,6,8,10]
Output: [24,15,13,15,21]


Constraints:

2 <= nums.length <= 105
1 <= nums[i] <= nums[i + 1] <= 104
Accepted
37.2K
Submissions
57.7K
Acceptance Rate
64.5%

*/

#include <cmath>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    vector<int> res;
    vector<int> ps;

    int sm = 0;
    for (int i : nums) {
      sm += i;
      ps.push_back(sm);
    }

    int tot = ps.back();

    int sz = nums.size();
    for (int i = 0; i < sz; ++i) {
      int cur = nums[i];
      int cursm = 0;
      if (i > 0) {
        int prevSum = ps[i - 1];
        int toMakeEven = i * cur;
        int diff = toMakeEven - prevSum;
        cursm += diff;
      }
      if (i < sz) {
        int pSum = tot - ps[i];
        int diff = pSum - ((sz - i - 1) * cur);
        cursm += diff;
      }
      res.push_back(cursm);
    }
    return res;
  }
};

/*

turns out to be a prefix sum problem

*/