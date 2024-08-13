/*
40. Combination Sum II
Medium
Topics
Companies
Given a collection of candidate numbers (candidates) and a target number
(target), find all unique combinations in candidates where the candidate numbers
sum to target.

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

#include <set>
#include <vector>

using namespace std;

class Solution {
  vector<vector<int>> res;
  void r(vector<int>& candidates, vector<int>& curv, int tgt, int cursum,
         int idx) {
    if (cursum == tgt) {
      // vector<int> hit = curv;
      res.push_back(curv);
      return;
      // done, backtrack
    }
    for (int i = idx; i < candidates.size() && tgt > cursum; ++i) {
      if (i == idx || candidates[i] != candidates[i - 1]) {
        curv.push_back(candidates[i]);
        cursum += curv.back();
        r(candidates, curv, tgt, cursum, i + 1);
        cursum -= curv.back();
        curv.pop_back();
      }
    }
  }

 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    // dp
    // with backtracking
    sort(candidates.begin(), candidates.end());
    vector<int> start;
    r(candidates, start, target, 0, 0);
    return res;
  }
};

// 1
// 1,1
// 1,1,1
// .....
// 01234
// 0
// 1
// ... 4
// 01
// .. 05
// 12
// .. 15
// 45
// 123
// 124
// ..
// 345

/*

10 - no, 10 done

- []
7
- 7 1 - ok!
- 7 2 - no
- 7 done
- 6 2 - ok
- 6 1
- 6 1 1 - ok
- 6 done
- 5

other direction
- []
- 1
- 1 1
- 1 1 2
- 1 1 2 5 - back
- 1 1
- 1 1 5 back
- 1 1
- 1 1 6 ok - 1 1 - done
- backtrack to 1 2

// take it or leave it algo
 */