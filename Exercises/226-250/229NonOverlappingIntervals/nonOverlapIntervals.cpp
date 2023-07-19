/*

435. Non-overlapping Intervals
Medium
6.4K
171
Companies
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.



Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.


Constraints:

1 <= intervals.length <= 105
intervals[i].length == 2
-5 * 104 <= starti < endi <= 5 * 104
Accepted
395.4K
Submissions
775.7K
Acceptance Rate
51.0%

*/

#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      // make map of vectors of intervals
      map<int, vector<int>> imap;
      for (auto a: intervals) {
        imap[a[1]].push_back(a[0]);
      }
      int ret = 0;
      // sort vectors by start (reverse)
      int prevMax = 0;
      for (auto p: imap) {
        sort(p.second.begin(), p.second.end());
        reverse(p.second.begin(), p.second.end());
        if (p.second[0] >= prevMax) {
          ret+=p.second.size() - 1;
          prevMax = p.first;
        } else {
          ret+=p.second.size();
        }
      }


      return ret;

    }
};

/*

[[1,2],[2,3],[3,4],[1,3]]

1 2    2 3   3 4    1 3
1 2 3 4
1 1 1 1
1->2
   2->3
      3->4
1---->3

[[1,2],[1,2],[1,2]]

1->2
1->2
1->2

1->7
6->8
3->9
4->10
3->11


*/