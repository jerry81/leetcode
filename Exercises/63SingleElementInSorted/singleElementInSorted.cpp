/*

540. Single Element in a Sorted Array
Medium
7.2K
121
Companies
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.



Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10


Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105

*/

#include <vector>

using namespace std;

class Solution {
  int dupeR(vector<int> nums, int low, int high) {
    cout << "low " << low << endl;
    cout << "high " << high << endl;
    int range = high - low;
    if (range == 1) return nums[low];

    if (range == 0) return nums[low];


    bool duped = false;
    int stored = -1;
    if (range < 5) {
        cout << "final check " << endl;
      for (int i = low; i < high; ++i) {
        if (nums[i] == stored) {
          duped = true;
        } else {
          if (stored != -1 && !duped) {
            return stored;
          }

          stored = nums[i];
          // stored 10
          // duped false
          cout << "stored is now "<<stored << endl;
          duped = false;
        }
      }
      return nums[high-1];
    }

    int mid = (high + low) / 2;
    cout << " mid is " << mid << endl;
    int pivot = nums[mid];
    int left = nums[mid-1];
    int right = nums[mid+1];
    if (pivot == left) {
      int potential_range = mid-2-low;
      if (potential_range % 2 == 1) {
        return dupeR(nums, mid+1, high);
      } else {
        return dupeR(nums, low, mid-1);
      }
    } else if (pivot == right) {
      int potential_range = high-mid-2;
      if (potential_range % 2 == 1) {
        return dupeR(nums, low, mid);
      } else {
        return dupeR(nums, (mid+2), high);
      }
    } else {
      return pivot;
    }
  }
public:
    int singleNonDuplicate(vector<int>& nums) {
      // binary search - check oddness of subarray lengths
      return dupeR(nums, 0, nums.size());
    }
};