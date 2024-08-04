
class Solution {
public:
    int rangeSum(std::vector<int>& nums, int n, int left, int right) {
        // Min-heap to maintain the largest `right` sums
        int MOD = 1e9 + 7;
        std::priority_queue<long long int, std::vector<long long int>> minHeap;

        int sz = nums.size();

        // Generate all subarray sums
        for (int i = 0; i < sz; ++i) {
            long long int cur_sum = 0;
            for (int j = i; j < sz; ++j) {
                cur_sum += nums[j];

                // Push current sum into the min-heap
                minHeap.push(cur_sum);

                // If heap size exceeds `right`, pop the smallest element
                if (minHeap.size() > right) {
                    minHeap.pop();
                }
            }
        }

        // Sum up the top sums in the range from `left` to `right`
        long long int res = 0;
        int count = right - left + 1;
        std::vector<long long int> topSums(count);

        // Extract the top sums in reverse order (as we pop the largest elements first)
        for (int i = count - 1; i >= 0; --i) {
            topSums[i] = minHeap.top();
            minHeap.pop();
        }

        // Sum the required range
        for (int i = 0; i < count; ++i) {
            res += topSums[i];
        }

        return (int)(res % MOD);
    }
};