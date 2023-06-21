/*

2448. Minimum Cost to Make Array Equal
Hard
713
11
Companies
You are given two 0-indexed arrays nums and cost consisting each of n positive integers.

You can do the following operation any number of times:

Increase or decrease any element of the array nums by 1.
The cost of doing one operation on the ith element is cost[i].

Return the minimum total cost such that all the elements of the array nums become equal.



Example 1:

Input: nums = [1,3,5,2], cost = [2,3,1,14]
Output: 8
Explanation: We can make all the elements equal to 2 in the following way:
- Increase the 0th element one time. The cost is 2.
- Decrease the 1st element one time. The cost is 3.
- Decrease the 2nd element three times. The cost is 1 + 1 + 1 = 3.
The total cost is 2 + 3 + 3 = 8.
It can be shown that we cannot make the array equal with a smaller cost.
Example 2:

Input: nums = [2,2,2,2,2], cost = [4,2,8,1,3]
Output: 0
Explanation: All the elements are already equal, so no operations are needed.


Constraints:

n == nums.length == cost.length
1 <= n <= 105
1 <= nums[i], cost[i] <= 106
Accepted
16K
Submissions
42.5K
Acceptance Rate
37.6%

*/

#include <vector>


using namespace std;

class Solution {
long long sumCost(int tgt, vector<int>& nums, vector<int>& cost) {
  long long rsum = 0;
  for (int i = 0; i < nums.size(); ++i) {
    int cur = nums[i];
    int diff = abs(nums[i] - tgt);
    rsum += diff*cost[i];
  }
  return rsum;
}

public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
      int mine = INT_MAX;
      int maxe = INT_MIN;
      for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] < mine) mine = nums[i];

        if (nums[i] > maxe) maxe = nums[i];
      }
      int minsum = INT_MAX;
      int midpoint = (mine + maxe) / 2;
      int compare = midpoint+1;
      long long sumMid=sumCost(midpoint, nums, cost);
      long long sumCmp=sumCost(compare, nums, cost);
      if (sumMid < sumCmp) {
        // colder
        maxe = compare - 1;
      } else {
        // warmer
        mine = compare;
      }
      cout << "maxe " << maxe << endl;
      cout << "mine " << mine << endl;
      return minsum;

    }
};

/*

seen this problem before (electrical wiring problem)
- but while the solution to that was to get some sort of average, this is different as each index has a different cost to "move"


- kind of like the triangulation problem
- first seed the triangulation with min jump to max
- get a warmer or colder
-
*/