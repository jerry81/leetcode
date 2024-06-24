#include <vector>

using namespace std;


class Solution {
    int r(std::vector<int>& nums, int k) {
        // Base case 1
        if (nums.empty()) return 0;

        // Find the first non-1 bit
        int new_start = 0;
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


        // Create a new vector excluding the first flipped part
        std::vector<int> new_nums(nums.begin() + new_start + 1, nums.end());

        // Recursively process the remaining part
        int res = r(new_nums, k);

        if (res == -1) return -1;

        return 1 + res;
    }

public:
    int minKBitFlips(std::vector<int>& nums, int k) {
        return r(nums, k);
    }
};
