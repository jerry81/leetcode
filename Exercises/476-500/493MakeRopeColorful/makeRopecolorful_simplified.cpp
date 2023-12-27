
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int minCost(string colors, vector<int>& neededTime) {
    // get blocks of a single color
    // pick the min out of those blocks.
    char prev_color = ' ';
    int cur_time_max = 0;
    int cur_time_accum = 0;
    int res = 0;
    for (int i = 0; i < colors.size(); ++i) {
      char cur_color = colors[i];
      int cur_time = neededTime[i];
      if (cur_color == prev_color) {
        cur_time_max = max(cur_time_max, cur_time);
        cur_time_accum += cur_time;
      } else {
        res += (cur_time_accum - cur_time_max);
        cur_time_accum = cur_time;
        cur_time_max = cur_time;
      }
    }

    return res;
  }
};