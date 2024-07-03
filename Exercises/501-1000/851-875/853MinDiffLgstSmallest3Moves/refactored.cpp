#include <vector>

using namespace std;

class Solution {
public:
    int minDifference(std::vector<int>& nums) {
        if (nums.size() < 4) return 0;

        std::sort(nums.begin(), nums.end());

        int n = nums.size();
        int res = INT_MAX;

        // Compare the differences by removing up to 3 smallest or largest elements
        for (int i = 0; i <= 3; ++i) {
            res = min(res, nums[n - 4 + i] - nums[i]);
        }

        return res;
    }
};
