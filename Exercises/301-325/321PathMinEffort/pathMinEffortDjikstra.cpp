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

#include <cmath>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct Point {
  int y = -1;
  int x = -1;
  int weight = INT_MAX;
  Point(int y, int x) : y(y), x(x){};
};

struct ComparePQ {
  bool operator()(Point *a, Point *b) { return a->weight > b->weight; }
};

class Solution {
  unordered_map<string, bool> visited;
  string toH(int y, int x) { return to_string(y) + "," + to_string(x); };
  string toH(Point *p) { return toH(p->y, p->x); }

 public:
  int minimumEffortPath(vector<vector<int>> &heights) {
    int h = heights.size();
    int w = heights[0].size();
    if (h == 1 && w == 1) return 0;

    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    Point *cur = new Point(0, 0);
    cur->weight = 0;
    priority_queue<Point *, vector<Point *>, ComparePQ> pq;
    pq.push(cur);
    int counter = 0;
      while (!pq.empty() && counter < 50) {
       counter++;
        cur = pq.top();
        int cx = cur->x;
        int cy = cur->y;
        int cw = cur->weight;
        if (cx == w-1 && cy == h-1) return cw;

        visited[toH(cur)] = true;
        pq.pop();
        // unvisited neighhbors -> queue
        for (auto d : dirs) {
          int ny = d[0] + cy;
          int nx = d[1] + cx;
          if (ny < 0) continue;
          if (nx < 0) continue;
          if (ny >= h) continue;
          if (nx >= w) continue;
          string hsh = toH(ny, nx);
          if (visited[hsh]) continue;
          int nextDiff = abs(heights[ny][nx] - heights[cy][cx]);
          int nextW = max(nextDiff, cw);
          Point *np = new Point(ny,nx);
          np->weight = nextW;
          pq.push(np);
        }
    }
    return 0;
  }
};

// bfs + pq
// mem limit exceeded... fack!

// double adds are happening brah