/*

2751. Robot Collisions
Hard
Topics
Companies
Hint
There are n 1-indexed robots, each having a position on a line, health, and
movement direction.

You are given 0-indexed integer arrays positions, healths, and a string
directions (directions[i] is either 'L' for left or 'R' for right). All integers
in positions are unique.

All robots start moving on the line simultaneously at the same speed in their
given directions. If two robots ever share the same position while moving, they
will collide.

If two robots collide, the robot with lower health is removed from the line, and
the health of the other robot decreases by one. The surviving robot continues in
the same direction it was going. If both robots have the same health, they are
both removed from the line.

Your task is to determine the health of the robots that survive the collisions,
in the same order that the robots were given, i.e. final heath of robot 1 (if
survived), final health of robot 2 (if survived), and so on. If there are no
survivors, return an empty array.

Return an array containing the health of the remaining robots (in the order they
were given in the input), after no further collisions can occur.

Note: The positions may be unsorted.




Example 1:



Input: positions = [5,4,3,2,1], healths = [2,17,9,15,10], directions = "RRRRR"
Output: [2,17,9,15,10]
Explanation: No collision occurs in this example, since all robots are moving in
the same direction. So, the health of the robots in order from the first robot
is returned, [2, 17, 9, 15, 10]. Example 2:



Input: positions = [3,5,2,6], healths = [10,10,15,12], directions = "RLRL"
Output: [14]
Explanation: There are 2 collisions in this example. Firstly, robot 1 and robot
2 will collide, and since both have the same health, they will be removed from
the line. Next, robot 3 and robot 4 will collide and since robot 4's health is
smaller, it gets removed, and robot 3's health becomes 15 - 1 = 14. Only robot 3
remains, so we return [14]. Example 3:



Input: positions = [1,2,5,6], healths = [10,10,11,11], directions = "RLRL"
Output: []
Explanation: Robot 1 and robot 2 will collide and since both have the same
health, they are both removed. Robot 3 and 4 will collide and since both have
the same health, they are both removed. So, we return an empty array, [].


Constraints:

1 <= positions.length == healths.length == directions.length == n <= 105
1 <= positions[i], healths[i] <= 109
directions[i] == 'L' or directions[i] == 'R'
All values in positions are distinct
Seen this question in a real interview before?
1/5
Yes
No
Accepted
13.4K
Submissions
29.6K
Acceptance Rate
45.1%

*/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> survivedRobotsHealths(vector<int>& positions,
                                    vector<int>& healths, string directions) {
    // map
    int sz = positions.size();
    unordered_map<int, tuple<int,int, char>> robots;
    vector<int> stk;
    for (int i = 0; i < sz; ++i) {
      robots[i] = {positions[i],healths[i], directions[i]};
    }
    for (auto [idx,r]: robots) {
      auto [p,h,d] = r;
      if (d == 'R') {
        stk.push_back(idx);
      } else {
        if (!stk.empty()) {
          int bk_idx = stk.back();
          auto [tp,th,td] = robots[bk_idx];
          if (td == 'L') continue;

          stk.pop_back();
          if (th == h) {
            robots.erase(bk_idx);
            robots.erase(idx);
            continue;
          }
          int sm = tp+p;
          int intersection_point =sm / 2;
          int new_health;
          char new_direction;
          if (th > h) { // left survives
            new_health = th - h;
            new_direction = 'L';
          } else {
            new_health = h - th;
            new_direction = 'R';
            intersection_point++;
          }
          robots[bk_idx] = {intersection_point, new_health, new_direction};
        }
      }
    }
    return {};
  }
};