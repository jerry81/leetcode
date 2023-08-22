/*

657. Robot Return to Origin
Easy
2.2K
734
Companies
There is a robot starting at the position (0, 0), the origin, on a 2D plane. Given a sequence of its moves, judge if this robot ends up at (0, 0) after it completes its moves.

You are given a string moves that represents the move sequence of the robot where moves[i] represents its ith move. Valid moves are 'R' (right), 'L' (left), 'U' (up), and 'D' (down).

Return true if the robot returns to the origin after it finishes all of its moves, or false otherwise.

Note: The way that the robot is "facing" is irrelevant. 'R' will always make the robot move to the right once, 'L' will always make it move left, etc. Also, assume that the magnitude of the robot's movement is the same for each move.



Example 1:

Input: moves = "UD"
Output: true
Explanation: The robot moves up once, and then down once. All moves have the same magnitude, so it ended up at the origin where it started. Therefore, we return true.
Example 2:

Input: moves = "LL"
Output: false
Explanation: The robot moves left twice. It ends up two "moves" to the left of the origin. We return false because it is not at the origin at the end of its moves.


Constraints:

1 <= moves.length <= 2 * 104
moves only contains the characters 'U', 'D', 'L' and 'R'.
Accepted
384.2K
Submissions
509.5K
Acceptance Rate
75.4%

*/

#include <string>
#include <map>

using namespace std;

struct Move {
  int dx = 0;
  int dy = 0;
  Move(int y, int x): dx(x), dy(y) {};
};
class Solution {
public:
    bool judgeCircle(string moves) {
      map<char, Move> movemap;
      Move up = Move(-1,0);
      movemap['U'] = up;
      Move down = Move(1,0);
      movemap['D'] = down;
      Move left = Move(0,-1);
      movemap['L'] = left;
      Move right = Move(0,1);
      movemap['R'] = right;
      int y = 0;
      int x = 0;
      for (char c: moves) {
        y+=movemap[c].dy;
        x+=movemap[c].dx;
      }
      return y == 0 && x == 0;
    }
};