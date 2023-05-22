/*

347. Top K Frequent Elements
Medium
13.6K
497
Companies
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.



Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]


Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.


Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

Accepted
1.4M
Submissions
2.2M
Acceptance Rate
64.0%

*/

#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
unordered_map<int, int> freq;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      vector<int> res;
      for (int n:nums) {
        freq[n]++;
      }
      return res;
    }
};

/*

init array from 0 to 20000

*/