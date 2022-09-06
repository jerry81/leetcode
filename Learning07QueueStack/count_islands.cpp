/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.



Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/

#include <iostream>
#include <vector> // make modules available, CLASSPATH in java
using namespace std; // saves us from prepending std:: corresponds to "import" in java

class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
      for (vector<char> line : grid) {
        for (char item : line) {
          cerr << "item is " << item << endl;
        }
      }
      return 0;
    }
};

int main() {
  cerr << "starting up!" <<endl;
  Solution s = Solution();
  vector<vector<char> > v;
  vector<char> l1;
  l1.push_back('1');
  l1.push_back('1');
  l1.push_back('1');
  l1.push_back('1');
  l1.push_back('0');
  v.push_back(l1);
  // v.push_back({'1','1','0','1','0'});
  // v.push_back({'1','1','0','0','0'});
  // v.push_back({'0','0','0','0','0'});
  int res = s.numIslands(v);
  cerr << " res is " << res << endl;
  return 0;
}