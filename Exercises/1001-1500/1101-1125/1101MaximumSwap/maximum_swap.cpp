/*

670. Maximum Swap
Medium
Topics
Companies
You are given an integer num. You can swap two digits at most once to get the maximum valued number.

Return the maximum valued number you can get.



Example 1:

Input: num = 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:

Input: num = 9973
Output: 9973
Explanation: No swap.


Constraints:

0 <= num <= 108
Seen this question in a real interview before?
1/5
Yes
No
Accepted
279.9K
Submissions
567.7K
Acceptance Rate
49.3%

*/

#include <vector>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
      vector<int> digits;
      // convert num into vector<int>
      vector<int> last_occurence_of_digit = vector(10, -1);
      string as_s = to_string(num);
      int n = as_s.size();
      for (int i = 0; i < n; ++i) {
        int dig = as_s[i] - '0';
        digits.push_back(dig);
        last_occurence_of_digit[dig] = i;
      }
      for (int ptr1 = 0; ptr1 < n; ++ptr1) {
        int d = digits[ptr1];
        if (d==9) continue;
        for (int i = 9; i > d; --i) {
          if (last_occurence_of_digit[i] > ptr1) {
            int ptr2 = last_occurence_of_digit[i];
            digits[ptr2] = d;
            digits[ptr1] = i;
            // create string and return
            int result = 0;
            for (int digit:digits) {
              result = result*10 + digit;
            }
            return result;
          }
        }
      }
      return num;
    }
};