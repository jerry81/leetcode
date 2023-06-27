/*

373. Find K Pairs with Smallest Sums
Medium
4.3K
258
Companies
You are given two integer arrays nums1 and nums2 sorted in ascending order and
an integer k.

Define a pair (u, v) which consists of one element from the first array and one
element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.



Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6] Example 2:

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
Explanation: The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3] Example 3:

Input: nums1 = [1,2], nums2 = [3], k = 3
Output: [[1,3],[2,3]]
Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]


Constraints:

1 <= nums1.length, nums2.length <= 105
-109 <= nums1[i], nums2[i] <= 109
nums1 and nums2 both are sorted in ascending order.
1 <= k <= 104
Accepted
205.6K
Submissions
534.8K
Acceptance Rate
38.4%

*/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                     int k) {
    int ptr1 = 0;
    int ptr2 = 0;
    vector<vector<int>> ret;
    while (true) {
      vector<int> vec;
      int cur1 = nums1[ptr1];
      int cur2 = nums2[ptr2];
      vec.push_back(cur1);
      vec.push_back(cur2);
      ret.push_back(vec);
      // get next ptrs
      int n1 = ptr1 + 1;
      int n2 = ptr2 + 1;

      if (n1 >= nums1.size() && n2 >= nums2.size()) return ret;

      if (n1 >= nums1.size()) {
        ptr2 = n2;
        continue;
      }

      if (n2 >= nums2.size()) {
        ptr1 = n1;
        continue;
      }

      int next1 = nums1[n1];
      int next2 = nums2[n2];

      if (cur1 < cur2) {
        // keep cur1, search for stopping point

        int toSearch = next1 + cur2 - cur1;
        auto found = lower_bound(nums2.begin() + n2, nums2.end(), toSearch + 1);
        int tmp = distance(nums2.begin(), found);
        for (int i = n2; i <= tmp; ++i) {
          vector<int> v;
          v.push_back(cur1);
          v.push_back(nums2[i]);
          ret.push_back(v);
          if (ret.size() == k) return ret;
        }
        ptr1++;
      } else if (cur1 > cur2) {
        int toSearch = next2 + cur1 - cur2;
        auto found = lower_bound(nums1.begin() + n1, nums1.end(), toSearch + 1);
        int tmp = distance(nums1.begin(), found);
        for (int i = n2; i <= tmp; ++i) {
          vector<int> v;
          v.push_back(cur2);
          v.push_back(nums1[i]);
          ret.push_back(v);
          if (ret.size() == k) return ret;
        }
        ptr2++;
      } else {
        // super annoying case - equal - could continue ad infinitum
        if (next1 <= next2) {
          // just increment 1
          vector<int> v;
          v.push_back(cur2);
          v.push_back(next1);
          ret.push_back(v);
          if (ret.size() == k) return ret;
          ptr1++;
        } else {
          vector<int> v;
          v.push_back(cur1);
          v.push_back(next2);
          ret.push_back(v);
          if (ret.size() == k) return ret;
          ptr2++;
        }
      }
    }
    return ret;
  }
};

/*

        [1,7,11] [2,4,6,8,9]
        cur 1,2
        keep - nums1
        next 7
        lowerbound 7 - entire array


        [1,3,7,10] [5,6,7,8]

        1 vs 5
        look for next1 3 + cur2 5 = (8-1) = 7
        ptr = 2
        so 0,[1,2] goes in
        ptr1+=1
        ptr2=0
        3,5
        next1 7
        cur2 5 look for 7+5 - cur1 3 = 9 3, [1,3] all go in
        ptr2+=1
        3 vs 6
        loop for 3
        next 7 + 6 = 13 - 3 = 10
        search 10 (incl)
        6,[2,3]
        1 - next 3+5  = 8  lower bound 7,1

      */

/*


Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

1,2
1,7 or 1,4
1 7 or 1,6

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
Explanation: The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]

1 or 1
1 or 1

Input: nums1 = [1,2], nums2 = [3], k = 3
Output: [[1,3],[2,3]]
Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]
1 or 3
2 or 3

- but it can't be this straightforward
- must be an optimization problem
- sorted so, bsearch for the index

*/