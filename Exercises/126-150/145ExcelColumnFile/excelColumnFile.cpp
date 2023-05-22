/*

168. Excel Sheet Column Title
Easy
3.8K
545
Companies
Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

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

Input: columnNumber = 1
Output: "A"
Example 2:

Input: columnNumber = 28
Output: "AB"
Example 3:

Input: columnNumber = 701
Output: "ZY"


Constraints:

1 <= columnNumber <= 231 - 1
Accepted
378.2K
Submissions
1.1M
Acceptance Rate
35.7%

*/

#include <string>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {

    }
};

// zy ->

// 26*26 + 25
// convert from base 10 to base 26
// 700 + 0 + 1
// base 26
//  26^2 to 26*26^2, 1*26^1 to 26*26^1, 26^0
// starting position first
