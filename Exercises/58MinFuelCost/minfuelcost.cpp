/*

2477. Minimum Fuel Cost to Report to the Capital
Medium
624
21
Companies
There is a tree (i.e., a connected, undirected graph with no cycles) structure country network consisting of n cities numbered from 0 to n - 1 and exactly n - 1 roads. The capital city is city 0. You are given a 2D integer array roads where roads[i] = [ai, bi] denotes that there exists a bidirectional road connecting cities ai and bi.

There is a meeting for the representatives of each city. The meeting is in the capital city.

There is a car in each city. You are given an integer seats that indicates the number of seats in each car.

A representative can use the car in their city to travel or change the car and ride with another representative. The cost of traveling between two cities is one liter of fuel.

Return the minimum number of liters of fuel to reach the capital city.



Example 1:


Input: roads = [[0,1],[0,2],[0,3]], seats = 5
Output: 3
Explanation:
- Representative1 goes directly to the capital with 1 liter of fuel.
- Representative2 goes directly to the capital with 1 liter of fuel.
- Representative3 goes directly to the capital with 1 liter of fuel.
It costs 3 liters of fuel at minimum.
It can be proven that 3 is the minimum number of liters of fuel needed.
Example 2:


Input: roads = [[3,1],[3,2],[1,0],[0,4],[0,5],[4,6]], seats = 2
Output: 7
Explanation:
- Representative2 goes directly to city 3 with 1 liter of fuel.
- Representative2 and representative3 go together to city 1 with 1 liter of fuel.
- Representative2 and representative3 go together to the capital with 1 liter of fuel.
- Representative1 goes directly to the capital with 1 liter of fuel.
- Representative5 goes directly to the capital with 1 liter of fuel.
- Representative6 goes directly to city 4 with 1 liter of fuel.
- Representative4 and representative6 go together to the capital with 1 liter of fuel.
It costs 7 liters of fuel at minimum.
It can be proven that 7 is the minimum number of liters of fuel needed.
Example 3:


Input: roads = [], seats = 1
Output: 0
Explanation: No representatives need to travel to the capital city.


Constraints:

1 <= n <= 105
roads.length == n - 1
roads[i].length == 2
0 <= ai, bi < n
ai != bi
roads represents a valid tree.
1 <= seats <= 105

*/

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, vector<int>> neighbors;

class Solution {

unordered_map<int, bool> visited;

unordered_map<int, vector<int>> cities;

unordered_map<int, vector<int>> dists;

unordered_map<int, bool> picked_mofos;

int maxDist = 0;
void makeCities() {
  vector<int> cur = {0};
  while (!cur.empty()) {
    vector<int> temp;
    for (int nxt: cur) {

      for (int n: neighbors[nxt]) {
        if (!visited[n]) {
          cities[n] = cities[nxt];
          cities[n].push_back(nxt);
          dists[cities[n].size()].push_back(n);
          temp.push_back(n);
          visited[n] = true;
          maxDist = cities[n].size();
        }

      }
      visited[nxt] = true;
    }

    cur = temp;
  }
}

public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
      long long res = 0;
      if (roads.empty()) return 0;

      neighbors.clear();
      for (vector<int> edge: roads) {
        int n1 = edge[0];
        int n2 = edge[1];
        neighbors[n1].push_back(n2);
        neighbors[n2].push_back(n1);
      }
      visited.clear();
      picked_mofos.clear();
      cities.clear();
      dists.clear();
      makeCities();

      // start with longest paths and count back

      for (int d=maxDist; d > 0; --d) {
        vector<int> curDist = dists[d];
        for (int city: curDist) {
          int countdown = seats;
          vector<int> path = cities[city];
          if (picked_mofos[city]) continue;

          res+=path.size();

          cout << "adding path of size" << path.size() << " for " << city << endl;
          for (int pathidx = (path.size() - 1); pathidx >= 0; --pathidx) {

            if (picked_mofos[path[pathidx]]) {
              cout << "subtracting path idx " << pathidx << endl;
              res -= pathidx;
              break;
            }
            if (countdown > 1) {
              picked_mofos[path[pathidx]] = true;
              countdown--;
            }

          }

        }
      }
      return res;
    }
};


int main () {
vector<vector<int>> test = {{0,1},{0,2},{1,3},{1,4}};

vector<vector<int>> test2 = {{0,1},{2,1},{3,2},{4,2},{4,5},{6,0},{5,7},{8,4},{9,2}};
Solution s;
// cerr << "expect 4 " << s.minimumFuelCost(test, 5) << endl;
cerr << "expect 16 " << s.minimumFuelCost(test2, 2) << endl;
return 0;
}

/*
          9       8
          |       |
  0 - 1 - 2 - 3 - 4 - 5 - 7
  |
  6
*/