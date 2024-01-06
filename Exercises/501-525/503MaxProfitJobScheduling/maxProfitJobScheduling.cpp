/*

1235. Maximum Profit in Job Scheduling
Hard
5.7K
73
Companies
We have n jobs, where every job is scheduled to be done from startTime[i] to
endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit
you can take such that there are no two jobs in the subset with overlapping time
range.

If you choose a job that ends at time X you will be able to start another job
that starts at time X.



Example 1:



Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job.
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
Example 2:



Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit =
[20,20,100,70,60] Output: 150 Explanation: The subset chosen is the first,
fourth and fifth job. Profit obtained 150 = 20 + 70 + 60. Example 3:



Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
Output: 6


Constraints:

1 <= startTime.length == endTime.length == profit.length <= 5 * 104
1 <= startTime[i] < endTime[i] <= 109
1 <= profit[i] <= 104
Accepted
215.6K
Submissions
403.6K
Acceptance Rate
53.4%

*/

#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
  vector<pair<int, int>> indexedStartTimes;

  static bool compare(pair<int, int> a, pair<int, int> b) {
    auto [t1, _] = a;
    auto [t2, __] = b;
    return t1 < t2;
  }

 public:
  int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                    vector<int>& profit) {
    int sz = startTime.size();
    unordered_set<int> starts_set;
    int mxStart = 0;
    int mxEnd = 0;
    for (int i = 0; i < sz; ++i) {
      mxStart = max(startTime[i], mxStart);
      mxEnd = max(mxEnd, endTime[i]);
      starts_set.insert(startTime[i]);
      indexedStartTimes.push_back({startTime[i], i});
    }
    sort(indexedStartTimes.begin(), indexedStartTimes.end(), compare);
    vector<int> mxp(mxEnd + 1, 0);
    int prevTime = mxStart;
    int curMx = 0;
    int curTime = mxStart;

    while (!indexedStartTimes.empty()) {
      auto [sTime, idx] = indexedStartTimes.back();
      if (curTime != sTime) {
        // mxp[sTime] = max(curMx, mxp[sTime]);
        // fill in
        for (int i = curTime-1; i >= sTime+1; --i) {

            mxp[i] = curMx;
        }
        curTime = sTime;
        continue;
      }
      indexedStartTimes.pop_back();
      curMx = max(curMx, profit[idx] + mxp[endTime[idx]]);
      mxp[sTime] = max(curMx, mxp[sTime]);
    }

    // new curMx, process old max, otherwise update curmx

    return *max_element(mxp.begin(), mxp.end());
  }
};