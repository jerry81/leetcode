/*

57. Insert Interval
Medium
Topics
Companies
You are given an array of non-overlapping intervals intervals where intervals[i]
= [starti, endi] represent the start and the end of the ith interval and
intervals is sorted in ascending order by starti. You are also given an interval
newInterval = [start, end] that represents the start and end of another
interval.

Insert newInterval into intervals such that intervals is still sorted in
ascending order by starti and intervals still does not have any overlapping
intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array
and return it.



Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].


Constraints:

0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 105
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 105
Seen this question in a real interview before?
1/4
Yes
No
Accepted
972.4K
Submissions
2.4M
Acceptance Rate
40.1%

*/

#include <vector>

using namespace std;

class Solution {
  static bool cmp(vector<int> a, vector<int> b) { return a[0] < b[0]; }

 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    // brute force first
    vector<vector<int>> sorted = intervals;
    sorted.push_back(newInterval);
    sort(sorted.begin(), sorted.end(), cmp);
    int cur_low = -1;
    int cur_high = -1;
    vector<vector<int>> res;
    for (auto v : sorted) {
      int l = v[0];
      int h = v[1];
      if (l < 0) cur_low = l;
      if (h < 0) cur_high = h;
    }
    return res;
  }
};