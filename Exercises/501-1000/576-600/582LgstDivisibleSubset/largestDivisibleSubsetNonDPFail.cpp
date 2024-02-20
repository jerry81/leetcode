/*
368. Largest Divisible Subset
Medium
Topics
Companies
Given a set of distinct positive integers nums, return the largest subset answer
such that every pair (answer[i], answer[j]) of elements in this subset
satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.



Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]


Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
All the integers in nums are unique.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
208.2K
Submissions
489.4K
Acceptance Rate
42.5%
*/

#include <cmath>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
  const long long int UPPERBOUND = 2 * pow(10, 9);

 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    vector<int> res;
    unordered_set<int> lookup;
    for (int i : nums) {
      lookup.insert(i);
    }
    for (int i : nums) {
      vector<int> cur = {};
      if (i == 1) continue;
      long long int curm = i;
      cur.push_back(i);
      while (curm <= UPPERBOUND) {
        curm*=2;
        if (lookup.find(curm) != lookup.end()) {
          cur.push_back(curm);
        }
      }
      if (cur.size() > res.size()) {
        res = cur;
      }
    }
    if (lookup.find(1) != lookup.end()) res.push_back(1);

    return res;
  }
};

/*
  1,2,3
  1 with anything
  1248
  if 2 and 1 work, then 4 and 2 work
  1,2,3,6,9,12
*/