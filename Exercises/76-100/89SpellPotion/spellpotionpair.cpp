/*

2300. Successful Pairs of Spells and Potions
Medium
595
18
Companies
You are given two positive integer arrays spells and potions, of length n and m
respectively, where spells[i] represents the strength of the ith spell and
potions[j] represents the strength of the jth potion.

You are also given an integer success. A spell and potion pair is considered
successful if the product of their strengths is at least success.

Return an integer array pairs of length n where pairs[i] is the number of
potions that will form a successful pair with the ith spell.



Example 1:

Input: spells = [5,1,3], potions = [1,2,3,4,5], success = 7
Output: [4,0,3]
Explanation:
- 0th spell: 5 * [1,2,3,4,5] = [5,10,15,20,25]. 4 pairs are successful.
- 1st spell: 1 * [1,2,3,4,5] = [1,2,3,4,5]. 0 pairs are successful.
- 2nd spell: 3 * [1,2,3,4,5] = [3,6,9,12,15]. 3 pairs are successful.
Thus, [4,0,3] is returned.
Example 2:

Input: spells = [3,1,2], potions = [8,5,8], success = 16
Output: [2,0,2]
Explanation:
- 0th spell: 3 * [8,5,8] = [24,15,24]. 2 pairs are successful.
- 1st spell: 1 * [8,5,8] = [8,5,8]. 0 pairs are successful.
- 2nd spell: 2 * [8,5,8] = [16,10,16]. 2 pairs are successful.
Thus, [2,0,2] is returned.


Constraints:

n == spells.length
m == potions.length
1 <= n, m <= 105
1 <= spells[i], potions[i] <= 105
1 <= success <= 1010
Accepted
27K
Submissions
77.3K
Acceptance Rate
34.9%

*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
  int bsearch(vector<int> v, long long target) {
    int low = 0;
    int high = v.size() - 1;
    int mid = (low + high) / 2;
    while (high > low) {
      int cur = v[mid];
      if (cur == target) return mid;
      if (cur < target) low = mid + 1;
      if (cur > target) high = mid - 1;
      mid = (low + high) / 2;
    }
    return mid;
  }

 public:
  vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                              long long success) {
    vector<int> pairs;
    unordered_map<int,bool> lu;
    unordered_map<int,int> val_lu;

    sort(potions.begin(), potions.end());
    int psize = potions.size();
    for (int sp : spells) {
      if (lu[sp]) {
        pairs.push_back(val_lu[sp]);
        continue;
      }
      lu[sp] = true;
      long long tgt = success/sp;

      if (tgt*sp < success) tgt++;
      int pivot = bsearch(potions, tgt);
      int count = psize - pivot;
      bool under = false;
      while (pivot < potions.size() && (((long long)potions[pivot]*sp) < success)) {
        count--;
        pivot++;
        under = true;
      }

      if (!under) {
        while (pivot >= 0 && (((long long)potions[pivot]*sp) >= success)) {
          pivot--;
          if (pivot >=0 && (long long)potions[pivot]*sp >= success)count++;
        }
      }

      val_lu[sp] = count;
      pairs.push_back(count);
    }
    return pairs;
  }
};

/*

TLE trap alert

- brute force build and count
O(N^2)

- sorted potions
- sort time + time to binary search each spell
- O(2nlog(n))

- fail case
spells - [15,39,38,35,33,25,31,12,40,27,29,16,22,24,7,36,29,34,24,9,11,35,21,3,33,10,9,27,35,17,14,3,35,35,39,23,35,14,31,7]
potions - [25,19,30,37,14,30,38,22,38,38,26,33,34,23,40,28,15,29,36,39,39,37,32,38,8,17,39,20,4,39,39,7,30,35,29,23]
success = 317
output - [28,33,33,33,33,33,33,23,34,33,33,29,32,33,0,33,33,33,33,13,22,33,31,0,33,17,13,33,33,30,26,0,33,33,33,33,33,26,33,0]
expected - [28,33,33,33,33,33,33,23,34,33,33,29,32,33,0,33,33,33,33,13,22,33,31,0,33,17,13,33,33,30,27,0,33,33,33,33,33,27,33,0]

(check third from last case )
*/