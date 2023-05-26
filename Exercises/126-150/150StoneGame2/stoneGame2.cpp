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
pair<int,int> r(bool aToPlay, int head, vector<int>& piles, int M) {
  int ulim = 2*M;
  if (ulim >= (piles.size() - head)) {
    int sum = 0;
    for (int i = head; i < piles.size(); ++i) {
      // optimization - this could be repeated.  can use prefix sums for faster sum lookup
      // could use hashmap to store as well.
      sum+=piles[i];
    }
    if (aToPlay) {
      return {sum,0};
    } else {
      return {0,sum};
    }
  }
  for (int x = 1; x < ulim; ++x) {
    int idx = x+head;
  }

}
public:
    int stoneGameII(vector<int>& piles) {
      pair<int,int> res = r(true,0,piles,1);
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