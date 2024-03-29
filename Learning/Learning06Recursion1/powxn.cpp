/*

Pow(x, n)

Solution
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).



Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25


Constraints:

-100.0 < x < 100.0
-231 <= n <= 231-1
n is an integer.
-104 <= xn <= 104

*/
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {

      if (n == 0) return 1;

      if (x == 0) return 0;

      if (n > 0) {
        if ((n%2) == 0) {
          double item = myPow(x, n/2);
          return item * item;
        } else {
          return x*myPow(x, (n-1));
        }
      }

      if (n < 0) {
        if ((n%2) == 0) {
          if (x == 0) return 0;

          double item = myPow(x, (-1*(n/2)));
          if (item == 0) return 0;

          return 1/item/item;
        } else {
         return myPow(x,n+1)/x;
        }
      }
      return 1;
    }
};

int main() {
  Solution s;

  cerr << "expect 1024.00000: " << s.myPow(2.00000, 10) << endl;
  cerr << "expect .25 " << s.myPow(2.00000, -2) << endl;
  cerr << "expect something " << s.myPow(0.00001, 2147483647) << endl;
  cerr << "expect something " << s.myPow(0.00001, -2147483648) << endl;
  return 0;
}