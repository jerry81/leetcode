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
#include <queue>
using namespace std; // saves us from prepending std:: corresponds to "import" in java

struct Item {
  int row;
  int col;
};
class Solution {
public:
    vector<vector<bool> > visited;
    vector<vector<char> > sgrid;
    int boundR;
    int boundC;

    void bfs(int row, int col) {
      if (visited.at(row).at(col)) {
        return;
      }

      // mark visited
      // neighbors
      queue<Item> q;
      Item start;
      start.row = row;
      start.col = col;
      visited.at(row).at(col) = true;
      q.push(start);
      while (!q.empty()) {
        Item cur = q.front();
        // add u l r d
        int ur = row-1;
        int dr = row+1;
        int lc = col-1;
        int rc = col+1;
        if ((ur >= 0) && (!visited.at(ur).at(col))) {
        }
        if ((dr <= 0) && (!visited.at(dr).at(col))) {
        }
        if ((lc >= 0) && (!visited.at(row).at(lc))) {
        }
        if ((rc >= 0) && (!visited.at(row).at(rc))) {
        }
        q.pop();
      }
    }

    int numIslands(vector<vector<char> >& grid) {
      sgrid = grid;
      int rows = grid.size();
      if (rows < 1) {
        return 0;
      }

      int cols = grid.at(0).size();
      for (int i = 0; i < rows; ++i) {
        vector<bool> row;
        for (int j = 0; j < cols; ++j) {
          row.push_back(false);
        }
        visited.push_back(row);
      }

      for (vector<bool> visitedrow : visited) {
        for (bool item : visitedrow) {
          cerr << "visited item is " << item << endl;
        }
      }

      for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
          Item i;
          i.col = c;
          i.row = r;
        }
      }
      // for each col and row
      return 0;
    }
};

int main() {
  cerr << "starting up!" <<endl;
  Solution s = Solution();
  vector<vector<char> > v;
  vector<char> l1;
  Item i;
  i.col = 0;
  i.row = 0;
  queue<Item> q;
  q.push(i);
  Item i2;
  i2.col = 1;
  i2.row = 1;
  q.push(i2);
  while (!q.empty()) {
    cerr << "front col is " << q.front().col << endl;
    q.pop();
  }
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

  for (int i = 0; i < 5; ++i) {
    cerr << "item is " << v.at(0).at(i) << endl;
  }

  return 0;
}

// note: compile the modern syntax with g++ -std=c++11 -o output_file source.cpp