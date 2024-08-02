
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int sz = nums.size();
        int totalOnes = 0;

        // Count total number of 1s in the array
        for (int num : nums) {
            if (num == 1) {
                totalOnes++;
            }
        }

        // Create a circular view by virtually doubling the array
        vector<int> circular(nums.begin(), nums.end());
        circular.insert(circular.end(), nums.begin(), nums.end());

        // Use sliding window to find maximum number of 1s in a window of size totalOnes
        int maxOnesInWindow = 0, currentOnes = 0;

        // Initialize the first window
        for (int i = 0; i < totalOnes; i++) {
            if (circular[i] == 1) {
                currentOnes++;
            }
        }
        maxOnesInWindow = currentOnes;

        // Slide the window
        for (int i = totalOnes; i < circular.size(); i++) {
            if (circular[i] == 1) {
                currentOnes++;
            }
            if (circular[i - totalOnes] == 1) {
                currentOnes--;
            }
            maxOnesInWindow = max(maxOnesInWindow, currentOnes);
        }

        // Calculate minimum swaps
        return totalOnes - maxOnesInWindow;
    }
};