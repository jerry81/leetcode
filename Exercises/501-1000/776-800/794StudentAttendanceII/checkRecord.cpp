/*

552. Student Attendance Record II
Hard
Topics
Companies
An attendance record for a student can be represented as a string where each
character signifies whether the student was absent, late, or present on that
day. The record only contains the following three characters:

'A': Absent.
'L': Late.
'P': Present.
Any student is eligible for an attendance award if they meet both of the
following criteria:

The student was absent ('A') for strictly fewer than 2 days total.
The student was never late ('L') for 3 or more consecutive days.
Given an integer n, return the number of possible attendance records of length n
that make a student eligible for an attendance award. The answer may be very
large, so return it modulo 109 + 7.



Example 1:

Input: n = 2
Output: 8
Explanation: There are 8 records with length 2 that are eligible for an award:
"PP", "AP", "PA", "LP", "PL", "AL", "LA", "LL"
Only "AA" is not eligible because there are 2 absences (there need to be fewer
than 2). Example 2:

Input: n = 1
Output: 3
Example 3:

Input: n = 10101
Output: 183236316


Constraints:

1 <= n <= 105
Seen this question in a real interview before?
1/5
Yes
No
Accepted
67.1K
Submissions
156.2K
Acceptance Rate
42.9%
*/

class Solution {
  const int MOD = 1e9 + 7;
  int r(int remain, int a, int l) {
    if (remain <= 0) return 0;

    if (a > 1) return 0;

    if (l > 2) return 0;

    if (remain == 1) {
      int early_ret = 3;
      if (a >= 1) early_ret--;
      if (l >= 2) early_ret--;
      return early_ret;
    }
    int nxt = remain-1;
    // P
    int p = 1 + r(nxt, a, 0);
    // A
    int a = 1 + r(nxt, a+1, 0);
    // L
    int l = 1 + r(nxt, a, l+1);
    long long sum = p;
    sum+=a;
    sum %= MOD;
    sum +=l;
    sum%=MOD;
    return (int)sum;
  }

 public:
  int checkRecord(int n) {
    // some kind of knapsack backtracking with math
    // two must not be A
    if (n == 1) return 3;
    return r(n, 0, 0);
  }
};