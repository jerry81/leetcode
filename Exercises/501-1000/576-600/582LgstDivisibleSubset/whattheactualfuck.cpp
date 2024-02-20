#include <vector>

using namespace std;


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        sort(nums.begin(), nums.end());

        // split the lookups into two different vectors
        vector<int> dp(n, 1); // dp[i] stores the size of the largest divisible subset ending at nums[i]
        vector<int> prev(n, -1); // prev[i] stores the index of the previous element in the largest divisible subset ending at nums[i]

        int max_len = 1, max_idx = 0;

        // the magic - bottom up dp, sliding window
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1; // update dp[i]
                    prev[i] = j;
                }
            }
            if (dp[i] > max_len) {
                max_len = dp[i];
                max_idx = i;
            }
        }

        vector<int> result;
        // prev was just to rebuild the path
        int idx = max_idx;
        while (idx != -1) {
            result.push_back(nums[idx]);
            idx = prev[idx];
        }

        return result;
    }
};