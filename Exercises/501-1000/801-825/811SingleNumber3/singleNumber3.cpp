/*


260. Single Number III
Medium
Topics
Companies
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.



Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
Example 2:

Input: nums = [-1,0]
Output: [-1,0]
Example 3:

Input: nums = [0,1]
Output: [1,0]


Constraints:

2 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each integer in nums will appear twice, only two integers will appear once.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
362.3K
Submissions
527.1K
Acceptance Rate
68.7%

*/

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
      unordered_set<int> seen;
      unordered_set<int> dups;
      for (int n: nums) {
        if (seen.find(n) != seen.end()) dups.insert(n);

        seen.insert(n);
      }
      vector<int> res;
      for (int n: nums) {
        if (dups.find(n) != dups.end()) res.push_back(n);
      }
      return res;
    }
};