/*

171. Excel Sheet Column Number
Easy
4.2K
331
Companies
Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...


Example 1:

Input: columnTitle = "A"
Output: 1
Example 2:

Input: columnTitle = "AB"
Output: 28
Example 3:

Input: columnTitle = "ZY"
Output: 701


Constraints:

1 <= columnTitle.length <= 7
columnTitle consists only of uppercase English letters.
columnTitle is in the range ["A", "FXSHRXW"].
Accepted
600.1K
Submissions
964K
Acceptance Rate
62.3%

*/

#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
      int sum = 0;
      int power = 0;
      for (int i = columnTitle.size()-1; i >= 0; --i) {

        char c = columnTitle[i];
        int append = pow(26,power);
        append*=(c - 'A' + 1);
        sum += append;
        power++;
      }
      return sum;
    }
};
