/*

2134. Minimum Swaps to Group All 1's Together II
Medium
Topics
Companies
Hint
A swap is defined as taking two distinct positions in an array and swapping the values in them.

A circular array is defined as an array where we consider the first element and the last element to be adjacent.

Given a binary circular array nums, return the minimum number of swaps required to group all 1's present in the array together at any location.



Example 1:

Input: nums = [0,1,0,1,1,0,0]
Output: 1
Explanation: Here are a few of the ways to group all the 1's together:
[0,0,1,1,1,0,0] using 1 swap.
[0,1,1,1,0,0,0] using 1 swap.
[1,1,0,0,0,0,1] using 2 swaps (using the circular property of the array).
There is no way to group all 1's together with 0 swaps.
Thus, the minimum number of swaps required is 1.
Example 2:

Input: nums = [0,1,1,1,0,0,1,1,0]
Output: 2
Explanation: Here are a few of the ways to group all the 1's together:
[1,1,1,0,0,0,0,1,1] using 2 swaps (using the circular property of the array).
[1,1,1,1,1,0,0,0,0] using 2 swaps.
There is no way to group all 1's together with 0 or 1 swaps.
Thus, the minimum number of swaps required is 2.
Example 3:

Input: nums = [1,1,0,0,1]
Output: 0
Explanation: All the 1's are already grouped together due to the circular property of the array.
Thus, the minimum number of swaps required is 0.


Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
65K
Submissions
108K
Acceptance Rate
60.2%

*/

#include <vector>

using namespace std;
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int sz = nums.size();
        // deal with circularness
        // pop zeroes and append to end until first 1
        int total1s = 0;
        for (int i: nums) if (i == 1) total1s++;
        vector<int> unrolled(nums.begin(),nums.end());
        unrolled.insert(unrolled.end(), nums.begin(), nums.end());
        int num1s = 0;
        for (int i = 0; i < sz; ++i) {
          if (unrolled[i] == 1) num1s++;
        }
        int curtotal = total1s;
        for (int i = 0; i < total1s; ++i) {
          int bki = total1s-i;
          if (unrolled[bki] == 1) curtotal+=1;
          if (unrolled[i] == 1) curtotal-=1;
          // window should be size of total 1s
        }
        return 0;
    }
};