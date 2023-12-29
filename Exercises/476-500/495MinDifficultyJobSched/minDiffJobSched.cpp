/*

1335. Minimum Difficulty of a Job Schedule
Hard
2.7K
244
Companies
You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work
on the ith job, you have to finish all the jobs j where 0 <= j < i).

You have to finish at least one task every day. The difficulty of a job schedule
is the sum of difficulties of each day of the d days. The difficulty of a day is
the maximum difficulty of a job done on that day.

You are given an integer array jobDifficulty and an integer d. The difficulty of
the ith job is jobDifficulty[i].

Return the minimum difficulty of a job schedule. If you cannot find a schedule
for the jobs return -1.



Example 1:


Input: jobDifficulty = [6,5,4,3,2,1], d = 2
Output: 7
Explanation: First day you can finish the first 5 jobs, total difficulty = 6.
Second day you can finish the last job, total difficulty = 1.
The difficulty of the schedule = 6 + 1 = 7
Example 2:

Input: jobDifficulty = [9,9,9], d = 4
Output: -1
Explanation: If you finish a job per day you will still have a free day. you
cannot find a schedule for the given jobs. Example 3:

Input: jobDifficulty = [1,1,1], d = 3
Output: 3
Explanation: The schedule is one job per day. total difficulty will be 3.


Constraints:

1 <= jobDifficulty.length <= 300
0 <= jobDifficulty[i] <= 1000
1 <= d <= 10
Accepted
131K
Submissions
224.4K
Acceptance Rate
58.4%

*/

#include <vector>

using namespace std;

class Solution {
  int max_in_ranges[301][301];
  int min_in_range[301][301];
  int get_max(vector<int>& jobDifficulty, int st, int en) {
    int mx = 0;
    for (int i = st; i <= en; ++i) {
      mx = max(jobDifficulty[i], mx);
    }
    return mx;
  }
  int r(vector<int>& jobDifficulty, int& sz, int d, int st) {
    if (d == 1) return get_max(jobDifficulty, st, sz - 1);
    int ret = INT_MAX;
    if (st >= sz) return ret;

    int en = sz - d;

    for (int ce = st; ce <= en; ++ce) {
      int mx = get_max(jobDifficulty, st, ce);
      // cout << "mx on day " << d << " with range " << st << " to " << en
      //      << " is " << mx << endl;
      ret = min(ret, mx + r(jobDifficulty, sz, d - 1, ce + 1));
    }

    return ret;
  }

 public:
  int minDifficulty(vector<int>& jobDifficulty, int d) {
    // get all combos
    int sz = jobDifficulty.size();
    memset(max_in_ranges, -1, sizeof(max_in_ranges));
    memset(max_in_ranges, -1, sizeof(max_in_ranges));
    int res = r(jobDifficulty, sz, d, 0);
    return res < INT_MAX ? res : -1;
  }
};

// recursion + dp