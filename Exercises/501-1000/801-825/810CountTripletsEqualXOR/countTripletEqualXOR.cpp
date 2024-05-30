/*

1442. Count Triplets That Can Form Two Arrays of Equal XOR
Medium
Topics
Companies
Hint
Given an array of integers arr.

We want to select three indices i, j and k where (0 <= i < j <= k < arr.length).

Let's define a and b as follows:

a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
Note that ^ denotes the bitwise-xor operation.

Return the number of triplets (i, j and k) Where a == b.



Example 1:

Input: arr = [2,3,1,6,7]
Output: 4
Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)
Example 2:

Input: arr = [1,1,1,1,1]
Output: 10


Constraints:

1 <= arr.length <= 300
1 <= arr[i] <= 108
Seen this question in a real interview before?
1/5
Yes
No
Accepted
43K
Submissions
55K
Acceptance Rate
78.2%

*/

#include <vector>

using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& arr) {
      int count = 0;
      // experiment
      int sz = arr.size();
      for (int i = 0; i < sz-1;++i) {
        for (int j = i+1; j < sz; ++j) {
          for (int k = j; k < sz; ++k) {
            int first = arr[i];
            for (int cur = i+1; cur < j; ++cur) {
              first ^= arr[cur];
            }
            int second = arr[j];
            for (int cur2 = j+1; cur2 <= k; ++cur2) {
              second ^= arr[cur2];
            }
            if (first == second) count++;
          }
        }
      }
      return count;
    }
};