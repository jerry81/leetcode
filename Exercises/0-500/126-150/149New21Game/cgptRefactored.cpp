class Solution {
 public:
  double new21Game(int n, int k, int maxPts) {
    if (k == 0) return 1.0;

    vector<double> dp(n + 1, 0.0);
    dp[0] = 1.0;
    double prob = 1.0 / maxPts;
    double ret = 0.0;
    double sum = 1.0;

    for (int i = 1; i <= n; ++i) {
      if (i > maxPts) {
        sum -= dp[i - maxPts - 1];
      }
      dp[i] = sum * prob;
      if (i < k) {
        sum += dp[i];
      }
    }

    for (int i = k; i <= n && i < k + maxPts; ++i) {
      ret += dp[i];
    }

    return ret;
  }
};