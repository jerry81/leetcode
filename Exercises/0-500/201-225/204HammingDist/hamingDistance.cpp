/*

461. Hamming Distance
Easy
3.6K
211
Companies
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, return the Hamming distance between them.



Example 1:

Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
The above arrows point to positions where the corresponding bits are different.
Example 2:

Input: x = 3, y = 1
Output: 1


Constraints:

0 <= x, y <= 231 - 1
Accepted
529K
Submissions
704.9K
Acceptance Rate
75.0%

*/

#include <bitset>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
      // to binary strs
      bitset<sizeof(int) * 8> asB(x);
      string xs = asB.to_string();
      bitset<sizeof(int) * 8> asB2(y);
      string ys = asB2.to_string();
      int res = 0;
      for (int i = 0; i < xs.size(); ++i) {
        if (asB[i] != asB2[i]) res++;
      }
      return res;
    }
};