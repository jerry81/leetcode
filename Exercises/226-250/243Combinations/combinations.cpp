/*

77. Combinations
Medium
6.4K
192
Companies
Given two integers n and k, return all possible combinations of k numbers chosen
from the range [1, n].

You may return the answer in any order.



Example 1:

Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be
the same combination. Example 2:

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
 vector<int> resetAt(vector<int> src, int idx, int start, int n, int k) {
   // check out of bounds
   if (start+k > n)
 }
 public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> cur;
    // initialize
    for (int i = 1; i <= k; ++i) {
      cur.push_back(i);
    }
    for (int pivot = k - 1; pivot >= 0; --pivot) {
      for (int j = 0; j >= (k-1)-pivot; ++j) {
        while (cur[j] < (n-j)) {
          cur[(k-1)-j]++;
          vector<int> cp = cur;
          res.push_back(cp);
        }
      }
    }
    res.push_back(cur);
  }
}
;

/*

12
13
14
23
24
34

n = 5
k = 3

123
124
125
134
135
145
234
235
245
345

create initial
n = ?
k = ?
for k places
print incr
vector [1,2,3,4,5,....,k]
pivot at k incr k until it reaches n
[1,2,3,4,5......, k-1, n]
carry over pivot is idx k-1
[1,2,3,4,5.....,k (idx is k-1),k+1] but only if it "fits" - so k-1 goes until
n-1
...
[1,2,3,4,5.....,n-1, n]
[1,2,3,4,5...k-1 (incremented from k-2), k, k+1]


*/