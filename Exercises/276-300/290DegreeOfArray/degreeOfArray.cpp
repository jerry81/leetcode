/*


class Solution {
public:
    int bestClosingTime(string customers) {
      int n = customers.size();
      // prefix sum of Y
      vector<int> yes;
      int accum = 0;
      for (char c: customers) {
        if (c == 'Y') accum++;

        yes.push_back(accum);
      }

      int beginV = yes[n-1];
      int endV = n - yes[n-1];
      int minV;
      int minI;
      if (beginV <= endV) {
        minI = 0;
        minV = beginV;
      } else {
        minI = n;
        minV = endV;
      }

      // handle edges
      // close at 0 - y count
      // total no count
      for (int i = 1; i < n; ++i) {

        int penaltyBefore = i - yes[i-1]; // N count to i
        int penaltyAfter = yes[n-1] - yes[i]; // Y count after i

        int cur = penaltyBefore + penaltyAfter;
        if (customers[i] == 'Y') cur++;

        if (minV > cur || (minV >= cur && minI > i)) {
          minV = cur;
          minI = i;
        }
      }
      return minI;
    }
};

*/

#include <vector>

using namespace std;

class Solution {
  struct Num {
    int first = -1;
    int last = -1;
    int freq = 0;
  };
  static bool compare(Num a, Num b) {
    if (a.freq > b.freq) return true;

    int alen = a.last - a.first;
    int blen = b.last - b.first;

    return (alen > blen);
  }

 public:
  int findShortestSubArray(vector<int>& nums) {
    // struct - first idx, freq, last idx
    vector<Num> lookup(50000);
    for (int i = 0; i < nums.size(); ++i) {
      Num item = lookup[nums[i]];
      item.freq++;
      if (item.first < 0) item.first = i;
      item.last = i;
      lookup[nums[i]] = item;
    }
    sort(lookup.begin(), lookup.end(), compare);
  }
};
