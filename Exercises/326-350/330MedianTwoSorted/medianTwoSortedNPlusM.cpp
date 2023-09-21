/*

4. Median of Two Sorted Arrays
Hard
25.7K
2.8K
Companies
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the
median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).



Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.


Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
Accepted
2.1M
Submissions
5.6M
Acceptance Rate
37.5%

*/

#include <vector>
using namespace std;

class Solution {
  double getMedian(vector<int>& nums) {
    int n = nums.size();
    if (n % 2 == 1) {
      return nums[(int)(n / 2)];
    } else {
      return ((double)nums[(int)(n / 2)] + (double)nums[(int)((n / 2) - 1)]) /
             (double)2.0;
    }
  }
  vector<int> merge(vector<int>& nums1, vector<int>& nums2, int& n1, int& n2) {
    int i1 = 0;
    int i2 = 0;
    vector<int> ret;
    while (i1 < n1 || i2 < n2) {
      int num1 = (i1 < n1) ? nums1[i1] : INT_MAX;
      int num2 = (i2 < n2) ? nums2[i2] : INT_MAX;
      if (num1 <= num2) {
        ret.push_back(num1);
        i1++;
      } else {
        ret.push_back(num2);
        i2++;
      }
    }
    return ret;
  }

 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    /*
    editorials back!
    merge, then get middle element
    */
    int n1 = nums1.size();
    int n2 = nums2.size();
    vector<int> merged = merge(nums1, nums2, n1, n2);

    return getMedian(merged);
  }
};