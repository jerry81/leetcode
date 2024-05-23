
class Solution {
  int res = 0;
  unordered_map<int,int> lookup;
  void r(int idx, vector<int>& nums, int k, int sz) {
    if (idx >= sz) return;

    int nxt = idx + 1;
    int cur = nums[idx];
    if (lookup.find(cur + k) == lookup.end() &&
        lookup.find(cur - k) == lookup.end()) {
        res += 1;
        lookup.[cur]++;
        r(nxt, nums, k, sz);
        lookup[cur]--;
        if (lookup[cur] == 0) lookup.erase(cur);
    }
    r(nxt, nums, k, sz);
  }

 public:
  int beautifulSubsets(vector<int>& nums, int k) {
    // subset = knapsack
    // knapsack with early term
    int sz = nums.size();
    r(0, nums, k, sz);
    return res;
  }
};