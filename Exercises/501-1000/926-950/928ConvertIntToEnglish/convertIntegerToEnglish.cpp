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
  const vector<string> ORDERS = {"Thousand", "Million", "Billion"};
  const vector<string> TENS = {"Twenty", "Thirty",  "Forty",  "Fifty",
                               "Sixty",  "Seventy", "Eighty", "Ninety"};
  const vector<string> TEENS = {"Ten",      "Eleven",  "Twelve",  "Thirteen",
                                "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                                "Eighteen", "Nineteen"};
  const vector<string> DIG = {"One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
  string convert_three(string num_s) {
    int l = num_s.size();
    string prefix = "";
    if (l == 3) {
      while (num_s[0] == '0') {
        num_s.erase(0,1);
        l--;
      }

      if (l == 3) {
        char front = num_s[0];
        num_s.erase(0,1);
        l--;
        prefix = DIG[front-'0'-1] + " Hundred ";
      }
    }
    if (l == 2) {
      if (num_s[0] == '0') {
        l = 1;
        num_s.erase(0,1);
      } else {
        int tens = num_s[0];
        int ones = num_s[1];
        string res = prefix;
        if (tens == '1') {
          return TEENS[ones-'0'];
        } else {
          res += TENS[tens-'0'-2];
          if (ones != '0') {
            res+=" ";
            res+=DIG[ones-'0'-1];
          }
          return res;
        }
      }
    }
    if (l == 1) {
      char c = num_s[0];
      if (c == '0') {
        return prefix+"";
      } else {
        return prefix+DIG[c - '0'-1];
      }
    }


    return prefix+"";
  };

 public:
  string numberToWords(int num) {
    if (num == 0) return "Zero";
    cout << "testing 27: " << convert_three("27") << endl;
    cout << "testing 08: " << convert_three("08") << endl;
    cout << "testing 19: " << convert_three("19") << endl;
    cout << "testing 10: " << convert_three("10") << endl;
    cout << "testing 001: " << convert_three("001") << endl;
    cout << "testing 000: " << convert_three("000") << endl;
    cout << "testing 100: " << convert_three("100") << endl;
    cout << "testing 101: " << convert_three("101") << endl;
    cout << "testing 120: " << convert_three("120") << endl;
    cout << "testing 123: " << convert_three("123") << endl;
    return "";
  }
};