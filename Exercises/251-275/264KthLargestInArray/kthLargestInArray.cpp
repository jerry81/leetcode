/*

215. Kth Largest Element in an Array
Medium
15K
719
Companies
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?



Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4


Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
Accepted
1.9M
Submissions
2.8M
Acceptance Rate
66.9%

*/

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct CustomComparator {
  bool operator()(int a, int b) const {
    return a > b;
  }
};
class Solution {


public:
    int findKthLargest(vector<int>& nums, int k) {

      priority_queue<int,vector<int>, CustomComparator> pq;
      pq.push(1);
      pq.push(2);
      cout << "expect 2 " << pq.top() << endl;
      return 0;
    }
};

/*

Input: nums = [3,2,1,5,6,4], k = 2

3,2 - 2
3,2,1 - 2
3,2,1,5 - 3
5,3,6 - 5


Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
*/