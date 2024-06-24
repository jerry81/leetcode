#include <vector>

using namespace std;


class Solution {
    int r(std::vector<int>& nums, int k, int idx, int sz) {
        // Base case 1
        if (idx >= sz) return 0;

        // Find the first non-1 bit
        int new_start = idx;
        while (new_start < nums.size() && nums[new_start] == 1) {
            new_start++;
        }

        // If all bits are 1, return 0 flips needed
        if (new_start >= nums.size()) return 0;

        // If there are not enough bits left to flip, return -1
        if (new_start + k > nums.size()) return -1;

        // Flip the k bits starting from new_start
        for (int i = 0; i < k; ++i) {
            nums[new_start + i] = nums[new_start + i] == 1 ? 0 : 1;
        }

        // Recursively process the remaining part
        int res = r(nums, k, new_start, sz);

        if (res == -1) return -1;

        return 1 + res;
    }

public:
    int minKBitFlips(std::vector<int>& nums, int k) {
        int sz = nums.size();
        return r(nums, k, 0, sz);
    }
};
