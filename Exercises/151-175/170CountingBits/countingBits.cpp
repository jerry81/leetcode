#include <vector>
#include <bitset>

using namespace std;

class Solution {
bool isPowerOfTwo(int number) {
    if (number <= 0)
        return false;

    return (number & (number - 1)) == 0;
}
public:
    vector<int> countBits(int n) {
      vector<int> memo(n, -1);
      vector<bool> bits(32, false);
      vector<int> res;
      if (n==0) return {0};
      memo[0] = 0;
      res.push_back(0);
      if (n==1) return {1};
      memo[1] = 1;
      res.push_back(1);
      int prevPower = 1;
      for (int i = 2; i <n; ++i) {
        if (isPowerOfTwo(i)) {
          memo[i] = 1;
          prevPower = i;
          res.push_back(1);
        } else {
          memo[i] = memo[prevPower] + memo[i-prevPower];
          res.push_back(memo[i]);
        }
      }
    }
};

/*

memoization
0 = 0
1 = 1
2 = 1
3 = 2+1
4 = 1
1-01 1 - incr  0+1
2-10 1 - reset
3-11 2 - incr   [2] + 1
4-100 1 - reset
5-101 2  - incr
6-110 2  - mini reset
7-111 3  - incr
8-1000 1 - reset
9 - 1001 2 -  8+1
10 - 1010 2
11 - 1011 3
13 - 1101 3
14 - 1110  3
15 - 1111 4   (8+7)
16 - 10000 1  16+1
17 - 10001 2
18  - 10010 2
19    10011 3
     10100 2
     10101 3
     10110 3
     10111 4
     11000 2
     11001 3
     11010 3
     11011 4
     11100 3
     11101 4
     11110 4
     11111 5
32  100000
- flip around
100000
010000
11
001
101
011

*/

/*

338. Counting Bits
Easy
8.9K
424
Companies
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.



Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101


Constraints:

0 <= n <= 105


Follow up:

It is very easy to come up with a solution with a runtime of O(n log n). Can you do it in linear time O(n) and possibly in a single pass?
Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?
Accepted
778K
Submissions
1M
Acceptance Rate
75.9%

*/