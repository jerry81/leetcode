/*

847. Shortest Path Visiting All Nodes
Hard
3.5K
146
Companies
You have an undirected, connected graph of n nodes labeled from 0 to n - 1. You are given an array graph where graph[i] is a list of all the nodes connected with node i by an edge.

Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.



Example 1:


Input: graph = [[1,2,3],[0],[0],[0]]
Output: 4
Explanation: One possible path is [1,0,2,0,3]
Example 2:


Input: graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
Output: 4
Explanation: One possible path is [0,1,4,2,3]


Constraints:

n == graph.length
1 <= n <= 12
0 <= graph[i].length < n
graph[i] does not contain i.
If graph[a] contains b, then graph[b] contains a.
The input graph is always connected.
Accepted
78.1K
Submissions
127K
Acceptance Rate
61.5%

*/

#include <vector>
#include <cmath>
#include <queue>

using namespace std;

struct State {
  int i;
  int cmask;
  int len=0;
  State(int i, int c):i(i), cmask(c) {};
};
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
      int sz = graph.size();
      int allVisitedMask = 0;
      vector<vector<bool>> visited(allVisitedMask, vector<bool>(sz));
      vector<int> masks;
      queue<State*> states;
      for (int i = 0; i < sz; ++i) {
        int p = pow(2,i);
        allVisitedMask+=p;
        masks.push_back(p);
        State* s = new State(i, p);
        states.push(s);
      }
      w

    }
};