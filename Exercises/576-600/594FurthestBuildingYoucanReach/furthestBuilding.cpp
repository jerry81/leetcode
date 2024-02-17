#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    priority_queue<int, vector<int>, std::greater<int>> pq;
    for (int i = 0; i < heights.size() - 1; ++i) {
      int next = heights[i + 1];
      int current = heights[i];
      int diff = next - current;
      if (diff > 0) {
        pq.push(diff);
      }
      if (pq.size() > ladders) {
        bricks -= pq.top();
        pq.pop();
        if (bricks < 0) return i;
      }
    }
    return heights.size() - 1;
  }
};