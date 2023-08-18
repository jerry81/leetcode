/*

645. Set Mismatch
Easy
3.8K
886
Companies
You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.



Example 1:

Input: nums = [1,2,2,4]
Output: [2,3]
Example 2:

Input: nums = [1,1]
Output: [1,2]


Constraints:

2 <= nums.length <= 104
1 <= nums[i] <= 104
Accepted
280.2K
Submissions
659.2K
Acceptance Rate
42.5%

*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
      vector<int> res(2,0);
      for (int i = 1; i < nums.size();++i) {
        if (nums[i] == nums[i-1]) {
          res[0] = nums[i];
          continue;
        }

        if (nums[i] != nums[i-1] - 1) {
          res[1] = nums[i-1] + 1;
        }
      }
      return res;
    }
};