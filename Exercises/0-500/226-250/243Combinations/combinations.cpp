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
 public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> cur;
    // initialize
    for (int i = 1; i <= k; ++i) {
      cur.push_back(i);
    }
    vector<int> cpy = cur;
    res.push_back(cpy);
    int counter = 0;
    while (counter < 100) {
        bool dirty = false;
        // just get the next item
        for (int i = k-1; i >= 0; --i) {
          if (cur[i] < n - (k-i-1)) {
            cur[i]++;
            dirty = true;
            // reset
            for (int j = i+1; j < k; ++j) {
              cur[j] = cur[j-1]+1;
            }
            vector<int> cpy = cur;
            res.push_back(cpy);
            break;
          }
        }
        if (!dirty) return res;
    }
    return res;
  }
};

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

1,2,3
...
1,2,n
1,3,4
...
1,3,n
...
1,n-1,n
...
2,3,4
...
2,3,n
2,n-1,n
n-2,n-1,n


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

1234
1235
1236
1245
1246
1256
1345
1346
1356
1456
2345
2346
2356
2456
3456

go more holistic
try to make strictly increasing digits
if maxxed backtrack a digit
*/