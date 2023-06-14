/*

405. Convert a Number to Hexadecimal
Easy
1.2K
198
Companies
Given an integer num, return a string representing its hexadecimal
representation. For negative integers, two’s complement method is used.

All the letters in the answer string should be lowercase characters, and there
should not be any leading zeros in the answer except for the zero itself.

Note: You are not allowed to use any built-in library method to directly solve
this problem.



Example 1:

Input: num = 26
Output: "1a"
Example 2:

Input: num = -1
Output: "ffffffff"


Constraints:

-231 <= num <= 231 - 1
Accepted
122.3K
Submissions
260.6K
Acceptance Rate
46.9%

*/

#include <string>

using namespace std;

class Solution {
  char hexTable[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                       '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

 public:
  string toHex(int num) {
    if (num == 0) return "0";
    string sol = "";
    uint unum;
    if (num < 0) {
      num*=-1;
      unum = num;
      unum = ~unum;
      unum+=1;
    } else {
      unum = num;
    }
    while (unum > 0) {
      sol = hexTable[unum%16] + sol;
      unum = unum/16;
    }
    return sol;
  }
};

// to fix, -2147483648 case