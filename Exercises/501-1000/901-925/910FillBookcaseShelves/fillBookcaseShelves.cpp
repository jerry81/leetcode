/*
1105. Filling Bookcase Shelves
Medium
Topics
Companies
Hint
You are given an array books where books[i] = [thicknessi, heighti] indicates
the thickness and height of the ith book. You are also given an integer
shelfWidth.

We want to place these books in order onto bookcase shelves that have a total
width shelfWidth.

We choose some of the books to place on this shelf such that the sum of their
thickness is less than or equal to shelfWidth, then build another level of the
shelf of the bookcase so that the total height of the bookcase has increased by
the maximum height of the books we just put down. We repeat this process until
there are no more books to place.

Note that at each step of the above process, the order of the books we place is
the same order as the given sequence of books.

For example, if we have an ordered list of 5 books, we might place the first and
second book onto the first shelf, the third book on the second shelf, and the
fourth and fifth book on the last shelf. Return the minimum possible height that
the total bookshelf can be after placing shelves in this manner.



Example 1:


Input: books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelfWidth = 4
Output: 6
Explanation:
The sum of the heights of the 3 shelves is 1 + 3 + 2 = 6.
Notice that book number 2 does not have to be on the first shelf.
Example 2:

Input: books = [[1,3],[2,4],[3,2]], shelfWidth = 6
Output: 4


Constraints:

1 <= books.length <= 1000
1 <= thicknessi <= shelfWidth <= 1000
1 <= heighti <= 1000
Seen this question in a real interview before?
1/5
Yes
No
Accepted
55.2K
Submissions
92.6K
Acceptance Rate
59.6%

*/

#include <vector>

using namespace std;

class Solution {
  vector<int> memo;

 public:
  int r(int idx, vector<vector<int>>& books, int w, int sz) {
    if (idx >= sz) return 0;
    if (memo[idx] != -1) return memo[idx];
    int total_w = 0;
    int mx_h = 0;
    int mn_result = INT_MAX;

    for (int i = idx; i < sz; ++i) {
      int cur_w = books[i][0];
      int cur_h = books[i][1];
      total_w += cur_w;
      if (total_w > w) break;

      mx_h = max(cur_h, mx_h);
      mn_result = min(mx_h + r(i + 1, books, w, sz), mn_result);
    }

    return memo[idx] = mn_result;
  };

 public:
  int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
    // cannot change order
    // only choices are the "breaks"
    // [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]]
    // width 4
    // height = build_shelf(idx, booknum);
    // (0,1) or (0,2)
    // (0,1) leads to (1,x) (0,2) leads to (2, x)
    // (1,1) or (1,2)
    int sz = books.size();
    memo.resize(sz, -1);

    return r(0, books, shelfWidth, sz);
  }
