/*
2290. Minimum Obstacle Removal to Reach Corner
Hard
Topics
Companies
Hint
You are given a 0-indexed 2D integer array grid of size m x n. Each cell has one of two values:

0 represents an empty cell,
1 represents an obstacle that may be removed.
You can move up, down, left, or right from and to an empty cell.

Return the minimum number of obstacles to remove so you can move from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1).



Example 1:


Input: grid = [[0,1,1],[1,1,0],[1,1,0]]
Output: 2
Explanation: We can remove the obstacles at (0, 1) and (0, 2) to create a path from (0, 0) to (2, 2).
It can be shown that we need to remove at least 2 obstacles, so we return 2.
Note that there may be other ways to remove 2 obstacles to create a path.
Example 2:


Input: grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]]
Output: 0
Explanation: We can move from (0, 0) to (2, 4) without removing any obstacles, so we return 0.


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 105
2 <= m * n <= 105
grid[i][j] is either 0 or 1.
grid[0][0] == grid[m - 1][n - 1] == 0

Seen this question in a real interview before?
1/5
Yes
No
Accepted
34.5K
Submissions
59.8K
Acceptance Rate
57.7%
*/

#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;


struct ComparePQ {
  bool operator()(pair<int, int> a, pair<int,int> b) { return a.first > b.first; }
};

class Solution {
const vector<pair<int, int>> NEIGHBORS = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
pair<int,int> coords_from_id(int id, int h, int w) {
  int row = id / w;

  return {row, id-(row-1)*w};
}
int id_from_coords(int y, int x, int h, int w) {
  return y*w + x;
}
public:
    int minimumObstacles(vector<vector<int>>& grid) {
       int h = grid.size();
       int w = grid[0].size();

      //  for (int i = 0; i < h; ++i) {
      //    for (int j = 0; j < w; ++j) {
      //      int id = id_from_coords(i,j,h,w);
      //      auto [r,c] = coords_from_id(id, h,w);
      //    }
      //  }
       unordered_set<int> visited;
       priority_queue<pair<int,int>, vector<pair<int,int>>, ComparePQ> q;
      //  q.push({2,1});
      //  q.push({1,1});
      //  q.push({0,0});
      int tgt = h*w-1;
       visited.insert({0,0});


       while (!q.empty()) {
         auto [weight, id] = q.top();
         if (id == tgt) return weight;

         q.pop();
         auto [cy,cx] = coords_from_id(id,h,w);
         for (auto [dy,dx]: NEIGHBORS) {
           int ny = dy + cy;
           int nx = dx + cx;
           if (ny < 0 || nx < 0) continue;

           if (ny >= h || nx >= w) continue;

           int new_id = id_from_coords(ny,nx,h,w);
           if (visited.find(new_id) != visited.end()) continue;

           visited.insert(new_id);
           int val = grid[ny][nx];
           int nw = weight;
           if (val) nw++;

           q.push({nw, new_id});
         }
       }
       return 0;
    }
};


/*
djikstra!
edges built in to the graph
*/