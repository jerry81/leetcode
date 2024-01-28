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
    for (int i = 0; i < v.size() - 1; ++i) {
      for (int j = i + 1; j < v.size(); ++j) {
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
    map<int, int> pairs;
    for (vector<int> v : perms) {
      //  cout << endl;
      // for (int i: v) cout << i << ",";
      //  cout << endl;
      int cnt = count_inverse_pairs(v);
      pairs[cnt]++;
    }
    for (auto [k, v] : pairs) cout << "k: " << k << " v: " << v << endl;
    return 0;
  }
};

// n = 1 gives 1
// n = 2 gives 1 1
// n = 3 gives 1 2 2 1
// n = 4 gives 1 3 5 6 5 3 1
// n = 5 gives 1 4 9 15 20 22 20 15 9 4 1
// n = 6 gives 1 5 14 29 49 71 90 101 101 90 71 49 29 14 5 1
// n = 7 gives 1 6 20 49 98 169 259 359 455 531 573 573 531 455 359 259 169 98 49 20 6 1
