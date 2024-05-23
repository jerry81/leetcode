/*
2597. The Number of Beautiful Subsets
Medium
Topics
Companies
Hint
You are given an array nums of positive integers and a positive integer k.

A subset of nums is beautiful if it does not contain two integers with an
absolute difference equal to k.

Return the number of non-empty beautiful subsets of the array nums.

A subset of nums is an array that can be obtained by deleting some (possibly
none) elements from nums. Two subsets are different if and only if the chosen
indices to delete are different.



Example 1:

Input: nums = [2,4,6], k = 2
Output: 4
Explanation: The beautiful subsets of the array nums are: [2], [4], [6], [2, 6].
It can be proved that there are only 4 beautiful subsets in the array [2,4,6].
Example 2:

Input: nums = [1], k = 1
Output: 1
Explanation: The beautiful subset of the array nums is [1].
It can be proved that there is only 1 beautiful subset in the array [1].


Constraints:

1 <= nums.length <= 20
1 <= nums[i], k <= 1000
Seen this question in a real interview before?
1/5
Yes
No
Accepted
29.1K
Submissions
78.6K
Acceptance Rate
37.0%
*/

#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
  int res = 0;
  unordered_set<string> all_indexes = {};
  void r(int idx, unordered_set<int>& lookup, string& indexes,
         vector<int>& nums, int k, int sz) {
    if (idx >= sz) return;

    int nxt = idx + 1;
    r(nxt, lookup, indexes, nums, k, sz);
    int cur = nums[idx];
    if (lookup.find(cur + k) == lookup.end() &&
        lookup.find(cur - k) == lookup.end()) {
      indexes[idx] = '1';
      if (all_indexes.find(indexes) == all_indexes.end()) {
        all_indexes.insert(indexes);
        res += 1;
      }
      lookup.insert(cur);
      r(nxt, lookup, indexes, nums, k, sz);
      lookup.erase(cur);
      indexes[idx] = '0';
    }
  }

 public:
  int beautifulSubsets(vector<int>& nums, int k) {
    // subset = knapsack
    // knapsack with early term
    unordered_set<int> start = {};
    int sz = nums.size();
    string indexes(sz, '0');
    r(0, start, indexes, nums, k, sz);
    return res;
  }
};