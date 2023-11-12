/*

815. Bus Routes
Hard
3.4K
85
Companies
You are given an array routes representing bus routes where routes[i] is a bus
route that the ith bus repeats forever.

For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in
the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever. You will start at
the bus stop source (You are not on any bus initially), and you want to go to
the bus stop target. You can travel between bus stops by buses only.

Return the least number of buses you must take to travel from source to target.
Return -1 if it is not possible.



Example 1:

Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
Output: 2
Explanation: The best strategy is take the first bus to the bus stop 7, then
take the second bus to the bus stop 6. Example 2:

Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target =
12 Output: -1


Constraints:

1 <= routes.length <= 500.
1 <= routes[i].length <= 105
All the values of routes[i] are unique.
sum(routes[i].length) <= 105
0 <= routes[i][j] < 106
0 <= source, target < 106
Accepted
144.3K
Submissions
313.8K
Acceptance Rate
46.0%

*/

#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
  unordered_map<int, unordered_set<int>> route_table;

 public:
  int numBusesToDestination(vector<vector<int>>& routes, int source,
                            int target) {
    bool sourceFound = false;
    bool targetFound = false;
    for (vector<int> r : routes) {
      for (int a : r) {
        if (source == a) sourceFound = true;
        if (target == a) targetFound = true;
        for (int b : r) {
          route_table[a].insert(b);
        }
      }
    }
    if (!sourceFound || !targetFound) return -1;

    if (source == target) return 0;

    int res = 0;
    int cur = source;
    // bfs?
    queue<int> q;
    q.push(cur);
    unordered_set<int> visited;
    visited.insert(cur);
    while (!q.empty()) {
      queue<int> nxt;

      while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == target) return res;

        // neighbors
        auto a = route_table[cur];
        for (int connectedStop : a) {
          if (visited.find(connectedStop) != visited.end()) continue;

          visited.insert(connectedStop);
          nxt.push(connectedStop);
        }
      }
      res++;
      q = nxt;
    }
    return -1;
  }
};