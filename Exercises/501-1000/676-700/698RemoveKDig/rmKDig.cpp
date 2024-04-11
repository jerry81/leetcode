/*

402. Remove K Digits
Medium
Topics
Companies
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.



Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.


Constraints:

1 <= k <= num.length <= 105
num consists of only digits.
num does not have any leading zeros except for the zero itself.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
369.5K
Submissions
1.2M
Acceptance Rate
31.2%

*/

#include <string>
#include <vector>

using namespace std;

class Solution {
// returns the indexes of digits to remove
vector<int> r(string remain, int k, int cur_idx) {
  // stop when k is 0
  if (k == 0) return {};
  if (remain.size() <= k) {
    vector<int> res = {};
    for (int i = cur_idx; i < remain.size(); ++i) {
      res.push_back(i);
      return res;
    }
  }

  // take it or leave it
  char first = remain[0];
  char second = remain[1];
  if (first < second) {
    return r(remain.substr(1), k, cur_idx+1);
  } else {
    vector<int> res = {cur_idx};
    vector<int> use = r(remain.substr(1), k-1, cur_idx+1);
    res.insert(res.end(), use.begin(), use.end());
    return res;
  }
  return {}; // never will reach here, right?
}

public:
    string removeKdigits(string num, int k) {
      // edge cases
      if (k == num.size()) return "0";

      // binary choice
      // take or leave current item.
      vector<int> to_rmv = r(num, k, 0);
      for (int i = k-1; i >= 0; --i) { // TIL: cool trick to remove indexes from a list
        num.erase(to_rmv[i],1);
      }
      return num;
    }
};