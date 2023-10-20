/*

1013. Partition Array Into Three Parts With Equal Sum
Easy
1.6K
148
Companies
Given an array of integers arr, return true if we can partition the array into
three non-empty parts with equal sums.

Formally, we can partition the array if we can find indexes i + 1 < j with
(arr[0] + arr[1] + ... + arr[i] == arr[i + 1] + arr[i + 2] + ... + arr[j - 1] ==
arr[j] + arr[j + 1] + ... + arr[arr.length - 1])



Example 1:

Input: arr = [0,2,1,-6,6,-7,9,1,2,0,1]
Output: true
Explanation: 0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
Example 2:

Input: arr = [0,2,1,-6,6,7,9,-1,2,0,1]
Output: false
Example 3:

Input: arr = [3,3,6,5,-2,2,5,1,-9,4]
Output: true
Explanation: 3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4


Constraints:

3 <= arr.length <= 5 * 104
-104 <= arr[i] <= 104
Accepted
85.3K
Submissions
202.3K
Acceptance Rate
42.2%

*/

#include <vector>

using namespace std;

class Solution {
 public:
  bool canThreePartsEqualSum(vector<int>& arr) {
    // prefix sums
    vector<int> psums;
    int sz = arr.size();
    int cursum = 0;
    for (int i : arr) {
      cursum = i + cursum;
      psums.push_back(cursum);
    }
    for (int ptr1 = 1; ptr1 < sz - 1; ++ptr1) {
      for (int ptr2 = ptr1 + 1; ptr2 < sz; ++ptr2) {
        int sum1 = psums[ptr1];
        int sum2 = psums[ptr2] - psums[ptr1];
        if (sum2 != sum1) continue;
        int sum3 = psums.back() - psums[ptr2];
        if (sum3 == sum2) return true;
      }
    }
    return false;
  }
};