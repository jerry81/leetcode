/*
40. Combination Sum II
Medium
Topics
Companies
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.



Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output:
[
[1,2,2],
[5]
]


Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
Seen this question in a real interview before?
1/5
Yes
No
Accepted
1.1M
Submissions
1.9M
Acceptance Rate
55.1%
*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      // every possible combination?
      // with early stops
      vector<int> sorted = candidates;
      sort(sorted.begin(), sorted.end());
      for (int i: sorted) cout << i << endl;

      return {};
    }
};