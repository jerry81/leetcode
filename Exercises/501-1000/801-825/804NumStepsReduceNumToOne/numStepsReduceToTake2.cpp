/*

1404. Number of Steps to Reduce a Number in Binary Representation to One
Medium
Topics
Companies
Hint
Given the binary representation of an integer as a string s, return the number
of steps to reduce it to 1 under the following rules:

If the current number is even, you have to divide it by 2.

If the current number is odd, you have to add 1 to it.

It is guaranteed that you can always reach one for all test cases.



Example 1:

Input: s = "1101"
Output: 6
Explanation: "1101" corressponds to number 13 in their decimal representation.
Step 1) 13 is odd, add 1 and obtain 14.
Step 2) 14 is even, divide by 2 and obtain 7.
Step 3) 7 is odd, add 1 and obtain 8.
Step 4) 8 is even, divide by 2 and obtain 4.
Step 5) 4 is even, divide by 2 and obtain 2.
Step 6) 2 is even, divide by 2 and obtain 1.
Example 2:

Input: s = "10"
Output: 1
Explanation: "10" corressponds to number 2 in their decimal representation.
Step 1) 2 is even, divide by 2 and obtain 1.
Example 3:

Input: s = "1"
Output: 0


Constraints:

1 <= s.length <= 500
s consists of characters '0' or '1'
s[0] == '1'
Seen this question in a real interview before?
1/5
Yes
No
Accepted
47K
Submissions
85.4K
Acceptance Rate
55.0%

*/

#include <string>

using namespace std;

class Solution {

 public:
  int numSteps(string s) {
    // bstring to int
    if (s == "1") return 0;

    string new_s = "";

    if (s.back() == '0') {
      s.pop_back();
      return 1+numSteps(s);
    } else {
      // carry (the meat)
      while (!s.empty() && s.back() == '1') {
        s.pop_back();
        new_s.insert(0,1,'0');

      }

      new_s.insert(0,1,'1');
      if (!s.empty()) {
        s.pop_back();
        new_s = s+new_s;
      }

      return 1+numSteps(new_s);
    }
  return 0;
  }
};