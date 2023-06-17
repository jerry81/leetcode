/*

1187. Make Array Strictly Increasing
Hard
829
19
Companies
Given two integer arrays arr1 and arr2, return the minimum number of operations (possibly zero) needed to make arr1 strictly increasing.

In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].

If there is no way to make arr1 strictly increasing, return -1.



Example 1:

Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
Output: 1
Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].
Example 2:

Input: arr1 = [1,5,3,6,7], arr2 = [4,3,1]
Output: 2
Explanation: Replace 5 with 3 and then replace 3 with 4. arr1 = [1, 3, 4, 6, 7].
Example 3:

Input: arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
Output: -1
Explanation: You can't make arr1 strictly increasing.


Constraints:

1 <= arr1.length, arr2.length <= 2000
0 <= arr1[i], arr2[i] <= 10^9


Accepted
14.4K
Submissions
31.6K
Acceptance Rate
45.6%

*/

#include <vector>

using namespace std;

class Solution {
int bsearch(vector<int>& arr, int tgt) {
  int retval = INT_MAX;
  int retidx = -1;
  int low = 0;
  int high = arr.size()-1;

  while (low < high) {
    int mid = (low+high) / 2;
    int val = arr[mid];
    if (val > tgt) {

      high = mid-1;
      if (retval > val) {
        retval = val;
        retidx = mid;
      }
    } else {
      low = mid+1;
    }
  }
  return retidx;
}

public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
      // sort arr2
      sort(arr2.begin(), arr2.end());
      // binary search helper to find first idx greater than val
      // for each item in arr1
      // if find a decrease
      // replace with binary search (greedy)
      // if no available then return -1.
    }
};