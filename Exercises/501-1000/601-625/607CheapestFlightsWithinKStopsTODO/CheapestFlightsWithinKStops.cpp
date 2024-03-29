/*


787. Cheapest Flights Within K Stops
Medium
Topics
Companies
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.



Example 1:


Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
Example 2:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.
Example 3:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.


Constraints:

1 <= n <= 100
0 <= flights.length <= (n * (n - 1) / 2)
flights[i].length == 3
0 <= fromi, toi < n
fromi != toi
1 <= pricei <= 104
There will not be any multiple flights between two cities.
0 <= src, dst, k < n
src != dst
Seen this question in a real interview before?
1/4
Yes
No
Accepted
465.1K
Submissions
1.2M
Acceptance Rate
37.8%

*/

#include <vector>

using namespace std;

class Solution {
long long r(vector<vector<pair<int,int>>>& neighbors, vector<bool> visited, int cur, int dest, int k, int used) {
  if (used > k) return INT_MAX;

  if (visited[cur]) return INT_MAX;
  visited[cur] = true;
  if (dest == cur) return 0;

  auto neighs = neighbors[cur];
  long long mn = INT_MAX;
  for (auto [node,dist]: neighs) {
    mn = min(mn,dist + r(neighbors, visited, node, dest, k, used+1));
  }
  return mn;
}

public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      // djikstra but new constraint, limit numbe of steps
      // so brute force dfs
      vector<bool> visited(n, false);
      vector<vector<pair<int,int>>> neighbors(n, vector<pair<int,int>>(0));
      for (auto v: flights) {
        neighbors[v[0]].push_back({v[1], v[2]});
      }

      int res = r(neighbors, visited, src, dst, k, -1);
      return (res == INT_MAX) ? -1 : res;
    }
};