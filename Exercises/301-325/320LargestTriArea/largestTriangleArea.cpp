/*

812. Largest Triangle Area
Easy
499
1.6K
Companies
Given an array of points on the X-Y plane points where points[i] = [xi, yi], return the area of the largest triangle that can be formed by any three different points. Answers within 10-5 of the actual answer will be accepted.



Example 1:


Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
Output: 2.00000
Explanation: The five points are shown in the above figure. The red triangle is the largest.
Example 2:

Input: points = [[1,0],[0,0],[0,1]]
Output: 0.50000


Constraints:

3 <= points.length <= 50
-50 <= xi, yi <= 50
All the given points are unique.
Accepted
44.4K
Submissions
73.9K
Acceptance Rate
60.1%

*/

#include <vector>
#include <cmath>
using namespace std;

class Solution {
double calculateArea(double x1, double y1, double x2, double y2, double x3, double y3) {
    return 0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
}
public:
    double largestTriangleArea(vector<vector<int>>& points) {
      double res = 0;
      int n = points.size();
      for (int i = 0; i < n-2; ++i) {
        for (int j = i+1; j < n-1; ++j) {
          for (int k = j+1; k < n; ++k) {
            vector<int> p1 = points[i];
            vector<int> p2 = points[j];
            vector<int> p3 = points[k];
            double area = calculateArea(p1[0],p1[1],p2[0],p2[1],p3[0],p3[1]);
            res = max(res,area);
          }
        }
      }
      return res;
    }
};