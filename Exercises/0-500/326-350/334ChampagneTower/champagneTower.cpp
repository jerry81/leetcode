/*

799. Champagne Tower
Medium
2.7K
153
Companies
We stack glasses in a pyramid, where the first row has 1 glass, the second row
has 2 glasses, and so on until the 100th row.  Each glass holds one cup of
champagne.

Then, some champagne is poured into the first glass at the top.  When the
topmost glass is full, any excess liquid poured will fall equally to the glass
immediately to the left and right of it.  When those glasses become full, any
excess champagne will fall equally to the left and right of those glasses, and
so on.  (A glass at the bottom row has its excess champagne fall on the floor.)

For example, after one cup of champagne is poured, the top most glass is full.
After two cups of champagne are poured, the two glasses on the second row are
half full.  After three cups of champagne are poured, those two cups become full
- there are 3 full glasses total now.  After four cups of champagne are poured,
the third row has the middle glass half full, and the two outside glasses are a
quarter full, as pictured below.



Now after pouring some non-negative integer cups of champagne, return how full
the jth glass in the ith row is (both i and j are 0-indexed.)



Example 1:

Input: poured = 1, query_row = 1, query_glass = 1
Output: 0.00000
Explanation: We poured 1 cup of champange to the top glass of the tower (which
is indexed as (0, 0)). There will be no excess liquid so all the glasses under
the top glass will remain empty. Example 2:

Input: poured = 2, query_row = 1, query_glass = 1
Output: 0.50000
Explanation: We poured 2 cups of champange to the top glass of the tower (which
is indexed as (0, 0)). There is one cup of excess liquid. The glass indexed as
(1, 0) and the glass indexed as (1, 1) will share the excess liquid equally, and
each will get half cup of champange. Example 3:

Input: poured = 100000009, query_row = 33, query_glass = 17
Output: 1.00000


Constraints:

0 <= poured <= 109
0 <= query_glass <= query_row < 100
Accepted
92.4K
Submissions
176.9K
Acceptance Rate
52.2%

*/

#include <vector>
using namespace std;

class Solution {
 public:
  double champagneTower(int poured, int query_row, int query_glass) {
    vector<vector<double>> flows(query_row + 1,
                                 vector<double>(query_row + 1, 0.0));
    int row = 1;
    flows[0][0] = (double)poured;

    while (row <= query_row) {
      for (int col = 0; col <= row; ++col) {
        double lparent = col > 0 ? flows[row - 1][col - 1] : 0;
        double rparent = col < row ? flows[row - 1][col] : 0;
        lparent -= 1;
        rparent -= 1;
        lparent /= 2.0;
        rparent /= 2.0;
        lparent = max(0.0, lparent);
        rparent = max(0.0, rparent);
        flows[row][col] = lparent + rparent;
      }
      ++row;
    }

    return min(flows[query_row][query_glass], 1.0);
  }
};