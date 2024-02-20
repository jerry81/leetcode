/*

1637. Widest Vertical Area Between Two Points Containing No Points
Medium
372
829
Companies
Given n points on a 2D plane where points[i] = [xi, yi], Return the widest vertical area between two points such that no points are inside the area.

A vertical area is an area of fixed-width extending infinitely along the y-axis (i.e., infinite height). The widest vertical area is the one with the maximum width.

Note that points on the edge of a vertical area are not considered included in the area.



Example 1:

​
Input: points = [[8,7],[9,9],[7,4],[9,7]]
Output: 1
Explanation: Both the red and the blue area are optimal.
Example 2:

Input: points = [[3,1],[9,0],[1,0],[1,4],[5,3],[8,8]]
Output: 3


Constraints:

n == points.length
2 <= n <= 105
points[i].length == 2
0 <= xi, yi <= 109
Accepted
52.5K
Submissions
61.3K
Acceptance Rate
85.7%

*/

#include <vector>
using namespace std;

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
      vector<int> x_vals;
      for (vector<int> pt: points) {
        x_vals.push_back(pt[0]);
      }
      sort(x_vals.begin(), x_vals.end());
      int res = 0;
      for (int i = 0; i < x_vals.size()-1; ++i) {
        int diff = abs(x_vals[i+1] - x_vals[i]);
        res = max(res,diff);
      }
      return res;
    }
};