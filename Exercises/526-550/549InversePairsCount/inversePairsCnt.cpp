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
#include <vector>

using namespace std;

class Solution {
  vector<vector<int>> perms;

  void dfs(vector<int> cur, vector<int> remain) {
    if (remain.empty()) perms.push_back(cur);

    for (int i = 0; i < remain.size(); ++i) {
      vector<int> rm_cpy = remain;
      vector<int> cur_cpy = cur;
      cur_cpy.push_back(rm_cpy[i]);
      rm_cpy.erase(rm_cpy.begin() + i);
      dfs(cur_cpy, rm_cpy);
    }
  }

  int count_inverse_pairs(vector<int> v) {
    int res = 0;
    for (int i = 0; i < v.size()-1; ++i) {
      for (int j = i+1; j < v.size(); ++j) {
        if (v[i] > v[j]) res++;
      }
    }
    return res;
  }

 public:
  int kInversePairs(int n, int k) {
    // print stuff out, look for a pattern
    vector<int> nums;
    for (int i = 1; i <= n; ++i) {
      nums.push_back(i);
    }

    dfs({}, nums);

    for (vector<int> v: perms) {
      cout << endl;
      for (int i: v) cout << i << ",";
      cout << endl;
      cout << " has " << count_inverse_pairs(v) << " items"<<endl;
    }
    return 0;
  }
};