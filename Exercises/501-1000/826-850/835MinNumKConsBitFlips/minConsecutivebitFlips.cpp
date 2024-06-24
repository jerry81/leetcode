#include <vector>

using namespace std;
class Solution {
public:
    int minKBitFlips(std::vector<int>& nums, int k) {
        int n = nums.size();
        int flips = 0;
        int flipCount = 0;  // Keeps track of the current number of flips applied

        std::vector<int> isFlipped(n, 0);  // Auxiliary array to mark flips

        for (int i = 0; i < n; ++i) {
            if (i >= k) {
                flipCount -= isFlipped[i - k];  // Adjust flip count when moving the window
            }
            if ((nums[i] + flipCount) % 2 == 0) {  // If the current bit is 0 (after previous flips)
                if (i + k > n) {
                    return -1;  // If there aren't enough bits to flip
                }
                isFlipped[i] = 1;  // Mark a flip starting at index i
                flipCount++;
                flips++;
            }
        }

        return flips;
    }
};