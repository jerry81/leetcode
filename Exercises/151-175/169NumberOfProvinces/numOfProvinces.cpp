/*

547. Number of Provinces
Medium
7.9K
300
Companies
There are n cities. Some of them are connected, while some are not. If city a is
connected directly with city b, and city b is connected directly with city c,
then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other
cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith
city and the jth city are directly connected, and isConnected[i][j] = 0
otherwise.

Return the total number of provinces.



Example 1:


Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:

Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3


Constraints:

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]
Accepted
648.7K
Submissions
1M
Acceptance Rate
64.4%

*/

#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<vector<int>> edges(n, vector<int>(0));
    for (int i = 0; i < n - 1; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (isConnected[i][j]) {
          edges[i].push_back(j);
          edges[j].push_back(i);
        }
      }
    }

    vector<bool> visited(n, false);
    int result = 0;

    for (int i = 0; i < n; ++i) {
      if (visited[i]) continue;

      vector<bool> visitedSnap = visited;

      cout << "examining " << i << endl;
      visited[i] = true;
      queue<int> nn;
      nn.push(i);
      bool indirect = false;
      while (!nn.empty()) {
        int cur = nn.front();
        nn.pop();
        for (int n : edges[cur]) {
          if (!visited[n]) {
            nn.push(n);
            visited[n] = true;
          } else {
            if (visitedSnap[n]) indirect = true;
          }
        }
      }
      if (!indirect) result++;
    }

    return result;
  }
};

/*

first impressions - islands

*/