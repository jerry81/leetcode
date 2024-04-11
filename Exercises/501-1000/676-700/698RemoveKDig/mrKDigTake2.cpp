#include <string>
#include <vector>
using namespace std;

class Solution {
  /* greedy */
  // returns the indexes of digits to remove
  string r(string remain, int k) {
    // stop when k is 0
    if (k == 0) return "";

    if (remain.size() <= k) return "";

    if (remain.size() < 2) return remain;

    // take it or leave it
    char first = remain[0];
    int second_idx = 1;
    int sz = remain.size();
    while (second_idx < sz) {
      char second = remain[second_idx];
      second_idx++;
      if (first > second) {
        remain.erase(0, 1);
        return r(remain, k - 1);
      } else if (first < second) {
        remain.erase(second_idx, 1);
        return r(remain, k - 1);
      }
    }

    return remain;  // never will reach here, right?
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