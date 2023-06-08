/*

1351. Count Negative Numbers in a Sorted Matrix
Easy
3.5K
96
Companies
Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.



Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100


Follow up: Could you find an O(n + m) solution?
Accepted
263.6K
Submissions
346.9K
Acceptance Rate
76.0%

*/

#include <vector>

using namespace std;

class Solution {
int bsearchForZero(vector<int> row) {
  int low = 0;
  int high = row.size()-1;
  while (low < high) {
    int mid = low+high / 2;
    int item = row[mid];
    if (item == 0) return mid;
    if (item > 0) {
      low = mid+1;
      continue;
    }

    high = mid-1;
  }
  return low;
}

public:
    int countNegatives(vector<vector<int>>& grid) {
      // binary search to find 0 in each
      int sum = 0;
      for (auto a: grid) {
        int idx = bsearchForZero(a);
        sum+=grid.size() - idx;

        if (a[idx] >= 0) sum--;
      }
      return sum;
    }
};