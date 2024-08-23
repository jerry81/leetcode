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
class Solution {
public:
    string fractionAddition(string expression) {
        int num = 0;
        int denom = 1;

        // separate expression into signed numbers
        vector<string> nums;
        int i = 0;
        if (expression[0] != '-') expression = '+' + expression;
        while (i < expression.size()) {
            int j = i + 1;
            while (j < expression.size() && expression[j] != '+' &&
                   expression[j] != '-') {
                j++;
            }
            nums.push_back(expression.substr(i, j - i));
            i = j;
        }

        for (int i = 0; i < nums.size(); ++i) {
            size_t pos = nums[i].find('/');
            int currNum = stoi(nums[i].substr(1, pos - 1));
            if (nums[i][0] == '-') currNum = -currNum;
            int currDenom = stoi(nums[i].substr(pos + 1));

            num = num * currDenom + currNum * denom;
            denom = denom * currDenom;

            int gcd = abs(FindGCD(num, denom));

            num /= gcd;
            denom /= gcd;
        }

        return to_string(num) + "/" + to_string(denom);
    }

private:
    int FindGCD(int a, int b) {
        if (a == 0) return b;
        return FindGCD(b % a, a);
    }
};