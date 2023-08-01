/*

77. Combinations
Medium
6.4K
192
Companies
Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.



Example 1:

Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
Example 2:

Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.


Constraints:

1 <= n <= 20
1 <= k <= n
Accepted
697.5K
Submissions
1M
Acceptance Rate
67.7%


*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
      vector<vector<int>> res;
      for (int i = 1; i < n; ++i) {
        for (int j = i+1; j <= n; ++j) {
          vector<int> cur;
          cur.push_back(i);
          cur.push_back(j);
          res.push_back(cur);
        }

      }
      return res;
    }
};