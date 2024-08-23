/*

592. Fraction Addition and Subtraction
Medium
Topics
Companies
Given a string expression representing an expression of fraction addition and subtraction, return the calculation result in string format.

The final result should be an irreducible fraction. If your final result is an integer, change it to the format of a fraction that has a denominator 1. So in this case, 2 should be converted to 2/1.



Example 1:

Input: expression = "-1/2+1/2"
Output: "0/1"
Example 2:

Input: expression = "-1/2+1/2+1/3"
Output: "1/3"
Example 3:

Input: expression = "1/3-1/2"
Output: "-1/6"


Constraints:

The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
Each fraction (input and output) has the format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1, 10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
The number of given fractions will be in the range [1, 10].
The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
52.9K
Submissions
90.6K
Acceptance Rate
58.4%

*/

#include <string>
#include <vector>

using namespace std;

vector<string> split(string str, string delimiter) {
  // Returns first token
  vector<string> ret;
  const char *del = delimiter.c_str();
  char *token = strtok(str.data(), del);

  // Keep printing tokens while one of the
  // delimiters present in str[].
  while (token != nullptr) {
    ret.push_back(token);
    token = strtok(nullptr,del);
  }

  return ret;
}
class Solution {
public:
    string fractionAddition(string expression) {
      vector<string> tmp;
      vector<string> spl_by_plus = split(expression, "+");
      for (auto s: spl_by_plus) {
        vector<string> spl_by_minus = split(s, "-");
        for (auto ss: spl_by_minus) tmp.push_back(ss);
      }

      for (auto s: tmp) cout << s << endl;

      return "";
    }
};