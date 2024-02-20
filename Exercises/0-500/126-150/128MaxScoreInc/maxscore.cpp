/*

1799. Maximize Score After N Operations
Hard
685
61
Companies
You are given nums, an array of positive integers of size 2 * n. You must perform n operations on this array.

In the ith operation (1-indexed), you will:

Choose two elements, x and y.
Receive a score of i * gcd(x, y).
Remove x and y from nums.
Return the maximum score you can receive after performing n operations.

The function gcd(x, y) is the greatest common divisor of x and y.



Example 1:

Input: nums = [1,2]
Output: 1
Explanation: The optimal choice of operations is:
(1 * gcd(1, 2)) = 1
Example 2:

Input: nums = [3,4,6,8]
Output: 11
Explanation: The optimal choice of operations is:
(1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11
Example 3:

Input: nums = [1,2,3,4,5,6]
Output: 14
Explanation: The optimal choice of operations is:
(1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14


Constraints:

1 <= n <= 7
nums.length == 2 * n
1 <= nums[i] <= 106
Accepted
21.3K
Submissions
42.5K
Acceptance Rate
50.0%

*/

#include <vector>
#include <cmath>
#include <unordered_map>
#include <iostream>

using namespace std;
class Solution {
unordered_map<int, int> lookup;
vector<int> sorted;
int gcd(int a, int b) {
    // Ensure that a is always greater than or equal to b
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}
int getMaxDivisor(int input) {
  int ret = 1;
  int limit = (int)input/2;
  if (lookup[input] > 1) return input;

  for (int i: sorted) {
    if (i == input) continue;

    int g = gcd(input, i);
    if (g > ret) ret = g;
  }
  return ret;
}
public:
    int maxScore(vector<int>& nums) {
        sorted = nums;
        vector<int> toUse;
        int sum = 0;
        sort(sorted.begin(), sorted.end());
        for (int i = 0; i < nums.size(); ++i) {
          lookup[nums[i]]++;
        }
        for (int i = sorted.size()-1; i >= nums.size()/2; --i) {
          toUse.push_back(getMaxDivisor(sorted[i]));
        }
        sort(toUse.begin(), toUse.end());
        int counter = 1;
        for (int i: toUse) {
          sum+=i*counter;
          counter++;
        }
        return sum;
    }
};
/*

sort by GCD
some kind of greedy

*/