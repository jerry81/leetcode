/*

717. 1-bit and 2-bit Characters
Easy
825
2K
Companies
We have two special characters:

The first character can be represented by one bit 0.
The second character can be represented by two bits (10 or 11).
Given a binary array bits that ends with 0, return true if the last character must be a one-bit character.



Example 1:

Input: bits = [1,0,0]
Output: true
Explanation: The only way to decode it is two-bit character and one-bit character.
So the last character is one-bit character.
Example 2:

Input: bits = [1,1,1,0]
Output: false
Explanation: The only way to decode it is two-bit character and two-bit character.
So the last character is not one-bit character.


Constraints:

1 <= bits.length <= 1000
bits[i] is either 0 or 1.
Accepted
122.4K
Submissions
270.1K
Acceptance Rate
45.3%

*/

#include <vector>

using namespace std;

class Solution {

bool r(int idx, vector<int>& bits, int &n){
  if (idx == n-1) return true;

  if (idx >= n) return false;
  int cur = bits[idx];
  if (cur == 0) {
    return r(idx+1, bits, n);
  } else {
    return r(idx+2, bits, n);
  }
}
public:
    bool isOneBitCharacter(vector<int>& bits) {
      int n = bits.size();
      return r(0,bits,n);
    }
};

/*

like staircase problem

recursive

*/