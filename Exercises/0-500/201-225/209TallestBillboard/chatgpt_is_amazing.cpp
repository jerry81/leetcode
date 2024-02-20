
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int tallestBillboard(vector<int>& rods) {
    int N = rods.size();
    int sum = accumulate(rods.begin(), rods.end(), 0); // this is how to sum.
    vector<vector<int>> dp(N + 1, vector<int>(2 * sum + 1, -1)); //
    dp[0][sum] = 0;

    for (int i = 1; i <= N; ++i) {
      for (int j = 0; j <= 2 * sum; ++j) {
        if (dp[i - 1][j] != -1) {
          // Do not use the current rod
          dp[i][j] = max(dp[i][j], dp[i - 1][j]);

          // Use the current rod as part of the higher support
          if (j - rods[i - 1] >= 0)
            dp[i][j - rods[i - 1]] = max(dp[i][j - rods[i - 1]], dp[i - 1][j] + rods[i - 1]);

          // Use the current rod as part of the lower support
          dp[i][j + rods[i - 1]] = max(dp[i][j + rods[i - 1]], dp[i - 1][j]);
        }
      }
    }

    return dp[N][sum] != -1 ? dp[N][sum] : 0;
  }
};