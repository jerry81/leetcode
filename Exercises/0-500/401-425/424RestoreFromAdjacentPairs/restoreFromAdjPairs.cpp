/*

1743. Restore the Array From Adjacent Pairs
Medium
1.4K
50
Companies
There is an integer array nums that consists of n unique elements, but you have forgotten it. However, you do remember every pair of adjacent elements in nums.

You are given a 2D integer array adjacentPairs of size n - 1 where each adjacentPairs[i] = [ui, vi] indicates that the elements ui and vi are adjacent in nums.

It is guaranteed that every adjacent pair of elements nums[i] and nums[i+1] will exist in adjacentPairs, either as [nums[i], nums[i+1]] or [nums[i+1], nums[i]]. The pairs can appear in any order.

Return the original array nums. If there are multiple solutions, return any of them.



Example 1:

Input: adjacentPairs = [[2,1],[3,4],[3,2]]
Output: [1,2,3,4]
Explanation: This array has all its adjacent pairs in adjacentPairs.
Notice that adjacentPairs[i] may not be in left-to-right order.
Example 2:

Input: adjacentPairs = [[4,-2],[1,4],[-3,1]]
Output: [-2,4,1,-3]
Explanation: There can be negative numbers.
Another solution is [-3,1,4,-2], which would also be accepted.
Example 3:

Input: adjacentPairs = [[100000,-100000]]
Output: [100000,-100000]


Constraints:

nums.length == n
adjacentPairs.length == n - 1
adjacentPairs[i].length == 2
2 <= n <= 105
-105 <= nums[i], ui, vi <= 105
There exists some nums that has adjacentPairs as its pairs.
Accepted
64.5K
Submissions
88.2K
Acceptance Rate
73.1%

*/

#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
      // graph problem, or hashmap
      unordered_map<int, unordered_set<int>> lookup;
      for (auto pair: adjacentPairs) {
        lookup[pair[0]].insert(pair[1]);
        lookup[pair[1]].insert(pair[0]);
      }
      vector<int> res;
      // find the start
      int prev;
      int cur;
      for (auto a: lookup) {
        if (a.second.size() == 1) {
          prev = a.first;
          res.push_back(prev);
          cur = *a.second.begin();;
          break;
        }
      }
      while (true) {
        res.push_back(cur);
        unordered_set<int> s = lookup[cur];
        int tmp = cur;
        for (int item: s) {
          if (item != prev) {
            cur = item;
          }
        }
        prev = tmp;
        if (s.size() == 1) {
          break;
        }
      }

      return res;
    }
};