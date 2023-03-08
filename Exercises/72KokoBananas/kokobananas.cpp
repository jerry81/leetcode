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
long long tryK(vector<int>& piles, int k) {
  long long h = 0;
  for (int pile: piles) {
    int remPile = pile;
    int rem = remPile % k;
    remPile /= k;
    h += remPile;
    if (rem > 0) h+=1;
  }
  return h;
}

int* minAndMax(vector<int> piles) {
  int mn = INT_MAX;
  int mx = 0;
  for (int p: piles) {
    if (p < mn) mn = p;
    if (p > mx) mx = p;
  }
  int *ret = new int[2];
  *ret = mn;
  *(ret+1) = mx;
  return ret;
}

public:
    int minEatingSpeed(vector<int>& piles, int h) {
      int* minmax = minAndMax(piles);
      if (h == piles.size()) return *(minmax+1);
      int mn = 1;
      int mx = *(minmax+1);
      int prevmid = -1;
      while (true) {
        int mid = (mn+mx) / 2;
        if (mid == prevmid) {
          mid++;
          long long k = tryK(piles, mid);
          while (k >= h) {
            mid++;
            k = tryK(piles, mid);
          }

          return mid;
        }
        prevmid = mid;
        if (mid == 0) return 1;
        long long tryR = tryK(piles, mid);
        if (tryR == h) {
          while (tryR == h) {
            mid--;
            tryR = tryK(piles, mid);
          }
          return mid+1;
        }
        if (tryR > h) mn = mid;

        if (tryR < h) mx = mid-1;

      }
      return 0;
    }
};

int main() {
  Solution s;
  vector<int> test1 = {3,6,7,11};
  cerr << "expect 10 " << endl << s.minEatingSpeed(test1, 8) << endl;
  vector<int>  test2 = {312884470};
  cerr << "expect something " << s.minEatingSpeed(test2, 312884469) << endl;
  vector<int> test3 = {332484035,524908576,855865114,632922376,222257295,690155293,112677673,679580077,337406589,290818316,877337160,901728858,679284947,688210097,692137887,718203285,629455728,941802184};
  cerr << "expect 14 " << s.minEatingSpeed(test3, 823855818) << endl;
  vector<int> test4 = {312884470};
  cerr << "expect no divbyzero " << s.minEatingSpeed(test4, 968709470) << endl;
  vector<int> test5 = {805306368,805306368,805306368};
  cerr << "expect no overflow " << s.minEatingSpeed(test5, 1000000000) << endl;
  return 0;
}

/*

plan: trial and error assisted by binary search
with min_initial = 1 banana
and max_initial = max pile size
  - this is the fastest koko can eat, and becomes # of piles hours
  - can handle as special case

*/