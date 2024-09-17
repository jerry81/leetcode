/*

539. Minimum Time Difference
Medium
Topics
Companies
Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.


Example 1:

Input: timePoints = ["23:59","00:00"]
Output: 1
Example 2:

Input: timePoints = ["00:00","23:59","00:00"]
Output: 0


Constraints:

2 <= timePoints.length <= 2 * 104
timePoints[i] is in the format "HH:MM".
Seen this question in a real interview before?
1/5
Yes
No
Accepted
198.1K
Submissions
334.4K
Acceptance Rate
59.2%

*/

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
  int minTimeDiff(string a, string b) {
    int a_mins = stoi(a.substr(0, 2)) * 60 + stoi(a.substr(3, 2));
    int b_mins = stoi(b.substr(0, 2)) * 60 + stoi(b.substr(3, 2));
    int forward_diff = (b_mins - a_mins + 1440) % 1440;
    int backward_diff = (a_mins - b_mins + 1440) % 1440;
    return min(forward_diff, backward_diff);
  }
public:
    int findMinDifference(vector<string>& timePoints) {
      sort(timePoints.begin(), timePoints.end());
      int min_diff = INT_MAX;
      int n = timePoints.size();
      for (int i = 0; i < n; ++i) {
        min_diff = min(min_diff, minTimeDiff(timePoints[i], timePoints[(i + 1) % n]));
      }
      return min_diff;
    }
};