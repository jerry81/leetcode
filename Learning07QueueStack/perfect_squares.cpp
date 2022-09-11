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

class Solution
{

private:
  vector<int> squares;
  void populate_squares(int lim)
  {
    int i = 1;
    while (i * i <= lim)
    {
      squares.push_back(i * i);
      ++i;
    }
  }

public:
  int numSquares(int n)
  {
   // if (n == 1) return 1;

    vector<int> answers;

    // get largest square up to

    populate_squares(n);

    vector<int> cursquares;
    cursquares = squares;
    int cur = n;
    while (!cursquares.empty())
    {
      int ret = 0;
      while (cur > 0)
      {
        int total = cur / cursquares.back();
        int rem = cur % cursquares.back();
        ret += total;
        cur = rem;
        cursquares.pop_back();
      }

      // find how many multiples of that number we can add
      // get difference
      // count + 1
      // pop until find an item lower

      answers.push_back(ret);
      squares.pop_back();
      cursquares = squares;
      cur = n;
    }
    for (int ans : answers) {
    cerr << "ans is " << ans <<endl;
    }
    return *min_element(answers.begin(), answers.end());
  }
};

int main()
{
  Solution s;
   int ans = s.numSquares(13);
   cerr << "ans is " << ans << endl;

   ans = s.numSquares(12);
   cerr << "expect 3 " << ans << endl;

    ans = s.numSquares(1);
  cerr << "expect 1 " << ans << endl;

   ans = s.numSquares(4);
  cerr << "expect 1 " << ans << endl;

  ans = s.numSquares(43);
  cerr << "expect 3 " << ans << endl;
  return 0;
}

// 43
// 7
// 3
// 2
// 1
// 0
// 43
// 18
// 9 9 (4)
// 43 - 16
// 25 9 9
// looks like recursion may be necessary