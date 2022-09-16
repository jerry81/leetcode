/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.



Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22


Constraints:

1 <= tokens.length <= 104
tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].
*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<int> nums;
    string ops[4] = {"+", "-", "/", "*"};
public:
    int evalRPN(vector<string>& tokens) {
      for (string s : tokens) {
        if (find(begin(ops), end(ops), s) != end(ops)) { // TIL: array includes
          cerr << "not an operator " << s <<endl;
        } else {
          cerr << "is an operator " << s <<endl;
        }
      }
      return 0;
    }
};

int main () {
  Solution s;
  vector<string> t;
  t.push_back("11");
  t.push_back("+");
  t.push_back("15");
  s.evalRPN(t);
  return 0;
}