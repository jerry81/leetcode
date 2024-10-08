/*
650. 2 Keys Keyboard
Medium
Topics
Companies
Hint
There is only one character 'A' on the screen of a notepad. You can perform one of two operations on this notepad for each step:

Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
Given an integer n, return the minimum number of operations to get the character 'A' exactly n times on the screen.



Example 1:

Input: n = 3
Output: 3
Explanation: Initially, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.
Example 2:

Input: n = 1
Output: 0


Constraints:

1 <= n <= 1000
Seen this question in a real interview before?
1/5
Yes
No
Accepted
146.7K
Submissions
267.8K
Acceptance Rate
54.8%
*/

#include <climits>
#include <algorithm>

using namespace std;

class Solution {
  int r(int tgt, int screen, int cnt) {
    // edge cases
    if (tgt == screen) return 0;

    if (screen > tgt) return 1001;

    int cpy_case = 2+r(tgt, screen*2, screen);

    if (cnt == 0) return cpy_case;

    int add_case = 1+r(tgt, screen+cnt, cnt);

    return min(add_case, (int)cpy_case);
  }
public:
    int minSteps(int n) {
      // dp & recursion
      return r(n, 1, 0);
    }
};