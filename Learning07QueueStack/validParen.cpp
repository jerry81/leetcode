/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.


Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false


Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

Use a stack of characters.

When you encounter an opening bracket, push it to the top of the stack.

When you encounter a closing bracket, check if the top of the stack was the
opening for it. If yes, pop it from the stack. Otherwise, return false.
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
 private:
  stack<char> st;

 public:
  bool isValid(string s) {
    for (auto &ch : s) {
      switch (ch) {
        case ')':
          if (st.empty()) return false;
          if (st.top() == '(') {
            st.pop();
          } else {
            return false;
          }
          break;
        case ']':
          if (st.empty()) return false;
          if (st.top() == '[') {
            st.pop();
          } else {
            return false;
          }
          break;
        case '}':
          if (st.empty()) return false;
          if (st.top() == '{') {
            st.pop();
          } else {
            return false;
          }
          break;
        default:
          st.push(ch);
      }
    }
    return st.empty();
  }
};

int main() {
  Solution s;
  cerr << "expect true " << s.isValid("(())") << endl;
  cerr << "expect false " << s.isValid("())") << endl;
  return 0;
}