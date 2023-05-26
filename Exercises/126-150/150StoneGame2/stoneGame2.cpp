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
 int s;
 vector<int> _piles;
int r(int aToPlay, int head, int m) {
  if (_lookup[aToPlay][head][m] >= 0) return _lookup[aToPlay][head][m];

  if (head >= s) return 0;

  int sum =
}
public:
    int stoneGameII(vector<int>& piles) {
      s = piles.size();
      _piles = piles;
      vector<vector<vector<int>>> lookup(2, vector<vector<int>>(s, vector<int>(s, -1)));
      _lookup = lookup;
      return r(false, 0, 1);
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