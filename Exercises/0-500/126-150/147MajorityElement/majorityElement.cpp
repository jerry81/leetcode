/*

169. Majority Element
Easy
14.8K
447
Companies
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.



Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2


Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109


Follow-up: Could you solve the problem in linear time and in O(1) space?
Accepted
1.7M
Submissions
2.7M
Acceptance Rate
63.9%

*/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
int mx = 0;
int maxE = 0;
public:
    int majorityElement(vector<int>& nums) {
      unordered_map<int, int> freq;
      for (int i: nums) {
        freq[i]++;
        int newv = freq[i];
        if (mx < newv) {
          mx = newv;
          maxE = i;
        }
      }
      return maxE;
    }
};