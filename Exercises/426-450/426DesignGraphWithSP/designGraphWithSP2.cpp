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

/*

why did pair perform better than vector?


You're correct. In general, vectors perform better than pairs for storing and accessing data. This is because vectors are dynamic arrays that can efficiently grow and shrink as needed, while pairs are fixed-size structures that cannot be resized.

However, the previous answer was specifically addressing the context of the provided graph implementation. In that context, using vector<vector<vector<int>>> _edges introduces additional layers of indirection and memory access overhead compared to vector<vector<pair<int, int>>> _edges, which can lead to worse performance, especially for larger graphs.

The reason for this difference is that accessing an edge in vector<vector<pair<int, int>>> _edges involves two levels of indirection (first to access the outer vector of pairs, and then to access the inner pair), while in vector<vector<vector<int>>> _edges, it involves three levels of indirection (first to access the outer vector of vectors, then to access the inner vector, and finally to access the integer value). This additional indirection can have a significant impact on performance, especially when dealing with large graphs with many edges.

In general, you should use vectors whenever possible for storing and accessing sequential data. Pairs can be useful for storing small amounts of data that are always used together, but they should be avoided for larger amounts of data or for data that needs to be frequently resized.

*/