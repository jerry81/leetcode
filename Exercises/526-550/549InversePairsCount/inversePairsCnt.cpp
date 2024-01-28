/*

629. K Inverse Pairs Array
Hard
Topics
Companies
For an integer array nums, an inverse pair is a pair of integers [i, j] where 0
<= i < j < nums.length and nums[i] > nums[j].

Given two integers n and k, return the number of different arrays consist of
numbers from 1 to n such that there are exactly k inverse pairs. Since the
answer can be huge, return it modulo 109 + 7.



Example 1:

Input: n = 3, k = 0
Output: 1
Explanation: Only the array [1,2,3] which consists of numbers from 1 to 3 has
exactly 0 inverse pairs. Example 2:

Input: n = 3, k = 1
Output: 2
Explanation: The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.


Constraints:

1 <= n <= 1000
0 <= k <= 1000

*/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  int kInversePairs(int n, int k) {
    vector<vector<int>> dp(1001, vector<int>(1001, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        cout << "n is now " << i << endl;
        cout << "printing prev" << endl;
        int j = 0;
        while (dp[i-1][j] != 0) {
            cout << dp[i-1][j] << endl;
            j++;
        }
      dp[i][0] = 1;
      int idx = 1;
      int sm = 1;
      while (true) {
        sm+=dp[i-1][idx];
        int left =  idx - i + 1;

        if (left > 0) {
          sm -= dp[i-1][left-1];
        }
        if (sm == 0) break;

        dp[i][idx] = sm;
        idx++;
      }
    }
    return dp[n][k];
  }
};