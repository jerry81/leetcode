/*

1232. Check If It Is a Straight Line
Easy
1.5K
199
Companies
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.


Example 1:



Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true
Example 2:



Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false


Constraints:

2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.
Accepted
163K
Submissions
401.9K
Acceptance Rate
40.6%

*/

#include <vector>

using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
      int dy = coordinates[1][1] - coordinates[0][1];
      int dx = coordinates[1][0] - coordinates[0][0];
      bool inf = dx == 0;
      double slope = inf ? 0 : (double)dy / (double)dx;
      for (int i = 2; i < coordinates.size(); ++i) {
        dy = coordinates[i][1] - coordinates[i-1][1];
        dx = coordinates[i][0] - coordinates[i-1][0];
        if (inf) {
          if (dx != 0) return false;

          continue;
        }
        double temp = (double)dy/(double)dx;
        if (temp != slope) return false;
      }
      return true;
    }
};