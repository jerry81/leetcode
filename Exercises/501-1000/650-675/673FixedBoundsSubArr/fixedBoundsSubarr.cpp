/*

*/

#include <vector>

using namespace std;

class Solution {
 public:
  long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    int curMin = INT_MAX;
    int curMax = INT_MIN;
    long long res = 0;
    int sz = nums.size();
    for (int l = 0; l < sz; ++l) {
      // find first index where conditions are satisfied
      int startR = -1;
      int endR = -1;
      for (int r = l; r < sz; ++r) {
        curMin = min(curMin, nums[r]);
        curMax = max(curMax, nums[r]);
        if (curMin == minK && curMax == maxK) {
          startR = startR < 0 ? r : startR;
        } else {
          if (startR >= l) {
            endR = r;
            break;
          }
        }
      }
      if (endR >= 0) {
        res += (endR - startR + 1);
      }
    }
    return res;
    // 2 ptr
  }
}