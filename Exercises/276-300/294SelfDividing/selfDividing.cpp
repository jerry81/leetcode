/*

728. Self Dividing Numbers
Easy
1.6K
363
Companies
A self-dividing number is a number that is divisible by every digit it contains.

For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
A self-dividing number is not allowed to contain the digit zero.

Given two integers left and right, return a list of all the self-dividing numbers in the range [left, right].



Example 1:

Input: left = 1, right = 22
Output: [1,2,3,4,5,6,7,8,9,11,12,15,22]
Example 2:

Input: left = 47, right = 85
Output: [48,55,66,77]


Constraints:

1 <= left <= right <= 104
Accepted
215.8K
Submissions
276.4K
Acceptance Rate
78.1%

*/

#include <vector>
#include <string>

using namespace std;

class Solution {
  bool selfDividing(int i) {
    string s = to_string(i);
    for (int c: s) {
      int asi = c - '0';
      if (asi == 0) return 0;
      if (i % asi != 0) return false;
    }
    return true;
  }
public:
    vector<int> selfDividingNumbers(int left, int right) {
      vector<int> res;
      for (int i = left; i <= right; ++i) {
        if (selfDividing(i)) res.push_back(i);
      }
      return res;
    }
};