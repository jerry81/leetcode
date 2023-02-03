/*

6. Zigzag Conversion
Medium
5.3K
11.1K
Companies
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of
rows like this: (you may want to display this pattern in a fixed font for better
legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number
of rows:

string convert(string s, int numRows);


Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"


Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000

*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string convert(string s, int numRows) {
    string ret = "";
    int counter = 0;
    int cycleLength = numRows + (numRows - 2);  // for 3: 4, for 4: 6, for 5, 8

    for (char c : s) {
      int state = counter % cycleLength;
      ++counter;
      cerr << "state is " << state << endl;
    }
    return ret;
  }
};

int main() {
  Solution s;

  s.convert("PAYPALISHIRING", 3);
  s.convert("PAYPALISHIRING", 4);
  s.convert("PAYPALISHIRING", 5);
  return 0;
}