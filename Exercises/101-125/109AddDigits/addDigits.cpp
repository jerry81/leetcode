/*

258. Add Digits
Easy
3.5K
1.8K
Companies
Given an integer num, repeatedly add all its digits until the result has only
one digit, and return it.



Example 1:

Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2
Since 2 has only one digit, return it.
Example 2:

Input: num = 0
Output: 0


Constraints:

0 <= num <= 231 - 1


Follow up: Could you do it without any loop/recursion in O(1) runtime?

Accepted
577.4K
Submissions
896.3K
Acceptance Rate
64.4%

*/

using namespace std;
#include <string>

class Solution {
 public:
  int addDigits(int num) {
    while (true) {
      string a = to_string(num);
      int sum = 0;
      for (char c: a) {
        sum+=(c-'0');
      }
      if (sum < 10) return sum;
      num = sum;
    }
  }
};

// naive first