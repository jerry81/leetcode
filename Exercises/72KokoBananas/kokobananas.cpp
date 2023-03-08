/*

875. Koko Eating Bananas
Medium
6.5K
309
Companies
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.



Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23


Constraints:

1 <= piles.length <= 104
piles.length <= h <= 109
1 <= piles[i] <= 109
Accepted
295.4K
Submissions
570.2K
Acceptance Rate
51.8%

*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
int tryK(vector<int>& piles, int k) {
  int h = 0;
  for (int pile: piles) {
    int remPile = pile;
    while (remPile > k) {
      remPile /= k;
      h += remPile;
    }
    if (remPile > 0) h+=1;
  }
  return h;
}

public:
    int minEatingSpeed(vector<int>& piles, int h) {
      return tryK(piles, 4);
    }
};

int main() {
  Solution s;
  vector<int> test1 = {3,6,7,11};
  cerr << "expect 8 " << s.minEatingSpeed(test1, 8);
  return 0;
}

/*

plan: trial and error assisted by binary search
with min_initial = 1 banana
and max_initial = max pile size
  - this is the fastest koko can eat, and becomes # of piles hours
  - can handle as special case

*/