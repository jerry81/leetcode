#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      int res = 0;
      int count = 0;

      vector<int> stk = {INT_MAX};
      for (int n: nums) {
        if (n <= stk.back()) {
          while (!stk.empty() && stk.back() >= n) {
            stk.pop_back();
          }
        }
        stk.push_back(n);
        res = max(res, (int)stk.size());
      }
      return res;
    }
};