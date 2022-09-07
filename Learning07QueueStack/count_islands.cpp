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

struct Item
{
  int row;
  int col;
};
class Solution
{
public:
  vector<vector<bool>> visited;
  vector<vector<char>> sgrid;
  int boundR;
  int boundC;

  int bfs(int row, int col)
  {
    if (visited.at(row).at(col) || sgrid.at(row).at(col) != '1')
    {
      cerr << "returning!" << endl;
      return 0;
    }

    // mark visited
    // neighbors
    queue<Item> q;
    Item start;
    start.row = row;
    start.col = col;
    visited.at(row).at(col) = true;
    q.push(start);
    while (!q.empty())
    {
      Item cur = q.front();
      visited.at(cur.row).at(cur.col) = true;
      // add u l r d
      int ur = cur.row - 1;
      int dr = cur.row + 1;
      int lc = cur.col - 1;
      int rc = cur.col + 1;
      cerr << "q size is " << q.size() << endl;
      cerr << "ur " << ur << " dr " << dr << " lc " << lc << " rc " << rc << endl;
      if ((ur >= 0) && (!visited.at(ur).at(cur.col)) && sgrid.at(ur).at(cur.col) == '1')
      {
        Item next;
        next.row = ur;
        next.col = cur.col;
        q.push(next);
      }
      if ((dr < boundR) && (!visited.at(dr).at(cur.col)) && sgrid.at(dr).at(cur.col) == '1')
      {
        Item next;
        next.row = dr;
        next.col = cur.col;
        q.push(next);
      }
      if ((lc >= 0) && (!visited.at(cur.row).at(lc)) && sgrid.at(cur.row).at(lc) == '1')
      {
        Item next;
        next.row = cur.row;
        next.col = lc;
        q.push(next);
      }
      if ((rc < boundC) && (!visited.at(cur.row).at(rc)) && sgrid.at(cur.row).at(rc) == '1')
      {
        Item next;
        next.row = cur.row;
        next.col = rc;
        q.push(next);
      }
      q.pop();
    }
    return 1;
  }

  int numIslands(vector<vector<char>> &grid)
  {
    sgrid = grid;
    boundR = grid.size();
    if (boundR < 1)
    {
      return 0;
    }

    boundC = grid.at(0).size();
    for (int i = 0; i < boundR; ++i)
    {
      vector<bool> row;
      for (int j = 0; j < boundC; ++j)
      {
        row.push_back(false);
      }
      visited.push_back(row);
    }

    for (vector<bool> visitedrow : visited)
    {
      for (bool item : visitedrow)
      {
        cerr << "visited item is " << item << endl;
      }
    }

    int total = 0;
    for (int r = 0; r < boundR; ++r)
    {
      for (int c = 0; c < boundC; ++c)
      {
        total += bfs(r,c);
      }
    }
    // for each col and row
    return total;
  }
};

int main()
{
  Solution s = Solution();
  vector<vector<char>> v{
  {'1','1','0','0','0'},
  {'1','1','0','0','0'},
  {'0','0','1','0','0'},
  {'0','0','0','1','1'}
  };

  int res = s.numIslands(v);
  cerr << " res is " << res << endl;
  return 0;
}

// note: compile the modern syntax with g++ -std=c++11 -o output_file source.cpp

/*
[["1","1","1","1","1","0","1","1","1","1","1","1","1","1","1","0","1","0","1","1"],["0","1","1","1","1","1","1","1","1","1","1","1","1","0","1","1","1","1","1","0"],["1","0","1","1","1","0","0","1","1","0","1","1","1","1","1","1","1","1","1","1"],["1","1","1","1","0","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"],["1","0","0","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"],["1","0","1","1","1","1","1","1","0","1","1","1","0","1","1","1","0","1","1","1"],["0","1","1","1","1","1","1","1","1","1","1","1","0","1","1","0","1","1","1","1"],["1","1","1","1","1","1","1","1","1","1","1","1","0","1","1","1","1","0","1","1"],["1","1","1","1","1","1","1","1","1","1","0","1","1","1","1","1","1","1","1","1"],["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"],["0","1","1","1","1","1","1","1","0","1","1","1","1","1","1","1","1","1","1","1"],["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"],["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"],["1","1","1","1","1","0","1","1","1","1","1","1","1","0","1","1","1","1","1","1"],["1","0","1","1","1","1","1","0","1","1","1","0","1","1","1","1","0","1","1","1"],["1","1","1","1","1","1","1","1","1","1","1","1","0","1","1","1","1","1","1","0"],["1","1","1","1","1","1","1","1","1","1","1","1","1","0","1","1","1","1","0","0"],["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"],["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"],["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"]]
*/