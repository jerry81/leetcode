/*

983. Minimum Cost For Tickets
Medium
5.8K
98
Companies
You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:

a 1-day pass is sold for costs[0] dollars,
a 7-day pass is sold for costs[1] dollars, and
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.

For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in the given list of days.



Example 1:

Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total, you spent $11 and covered all the days of your travel.
Example 2:

Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
Output: 17
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
In total, you spent $17 and covered all the days of your travel.


Constraints:

1 <= days.length <= 365
1 <= days[i] <= 365
days is in strictly increasing order.
costs.length == 3
1 <= costs[i] <= 1000
Accepted
193.5K
Submissions
300K
Acceptance Rate
64.5%

*/

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
int result = INT_MAX;
vector<int> _costs;
void traverse(vector<int> remaining, int accum) {
  if (accum > result) return;

  if (remaining.size() <= 0) {
    if (accum < result) result = accum;

    return;
  }

  int startday = remaining[0];

  remaining.erase(remaining.begin());

  // 1 day

  traverse(remaining, accum+_costs[0]);

  // 7 day

  int nextday = startday + 7;

  while (remaining.size() > 0 && remaining[0] < nextday) {
    remaining.erase(remaining.begin());
  }

  traverse(remaining, accum+_costs[1]);

  nextday = startday + 30;

  // probably can somehow combine this with the above block
  while (remaining.size() > 0 && remaining[0] < nextday)  {
    remaining.erase(remaining.begin());
  }

  traverse(remaining, accum+_costs[2]);
}

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
      _costs = costs;

      traverse(days, 0);
      return result;
    }
};

int main() {
  vector<int> test1 = {1,2,3};
  test1.erase(test1.begin());
  test1.erase(test1.begin());
  cerr << "expect size 1: " << test1.size() << endl;
  cerr << "expect 3: " << test1[0] <<endl;
}

/*

start - traverse it as a tree

*/