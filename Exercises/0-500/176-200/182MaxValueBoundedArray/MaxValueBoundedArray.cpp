/*

1802. Maximum Value at a Given Index in a Bounded Array
Medium
845
148
Companies
You are given three positive integers: n, index, and maxSum. You want to
construct an array nums (0-indexed) that satisfies the following conditions:

nums.length == n
nums[i] is a positive integer where 0 <= i < n.
abs(nums[i] - nums[i+1]) <= 1 where 0 <= i < n-1. so, 1 or 0 diff
The sum of all the elements of nums does not exceed maxSum.
nums[index] is maximized.
Return nums[index] of the constructed array.

Note that abs(x) equals x if x >= 0, and -x otherwise.

Input: n = 6, index = 1,  maxSum = 10
Output: 3

[454321] max sum exceeded
[3,4,3,2,1,0]
[2,3,2,1,0,0]

Example 1:

Input: n = 4, index = 2,  maxSum = 6
Output: 2
Explanation: nums = [1,2,2,1] is one array that satisfies all the conditions.
There are no arrays that satisfy all the conditions and have nums[2] == 3, so 2
is the maximum nums[2]. Example 2:

Input: n = 6, index = 1,  maxSum = 10
Output: 3




Constraints:

1 <= n <= maxSum <= 109
0 <= index < n
Accepted
18.3K
Submissions
54.7K
Acceptance Rate
33.4%

*/

#include <iostream>
using namespace std;

class Solution {
 public:
  long long sumSeries(int startV, int endV) {
    if (startV < 0) return 0;
    if (endV < 0) return 0;
    if (endV < startV) return 0;

    int n = endV - startV + 1;
    return (long long)(n * (long long)(startV + endV)) / 2;
  }

  int maxValue(int n, int index, int maxSum) {
    int high = maxSum;
    int low = 0;
    int result = 0;
    int itemsAfterIdx = n - index - 1;

    while (high >= low) {
      int mid = (high + low) / 2;
      long long curSum = mid;

      // 0 to mid if index > mid mid 7, idx 2 then 5,6,7

      long long sum1 = sumSeries(max(mid - index, 1), mid - 1);
      if (index > 0) {
        curSum += sum1;
      }
      if (index >= mid)
        curSum += (index - mid + 1);  // off by one?
                                      // index 7, mid 5
                                      // [11112345]


      if (curSum > maxSum) {
        high = mid - 1;
        continue;
      }
      long long sum2 = sumSeries(max(mid - (n - index -1), 1), mid - 1);
      if (index < n - 1) curSum += sum2;


      if (itemsAfterIdx >= mid) curSum += (itemsAfterIdx - mid) + 1;



      if (curSum > maxSum) {
        high = mid - 1;
        continue;
      }
      if (curSum == maxSum) {
        return max(1, mid);
      }
      if (curSum <= maxSum) result = mid;
      low = mid + 1;
    }
    return max(1, result);
  }
};

int main() {
  Solution s;
  // cout << "expect 6 " << s.sumSeries(0,3) << endl;
  //  cout << "expect 5 " << s.sumSeries(2,3) << endl;
  // cout << "expect 4 " << s.sumSeries(4, 4) << endl;
  // cout << "expect 3 " << s.maxValue(6, 1, 10) << endl;
  // cout << "expect 2 " << s.maxValue(4, 2, 6) << endl;
  // cout << "expect 7 " << s.maxValue(3, 2, 18) << endl;
  // cout << "expect 1 " << s.maxValue(4, 0, 4) << endl;
  // cout << "expect 3 " << s.maxValue(9, 3, 16) << endl;
    // cout << "expect 6 " << s.maxValue(7, 5, 29) << endl;
  // cout << "expect 4 " << s.maxValue(9, 5, 24) << endl;
  // cout << "expect 2 " << s.maxValue(4, 0, 6) << endl;
   cout << "expect 132863030 " << s.maxValue(7, 0, 930041194) << endl;

}

/*

  [2,1,1,1] - 5
  [3,2,1,1] - 7
    - first check 0
    - seocnd check 0
    - 3rd check 6
    - 4th check 7

  [1,1,2,3,4,5,4,3,2] - 25 over
  first step - 1 to 5  - 15
  second step 16

  [1,2,3,4,5,6,5] - 26
  // after first half: 21
  //

  [1 1 2 3 2 1 1 1 1] = 13
  [1,1 1 2 1 1 1 1 1]

*/
/*

changes - add 1s at the end

*/