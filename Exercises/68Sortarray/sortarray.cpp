/*

Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.



Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.


Constraints:

1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104
Accepted
371.9K
Submissions
634.4K
Acceptance Rate
58.6%

*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {

// use swaps as they cost the least
// swap built-in in std

int partition(vector<int>& nums, int low, int high) {

  int lowT = (low-1);
  int pivot = nums[high];
  for (int i = low; i < high; ++i) {
    int cur = nums[i];
    if (cur < pivot) {
      lowT++;;
      swap(nums[i], nums[lowT]);
    }
  }
  swap(nums[(lowT+1)],nums[high]);
  return (lowT+1);
}

void qSort(vector<int>& nums, int low, int high) {
  for (int i: nums) cerr << i << " ";
  if (low < high) {
    int idx = partition(nums, low, high);
    qSort(nums, low, idx-1);
    qSort(nums, idx+1, high);
  }
}
public:
    vector<int> sortArray(vector<int>& nums) {
      // requires nlogn time, so need to do quicksort (the divide and conquer one)
      qSort(nums, 0, nums.size()-1);
      return nums;
    }
};

int main () {
  Solution s;
  vector<int> input1 = {5,2,3,1};
  vector<int> output1 = s.sortArray(input1);
  cerr << "expect [1,2,3,5] " <<  endl;
  for (int i: output1) cerr << i << " ";
  cerr << endl;
  return 0;
}