/*

a better, two pointer method to solve this

*/

#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 4) return {};
        sort(nums.begin(), nums.end());
        set<vector<int>> result_set;

        // Iterate through the array
        for (int i = 0; i < n - 3; ++i) {
            // Skip duplicates for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n - 2; ++j) {
                // Skip duplicates for the second number
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = j + 1, right = n - 1;

                // Use two pointers to find the remaining two numbers
                while (left < right) {
                    long long sum = (long long)(nums[i] + nums[j]) + (long long)(nums[left] + nums[right]);
                    if (sum == target) {
                        result_set.insert({nums[i], nums[j], nums[left], nums[right]});
                        // Skip duplicates for the third number
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        // Skip duplicates for the fourth number
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        left++;
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        vector<vector<int>> result(result_set.begin(), result_set.end());
        return result; // Return the result
    }
};