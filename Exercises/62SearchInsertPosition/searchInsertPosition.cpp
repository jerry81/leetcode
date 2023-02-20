/*

35. Search Insert Position
Easy
11.8K
531
Companies
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4


Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104
Accepted
2M
Submissions
4.7M
Acceptance Rate
42.6%

*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

    }
};

int main() {
  Solution s;
  vector<int> test1 = {1,3,5,6};
  cerr << "expect 2 " << s.searchInsert(test1, 5) << endl;
  vector<int> test2 = {1,3,5,6};
  cerr << "expect 1 " << s.searchInsert(test2, 2) << endl;
  vector<int> test1 = {1,3,5,6};
  cerr << "expect 4 " << s.searchInsert(test1, 7) << endl;
  return 0;
}