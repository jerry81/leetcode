/*

1631. Path With Minimum Effort
Medium
4.9K
164
Companies
You are a hiker preparing for an upcoming hike. You are given heights, a 2D
array of size rows x columns, where heights[row][col] represents the height of
cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to
travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can
move up, down, left, or right, and you wish to find a route that requires the
minimum effort.

A route's effort is the maximum absolute difference in heights between two
consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the
bottom-right cell.



Example 1:



Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in
consecutive cells. This is better than the route of [1,2,2,2,5], where the
maximum absolute difference is 3. Example 2:



Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in
consecutive cells, which is better than route [1,3,5,3,5]. Example 3:


Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.


Constraints:

rows == heights.length
columns == heights[i].length
1 <= rows, columns <= 100
1 <= heights[i][j] <= 106
Accepted
171.9K
Submissions
301.4K
Acceptance Rate
57.0%

*/

#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct Point {
  int y = -1;
  int x = -1;
  int weight = -1;
  string toH() { return to_string(y) + "," + to_string(x); };
  Point(int y, int x, int w) : y(y), x(x), weight(w){};
};

struct State {
  Point *p;
  unordered_map<string, bool> visited;
  State(Point *p, unordered_map<string, bool> st):p(p), visited(st){}
};

struct ComparePQ {
    bool operator()(State *a, State *b) { return a->p->weight < b->p->weight; }
};

class Solution {
 public:
  int minimumEffortPath(vector<vector<int>>& heights) {
    int h = heights.size();
    int w = heights[0].size();
    int startW = heights[0][0];

    unordered_map<string, bool> startst;
    Point *start = new Point(0,0,startW);
    State *cur = new State(start, startst);
    priority_queue<State*, vector<State*>, ComparePQ> pq;
    pq.push(cur);
    while (!pq.empty()) {
      cur = pq.top();
      Point *curp = cur->p;
      if (curp->x == w-1 && curp->y == h-1) return curp->weight;
      pq.pop();
    }
    return 0;
  }
};

// dfs + dp