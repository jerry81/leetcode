/*

2492. Minimum Score of a Path Between Two Cities
Medium
705
133
Companies
You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road between cities ai and bi with a distance equal to distancei. The cities graph is not necessarily connected.

The score of a path between two cities is defined as the minimum distance of a road in this path.

Return the minimum possible score of a path between cities 1 and n.

Note:

A path is a sequence of roads between two cities.
It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the path.
The test cases are generated such that there is at least one path between 1 and n.


Example 1:


Input: n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
Output: 5
Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 4. The score of this path is min(9,5) = 5.
It can be shown that no other path has less score.
Example 2:


Input: n = 4, roads = [[1,2,2],[1,3,4],[3,4,7]]
Output: 2
Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 1 -> 3 -> 4. The score of this path is min(2,2,4,7) = 2.


Constraints:

2 <= n <= 105
1 <= roads.length <= 105
roads[i].length == 3
1 <= ai, bi <= n
ai != bi
1 <= distancei <= 104
There are no repeated edges.
There is at least one path between 1 and n.
Accepted
30.6K
Submissions
57.5K
Acceptance Rate
53.3%

*/

// are we just doing djikstra's again?

// after reading instructions again, this is not djikstra
// this is an islands problem - find the reachable nodes from 1, the min path is in this set.  b/c if 1 can reach it, 4 can reach it too.

/*

1.  Nodes
2.  Neighbors

*/
#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>

using namespace std;
class Solution {
struct Node {
  unordered_map<int, int> neighbors;
  int id;
  void print() {
    for (auto a: neighbors) {
      cout << "i have a neighbor " << a.first << ", " << a.second << " away." << endl;
    }
  }
};
int ncount;
vector<Node*> nodes;
void makeNodes() {
  for (int i = 0; i < ncount; ++i) {
    Node *n = new Node();
    n->id = i;
    nodes.push_back(n);
  }
}
void makeNeighbors(vector<vector<int>> roads) {
  for (vector<int> v: roads) {
    int from = v[0] - 1;
    int to = v[1] - 1;
    int dist = v[2];
    nodes[from]->neighbors[to] = dist;
    nodes[to]->neighbors[from] = dist;
  }
}

void printme() {
  int count = 0;
  for (Node* n: nodes) {
    cout << "i am node " << count << endl;
    n->print();
    count++;
  }
}

int bfsFindMin() {
  unordered_map<int, bool> visited;
  int res = 99999999;
  Node* start = nodes[0];
  visited[0] = true;
  queue<Node*> neighbors;
  neighbors.push(start);
  while (!neighbors.empty()) {
    Node* cur = neighbors.front();
    visited[cur->id] = true;
    neighbors.pop();
    for (auto a: cur->neighbors) {
      if (a.second < res) res = a.second;

      if (!visited[a.first]) {
        neighbors.push(nodes[a.first]);
      }
    }
  }
  return res;
}
public:
    int minScore(int n, vector<vector<int>>& roads) {
      ncount = n;
      makeNodes();
      makeNeighbors(roads);
      return bfsFindMin();
    }
};

int main() {
  Solution s;
  vector<vector<int>> test1 = {{12,7,2151},{7,2,7116},{11,14,8450},{11,2,9954},{1,11,3307},{10,7,3561},{10,1,4986},{11,7,7674},{14,2,1764},{11,12,6608},{14,7,1070},{9,8,2287},{14,12,6559},{1,2,1450},{2,12,9165}};
  cerr << "expect 1070 " <<  s.minScore(14, test1) << endl;
  vector<vector<int>> test2 = {{6,2,7},{3,7,2},{9,6,5},{2,4,9},{7,8,7},{8,4,5},{6,1,10}};
  cerr << "expect 2 " << s.minScore(9, test2) << endl;
  return 0;
}