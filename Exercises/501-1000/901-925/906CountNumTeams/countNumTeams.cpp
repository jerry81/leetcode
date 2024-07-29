/*
1395. Count Number of Teams
Medium
Topics
Companies
Hint
There are n soldiers standing in a line. Each soldier is assigned a unique
rating value.

You have to form a team of 3 soldiers amongst them under the following rules:

Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j],
rating[k]). A team is valid if: (rating[i] < rating[j] < rating[k]) or
(rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n). Return the
number of teams you can form given the conditions. (soldiers can be part of
multiple teams).



Example 1:

Input: rating = [2,5,3,4,1]
Output: 3
Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1),
(5,3,1). Example 2:

Input: rating = [2,1,3]
Output: 0
Explanation: We can't form any team given the conditions.
Example 3:

Input: rating = [1,2,3,4]
Output: 4


Constraints:

n == rating.length
3 <= n <= 1000
1 <= rating[i] <= 105
All the integers in rating are unique.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
115.4K
Submissions
174.7K
Acceptance Rate
66.0%
*/

#include <vector>

using namespace std;


class Solution {
  vector<vector<vector<int>>> memo;
  int r(vector<int>& rating, int idx, int remain, int last, int n) {
    if (idx == n) {
        return remain == -1 ? 1: 0;
    }

    if (remain < 0) return 1;

    if (memo[idx][last+1][remain] >= 0) return memo[idx][last+1][remain];

    int cur = rating[idx];

    int nxt = idx+1;
    int res = r(rating, nxt, remain, last, n);
    // can only take if cur > last
    if (cur > last) {
      int take = r(rating, nxt, remain-1, cur, n);
      res+=take;
    }
    return memo[idx][last+1][remain] = res;
  }

 public:
  int numTeams(vector<int>& rating) {
    // recursive dp
    int sz = rating.size();
    memo.resize(sz, vector<vector<int>>(sz+2, vector<int>(3, -1)));
    int inc = r(rating, 0, 2, -1, sz);
    fill(memo.begin(), memo.end(), vector<vector<int>>(sz + 2, vector<int>(3, -1))); // TIL: reset the vector
    vector<int> rev = rating;
    reverse(rev.begin(), rev.end());
    int dec = r(rev, 0, 2, -1, sz);
    return inc + dec;
    // 2 problems: increasing subseq, decreasing subseq
  }
};