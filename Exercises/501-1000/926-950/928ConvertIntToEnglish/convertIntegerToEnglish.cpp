/*
273. Integer to English Words
Hard
Topics
Companies
Hint
Convert a non-negative integer num to its English words representation.



Example 1:

Input: num = 123
Output: "One Hundred Twenty Three"
Example 2:

Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"
Example 3:

Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"


Constraints:

0 <= num <= 231 - 1
Seen this question in a real interview before?
1/5
Yes
No
Accepted
393.2K
Submissions
1.3M
Acceptance Rate
31.0%
*/

// cover case
// 2,147,483,647

#include <string>
#include <vector>
using namespace std;
class Solution {
  const vector<string> ORDERS = {"Hundred", "Thousand", "Million", "Billion"};
  const vector<string> TENS = {"Twenty", "Thirty",  "Forty",  "Fifty",
                               "Sixty",  "Seventy", "Eighty", "Ninety"};
  const vector<string> TEENS = {"Ten",      "Eleven",  "Twelve",  "Thirteen",
                                "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                                "Eighteen", "Nineteen"};
  string convert_three(string num) {};

 public:
  string numberToWords(int num) {
    if (num == 0) return "Zero";
    return "";
  }
};