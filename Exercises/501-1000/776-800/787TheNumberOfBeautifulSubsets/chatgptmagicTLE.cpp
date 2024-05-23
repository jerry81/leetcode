class Solution {
    unordered_map<string, int> memo;

    int r(int idx, int mask, vector<int>& nums, int k, int sz) {
        if (idx >= sz) return 0;

        // Create a unique key for the current state
        string key = to_string(idx) + "_" + to_string(mask);
        if (memo.find(key) != memo.end()) return memo[key];

        // Skip the current element
        int res = r(idx + 1, mask, nums, k, sz);

        // Include the current element if valid
        int cur = nums[idx];
        bool valid = true;
        for (int i = 0; i < sz; ++i) {
            if (mask & (1 << i)) {
                if (abs(nums[i] - cur) == k) {
                    valid = false;
                    break;
                }
            }
        }

        if (valid) {
            res += 1 + r(idx + 1, mask | (1 << idx), nums, k, sz);
        }

        memo[key] = res;
        return res;
    }

public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int sz = nums.size();
        memo.clear();
        return r(0, 0, nums, k, sz);
    }
};