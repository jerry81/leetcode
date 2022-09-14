/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

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

When you encounter a closing bracket, check if the top of the stack was the opening for it. If yes, pop it from the stack. Otherwise, return false.
*/
#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
private:
    stack<char> s;
public:
    bool isValid(string s) {
      for (auto &ch : s) {
        cerr << "ch is " << ch <<endl;
      }
      return false;
    }
};

int main() {
  Solution s;
  s.isValid("(())");
  return 0;
}