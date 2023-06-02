/*

2101. Detonate the Maximum Bombs
Medium
1.2K
83
Companies
You are given a list of bombs. The range of a bomb is defined as the area where its effect can be felt. This area is in the shape of a circle with the center as the location of the bomb.

The bombs are represented by a 0-indexed 2D integer array bombs where bombs[i] = [xi, yi, ri]. xi and yi denote the X-coordinate and Y-coordinate of the location of the ith bomb, whereas ri denotes the radius of its range.

You may choose to detonate a single bomb. When a bomb is detonated, it will detonate all bombs that lie in its range. These bombs will further detonate the bombs that lie in their ranges.

Given the list of bombs, return the maximum number of bombs that can be detonated if you are allowed to detonate only one bomb.



Example 1:


Input: bombs = [[2,1,3],[6,1,4]]
Output: 2
Explanation:
The above figure shows the positions and ranges of the 2 bombs.
If we detonate the left bomb, the right bomb will not be affected.
But if we detonate the right bomb, both bombs will be detonated.
So the maximum bombs that can be detonated is max(1, 2) = 2.
Example 2:


Input: bombs = [[1,1,5],[10,10,5]]
Output: 1
Explanation:
Detonating either bomb will not detonate the other bomb, so the maximum number of bombs that can be detonated is 1.
Example 3:


Input: bombs = [[1,2,3],[2,3,1],[3,4,2],[4,5,3],[5,6,4]]
Output: 5
Explanation:
The best bomb to detonate is bomb 0 because:
- Bomb 0 detonates bombs 1 and 2. The red circle denotes the range of bomb 0.
- Bomb 2 detonates bomb 3. The blue circle denotes the range of bomb 2.
- Bomb 3 detonates bomb 4. The green circle denotes the range of bomb 3.
Thus all 5 bombs are detonated.


Constraints:

1 <= bombs.length <= 100
bombs[i].length == 3
1 <= xi, yi, ri <= 105
Accepted
35.6K
Submissions
81.9K
Acceptance Rate
43.5%


*/

#include <vector>
#include <cmath>
#include <queue>

using namespace std;

class Solution {
vector<vector<int>> neighbors;
bool intersects(vector<int> cur, vector<int> comp) {
  // hit detection
  // dist between the two points <= radius
  int radius = cur[2];
  int curx = cur[0];
  int cury = cur[1];
  int compx = comp[0];
  int compy = comp[1];
  long long dx = abs(compx - curx);
  long long dy = abs(compy - cury);
  double dist = sqrt((dx*dx) + (dy*dy));
  return dist <= radius;
}

int bfs(int start, vector<bool>& visited) {
  vector<bool> bfsVisited(visited.size(), false);
  bfsVisited[start] = true;
  queue<int> nn;
  nn.push(start);
  int count = 0;
  while (!nn.empty()) {
    int cur = nn.front();
    nn.pop();
    count++;

    visited[cur] = true;
    for (int n: neighbors[cur]) {
      if (!bfsVisited[n]) {
        nn.push(n);
        bfsVisited[n] = true;
      }
    }
  }
  return count;
}

public:
    int maximumDetonation(vector<vector<int>>& bombs) {
      int number_of_bombs = bombs.size();
      neighbors.resize(number_of_bombs, vector<int>());
      // make neighbors
      for (int i = 0; i < bombs.size(); ++i) {
        vector<int> currentBomb = bombs[i];
        for (int j = 0; j < bombs.size(); ++j) {
          if (i == j) continue;

          vector<int> comparedBomb = bombs[j];
          if (intersects(currentBomb, comparedBomb)) neighbors[i].push_back(j);

        }
      }

      // get max path size
      int res = 0;
      vector<bool> pathCreated(number_of_bombs, false);
      for (int i = 0; i < number_of_bombs; ++i) {
        if (!pathCreated[i]) {
          int sz = bfs(i, pathCreated);

          if (sz > res) res = sz;
        }
      }

      return res;
    }
};

/*

try using bfs islands
n^2 comparison of each bomb to each other bomb?

AB AC AD AE...
BA BC BD BE... b/c AB != BA
CA CB CD CE...

example 1

AB - false     A: []
BA - true      B: [A]   B->A

example 3
- sbould be using disjoint union
A: [B,C] B, C->D->E, visited
B: [], visited
C: [D], [C->D->E, visited]
D: [E]  [D->E, visited]
E: [B,C,D] <- 3 - but revisiting of B, C, and D


failing case!
[[1,1,100000],[100000,100000,1]]
runtime error: signed integer overflow: 99999 * 99999 cannot be represented in type 'int' (solution.cpp)
*/