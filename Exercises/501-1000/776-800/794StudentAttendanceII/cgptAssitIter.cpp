#include <vector>

using namespace std;

class Solution {
    const int MOD = 1e9 + 7;
public:
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0))); // memoization

        dp[0][0][0] = 1; // Base case: one valid sequence of length 0

        // no recursion, use iteration
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 2; ++j) { // 'A' count can be 0 or 1
                for (int k = 0; k < 3; ++k) { // 'L' streak can be 0, 1, or 2
                    // Add 'P': resets 'L' streak
                    dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][k]) % MOD;

                    // Add 'A': increment 'A' count, resets 'L' streak
                    if (j < 1) {
                        dp[i][j + 1][0] = (dp[i][j + 1][0] + dp[i - 1][j][k]) % MOD;
                    }

                    // Add 'L': increment 'L' streak
                    if (k < 2) {
                        dp[i][j][k + 1] = (dp[i][j][k + 1] + dp[i - 1][j][k]) % MOD;
                    }
                }
            }
        }

        // Sum all valid sequences of length n
        int result = 0;
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                result = (result + dp[n][j][k]) % MOD;
            }
        }

        return result;
    }
};