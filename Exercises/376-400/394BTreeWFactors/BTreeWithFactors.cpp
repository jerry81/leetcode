/*

823. Binary Trees With Factors
Medium
2.6K
192
Companies
Given an array of unique integers, arr, where each integer arr[i] is strictly
greater than 1.

We make a binary tree using these integers, and each number may be used for any
number of times. Each non-leaf node's value should be equal to the product of
the values of its children.

Return the number of binary trees we can make. The answer may be too large so
return the answer modulo 109 + 7.



Example 1:

Input: arr = [2,4]
Output: 3
Explanation: We can make these trees: [2], [4], [4, 2, 2]
Example 2:

Input: arr = [2,4,5,10]
Output: 7
Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2,
5], [10, 5, 2].


Constraints:

1 <= arr.length <= 1000
2 <= arr[i] <= 109
All the values of arr are unique.
Accepted
95.1K
Submissions
190.3K
Acceptance Rate
50.0%

*/

#include <cmath>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  const int MOD = pow(10, 9) + 7;

 public:
  int numFactoredBinaryTrees(vector<int>& arr) {
    unordered_map<int,long long int> lookup;
    sort(arr.begin(),arr.end());
    long long res = 0;
    for (int cur : arr) {
      // get factors up to sqrt(cur);
      lookup[cur] = 1;  // add the inevitable one
      int upper = sqrt(cur);
      for (int i = 2; i <= upper; ++i) {
        if (cur % i != 0) continue;

        int f = cur / i;
        long long int addend = lookup[f] * lookup[i];
        addend %= MOD;
        if (f != i) {
          addend *= 2;
          addend %= MOD;
        }
        lookup[cur] += addend;
        lookup[cur] %= MOD;
      }
      res += lookup[cur];
      res %= MOD;
    }
    return res;
  }
};