/*

41. First Missing Positive
Hard
Topics
Companies
Hint
Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.



Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.


Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
Seen this question in a real interview before?
1/4
Yes
No
Accepted
1.1M
Submissions
2.8M
Acceptance Rate
38.0%

*/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
unordered_set<int> lookup;
public:
    int firstMissingPositive(vector<int>& nums) {

      int mnPos = 1;
      for (int i: nums) {
        if (i > 0) lookup.insert(i);
      }

      int cur = 1;
      while (true) {
      if (lookup.find(cur) == lookup.end()) {
        return cur;
      }
      cur++;
    }
          return 1;
}
};