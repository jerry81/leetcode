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
#include <cmath>

using namespace std;

struct Point {
  int y = -1;
  int x = -1;
  int weight = INT_MIN;
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
 string toH(int x, int y) { return to_string(y) + "," + to_string(x); };
 string toH(Point *p) { return toH(p->x, p->y); }
 public:
  int minimumEffortPath(vector<vector<int>>& heights) {
    int h = heights.size();
    int w = heights[0].size();
    if (h == 1 && w == 1) return 0;

    vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    Point *start = new Point(0,0,INT_MAX);
    unordered_map<string, bool> startst;
    startst[toH(start)] = true;
    State *cur = new State(start, startst);
    priority_queue<State*, vector<State*>, ComparePQ> pq;
    pq.push(cur);
    while (!pq.empty()) {
      cur = pq.top();
      Point *curp = cur->p;
      int cx = curp->x;
      int cy = curp->y;
      int cw = curp->weight;
      auto state = cur->visited;

      if (cx == w-1 && cy == h-1) return cw;
      pq.pop();
      // unvisited neighhbors -> queue
      for (auto d: dirs) {
        int ny = d[0] + cy;
        int nx = d[1] + cx;
        if (ny < 0) continue;
        if (nx < 0) continue;
        if (ny >= h) continue;
        if (nx >= w) continue;
        string hsh = toH(ny,nx);
        if (state[hsh]) continue;
        int nextDiff = abs(heights[ny][nx] - heights[cy][cx]);
        int nextW = max(nextDiff,cw);
        Point *np = new Point(ny,nx,nextW);
        unordered_map<string, bool> nextSt;
        nextSt = state;
        nextSt[hsh] = true;
        State *ns = new State(np, nextSt);
        pq.push(ns);
      }

    }
    return 0;
  }
};

// dfs + dp