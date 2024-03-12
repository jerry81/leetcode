#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      int sz = nums.size();
      vector<int> dp(sz,1);
      for (int i = 1; i < sz; ++i) {
        for (int j = 0; j < i; ++j) {
          if (nums[i] > nums[j]) {
            dp[i] = max(dp[i], 1+dp[j]);
          }
        }
      }
      return *max_element(dp.begin(), dp.end());
    }
};