/*
Perfect Squares

Solution
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.



Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.


Constraints:

1 <= n <= 104
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {

private:
  vector<int> squares;
  void populate_squares(int lim) {
    int i = 1;
    while (i*i < lim) {
      squares.push_back(i*i);
      ++i;
    }
  }

public:
    int numSquares(int n) {
      // get largest square up to
      int count = 0;
      populate_squares(n);
      int total = n / squares.back();
      cerr << "total is " << total <<endl;
      int rem = n % squares.back();
      total *= squares.back();
      n = n - total;
      squares.pop_back();
      cerr << "rem is " << rem << endl;
      for (int i : squares) {
        cerr << "i is " << i <<endl;
      }
      cerr << "n is now " << n << endl;
      // find how many multiples of that number we can add
      // get difference
      // count + 1
      // pop until find an item lower

      return 0;
    }
};

int main() {
  Solution s;
  s.numSquares(13);
  return 0;
}
