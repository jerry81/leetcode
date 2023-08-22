/*

661. Image Smoother
Easy
477
1.9K
Companies
An image smoother is a filter of the size 3 x 3 that can be applied to each cell
of an image by rounding down the average of the cell and the eight surrounding
cells (i.e., the average of the nine cells in the blue smoother). If one or more
of the surrounding cells of a cell is not present, we do not consider it in the
average (i.e., the average of the four cells in the red smoother).


Given an m x n integer matrix img representing the grayscale of an image, return
the image after applying the smoother on each cell of it.



Example 1:


Input: img = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[0,0,0],[0,0,0],[0,0,0]]
Explanation:
For the points (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the points (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0
Example 2:


Input: img = [[100,200,100],[200,50,200],[100,200,100]]
Output: [[137,141,137],[141,138,141],[137,141,137]]
Explanation:
For the points (0,0), (0,2), (2,0), (2,2): floor((100+200+200+50)/4) =
floor(137.5) = 137 For the points (0,1), (1,0), (1,2), (2,1):
floor((200+200+50+200+100+100)/6) = floor(141.666667) = 141 For the point (1,1):
floor((50+200+200+200+200+100+100+100+100)/9) = floor(138.888889) = 138


Constraints:

m == img.length
n == img[i].length
1 <= m, n <= 200
0 <= img[i][j] <= 255
Accepted
74.7K
Submissions
134.1K
Acceptance Rate
55.7%

*/

#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
    vector<vector<int>> result;
    int h = img.size();
    int w = img[0].size();
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {1, 1},  {-1, 1},
                                {0, 1}, {0, -1}, {1, -1}, {-1, -1}};
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        int neighbors = 0;
        int sum = 0;
        for (vector<int> d : dirs) {
          int cy = y+d[0];
          int cx = x+d[1];
          if (cy >= 0 && cy < h && cx >= 0 && cx < w) {
            neighbors += 1;
            sum += img[cy][cx];
          }
        }
        result[y][x] = sum/neighbors;
      }
    }
    return result;
  }
};