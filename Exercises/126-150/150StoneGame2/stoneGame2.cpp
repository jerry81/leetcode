/*

1140. Stone Game II
Medium
1.7K
318
Companies
Alice and Bob continue their games with piles of stones.  There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].  The objective of the game is to end with the most stones.

Alice and Bob take turns, with Alice starting first.  Initially, M = 1.

On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).

The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.



Example 1:

Input: piles = [2,7,9,4,4]
Output: 10
Explanation:  If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 piles in total. If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 piles in total. So we return 10 since it's larger.
Example 2:

Input: piles = [1,2,3,4,5,100]
Output: 104


Constraints:

1 <= piles.length <= 100
1 <= piles[i] <= 104
Accepted
48.9K
Submissions
75.2K
Acceptance Rate
65.1%

*/

#include <vector>

using namespace std;
class Solution {
 vector<vector<vector<int>>> _lookup;
 int size;
 vector<int> _piles;
int r(int turn, int head, int m) {

  if (head >= size) return 0;
  if (_lookup[turn][head][m] != -1) return _lookup[turn][head][m];
  int res = (turn == 0) ? -1 : INT_MAX;


  int sum = 0;
  for (int i = 1; i <= min(m*2,size-head); ++i) {
    int nextm = max(i,m);
    int idx = i+head;

    sum+=_piles[idx-1];
    if (turn==0) {
      res = max(res, sum+r(1,idx,nextm));
    } else {
      res = min(res, r(0, idx, nextm));
    }
  }
    return _lookup[turn][head][m] = res;
}
public:
    int stoneGameII(vector<int>& piles) {
      size = piles.size();
      _piles = piles;
      vector lookup(2, vector(size+1, vector<int>(size+1, -1)));
      _lookup = lookup;
      return r(0, 0, 1);
    }
};
/*

ideas:

DP + recursion

pick greedily (guessing) or
solve all possibilities

example one shows greedy doesn't work.

- base cases
- 2M >= items - take them all
- first example doesn't show need for dp
- at each tree node we have
- 1 to 2M children
- we have A and B's sums
- we have bool identifying whose turn it is
- we have pointer to head of array
- we have current M

*/