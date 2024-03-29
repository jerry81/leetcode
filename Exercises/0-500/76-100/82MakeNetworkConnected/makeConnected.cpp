/*

1319. Number of Operations to Make Network Connected
Medium
3.6K
44
Companies
There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.



Example 1:


Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
Example 2:


Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2
Example 3:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.


Constraints:

1 <= n <= 105
1 <= connections.length <= min(n * (n - 1) / 2, 105)
connections[i].length == 2
0 <= ai, bi < n
ai != bi
There are no repeated connections.
No two computers are connected by more than one cable.
Accepted
134.4K
Submissions
222.5K
Acceptance Rate
60.4%

*/

#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;



class Solution {
int ncount;
struct Node {
  int id;
  unordered_map<int, bool> neighbors;
};
vector<Node*> nodes;
  int getIslands() {
    return 0;
  }
  void makeNodes() {
  for (int i = 0; i < ncount; ++i) {
    Node *n = new Node();
    n->id = i;
    nodes.push_back(n);
  }
}
void makeNeighbors(vector<vector<int>> roads) {
  for (vector<int> v: roads) {
    int from = v[0];
    int to = v[1];
    nodes[from]->neighbors[to] = true;
    nodes[to]->neighbors[from] = true;
  }
}
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
      if (connections.size() < (n - 1)) return -1;
      ncount = n;
      makeNodes();
      makeNeighbors(connections);
      return 0;
    }
};

/*
1.  build stuff
2.  bfs to find number of islands
3.  calculate total number of cables in the connected islands.  the "island" only needs node count-1 cables
4.  cables "swaps" needed are # of islands - 1
5.  edge case - not enough cables

*/

/*

- after some thinking
- find number of cables in each of the islands - there could be more than one island with a surplus of cables
*/