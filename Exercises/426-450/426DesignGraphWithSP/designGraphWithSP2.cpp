#include <queue>
#include <vector>

using namespace std;

class Graph {
vector<vector<vector<int>>> _edges;

public:
  Graph(int n, vector<vector<int>>& edges) {
    _edges.resize(n);
    for (auto a: edges) {
      _edges[a[0]].push_back({ a[1], a[2]});
    }
  }

  void addEdge(vector<int> edge) {
    _edges[edge[0]].push_back({edge[1],edge[2]});
  }

  int shortestPath(int node1, int node2) {}
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */