#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

struct ComparePQ {
  bool operator()(vector<int> a, vector<int> b) { return a[2] > b[2]; }
};
class Graph {
  vector<vector<vector<int>>> _edges;
  int _n;

  string hashEdge(int a, int b) { return to_string(a) + "," + to_string(b); }

 public:
  Graph(int n, vector<vector<int>>& edges) {
    _n = n;
    _edges.resize(n);
    cout << "resized " << endl;
    for (auto a : edges) {
      _edges[a[0]].push_back({a[1], a[2]});
      cout << "from " << a[0] << " to " << a[1] << "with weight " << a[2] << endl;
    }

  }

  void addEdge(vector<int> edge) {
    _edges[edge[0]].push_back({edge[1], edge[2]});
    cout << "added " << edge[0] << " to " << edge[1] << "with weight " << edge[2] << endl;
  }

  int shortestPath(int node1, int node2) {
    cout << "sp start " << endl;
    vector<int> dists(_n, INT_MAX);
    priority_queue<vector<int>, vector<vector<int>>, ComparePQ> q;
    unordered_set<string> visited;

    dists[node1] = 0;
    cout << "dist 0 set " << endl;
    auto startingEdges = _edges[node1];
    for (auto v: startingEdges) {
      q.push({node1,v[0],v[1]});
    }
    while (!q.empty()) {
      auto cur = q.top();
      cout << "cur popped and is " << cur[0] << ","<<cur[1]<<","<<cur[2]<<endl;
      q.pop();
      int src = cur[0];
      int accumWeight = dists[src];
      int dest = cur[1];
      int weight = cur[2];

      dists[dest] = min(dists[dest], accumWeight + weight);
      visited.insert(hashEdge(src,dest));
      auto neighs = _edges[dest];
      for (auto newEdge: neighs) {
        if (visited.find(hashEdge(newEdge[0], newEdge[1])) != visited.end()) continue;

        q.push({dest,newEdge[0],newEdge[1]+accumWeight});
      }
    }
    cout << "sp end " << endl;
    return dists[node2] < INT_MAX ? dists[node2] : -1;
  }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */