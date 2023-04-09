/*

1857. Largest Color Value in a Directed Graph
Hard
714
22
Companies
There is a directed graph of n colored nodes and m edges. The nodes are numbered
from 0 to n - 1.

You are given a string colors where colors[i] is a lowercase English letter
representing the color of the ith node in this graph (0-indexed). You are also
given a 2D array edges where edges[j] = [aj, bj] indicates that there is a
directed edge from node aj to node bj.

A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk
such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The
color value of the path is the number of nodes that are colored the most
frequently occurring color along that path.

Return the largest color value of any valid path in the given graph, or -1 if
the graph contains a cycle.



Example 1:



Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
Output: 3
Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored "a"
(red in the above image). Example 2:



Input: colors = "a", edges = [[0,0]]
Output: -1
Explanation: There is a cycle from 0 to 0.


Constraints:

n == colors.length
m == edges.length
1 <= n <= 105
0 <= m <= 105
colors consists of lowercase English letters.
0 <= aj, bj < n
Accepted
16.1K
Submissions
38.9K
Acceptance Rate
41.5%

*/

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  struct Node {
    int val;
    vector<int> neighbors;
    char color;
    Node(int val, char color) : val(val), color(color){};
  };
  unordered_map<int, Node*> nodes;
  unordered_map<int, bool> traversed;

void dfs(Node* cur, unordered_map<char, int>& colorcount, unordered_map<int, bool> visited, bool& cycle) {
  if (cur == nullptr) return;

  if (cycle) return;

  if (visited[cur->val]) {
    cycle = true;
    return;
  }

  traversed[cur->val] = true;
  visited[cur->val] = true;
  colorcount[cur->color]++;

  for (int i: cur->neighbors) {
    dfs(nodes[i], colorcount, visited, cycle);
  }
}
 public:
  int largestPathValue(string colors, vector<vector<int>>& edges) {
    for (auto edgepair : edges) {
      int a = edgepair[0];
      int b = edgepair[1];
      if (nodes[a] == nullptr) {
        nodes[a] = new Node(a, colors[a]);
      }
      if (nodes[b] == nullptr) {
        nodes[b] = new Node(b, colors[b]);
      }
      nodes[a]->neighbors.push_back(b);
    }
    int max = 0;
    // for each untraversed node,
    // dfs getting count
    for (int i = 0; i < nodes.size(); ++i) {
      Node* n = nodes[i];
      if (traversed[i]) continue;

      unordered_map<char, int> colorcount;
      unordered_map<int, bool> visited;
      bool cycle = false;
      dfs(n, colorcount, visited, cycle);
      if (cycle) return -1;

      for (auto a: colorcount) {
        if (a.second > max) max = a.second;
      }
      // max of color count?
      // if ( > max) max = cur;
    }
    return max;
  }
};