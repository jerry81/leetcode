/*

857. Minimum Cost to Hire K Workers
Hard
Topics
Companies
There are n workers. You are given two integer arrays quality and wage where
quality[i] is the quality of the ith worker and wage[i] is the minimum wage
expectation for the ith worker.

We want to hire exactly k workers to form a paid group. To hire a group of k
workers, we must pay them according to the following rules:

Every worker in the paid group must be paid at least their minimum wage
expectation. In the group, each worker's pay must be directly proportional to
their quality. This means if a worker’s quality is double that of another worker
in the group, then they must be paid twice as much as the other worker. Given
the integer k, return the least amount of money needed to form a paid group
satisfying the above conditions. Answers within 10-5 of the actual answer will
be accepted.



Example 1:

Input: quality = [10,20,5], wage = [70,50,30], k = 2
Output: 105.00000
Explanation: We pay 70 to 0th worker and 35 to 2nd worker.
Example 2:

Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], k = 3
Output: 30.66667
Explanation: We pay 4 to 0th worker, 13.33333 to 2nd and 3rd workers separately.


Constraints:

n == quality.length == wage.length
1 <= k <= n <= 104
1 <= quality[i], wage[i] <= 104
Seen this question in a real interview before?
1/5
Yes
No
Accepted
71.6K
Submissions
131.1K
Acceptance Rate
54.6%

*/

#include <limits>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
    vector<pair<double, int>> wage_quality;

    for (int i = 0; i < quality.size(); ++i) {
      int q = quality[i];
      double ratio = (double)wage[i] / (double)q;
      wage_quality.push_back({ratio, q});
    }

    sort(wage_quality.begin(), wage_quality.end());
    priority_queue<int> pq;
    double res = numeric_limits<double>::max();
    int current_total_q = 0;
    for (auto [f, s] : wage_quality) {
      pq.push(s);
      current_total_q += s;
      if (pq.size() > k) {
        current_total_q -= pq.top();
        pq.pop();
      }
      if (pq.size() == k) {
        double cur_total_wage = current_total_q * f;
        res = max(res, cur_total_wage);
      }
    }
    return res;
  }
};