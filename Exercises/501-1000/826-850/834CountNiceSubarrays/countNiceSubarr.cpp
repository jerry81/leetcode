#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
      unordered_map<int, int> counts;
      int res = 0;
      int cur = 0;
      counts[0] = 1;
      for (int n: nums) {
        if (n%2 == 1) cur++;
        if (counts.find(cur-k) != counts.end()) {
          res+=counts[cur-k];
        }
        counts[cur]++;
      }
      return res;
    }
};