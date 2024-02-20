/*

594. Longest Harmonious Subsequence
Easy
2K
196
Companies
We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.

A subsequence of array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.



Example 1:

Input: nums = [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
Example 2:

Input: nums = [1,2,3,4]
Output: 2
Example 3:

Input: nums = [1,1,1,1]
Output: 0


Constraints:

1 <= nums.length <= 2 * 104
-109 <= nums[i] <= 109
Accepted
139.3K
Submissions
258.8K
Acceptance Rate
53.8%


*/

#include <vector>
#include <map>

using namespace std;

class Solution {
map<int,int> freq;
public:
    int findLHS(vector<int>& nums) {
      for (int i: nums) {
        freq[i]++;
      }
      int mx = 0;
      for (auto a: freq) {
        if (a.second == 0) continue;

        if (freq[a.first+1] == 0) continue;

        int total = a.second;
        total+= freq[a.first+1];
        if (total > mx) mx = total;
      }
      return mx;
    }
};

// counting:
// store keys and frequencies of that key
// iterate thru keys - always find the adjacent key to right
