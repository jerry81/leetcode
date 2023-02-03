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
    if (numRows == 0) return "";

    if (numRows == 1) return s;

    if (numRows == 2) {
      string res = "";
      for (int i = 0; i < s.length(); i=i+2) {
        res += s[i];
      }
      for (int i = 1; i < s.length(); i=i+2) {
        res+= s[i];
      }
      return res;
    }

    string ret = "";
    vector<string> zz;

    // init
    for (int i = 0; i < numRows; ++i) {
      zz.push_back("");
    }
    int counter = 0;
    int cycleLength = numRows + (numRows - 2);  // for 3: 4, for 4: 6, for 5, 8

    // rows: 0,1,2,1,0,1,2,1,0
    //       0,1,2,3,0,1,2,3,0
    // rows: 0,1,2,3,2,1,0,1,2,3,2,1,
    //       0,1,2,3,4,5,0,1,2,3,4,5

    for (char c : s) {
      int state = counter % cycleLength;
      ++counter;
      if (state < numRows) {
        zz[state] += c;
      } else {
        int idx = cycleLength- state;
        zz[idx] += c;
        for (int i = 0; i < numRows; ++i) {
          if (i != idx) zz[i] += ' ';
        }
      }
    }

    for (string s: zz) {
      for (char c: s) {
        if (c != ' ') ret+=c;
      }
    }
    return ret;
  }
};

int main() {
  Solution s;

  cerr << "expect answer " << s.convert("PAYPALISHIRING", 3) << endl;;
  cerr << "expect answer " << s.convert("PAYPALISHIRING", 4) << endl;;
  cerr << "expect answer " << s.convert("PAYPALISHIRING", 5) << endl;
  return 0;
}