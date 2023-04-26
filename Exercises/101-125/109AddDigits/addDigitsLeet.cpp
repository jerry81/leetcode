/*

258. Add Digits
Easy
3.5K
1.8K
Companies
Given an integer num, repeatedly add all its digits until the result has only
one digit, and return it.



Example 1:

Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2
Since 2 has only one digit, return it.
Example 2:

Input: num = 0
Output: 0


Constraints:

0 <= num <= 231 - 1


Follow up: Could you do it without any loop/recursion in O(1) runtime?

Accepted
577.4K
Submissions
896.3K
Acceptance Rate
64.4%

*/

using namespace std;
#include <string>

class Solution {
 public:
  int addDigits(int num) {
    int rem = num%9;
    if (num == 0) return 0;
    return rem == 0 ? 9 : rem;
  }
};

// naive first

// no loop???
// special math knowledge needed: Digital root
/*

If number is divisible by 9 completely then digital root(ans) is 9,else the digital root is remainder obtained.

P.S-I learnt this beautiful thing today!

11 -> 2
12 -> 3
20 -> 2
21 -> 3
27 -> 9
28 -> 1
29 -> 2
30 -> 3
31 -> 4
980-> 8
981 -> 9
982 -> 1
983 -> 2
...
990 -> 9
991 -> 1
992 -> 2
...
999 -> 9


*/