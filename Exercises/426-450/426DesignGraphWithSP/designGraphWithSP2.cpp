#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

struct ComparePQ {
  bool operator()(vector<int> a, vector<int> b) { return a[1] > b[1]; }
};
class Graph {
  vector<vector<pair<int, int>>> _edges;
  int _n;

  string hashEdge(int a, int b) { return to_string(a) + "," + to_string(b); }

 public:
  Graph(int n, vector<vector<int>>& edges) {
    _n = n;
    _edges.resize(n);
    for (auto a : edges) {
      _edges[a[0]].push_back({a[1], a[2]});
    }
  }

  void addEdge(vector<int> edge) {
    _edges[edge[0]].push_back({edge[1], edge[2]});
  }
  int shortestPath(int node1, int node2) {
    vector<int> costs(_n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    costs[node1] = 0;
    pq.push({0, node1});

    while (!pq.empty()) {
      auto [curr_cost, curr_node] = pq.top();
      pq.pop();
      for (auto [next_node, next_cost] : _edges[curr_node]) {
        int cost = curr_cost + next_cost;
        if (cost >= costs[next_node]) continue;
        costs[next_node] = cost;
        pq.push({cost, next_node});
      }
    }

    if (costs[node2] == INT_MAX) return -1;
    return costs[node2];
  }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */