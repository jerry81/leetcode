#include <string>
#include <vector>
using namespace std;

class Solution {
  /* greedy */
  // returns the indexes of digits to remove
  string r(string remain, int k) {\
    // stop when k is 0
    if (k == 0) return remain;

    if (remain.size() <= k) return "";

    if (remain.size() < 2) return remain;

    // take it or leave it
    int idx = 0;
    int sz = remain.size();
    while (idx < sz-1) {
      char first = remain[idx];
      char second = remain[idx+1];
      if (first > second) {
        remain.erase(idx,1);
        return r(remain, k - 1);
      }
      idx++;
    }
    remain.pop_back();
    return r(remain, k-1);  // never will reach here, right?
  }

 public:
  string removeKdigits(string num, int k) {
    // edge cases
    if (k >= num.size()) return "0";

    string ret = r(num, k);

    if (ret.empty()) return "0";

    // trim 0's.
    while (ret.size() > 1) {
      if (ret[0] == '0') {
        ret.erase(0, 1);
      } else {
        break;
      }
    }

    return ret;
  }
};

/*

fundamental mistake

"12345"
k = 2
fails in case of greedy

we greedy remove 2 then 3 according to our algo

*/