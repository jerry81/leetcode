/*

1514. Path with Maximum Probability
Medium
1.9K
39
Companies
You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.



Example 1:



Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
Example 2:



Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
Output: 0.30000
Example 3:



Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
Output: 0.00000
Explanation: There is no path between 0 and 2.


Constraints:

2 <= n <= 10^4
0 <= start, end < n
start != end
0 <= a, b < n
a != b
0 <= succProb.length == edges.length <= 2*10^4
0 <= succProb[i] <= 1
There is at most one edge between every two nodes.
Accepted
70.5K
Submissions
142.5K
Acceptance Rate
49.5%

*/

#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
      // edge map
      unordered_map<int, unordered_map<int, pair<int,double>>> edgemap;
      for (int i = 0; i < edges.size(); ++i) {
        vector<int> edge = edges[i];
        edgemap[edge[0]][edge[1]] = {i,succProb[i]};
        edgemap[edge[1]][edge[0]] = {i,succProb[i]};
      }

      queue<pair<int,double>> nn; // item, weight
      // bfs start
      nn.push({start,1.0});
      vector<double> minProbs(n,0);

      double maxProb = 0.0;
      while (!nn.empty()) {
        auto [current, prob] = nn.front();
        nn.pop();
        if (current == end) {
          if (prob > maxProb) maxProb = prob;
        } else {
          // neighbors!
          auto neighbormap = edgemap[current];
          for (auto [neighborIdx, edgeMeta] : neighbormap) {
            auto [edgeIdx, edgeProb] = edgeMeta;
            double nextProb = edgeProb * prob;
            if (neighborIdx != current && !minProbs[neighborIdx] > nextProb) {
              minProbs[neighborIdx] = nextProb;
              nn.push({neighborIdx, nextProb});
            }
          }
        }
      }
      return maxProb;
    }
};
