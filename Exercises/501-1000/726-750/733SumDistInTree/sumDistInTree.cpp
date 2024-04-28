/*

834. Sum of Distances in Tree
Hard
Topics
Companies
There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n
- 1 edges.

You are given the integer n and the array edges where edges[i] = [ai, bi]
indicates that there is an edge between nodes ai and bi in the tree.

Return an array answer of length n where answer[i] is the sum of the distances
between the ith node in the tree and all other nodes.



Example 1:


Input: n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
Output: [8,12,6,10,10,10]
Explanation: The tree is shown above.
We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
equals 1 + 1 + 2 + 2 + 2 = 8.
Hence, answer[0] = 8, and so on.
Example 2:


Input: n = 1, edges = []
Output: [0]
Example 3:


Input: n = 2, edges = [[1,0]]
Output: [1,1]


Constraints:

1 <= n <= 3 * 104
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
ai != bi
The given input represents a valid tree.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
99.6K
Submissions
165.3K
Acceptance Rate
60.3%

*/

#include <vector>

using namespace std;

class Solution {
  vector<vector<int>> neighbors;
  vector<int> res;
  vector<int> counts;

  void build_dists(int node, int parent) {
    vector<int> neighs = neighbors[node];
    for (int n: neighs) {
      if (n == parent) continue;

      build_dists(n, node);

      counts[node] += counts[n];
      res[node] += res[n]+counts[n];
    }
  }

  void reroot(int prev, int from, int &n) {
    vector<int> neighs = neighbors[from];
    for (int to: neighs) {
      if (to == prev) continue;

      res[to] = res[from] + n - counts[to] - counts[to];
      reroot(from, to, n);
    }
  }

 public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    // edges are undirected
    // bfs
    /*
     so it turns out, bfs from any node will wor
    */
    /* this was right!*/
    neighbors.resize(n);
    for (vector<int> v : edges) {
      neighbors[v[0]].push_back(v[1]);
      neighbors[v[1]].push_back(v[0]);
    }

    counts.resize(n, 1);
    res.resize(n, 0);
    build_dists(0,-1);
    reroot(-1,0,n);
    // need another vec of dists
    // and counts, or just pairs
    // starting from 0, just make a dfs function that includes parent
    // skip parent and you will make your undirected graph directed
    // tree built, sum built to root.
    // this builds the initial tree
    // then the magic
    // dfs again,
    // at each
    // void reroot(int i, int parent, int n){
    // for (int j: adj[i]){
    //     if (j==parent) continue;
    //     sum[j]=sum[i]+n-2*cnt[j];
    //     reroot(j, i, n);
    // }
    //

    // bfs build tree
    // dfs make map
    // finally, dfs, gather sums
    // when bfs, must copy the tree at each parent for each child, may lead to
    // TLE/MLE
    return res;
  }
};