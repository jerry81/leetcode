/*

785. Is Graph Bipartite?
Medium
6.6K
308
Companies
There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.



Example 1:


Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.
Example 2:


Input: graph = [[1,3],[0,2],[1,3],[0,2]]
Output: true
Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.


Constraints:

graph.length == n
1 <= n <= 100
0 <= graph[u].length < n
0 <= graph[u][i] <= n - 1
graph[u] does not contain u.
All the values of graph[u] are unique.
If graph[u] contains v, then graph[v] contains u.
Accepted
413K
Submissions
770.9K
Acceptance Rate
53.6%

*/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
      if (graph.size() <= 1) return 0;

      unordered_map<int, vector<int>> banned;


      for (int nodeid = 0; nodeid < graph.size(); ++nodeid) {
        vector<int> bannedList;
        if (banned.find(nodeid) != banned.end()) {
          bannedList = banned[nodeid]; // get this node's banned list
        }
        vector<int> neighbors = graph[nodeid];
        if (neighbors.size() > 1) {
          for (int i = 0; i < neighbors.size(); ++i) {
            int neighbor = neighbors[i];
            if (find(bannedList.begin(), bannedList.end(), neighbors[i])!=bannedList.end()) return false;
            vector<int> newv;
            if (banned.find(neighbor) == banned.end()) banned[neighbor] = newv;
            for (int j = 0; j < neighbors.size(); ++j) {
              if (neighbors[j] == neighbor) continue;
              banned[neighbor].push_back(neighbors[j]);
            }
          }
        }
      }

      return true;
    }
};

/*

undirected

bipartite - partition into 2 independent sets - each edge in graph connects node in set a and set b

take a stab -

other option - do a BFS
- on each node marking visited as we go
- after the first item,

*/