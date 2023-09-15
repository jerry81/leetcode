/*

1584. Min Cost to Connect All Points
Medium
4.2K
99
Companies
You are given an array points representing integer coordinates of some points on
a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan
distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute
value of val.

Return the minimum cost to make all points connected. All points are connected
if there is exactly one simple path between any two points.



Example 1:


Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation:

We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.
Example 2:

Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18


Constraints:

1 <= points.length <= 1000
-106 <= xi, yi <= 106
All pairs (xi, yi) are distinct.
Accepted
199.6K
Submissions
306.1K
Acceptance Rate
65.2%

*/

#include <vector>

using namespace std;

class UnionFind {
 public:
  UnionFind(int n) {
    parent.resize(n);

    // Initialize each element as its own parent
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
    }
  }

  // Find operation with path compression
  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);  // Path compression
    }
    return parent[x];
  }

  // Union operation with rank optimization
  void unite(int x, int y) {
    int root_x = find(x);
    int root_y = find(y);

    if (root_x != root_y) {
      parent[root_y] = root_x;
    }
  }

  // Check if two elements are in the same set
  bool isConnected(int x, int y) { return find(x) == find(y); }

 private:
  vector<int> parent;  // Parent array for each element
};

struct Edge {
  int pointA;
  int pointB;
  int dist;
  Edge(int a, int b, int d) : pointA(a), pointB(b), dist(d){};
  void print() {
    cout << "edge is " << pointA << " to " << pointB << ": dist of " << dist
         << endl;
  }
};

static bool cCompare(Edge* a, Edge* b) { return a->dist < b->dist; }

class Solution {
 public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    vector<Edge*> edges;
    vector<vector<int>> distTo(n, vector<int>(n));
    for (int i = 0; i < n - 1; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int dist =
            abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
        edges.push_back(new Edge(i, j, dist));
      }
    }
    sort(edges.begin(), edges.end(), cCompare);
    int res = 0;
    UnionFind *uf = new UnionFind(n);
    int edgeCount = 0;
    for (Edge* e : edges) {
      // if doesn't make a cycle, add e
      int a = e->pointA;
      int b = e->pointB;
      if (!uf->isConnected(a,b)) {
        edgeCount++;
        uf->unite(a, b);
        res += e->dist;
      }
    }
    return res;
  }
};