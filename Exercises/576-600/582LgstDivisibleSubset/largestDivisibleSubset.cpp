#include <map>
#include <vector>

using namespace std;

class Solution {
  map<pair<int, int>, vector<int>> dp;
  vector<int> get_chain(int idx, int back, vector<int>& nums, int& sz) {
    if (idx >= sz) return {};

    if (dp.find({idx,back}) != dp.end()) return dp[{idx,back}];
    int cur = nums[idx];
    vector<int> curv = {cur};
    // leave case
    vector<int> orig = get_chain(idx + 1, back, nums, sz);
    if (cur % back == 0 || back % cur == 0) {
      vector<int> cmp = get_chain(idx + 1, cur, nums, sz);
      curv.insert(curv.end(), cmp.begin(), cmp.end());
    }
    dp[{idx, back}] = (curv.size() >= orig.size()) ? curv : orig;
    return dp[{idx, back}];
  }

 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int sz = nums.size();
    return get_chain(0, 1, nums, sz);
  }
};