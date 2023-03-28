/*

983. Minimum Cost For Tickets
Medium
5.8K
98
Companies
You have planned some train traveling one year in advance. The days of the year
in which you will travel are given as an integer array days. Each day is an
integer from 1 to 365.

Train tickets are sold in three different ways:

a 1-day pass is sold for costs[0] dollars,
a 7-day pass is sold for costs[1] dollars, and
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.

For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2,
3, 4, 5, 6, 7, and 8. Return the minimum number of dollars you need to travel
every day in the given list of days.



Example 1:

Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: For example, here is one way to buy passes that lets you travel
your travel plan: On day 1, you bought a 1-day pass for costs[0] = $2, which
covered day 1. On day 3, you bought a 7-day pass for costs[1] = $7, which
covered days 3, 4, ..., 9. On day 20, you bought a 1-day pass for costs[0] = $2,
which covered day 20. In total, you spent $11 and covered all the days of your
travel. Example 2:

Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
Output: 17
Explanation: For example, here is one way to buy passes that lets you travel
your travel plan: On day 1, you bought a 30-day pass for costs[2] = $15 which
covered days 1, 2, ..., 30. On day 31, you bought a 1-day pass for costs[0] = $2
which covered day 31. In total, you spent $17 and covered all the days of your
travel.


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

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
  int result = INT_MAX;
  vector<int> _costs;
  vector<int> _days;
  int bsearch(int start, int target) {
    int end = _days.size() - 1;
    while (start <= end) {
      int mid = (start + end) / 2;
      if (_days[mid] == target) {
        return mid;
      } else if (_days[mid] < target) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }
    return end + 1;
  }

  void traverse(int idx, int accum) {
    if (accum > result) return;


    if (idx >= _days.size()) {
      if (accum < result) result = accum;

      return;
    }

    int startday = _days[idx];

    int nextday = startday + 30;

    traverse(bsearch(idx, nextday), accum + _costs[2]);

    // 7 day

    nextday = startday + 7;

    traverse(bsearch(idx, nextday), accum + _costs[1]);

    traverse(idx+1, accum + _costs[0]);

    // 1 day
  }

 public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    _costs = costs;
    _days = days;

    traverse(0, 0);
    return result;
  }
};

int main() {
  vector<int> test1 = {1, 2, 3};
  test1.erase(test1.begin());
  test1.erase(test1.begin());
  cerr << "expect size 1: " << test1.size() << endl;
  cerr << "expect 3: " << test1[0] << endl;
}

/*

start - traverse it as a tree

TLE on case 26
- flip the order of calculation
- do 30 day first
- then 7 day
- then 2 day
- still TLE

- try using ptr instead of doing erase ops

- better but fails on case 46
days [6,9,10,14,15,16,17,18,20,22,23,24,29,30,31,33,35,37,38,40,41,46,47,51,54,57,59,65,70,76,77,81,85,87,90,91,93,94,95,97,98,100,103,104,105,106,107,111,112,113,114,116,117,118,120,124,128,129,135,137,139,145,146,151,152,153,157,165,166,173,174,179,181,182,185,187,188,190,191,192,195,196,204,205,206,208,210,214,218,219,221,225,229,231,233,235,239,240,245,247,249,251,252,258,261,263,268,270,273,274,275,276,280,283,285,286,288,289,290,291,292,293,296,298,299,301,303,307,313,314,319,323,325,327,329,334,339,340,341,342,344,346,349,352,354,355,356,357,358,359,363,364]
costs [21,115,345]

failing case
days [1,2,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,20,21,24,25,27,28,29,30,31,34,37,38,39,41,43,44,45,47,48,49,54,57,60,62,63,66,69,70,72,74,76,78,80,81,82,83,84,85,88,89,91,93,94,97,99]
costs [9,38,134]
*/