/*

1539. Kth Missing Positive Number
Easy
3.7K
275
Companies
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.



Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
Example 2:

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.


Constraints:

1 <= arr.length <= 1000
1 <= arr[i] <= 1000
1 <= k <= 1000
arr[i] < arr[j] for 1 <= i < j <= arr.length


Follow up:

Could you solve this problem in less than O(n) complexity?

Accepted
222.9K
Submissions
394.1K
Acceptance Rate


*/

#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
      vector<int> missing;
      int msize = 0;
      int curPtr = 0;
      int i = 0;
      while (true) {
        int expected = i+1;

        int curV = curPtr < arr.size() ? arr[curPtr] : -1;
        if (expected != curV) {
          missing.push_back(expected);
        } else {
          curPtr++;
        }
        if (missing.size() == k) {
          return missing[k-1];
        }
        ++i;
      }
      return 0;
    }
};

// O(n) - just loop and make a vector of missing ints until size k


// O(log n) ?
// start midway
// the # of missing integers up to that point is the value - the index
// if this missing integer count is GT k, try midpoint of lower half
// else try midpoint of upper half