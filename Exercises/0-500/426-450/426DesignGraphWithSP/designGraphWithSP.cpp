/*

2642. Design Graph With Shortest Path Calculator
Hard
427
29
Companies
There is a directed weighted graph that consists of n nodes numbered from 0 to n
- 1. The edges of the graph are initially represented by the given array edges
where edges[i] = [fromi, toi, edgeCosti] meaning that there is an edge from
fromi to toi with the cost edgeCosti.

Implement the Graph class:

Graph(int n, int[][] edges) initializes the object with n nodes and the given
edges. addEdge(int[] edge) adds an edge to the list of edges where edge = [from,
to, edgeCost]. It is guaranteed that there is no edge between the two nodes
before adding this one. int shortestPath(int node1, int node2) returns the
minimum cost of a path from node1 to node2. If no path exists, return -1. The
cost of a path is the sum of the costs of the edges in the path.


Example 1:


Input
["Graph", "shortestPath", "shortestPath", "addEdge", "shortestPath"]
[[4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]], [3, 2], [0, 3], [[1, 3, 4]],
[0, 3]] Output [null, 6, -1, null, 6]

Explanation
Graph g = new Graph(4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]);
g.shortestPath(3, 2); // return 6. The shortest path from 3 to 2 in the first
diagram above is 3 -> 0 -> 1 -> 2 with a total cost of 3 + 2 + 1 = 6.
g.shortestPath(0, 3); // return -1. There is no path from 0 to 3.
g.addEdge([1, 3, 4]); // We add an edge from node 1 to node 3, and we get the
second diagram above. g.shortestPath(0, 3); // return 6. The shortest path from
0 to 3 now is 0 -> 1 -> 3 with a total cost of 2 + 4 = 6.


Constraints:

1 <= n <= 100
0 <= edges.length <= n * (n - 1)
edges[i].length == edge.length == 3
0 <= fromi, toi, from, to, node1, node2 <= n - 1
1 <= edgeCosti, edgeCost <= 106
There are no repeated edges and no self-loops in the graph at any point.
At most 100 calls will be made for addEdge.
At most 100 calls will be made for shortestPath.
Accepted
26.4K
Submissions
39.1K
Acceptance Rate
67.4%

*/

#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

struct Node {
  int id;
  vector<pair<int, int>> edges;
};

struct ComparePQ {
  bool operator()(vector<int> a, vector<int> b) { return a[2] > b[2]; }
};
class Graph {
  vector<vector<int>> _edges;
  unordered_map<int, Node*> _nodes;
  int _n;

 public:
  Graph(int n, vector<vector<int>>& edges) {
    _n = n;
    _edges = edges;
    for (vector<int> v : edges) {
      if (_nodes.find(v[0]) == _nodes.end()) {
        Node* tmp = new Node();
        tmp->id = v[0];
        tmp->edges.push_back({v[1], v[2]});
        _nodes[v[0]] = tmp;
      } else {
        _nodes[v[0]]->edges.push_back({v[1], v[2]});
      }
    }
  }

  void addEdge(vector<int> edge) {
    _nodes[edge[0]]->edges.push_back({edge[1], edge[2]});
  }

  int shortestPath(int node1, int node2) {
    // djikstra or something
    unordered_set<string> visited;
    priority_queue<vector<int>, vector<vector<int>>, ComparePQ> q;
    vector<int> dist(_n, INT_MAX);
    dist[node1] = 0;
    for (pair<int, int> ed : _nodes[node1]->edges) {
      q.push({node1, ed.first, ed.second});
    }
    while (!q.empty()) {
      auto curv = q.top();
      q.pop();

      int newWeight = dist[curv[0]] + curv[2];
      dist[curv[1]] = min(dist[curv[1]],newWeight);
      visited.insert(to_string(curv[0]) + "," + to_string(curv[1]));

      // if (curv[1] == node2) return dist[curv[1]];

      if (_nodes.find(curv[1]) == _nodes.end()) continue;
      auto nxtEdges = _nodes[curv[1]]->edges;
      for (auto a : nxtEdges) {
        if (visited.find(to_string(curv[0]) + "," + to_string(curv[1])) != visited.end()) continue;

        q.push({curv[1], a.first, a.second});
      }
    }
    return dist[node2];
  }
};
/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */