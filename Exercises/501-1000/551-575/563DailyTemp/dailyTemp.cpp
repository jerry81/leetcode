/*

739. Daily Temperatures
Solved
Medium
Topics
Companies
Hint
Given an array of integers temperatures represents the daily temperatures,
return an array answer such that answer[i] is the number of days you have to
wait after the ith day to get a warmer temperature. If there is no future day
for which this is possible, keep answer[i] == 0 instead.



Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]


Constraints:

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100
Seen this question in a real interview before?
1/4
Yes
No
Accepted
798K
Submissions
1.2M
Acceptance Rate
66.0%

*/

#include <vector>
#include <queue>

using namespace std;


class Solution {
 struct cc {
   bool operator()(const pair<int,int>& a, const pair<int,int>& b) {
     return a.first > b.first;
   }
 };

 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<pair<int, int>> temps;
    int sz = temperatures.size();
    vector<int> ret(sz, 0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, cc> hp;
    for (int i = 0; i < sz; ++i) {
      int cur = temperatures[i];
      while (!hp.empty() && hp.top().first < cur) {
        ret[hp.top().second] = i - hp.top().second;
        hp.pop();
      }
      hp.push({cur, i});
    }

    return ret;
  }
};