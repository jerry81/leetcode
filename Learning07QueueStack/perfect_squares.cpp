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
#include <unordered_map>
using namespace std;

class Solution
{

private:
  vector<int> squares;
  unordered_map<int, int> lookup;
  void populate_squares(int lim)
  {
    int i = 1;
    while (i * i <= lim)
    {
      squares.push_back(i * i);
      lookup[i * i] = 1;
      ++i;
    }
  }

  int reduceR(int cur)
  {
    // cerr << "reducing " << cur << endl;

    // cerr << "reduce the following now " << cur << endl;
    if (cur == 0)
      return 0;

    if (lookup[cur] > 0)
    {
      // cerr << "returning from memo cur: " << cur << " lookup: " << lookup[cur] << endl;
      return lookup[cur];
    }

    vector<int> res;
    for (int sq : squares)
    {
      int diff = cur - sq;
      int diffAns = lookup[diff];
      if (diff >= 0)
      {
        if (diffAns > 0)
        {
          res.push_back(1 + diffAns);
        }
        else
        {
          res.push_back((1 + reduceR(diff)));
        }
      }
    }
    int count = 0;
    for (int r : res)
    {
      // cerr << "res item is " << r << " and count is " << count << endl;
      count++;
    }
    int ans = *min_element(res.begin(), res.end());
    lookup[cur] = ans;
    return lookup[cur];
    // end condition - return 0
    // recursive condition
    // memory
    // return - count
  }

public:
  int numSquares(int n)
  {
    lookup.clear();

    lookup[0] = 0;
    lookup[1] = 1;

    // get largest square up to

    populate_squares(n);
    return reduceR(n);
  }
};

int main()
{
  Solution s;
  int ans = s.numSquares(13);
  cerr << "expect 2 " << ans << endl;

  ans = s.numSquares(12);
  cerr << "expect 3 " << ans << endl;
//
  ans = s.numSquares(1);
  cerr << "expect 1 " << ans << endl;
//
  ans = s.numSquares(4);
  cerr << "expect 1 " << ans << endl; // inf loop!
//
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

// 8829 fails time limit