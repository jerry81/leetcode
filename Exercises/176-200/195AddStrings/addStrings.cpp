/*

415. Add Strings
Easy
4.5K
662
Companies
Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.



Example 1:

Input: num1 = "11", num2 = "123"
Output: "134"
Example 2:

Input: num1 = "456", num2 = "77"
Output: "533"
Example 3:

Input: num1 = "0", num2 = "0"
Output: "0"


Constraints:

1 <= num1.length, num2.length <= 104
num1 and num2 consist of only digits.
num1 and num2 don't have any leading zeros except for the zero itself.
Accepted
574.7K
Submissions
1.1M
Acceptance Rate
52.3%

*/

#include <string>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
      // long addition problem
      string sum = "";
      int longer = max(num1.size(), num2.size());
      int carry = 0;
      for (int i = 0; i < longer; ++i) {
        int idx1 = num1.size() - 1 - i;
        int idx2 = num2.size() - 1 - i;
        int addend1 = 0;
        if (idx1 > -1) addend1 = num1[idx1] - '0';
        int addend2 = 0;
        if (idx2 > -1) addend2 = num2[idx2] - '0';
        int sumi = addend1 + addend2 + carry;
        if (sumi > 10) {
          carry = 1;
        } else {
          carry = 0;
        }
        sumi %= 10;
        sum = (char)(sumi + '0') + sum;
      }
      if (carry == 1) sum = '1' + sum;
      return sum;
    }
};