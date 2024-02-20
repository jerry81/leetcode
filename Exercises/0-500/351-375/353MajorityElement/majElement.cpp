/*

229. Majority Element II
Medium
8.3K
364
Companies
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.



Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]


Constraints:

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109


Follow up: Could you solve the problem in linear time and in O(1) space?

Accepted
478.4K
Submissions
1M
Acceptance Rate
47.2%

*/

#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      int s = nums.size();
      double third = s/3.0;
      unordered_map<int,int> freq;
      unordered_set<int> asSet;

      for (int i: nums) {
        freq[i]++;
        if (freq[i] > third) {
          asSet.insert(i);
        }
      }
      vector<int> ret(asSet.begin(),asSet.end());
      return ret;
    }
};