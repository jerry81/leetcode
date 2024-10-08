/*

719. Find K-th Smallest Pair Distance
Hard
Topics
Companies
Hint
The distance of a pair of integers a and b is defined as the absolute difference between a and b.

Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.



Example 1:

Input: nums = [1,3,1], k = 1
Output: 0
Explanation: Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.
Example 2:

Input: nums = [1,1,1], k = 2
Output: 0
Example 3:

Input: nums = [1,6,1], k = 3
Output: 5


Constraints:

n == nums.length
2 <= n <= 104
0 <= nums[i] <= 106
1 <= k <= n * (n - 1) / 2
Seen this question in a real interview before?
1/5
Yes
No
Accepted
114.7K
Submissions
286.7K
Acceptance Rate
40.0%

*/

#include <vector>

using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int rng = *max_element(nums.begin(), nums.end());
        int sz = nums.size();
        vector<int> buckets(rng+1, 0);
        for (int i = 0; i < sz-1; ++i) {
            for (int j = i+1; j < sz; ++j) {
                int dist = abs(nums[i]-nums[j]);
                buckets[dist]+=1;
            }
        }
        int cnt = 0;
        while (k > 0) {
            k-=buckets[cnt];
            cnt++;
        }
        return cnt-1;
    }
};

// brute force but TLE:
        // get every pair?
        // first sort and stop at k
        // improvement 1 : use heap to store distances
        // cap heap size at k
        // finally remove top
/*
bucket sort
need bounded range of values
0 to max num - min num
*/

// brute force but TLE:
        // get every pair?
        // first sort and stop at k
        // improvement 1 : use heap to store distances
        // cap heap size at k
        // finally remove top
/*
bucket sort
need bounded range of values
0 to max num - min num
*/