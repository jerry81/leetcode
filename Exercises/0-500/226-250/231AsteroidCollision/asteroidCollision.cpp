/*

735. Asteroid Collision
Medium
5.9K
587
Companies
We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign
represents its direction (positive meaning right, negative meaning left). Each
asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet,
the smaller one will explode. If both are the same size, both will explode. Two
asteroids moving in the same direction will never meet.



Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide
resulting in 10.


Constraints:

2 <= asteroids.length <= 104
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0
Accepted
316.2K
Submissions
704.7K
Acceptance Rate
44.9%

*/

#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> ret;
    for (int i : asteroids) {
      if (ret.empty()) {
        ret.push_back(i);
        continue;
      }
      int bk = ret.back();
      bool oppositeSigns = (bk >= 0 && i < 0);
      if (oppositeSigns) {
        if (abs(bk) == abs(i)) {
          ret.pop_back();
          continue;
        }

        while (!ret.empty() && abs(bk) < abs(i)) {
          ret.pop_back();
          if (ret.empty()) {
            ret.push_back(i);
            break;
          }
          bk = ret.back();
          oppositeSigns = (bk >= 0 && i < 0);
          if (!oppositeSigns) {
            ret.push_back(i);
            break;
          }
          if (abs(i) == abs(bk)) {
            ret.pop_back();
            break;
          }
          if (abs(i) < abs(bk)) {
            break;
          }
        }
      } else {
        ret.push_back(i);
      }
    }

    return ret;
  }
};