/*

179. Largest Number
Medium
Topics
Companies
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.



Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"


Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 109

Seen this question in a real interview before?
1/5
Yes
No
Accepted
515.2K
Submissions
1.4M
Acceptance Rate
37.1%

*/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
      string res = "";


      vector<string> strs = vector<string>(nums.size());
      for (int i = 0; i < nums.size(); i++) {
        strs[i] = to_string(nums[i]);
      }


      sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
        return a + b > b + a;
      });

      for (auto s: strs) {
        res += s;
      }

      return res;
    }
};