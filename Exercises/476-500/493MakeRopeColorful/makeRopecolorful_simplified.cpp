
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
      // get blocks of a single color
      // pick the min out of those blocks.
      char prev_color = ' ';
      int cur_time = INT_MAX;
      int res = 0;
      for (int i = 0; i < colors.size(); ++i) {
        char cur_color = colors[i];
      }

      return res;
    }
};