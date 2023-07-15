/*

504. Base 7
Easy
705
213
Companies
Given an integer num, return a string of its base 7 representation.



Example 1:

Input: num = 100
Output: "202"
Example 2:

Input: num = -7
Output: "-10"


Constraints:

-107 <= num <= 107
Accepted
110K
Submissions
225.7K
Acceptance Rate
48.7%

*/

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
      bool neg = num < 0;
      string ret = "";
      num = abs(num);
      while (true) {
        if (num == 0) break;
        int rem = num % 7;
        char add = '0' + rem;
        ret = add + ret;
        num = num / 7;
      }
      if (neg) ret = '-'+ret;
      return ret;
      // 100 -> 202
      // 100%7 - 14*7 98?
      // r = 2, 100/7 = 14
      // 14%7 = 0
      // r = 2
    }
};

int main () {
  Solution s;
  cerr << "expect 202 " << s.convertToBase7(100) << endl;
}