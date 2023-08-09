/*

2616. Minimize the Maximum Difference of Pairs
Medium
467
21
Companies
You are given a 0-indexed integer array nums and an integer p. Find p pairs of indices of nums such that the maximum difference amongst all the pairs is minimized. Also, ensure no index appears more than once amongst the p pairs.

Note that for a pair of elements at the index i and j, the difference of this pair is |nums[i] - nums[j]|, where |x| represents the absolute value of x.

Return the minimum maximum difference among all p pairs. We define the maximum of an empty set to be zero.



Example 1:

Input: nums = [10,1,2,7,1,3], p = 2
Output: 1
Explanation: The first pair is formed from the indices 1 and 4, and the second pair is formed from the indices 2 and 5.
The maximum difference is max(|nums[1] - nums[4]|, |nums[2] - nums[5]|) = max(0, 1) = 1. Therefore, we return 1.
Example 2:

Input: nums = [4,2,1,2], p = 1
Output: 0
Explanation: Let the indices 1 and 3 form a pair. The difference of that pair is |2 - 2| = 0, which is the minimum we can attain.


Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109
0 <= p <= (nums.length)/2
Accepted
9.8K
Submissions
30.6K
Acceptance Rate
31.9%

*/

#include <vector>
#include <queue>

using namespace std;

class Solution {
int countPairs(vector<int>& nums, int thresh) {
  int i = 0;
  int count = 0;
  while (i < nums.size()-1) {
    int j = nums[i];
    int k = nums[i+1];
    if (abs(j-k) < thresh) {
      ++count;
      ++i;
    }
    ++i;
  }
  return count;
}
public:
    int minimizeMax(vector<int>& nums, int p) {

      sort(nums.begin(), nums.end());
      int mx = abs(nums.back() - nums.front());
      int mn = 0;
      int res = mx;
      while (mn < mx) {
        int mid = mn + (mx-mn) / 2;
        int pairs = countPairs(nums, mid);
        if (pairs >= p) {
          res = mid;
          mx = mid-1;
        } else {
          mn = mid+1;
        }
      }
      return res;
    }
};

/*

Input: nums = [10,1,2,7,1,3], p = 2
Output: 1

compare 0,1 0,2 0,3 ... 0,5
compare 1,2 1,3 1,4 ,1,5
etc...
4,5 - but indexes can't be reused
so 0,1  precludes all items from 0 row and 1 row 0x and 1x

or we make n*n matrix
_ 01 02 03 04 05
10 _ 12 13 14 15

or just dp/dfs it

pick idx from a pool - eliminate that from pool
keep track of depth
at depth p you end
every other pick calc diff
keep pq (max on top)
keep track of items in pq
if capacity
if diff < pq pop top, insert

cur [], remain [0,1,2,3,4,5]
[0]
  [0,1] [0,2] [0,3] [0,4] [0,5]
[1]
  [0,1]<-- dont recount this [1,2] [1,3]
[2]
  [2,3]
  base:
  if remain just has two items,

  pick 2 each time?

  01, 02, 03, 04, 05
  12, 13, 14, 15
  23, 24, 25,
  34, 35
  45

  01 2345
  02 1345
  03 1245
  04 1235
  05 1234

  Peek official: not dp, but greedy+Binary search
  sort arr

  sorted
  [1,1,2,3,7,10]
  [1,1] [2,3]

  sorted
  [1,2,2,4]
  [1,2] or
  [2,2] or <--
  [2,4]

*/