#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
  unordered_map<int, vector<int>> dp;
  vector<int> get_chain(int idx, vector<int>& nums, int &sz) {
    vector<int> res;
    for (int i = idx; i < sz; ++i) {
      int cur = nums[i];
      if (res.empty()) {
        res.push_back(cur);
      } else {
        int curb = res.back();
        if (cur % curb == 0 || curb % cur == 0) res.push_back(nums[i]);
      }
    }
    return res;
  }

 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    vector<int> res;
    sort(nums.begin(), nums.end());
    int sz = nums.size();
    for (int idx = 0; idx < sz; ++idx) {
      vector<int> brute = get_chain(idx,nums,sz);
      if (brute.size() > res.size()) res = brute;
    }
    return res;
  }
};