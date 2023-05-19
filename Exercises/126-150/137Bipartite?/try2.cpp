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
#include <queue>

using namespace std;

class Solution {
unordered_map<int, bool> teams;
unordered_map<int, bool> visited;
pair<bool,bool> bfs(vector<vector<int>> graph, int start) {
  if (visited[start]) return {true, false};
  queue<int> nextneighbors;
  nextneighbors.push(start);
  while (!nextneighbors.empty()) {
    int parent = nextneighbors.front();
    bool parentTeam = teams[parent];
    visited[parent] = true;
    nextneighbors.pop();
    vector<int> neighbors = graph[parent];
    for (int n:neighbors) {
      if (visited[n]) continue;

      if (teams.find(n) != teams.end() && teams[n] == parentTeam) return {false,true};

      nextneighbors.push(n);
      teams[n] = !parentTeam;
    }
  }
  return {true, true};
}
public:
    bool isBipartite(vector<vector<int>>& graph) {
      if (graph.size() <= 1) return 0;

      teams[0] = false;
      bool somethingmodified = true;
      while (somethingmodified) {
        somethingmodified = false;
        for (int i = 0; i < graph.size(); ++i) {
          if (teams.find(i) == teams.end()) continue;

          if (visited[i]) continue;
          auto res = bfs(graph, i);
          if (!res.first) return false;
          if (res.first) somethingmodified = true;
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